set(TARGET simple-project)
set(SOURCES main.cpp)

project(${TARGET})

add_executable(${TARGET} ${SOURCES})

#TEST
set(
    TEST_SOURCES test/simple-test.cpp
)
option(
  gtest_force_shared_crt
  "Use shared (DLL) run-time lib even when Google Test is built as static lib."
  ON)

add_executable(${TARGET}-test ${TEST_SOURCES})
target_link_libraries(${TARGET}-test PRIVATE gmock_main gtest)