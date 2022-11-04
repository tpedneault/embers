#include "embers.h"
#include "logging.h"

#if EMBERS_ENABLE_UART_CONSOLE == ENABLED
void _uartConsoleReadCb(char *buffer, int length) {
  buffer = "read_test";
}

void _uartConsoleWriteCb(const char *buffer, int length) {
  logTrace(buffer);
}
#endif

uint8_t embersInit() {
  logInit();
#ifdef EMBERS_ENABLE_UART_CONSOLE
  uartInit(UART_CONSOLE, (uartReadCb)_uartConsoleReadCb, (uartWriteCb)_uartConsoleWriteCb);
#endif
  return 0;
}
