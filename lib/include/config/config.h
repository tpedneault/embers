#ifndef _CONFIG_H
#define _CONFIG_H

//
// Configuration file for the Embers framework.
// To enable an option, set its value to ENABLED / DISABLED.
// If the option takes in a specific value, follow the instructions.
//

#define ENABLED  0
#define DISABLED 1

/////////////////////////////////////////////////////////////////
//                      LOGGING SETTINGS                       //
/////////////////////////////////////////////////////////////////

// Enables the default logger function.
#define EMBERS_LOG_DEFAULT_CB ENABLED

// Sets the maximum number of callbacks for the logger.
#define EMBERS_LOG_MAX_CALLBACKS 32

/////////////////////////////////////////////////////////////////
//                        UART SETTINGS                        //
/////////////////////////////////////////////////////////////////

// Sets the maximum number of instances for the UART drivers.
#define EMBERS_UART_MAX_INSTANCES 8

// Enables printing to stdout using UART_CONSOLE.
#define EMBERS_ENABLE_UART_CONSOLE ENABLED



#endif
