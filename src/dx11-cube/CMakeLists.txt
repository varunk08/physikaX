set(TARGET dx11-cube)

set( SOURCES 
        main.cpp
        cube-app.h
        cube-app.cpp
)

phi_add_executable(${TARGET}
                    SOURCES 
                        main.cpp
                        cube-app.h
                        cube-app.cpp)

target_link_libraries(${TARGET} app-framework)