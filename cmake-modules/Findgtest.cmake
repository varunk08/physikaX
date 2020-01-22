include(GoogleTest)
enable_testing()

option(
  gtest_force_shared_crt
  "Use shared (DLL) run-time lib even when Google Test is built as static lib."
  ON)

  add_subdirectory(${CMAKE_SOURCE_DIR}/3rdParty/gtest)


  set_target_properties(gtest PROPERTIES FOLDER extern)
  set_target_properties(gtest_main PROPERTIES FOLDER extern)
  set_target_properties(gmock PROPERTIES FOLDER extern)
  set_target_properties(gmock_main PROPERTIES FOLDER extern)

function(phi_add_gtest TEST_TARGET)
  cmake_parse_arguments(
      PHI
      ""
      ""
      "SOURCES"
      ${ARGN}
  )
  phi_add_executable(${TEST_TARGET} SOURCES ${PHI_SOURCES})
  target_link_libraries(${TEST_TARGET}  
                              PRIVATE
                              gmock_main 
                              gtest
                            )
  add_custom_command(
        TARGET ${TEST_TARGET}
        POST_BUILD
        COMMAND ${TEST_TARGET}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Running test target ${TEST_TARGET}"
    )
  gtest_discover_tests(${TEST_TARGET})
endfunction()