SET(TARGET app-framework)

SET(SOURCES 
    main.cpp
    application-win32.h
    application-win32.cpp
)

add_executable(${TARGET} WIN32 ${SOURCES})