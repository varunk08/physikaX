#include "timer/timer.h"

#include "gtest/gtest.h"

namespace {
using namespace physika;

TEST(TimerTest, InitializeTimer)
{
    Timer timer;
    EXPECT_FLOAT_EQ(0.0f, timer.TotalElapsedTime());
}
}  // namespace