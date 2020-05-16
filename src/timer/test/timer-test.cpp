#include "timer/timer.h"

#include <chrono>  // std::chrono::seconds
#include <thread>  // std::this_thread::sleep_for

#include "gtest/gtest.h"

namespace {

using namespace std;
using namespace physika;

TEST(TimerTest, InitializeTimer)
{
    Timer timer;
    EXPECT_FLOAT_EQ(0.0f, timer.TotalRunningTime());
}

TEST(TimerTest, GetTotalRunningTimeAfterATick)
{
    Timer timer;
    timer.Start();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    timer.Tick();
    EXPECT_LE(1.0f, timer.TotalRunningTime());
}

TEST(TimerTest, GetTotalRunningTimeAfterStop)
{
    Timer timer;
    timer.Start();

    std::this_thread::sleep_for(std::chrono::seconds(1));
    timer.Tick();
    ASSERT_LE(1.0f, timer.TotalRunningTime());

    std::this_thread::sleep_for(std::chrono::seconds(1));
    timer.Tick();
    ASSERT_LE(2.0f, timer.TotalRunningTime());
    timer.Stop();

    std::this_thread::sleep_for(std::chrono::seconds(1));
    timer.Tick();
    ASSERT_GT(3.0f, timer.TotalRunningTime());
}

TEST(TimerTest, GetTotalRunningTimeAfterReset)
{
    Timer timer;
    timer.Start();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    timer.Tick();
    ASSERT_LE(1.0f, timer.TotalRunningTime());

    timer.Stop();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    timer.Tick();
    ASSERT_GT(2.0f, timer.TotalRunningTime());

    timer.Reset();
    ASSERT_FLOAT_EQ(0.0f, timer.TotalRunningTime());
}

TEST(TimerTest, CallResetBetweenStartAndStop)
{
    Timer timer;
    timer.Start();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    timer.Tick();
    ASSERT_LE(1.0f, timer.TotalRunningTime());

    timer.Reset();
    ASSERT_NE(0.0f, timer.TotalRunningTime());

    timer.Stop();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    timer.Tick();
    ASSERT_GT(2.0f, timer.TotalRunningTime());
}

}  // namespace