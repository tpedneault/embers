#include "embers.h"
#include "logging.h"

int main(void) {
  int res = embersInit();
  if (res != 0) {
    logFatal("Failed to initialize Embers.");
    return EXIT_FAILURE;
  }

  logDebug("Debug mode message!");

  return 0;
}
