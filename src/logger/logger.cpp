#include "logger/logger.h"

#include <iostream>

namespace {
physika::logger::LogLevel sLevel;
}

namespace physika {
namespace logger {

void SetLoggingLevel(LogLevel level)
{
    sLevel = level;
}
void LogMessage(LogLevel level, char const* severity, char const* message)
{
    if (level < sLevel) {
        return;
    }
    printf("[%s]: %s\n", severity, message);
}

}  // namespace logger
}  // namespace physika