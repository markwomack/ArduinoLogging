//
// Licensed under Apache 2.0 license.
// See accompanying LICENSE file for details.
//

#include <Arduino.h>
#include "src/DebugMsgs.h"
#include "src/NullPrintWrapper.h"
#include "src/SerialPrintWrapper.h"

void setup() {
  Serial.begin(9600);

  DebugMsgs.enableLevel(DEBUG);

  DebugMsgs.debug().println("This line will print");

  // Set a null print wrapper that prints nothing
  DebugMsgs.setPrintWrapper(new NullPrintWrapper());

  DebugMsgs.debug().println("This line will not print");

  // Set a serial print wrapper that will print
  PrintWrapper* oldPrintWrapper = DebugMsgs.setPrintWrapper(new SerialPrintWrapper());

  DebugMsgs.debug().println("...and now we are back!");

  // free up space of unused wrapper
  free(oldPrintWrapper);

}

void loop() {
  // nothing to see here, move along
}
