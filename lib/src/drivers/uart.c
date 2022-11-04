#include "drivers/uart.h"
#include "logging.h"

typedef struct {
  uint8_t instanceId;
  uartReadCb read;
  void* readData;
  uartWriteCb write;
  void* writeData;
} uartCallback;

static struct {
  uint8_t numCallbacks;
  uartCallback callbacks[EMBERS_UART_MAX_INSTANCES];
} UART;

uint8_t uartInit(const uint8_t id, uartReadCb readCallback,
                 uartWriteCb writeCallback) {
  if (UART.numCallbacks >= EMBERS_UART_MAX_INSTANCES - 1) {
    logError("Failed to register UART instance id=%d, maximum capacity reached "
             "(cannot exceed %d instances).",
             id, EMBERS_UART_MAX_INSTANCES);
    return -1;
  }

  for (int i = 0; i < UART.numCallbacks && UART.callbacks[i].instanceId; i++) {
    logError("Failed to register UART instance id=%d, id is already in use.", id);
    return -1;
  }

  uartCallback cb = {
      .instanceId = id, .read = readCallback, .write = writeCallback };

  UART.callbacks[UART.numCallbacks] = cb;
  UART.numCallbacks++;

  logInfo("Successfully registered UART instance id=%d", id);

  return 0;
}

uint8_t uartRead(const uint8_t id, char *buffer, int length) {
  for (int i = 0; i < UART.numCallbacks; i++) {
    if (UART.callbacks[i].instanceId == id) {
      UART.callbacks[i].read(buffer, length);
      return 0;
    }
  }

  logError("Failed to write to UART instance id=%d, callback is not available", id);
  return -1;
}

uint8_t uartWrite(const uint8_t id, const char *buffer, int length) {
  for (int i = 0; i < UART.numCallbacks; i++) {
    if (UART.callbacks[i].instanceId == id) {
      UART.callbacks[i].write(buffer, length);
      return 0;
    }
  }

  logError("Failed to write to UART instance id=%d, callback is not available.", id);
  return -1;
}
