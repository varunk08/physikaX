SET(TARGET app-framework)

SET(SOURCES 
    application-win32.cpp
    include/app-framework/input.h
    include/app-framework/application.h
    include/app-framework/application-win32.h
)

add_library(${TARGET} STATIC ${SOURCES})

target_include_directories(app-framework PUBLIC include)
target_compile_definitions(app-framework PUBLIC WIN32_LEAN_AND_MEAN)


set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:CONSOLE /ENTRY:mainCRTStartup")

# Configure example project
add_executable(${TARGET}-example example/main.cpp
                                 example/example-app.h
                                 example/example-app.cpp)

# link to app-framework static library
target_link_libraries(${TARGET}-example ${TARGET})