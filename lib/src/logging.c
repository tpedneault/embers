#include "logging.h"
#include <stdarg.h>
#include <stdio.h>

#define LOGGING_MAX_CALLBACKS 32

static const char *logSeverityString[6] = {"TRACE", "DEBUG", "INFO",
                                           "WARN",  "ERROR", "FATAL"};

static const char *logSeverityColors[6] = {"\x1b[90m", "\x1b[32m", "",
                                           "\x1b[33m", "\x1b[31m", "\x1b[35m"};

typedef struct {
  loggingFn fn;
  void* data;
} loggingCallback; 

static struct {
  uint8_t numCallbacks;
  loggingCallback callbacks[LOGGING_MAX_CALLBACKS];
} LOGGING;

struct tm *_logGetTimestamp() {
  time_t currentTime = time(NULL);
  if (currentTime == ((time_t)-1)) {
    (void)fprintf(stderr, "Failed to obtain the current time.\n");
    exit(EXIT_FAILURE);
  }

  struct tm *timeInfo = localtime(&currentTime);
  return timeInfo;
}

void _logDefaultCallback(const uint8_t severity, const char *file, int line, const char *fmt, va_list args) {
  const char *color = logSeverityColors[severity];
  const char *severityStr = logSeverityString[severity];
  struct tm *timestamp = _logGetTimestamp();
  printf("%s%02d:%02d:%02d %-5s %s:%i: \x1b[0m", color, timestamp->tm_hour,
         timestamp->tm_min, timestamp->tm_sec, severityStr, file, line);
  vprintf(fmt, args);
  printf("\n");
}

void logInit() {
  logRegisterCb(_logDefaultCallback); 
}

void logRegisterCb(loggingFn callback) {
  loggingCallback cb = { .fn = callback, .data = NULL }; 
  int i = LOGGING.numCallbacks;
  LOGGING.callbacks[i] = cb;
  LOGGING.numCallbacks++;
}

void logMsg(const uint8_t severity, const char *file, int line, const char *fmt, ...) {
  for (int i = 0; i < LOGGING.numCallbacks; i++) {
    if (!LOGGING.callbacks[i].fn) {
      continue;
    }
    va_list args;
    va_start(args, fmt);
    LOGGING.callbacks[i].fn(severity, file, line, fmt, args);
    va_end(args);
  }
}
