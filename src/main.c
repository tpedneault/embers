#include "embers.h"

void exampleLogCallback(const uint8_t severity, const char* file, int line, const char* fmt, va_list args) {
  vprintf(fmt, args);
  printf("\n");
}

int main(void) {
  int res = embersInit();
  if (res != 0) {
    logFatal("Failed to initialize Embers.");
    return EXIT_FAILURE;
  }

  logRegisterCb(exampleLogCallback);

  logDebug("Debug mode message!");

  return 0;
}
