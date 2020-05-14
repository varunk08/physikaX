#pragma once

namespace physika {

/**
 * @brief Represent a timer object which can start/stop a timer
 *        and sample time at user-defined intervals
 *
 */
class Timer
{
public:
    /**
     * @brief Construct a new Timer object
     *
     */
    Timer();
    /**
     * @brief Returns the total elapsed time since the
     *        the creation of the timer object
     */
    float TotalElapsedTime();
};
}  // namespace physika