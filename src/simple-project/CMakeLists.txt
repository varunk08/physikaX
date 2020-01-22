set(TARGET simple-project)

set(
  SOURCES main.cpp
)

project(${TARGET})

add_executable(${TARGET} ${SOURCES})

#TEST
set(TEST_SOURCES test/simple-test.cpp)


phi_add_gtest(${TARGET}-test SOURCES ${TEST_SOURCES})