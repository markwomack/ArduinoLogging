//
// Licensed under Apache 2.0 license.
// See accompanying LICENSE file for details.
//

/**
 * This example demonstrates how to use the LOG macros and how they allow
 * the removal of the logging code from compiled code with a simple flag
 * definition.
 */
 
// Uncomment this line to remove all log macro calls
//#define INCLUDE_LOGGING false

#include <Arduino.h>
#include "src/DebugMsgs.h"
#include "src/SerialPrintWrapper.h"

void setup() {
  // Serial needs to be initialized prior to messages being printed
  Serial.begin(9600);

#if(INCLUDE_LOGGING)
  // this is a place where logging setup code could be placed
  DebugMsgs.setPrintWrapper(new SerialPrintWrapper());
#endif

  if (!INCLUDE_LOGGING) {
    Serial.println("!!!!!! No log messages should print, log macros are disabled");
    Serial.println();
  }

  Serial.println("TEST #1: default level is none");
  LOG_DEBUG("this should not print")
  LOG_WARNING("this should not print")
  LOG_ERROR("this should not print")
  LOG_NOTIFICATION("this should not print")
  LOG_STATUS("this should not print")
  LOG("this will print, but with no header")
  Serial.println();

  Serial.println("TEST #2: debug level enabled");
  LOG_ENABLE(DEBUG)
  LOG_DEBUG("this should print")
  LOG_WARNING("this should not print")
  LOG_ERROR("this should not print")
  LOG_NOTIFICATION("this should not print")
  LOG_STATUS("this should not print")
  LOG("this will print, but with no header")
  Serial.println();

  Serial.println("TEST #3: debug, warning levels enabled");
  LOG_ENABLE(WARNING);
  LOG_DEBUG("this should print")
  LOG_WARNING("this should print")
  LOG_ERROR("this should not print")
  LOG_NOTIFICATION("this should not print")
  LOG_STATUS("this should not print")
  LOG("this will print, but with no header")
  Serial.println();

  Serial.println("TEST #4: debug, warning, error levels enabled");
  LOG_ENABLE(ERROR);
  LOG_DEBUG("this should print")
  LOG_WARNING("this should print")
  LOG_ERROR("this should print")
  LOG_NOTIFICATION("this should not print")
  LOG_STATUS("this should not print")
  LOG("this will print, but with no header")
  Serial.println();

  Serial.println("TEST #5: debug, warning, error, notification levels enabled");
  LOG_ENABLE(NOTIFICATION)
  LOG_DEBUG("this should print")
  LOG_WARNING("this should print")
  LOG_ERROR("this should print")
  LOG_NOTIFICATION("this should print")
  LOG_STATUS("this should not print")
  LOG("this will print, but with no header")
  Serial.println();

  Serial.println("TEST #6: debug, warning, error, notification, status levels enabled");
  LOG_ENABLE(STATUS)
  LOG_DEBUG("this should print")
  LOG_WARNING("this should print")
  LOG_ERROR("this should print")
  LOG_NOTIFICATION("this should print")
  LOG_STATUS("this should print")
  LOG("this will print, but with no header")
  Serial.println();

  Serial.println("TEST #7: all levels disabled");
  LOG_ENABLE(NONE)
  LOG_DEBUG("this should not print")
  LOG_WARNING("this should not print")
  LOG_ERROR("this should not print")
  LOG_NOTIFICATION("this should not print")
  LOG_STATUS("this should not print")
  LOG("this will print, but with no header")
  Serial.println();

  Serial.println("TEST #8: all levels enabled");
  LOG_ENABLE(ALL)
  LOG_DEBUG("this should print")
  LOG_WARNING("this should print")
  LOG_ERROR("this should print")
  LOG_NOTIFICATION("this should print")
  LOG_STATUS("this should print")
  LOG("this will print, but with no header")
  Serial.println();

  Serial.println("TEST #8: messages with values");
  LOG_ENABLE(ALL)
  LOG_DEBUG("Message with values: %s, %d", "string value", 1234)
  Serial.println();
  
  Serial.println("Complete");
};

void loop() {
  // nothing to see here, move along.
}
