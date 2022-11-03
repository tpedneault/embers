#include "embers.h"

#define UART_MAX_INSTANCES 6

#define ENABLE_UART_CONSOLE
#ifdef ENABLE_UART_CONSOLE
void _uartConsoleReadCb(char *buffer, int length) {
  buffer = "read_test";
}

void _uartConsoleWriteCb(const char *buffer, int length) {
  logTrace(buffer);
}
#endif

uint8_t embersInit() {
#ifdef ENABLE_UART_CONSOLE
  uartInit(UART_CONSOLE, (uartReadCb)_uartConsoleReadCb, (uartWriteCb)_uartConsoleWriteCb);
  uartWrite(UART_CONSOLE, "Hello, world!", 13);
  uartWrite(0x00, "Hello, world!", 13);
#endif
  return 0;
}
