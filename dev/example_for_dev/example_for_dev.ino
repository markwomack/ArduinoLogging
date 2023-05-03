//
// Licensed under Apache 2.0 license.
// See accompanying LICENSE file for details.
//

#include "src/DebugMsgs.h"
#include "src/CascadePrinter.h"
#include "src/PrintWrapper.h"

void setup() {
  Serial.begin(9600);

  DebugMsgs.enableLevel(DEBUG);

  DebugMsgs.debug().println("This line will print");

  // Set a null print wrapper that prints nothing
  DebugMsgs.setPrint(new NullPrintWrapper());

  DebugMsgs.debug().println("This line will not print");

  SerialPrintWrapper serialPrintWrapper;
  
  // Set a serial print wrapper that will print
  DebugMsgs.setPrint(&serialPrintWrapper);

  DebugMsgs.debug().println("...and now we are back!");

  FlushingPrintWrapper flushingPrintWrapper(&serialPrintWrapper);

  DebugMsgs.setPrint(&flushingPrintWrapper);

  DebugMsgs.debug().print("print, ").print("print, ").println(" flush!");

  CascadePrinter cascadePrinter;

  cascadePrinter.println("This won't print");

  PrintWrapper* oldPrintWrapper = cascadePrinter.setPrint(new SerialPrintWrapper());

  cascadePrinter.println("But this will print");

  // free up this unused object
  free(oldPrintWrapper);
}

void loop() {
  // nothing to see here, move along
}
