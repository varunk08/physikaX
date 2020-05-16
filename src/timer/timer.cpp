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

float Timer::Delta()
{
    return mDelta;
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
    mDelta            = 0.0f;
    mPreviousTime     = 0;
}

void Timer::Tick()
{
    if (mStopped) {
        return;
    }
    int64_t currentTime;
    QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);
    mDelta = (float)(currentTime - mPreviousTime) * mSecondsPerCount;
    mTotalRunningTime += mDelta;
    mPreviousTime = currentTime;
}

}  // namespace physika