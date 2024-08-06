//
// Licensed under Apache 2.0 license.
// See accompanying LICENSE file for details.
//

/**
 * This example demonstrates almost all of the basiclogging methods on
 * the DebugMsgs object.
 */
 
#include <Arduino.h>
#include "src/DebugMsgs.h"
#include "src/CascadePrinter.h"
#include "src/SerialPrintWrapper.h"

void setup() {
  // Serial needs to be initialized prior to messages being printed
  Serial.begin(9600);

  Serial.println("Round 1 - all disabled by default");
  DebugMsgs.debug().println("this should not print");
  DebugMsgs.warning().println("this should not print");
  DebugMsgs.error().println("this should not print");
  DebugMsgs.notification().println("this should not print");
  DebugMsgs.status().println("this should not print");\
  Serial.println();

  Serial.println("Round 2 - debug");
  DebugMsgs.enableLevel(DEBUG);
  DebugMsgs.debug().println("this should print");
  DebugMsgs.warning().println("this should not print");
  DebugMsgs.error().println("this should not print");
  DebugMsgs.notification().println("this should not print");
  DebugMsgs.status().println("this should not print");\
  Serial.println();

  Serial.println("Round 3 - debug, warning");
  DebugMsgs.enableLevel(WARNING);
  DebugMsgs.debug().println("this should print");
  DebugMsgs.warning().println("this should print");
  DebugMsgs.error().println("this should not print");
  DebugMsgs.notification().println("this should not print");
  DebugMsgs.status().println("this should not print");\
  Serial.println();

  Serial.println("Round 4 - debug, warning, error");
  DebugMsgs.enableLevel(ERROR);
  DebugMsgs.debug().println("this should print");
  DebugMsgs.warning().println("this should print");
  DebugMsgs.error().println("this should print");
  DebugMsgs.notification().println("this should not print");
  DebugMsgs.status().println("this should not print");\
  Serial.println();

  Serial.println("Round 5 - debug, warning, error, notification");
  DebugMsgs.enableLevel(NOTIFICATION);
  DebugMsgs.debug().println("this should print");
  DebugMsgs.warning().println("this should print");
  DebugMsgs.error().println("this should print");
  DebugMsgs.notification().println("this should print");
  DebugMsgs.status().println("this should not print");\
  Serial.println();

  Serial.println("Round 6 - debug, warning, error, notification, status");
  DebugMsgs.enableLevel(STATUS);
  DebugMsgs.debug().println("this should print");
  DebugMsgs.warning().println("this should print");
  DebugMsgs.error().println("this should print");
  DebugMsgs.notification().println("this should print");
  DebugMsgs.status().println("this should print");
  Serial.println();

  Serial.println("Round 7 - all disabled");
  DebugMsgs.disableAll();
  DebugMsgs.debug().println("this should not print");
  DebugMsgs.warning().println("this should not print");
  DebugMsgs.error().println("this should not print");
  DebugMsgs.notification().println("this should not print");
  DebugMsgs.status().println("this should not print");
  Serial.println();

  Serial.println("Round 8 - warning, status");
  DebugMsgs.enableLevel(WARNING);
  DebugMsgs.enableLevel(STATUS);
  DebugMsgs.debug().println("this should not print");
  DebugMsgs.warning().println("this should print");
  DebugMsgs.error().println("this should not print");
  DebugMsgs.notification().println("this should not print");
  DebugMsgs.status().println("this should print");
  Serial.println();

  Serial.println("Round 9 - all enabled: debug, warning, error, notification, status");
  DebugMsgs.enableAll();
  DebugMsgs.debug().println("this should print");
  DebugMsgs.warning().println("this should print");
  DebugMsgs.error().println("this should print");
  DebugMsgs.notification().println("this should print");
  DebugMsgs.status().println("this should print");
  Serial.println();

  Serial.println("Round 10 - compound messages");
  DebugMsgs.debug().print("This is ").print("a compound ").println("message line!");
  DebugMsgs.debug().print("This is another compound message line made up of numbers (")
    .print(1).print(", ").print(3.0).print(", ").print(-5).println(')');
  Serial.println();

  Serial.println("Round 11 - using flush()");
  DebugMsgs.debug().print("This is ").print("a compound ").print("message line").println(" with flush call!").flush();
  DebugMsgs.debug().println("Single line, then flush");
  DebugMsgs.flush();
  Serial.println();

  Serial.println("Round 12 - using boolean check with level");
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

  Serial.println("Round 13 - using print, println, printf and printfln directly");
  DebugMsgs.enableAll();
  DebugMsgs.print("this should ").println("print, but without the pre header");
  DebugMsgs.printfln("No preheader, A message with some value: %s, %d, %08X, %.2lf", "A string", 1234, 56999999, 1.23567);
  DebugMsgs.printf("No preheader, A variable %d; ", 1234).printf("Another variable %s; ", "StRiNg").printfln("And another variable %02d;", 5);
  DebugMsgs.disableAll();
  DebugMsgs.print("this should still ").println("print, but without the pre header");
  DebugMsgs.printfln("Will still print, A message with some value: %s, %d, %08X, %.2lf", "A string", 1234, 56999999, 1.23567);
  DebugMsgs.printf("Will still print, A variable %d; ", 1234).printf("Another variable %s; ", "StRiNg").printfln("And another variable %02d;", 5);
  Serial.println();

  Serial.println("Round 14 - using CascadePrinter");
  CascadePrinter cascadePrinter;
  cascadePrinter.println("This won't print");
  PrintWrapper* oldPrintWrapper = cascadePrinter.setPrintWrapper(new SerialPrintWrapper());
  cascadePrinter.println("This will print");
  free(oldPrintWrapper); // free up this unused object
  Serial.println();
}

void loop() {
  // nothing to see here, move along.
}
