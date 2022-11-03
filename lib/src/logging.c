#include "logging.h"
#include <stdio.h>

static const char *logSeverityString[6] = {"TRACE", "DEBUG", "INFO",
                                           "WARN",  "ERROR", "FATAL"};

static const char *logSeverityColors[6] = {"\x1b[90m", "\x1b[32m", "",
                                           "\x1b[33m", "\x1b[31m", "\x1b[35m"};

struct tm *_logGetTimestamp() {
  time_t currentTime = time(NULL);
  if (currentTime == ((time_t)-1)) {
    (void)fprintf(stderr, "Failed to obtain the current time.\n");
    exit(EXIT_FAILURE);
  }

  struct tm *timeInfo = localtime(&currentTime);
  return timeInfo;
}

void logMsg(const uint8_t severity, const char *file, int line, const char *fmt, ...) {
  const char *color = logSeverityColors[severity];
  const char *severityStr = logSeverityString[severity];
  struct tm *timestamp = _logGetTimestamp();
  printf("%s%02d:%02d:%02d %-5s %s:%i: \x1b[0m", color, timestamp->tm_hour,
         timestamp->tm_min, timestamp->tm_sec, severityStr, file, line);
  va_list args;
  va_start(args, fmt);
  vprintf(fmt, args);
  va_end(args);
  printf("\n");
}
