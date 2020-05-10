#pragma once

namespace physika {
namespace logger {

enum class LogLevel {
    kTrace = 1 << 0,
    kDebug = 1 << 1,
    kInfo  = 1 << 2,
    kWarn  = 1 << 3,
    kError = 1 << 4,
    kFatal = 1 << 5,
};

void SetLoggingLevel(LogLevel level);
void LogMessage(LogLevel level, char const* severity, char const* message);

inline void LOG_FATAL(char const* message)
{
    LogMessage(LogLevel::kFatal, "FATAL", message);
}
inline void LOG_ERROR(char const* message)
{
    LogMessage(LogLevel::kError, "ERROR", message);
}
inline void LOG_WARN(char const* message)
{
    LogMessage(LogLevel::kWarn, "WARN", message);
}
inline void LOG_INFO(char const* message)
{
    LogMessage(LogLevel::kInfo, "INFO", message);
}
inline void LOG_DEBUG(char const* message)
{
    LogMessage(LogLevel::kDebug, "DEBUG", message);
}
inline void LOG_TRACE(char const* message)
{
    LogMessage(LogLevel::kTrace, "TRACE", message);
}

}  // namespace logger
}  // namespace physika
