//
// Licensed under Apache 2.0 license.
// See accompanying LICENSE file for details.
//

#include <Arduino.h>
#include <DebugMsgs.h>

void setup() {
  // Serial needs to be initialized prior to messages being printed
  Serial.begin(9600);

  Serial.println("Round 1 - all disabled by default");
  DebugMsgs.debug().println("this should not print");
  DebugMsgs.warning().println("this should not print");
  DebugMsgs.error().println("this should not print");
  DebugMsgs.notification().println("this should not print");
  DebugMsgs.status().println("this should not print");
  DebugMsgs.println("this should not print");
  Serial.println();

  Serial.println("Round 2 - debug, not specified");
  DebugMsgs.enableLevel(DEBUG);
  DebugMsgs.debug().println("this should print");
  DebugMsgs.warning().println("this should not print");
  DebugMsgs.error().println("this should not print");
  DebugMsgs.notification().println("this should not print");
  DebugMsgs.status().println("this should not print");
  DebugMsgs.println("this should print, but without the pre header");
  Serial.println();

  Serial.println("Round 3 - debug, warning, not specified");
  DebugMsgs.enableLevel(WARNING);
  DebugMsgs.debug().println("this should print");
  DebugMsgs.warning().println("this should print");
  DebugMsgs.error().println("this should not print");
  DebugMsgs.notification().println("this should not print");
  DebugMsgs.status().println("this should not print");
  DebugMsgs.println("this should print, but without the pre header");
  Serial.println();

  Serial.println("Round 4 - debug, warning, error, not specified");
  DebugMsgs.enableLevel(ERROR);
  DebugMsgs.debug().println("this should print");
  DebugMsgs.warning().println("this should print");
  DebugMsgs.error().println("this should print");
  DebugMsgs.notification().println("this should not print");
  DebugMsgs.status().println("this should not print");
  DebugMsgs.println("this should print, but without the pre header");
  Serial.println();

  Serial.println("Round 5 - debug, warning, error, notification, not specified");
  DebugMsgs.enableLevel(NOTIFICATION);
  DebugMsgs.debug().println("this should print");
  DebugMsgs.warning().println("this should print");
  DebugMsgs.error().println("this should print");
  DebugMsgs.notification().println("this should print");
  DebugMsgs.status().println("this should not print");
  DebugMsgs.println("this should print, but without the pre header");
  Serial.println();

  Serial.println("Round 6 - debug, warning, error, notification, status, not specified");
  DebugMsgs.enableLevel(STATUS);
  DebugMsgs.debug().println("this should print");
  DebugMsgs.warning().println("this should print");
  DebugMsgs.error().println("this should print");
  DebugMsgs.notification().println("this should print");
  DebugMsgs.status().println("this should print");
  DebugMsgs.println("this should print, but without the pre header");
  Serial.println();

  Serial.println("Round 7 - all disabled");
  DebugMsgs.disableAll();
  DebugMsgs.debug().println("this should not print");
  DebugMsgs.warning().println("this should not print");
  DebugMsgs.error().println("this should not print");
  DebugMsgs.notification().println("this should not print");
  DebugMsgs.status().println("this should not print");
  DebugMsgs.println("this should not print");
  Serial.println();

  Serial.println("Round 8 - warning, status, not specified");
  DebugMsgs.enableLevel(WARNING);
  DebugMsgs.enableLevel(STATUS);
  DebugMsgs.debug().println("this should not print");
  DebugMsgs.warning().println("this should print");
  DebugMsgs.error().println("this should not print");
  DebugMsgs.notification().println("this should not print");
  DebugMsgs.status().println("this should print");
  DebugMsgs.println("this should print, but without the pre header");
  Serial.println();

  Serial.println("Round 9 - all enabled: debug, warning, error, notification, status, not specified");
  DebugMsgs.enableAll();
  DebugMsgs.debug().println("this should print");
  DebugMsgs.warning().println("this should print");
  DebugMsgs.error().println("this should print");
  DebugMsgs.notification().println("this should print");
  DebugMsgs.status().println("this should print");
  DebugMsgs.println("this should print, but without the pre header");
  Serial.println();

  Serial.println("Round 10");
  DebugMsgs.debug().print("This is ").print("a compound ").println("message line!");
  DebugMsgs.debug().print("This is another compound message line made up of numbers (")
    .print(1).print(", ").print(3.0).print(", ").print(-5).println(')');
  Serial.println();

  Serial.println("Round 11");
  DebugMsgs.debug().print("This is ").print("a compound ").print("message line").println(" with flush call!").flush();
  DebugMsgs.debug().println("Single line, then flush");
  DebugMsgs.flush();
  Serial.println();

  Serial.println("Round 12");
  DebugMsgs.enableAll();
  DebugMsgs.debug(1 == 1).println("this should print");
  DebugMsgs.debug(1 == 0).println("this should not print");
  DebugMsgs.warning(1 == 1).println("this should print");
  DebugMsgs.warning(1 == 0).println("this should not print");
  DebugMsgs.error(1 == 1).println("this should print");
  DebugMsgs.error(1 == 0).println("this should not print");
  DebugMsgs.notification(1 == 1).println("this should print");
  DebugMsgs.notification(1 == 0).println("this should not print");
  DebugMsgs.status(1 == 1).println("this should print");
  DebugMsgs.status(1 == 0).println("this should not print");
  Serial.println();
}

void loop() {
  // nothing to see here, move along.
}
