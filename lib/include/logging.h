#ifndef _LOGGING_H
#define _LOGGING_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

enum { LOG_TRACE, LOG_DEBUG, LOG_INFO, LOG_WARN, LOG_ERROR, LOG_FATAL };

typedef void (*loggingFn)(const uint8_t severity, const char *file, int line,
                          const char *fmt, va_list args);

#define logTrace(fmt, ...)   logMsg(LOG_TRACE, __FILENAME__, __LINE__, fmt, ##__VA_ARGS__)
#define logDebug(fmt, ...)   logMsg(LOG_DEBUG, __FILENAME__, __LINE__, fmt, ##__VA_ARGS__)
#define logInfo(fmt,  ...)   logMsg(LOG_INFO,  __FILENAME__, __LINE__, fmt, ##__VA_ARGS__)
#define logWarn(fmt,  ...)   logMsg(LOG_WARN,  __FILENAME__, __LINE__, fmt, ##__VA_ARGS__)
#define logError(fmt, ...)   logMsg(LOG_ERROR, __FILENAME__, __LINE__, fmt, ##__VA_ARGS__)
#define logFatal(fmt, ...)   logMsg(LOG_FATAL, __FILENAME__, __LINE__, fmt, ##__VA_ARGS__)

void logInit();
void logRegisterCb(loggingFn callback);
void logMsg(const uint8_t severity, const char* file, int line, const char* fmt, ...);

#endif
