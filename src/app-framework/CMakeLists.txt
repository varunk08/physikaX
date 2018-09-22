SET(TARGET app-framework)

SET(SOURCES 
    main.cpp
    application-win32.h
    application-win32.cpp
)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:CONSOLE /ENTRY:mainCRTStartup")

add_executable(${TARGET} WIN32 ${SOURCES})