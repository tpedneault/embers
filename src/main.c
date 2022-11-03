#include "embers.h"

int main(void) {
  int res = embersInit();
  if (res != 0) {
    logFatal("Failed to initialize Embers.");
    return EXIT_FAILURE;
  }

  return 0;
}
