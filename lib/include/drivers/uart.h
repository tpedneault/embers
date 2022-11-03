#ifndef _UART_H
#define _UART_H

#include "logging.h"

#define UART_CONSOLE 0xFF

typedef void (*uartReadCb)(char* buffer, int length);
typedef void (*uartWriteCb)(const char* buffer, int length);

uint8_t uartInit(const uint8_t id, uartReadCb readCallback,
              uartWriteCb writeCallback);
uint8_t uartRead(const uint8_t id, char *buffer, int length);
uint8_t uartWrite(const uint8_t id, const char *buffer, int length);

#endif
