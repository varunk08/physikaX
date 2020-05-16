#include "timer/timer.h"

#include <Windows.h>
namespace physika {

Timer::Timer()
    : mPreviousTime{ 0 }, mTotalRunningTime{ 0.0f }, mStopped{ false }
{
    int64_t frequency;
    QueryPerformanceCounter((LARGE_INTEGER*)&mPreviousTime);
    QueryPerformanceFrequency((LARGE_INTEGER*)&frequency);  // 1/T
    mSecondsPerCount = (float)1 / frequency;                // 1/F
}

float Timer::TotalRunningTime()
{
    return mTotalRunningTime;
}

void Timer::Start()
{
    mTotalRunningTime = 0.0f;
    QueryPerformanceCounter((LARGE_INTEGER*)&mPreviousTime);
    mStopped = false;
}

void Timer::Stop()
{
    mStopped = true;
}

void Timer::Reset()
{
    if (!mStopped) {
        return;
    }
    mTotalRunningTime = 0.0f;
    mPreviousTime     = 0.0f;
}

void Timer::Tick()
{
    if (mStopped) {
        return;
    }
    int64_t currentTime;
    QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);
    float delta = (float)(currentTime - mPreviousTime) * mSecondsPerCount;
    mTotalRunningTime += delta;
    mPreviousTime = currentTime;
}

}  // namespace physika