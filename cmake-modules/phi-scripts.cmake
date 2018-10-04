############################################
# name: phi_add_exectuable
# Description: Wrapper for add_executable 
#              Invokes clang-format as a 
#              pre-build step.
############################################
function(phi_add_executable PHI_TARGET)
    cmake_parse_arguments(
        PHI
        "WIN32"
        ""
        "SOURCES"
        ${ARGN}
    )
    
    if(PHI_WIN32)
        add_executable(${PHI_TARGET} WIN32 ${PHI_SOURCES} ${PHI_UNPARSED_ARGUMENTS})
    else()
        add_executable(${PHI_TARGET} ${PHI_SOURCES} ${PHI_UNPARSED_ARGUMENTS})
    endif()

    # Run clang-format as pre-build event.    
    add_custom_command(
        TARGET ${PHI_TARGET}
        PRE_BUILD
        COMMAND clang-format.exe -i -style=file ${PHI_SOURCES}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
endfunction()

############################################
# name: phi_add_library
# Description: Wrapper for add_library 
#              Invokes clang-format as a 
#              pre-build step.
############################################
function(phi_add_library PHI_TARGET)
    cmake_parse_arguments(
        PHI
        "STATIC;SHARED"
        ""
        "SOURCES"
        ${ARGN}
    )
    
    if(PHI_STATIC)
        add_library(${PHI_TARGET} STATIC ${PHI_SOURCES} ${PHI_UNPARSED_ARGUMENTS})
    elseif(PHI_SHARED)
        add_library(${PHI_TARGET} SHARED ${PHI_SOURCES} ${PHI_UNPARSED_ARGUMENTS})
    else()
        add_executable(${PHI_TARGET} MODULE ${PHI_SOURCES} ${PHI_UNPARSED_ARGUMENTS})
    endif()

    # Run clang-format as pre-build event.    
    add_custom_command(
        TARGET ${PHI_TARGET}
        PRE_BUILD
        COMMAND clang-format.exe -i -style=file ${PHI_SOURCES}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
endfunction()

