//
// Licensed under Apache 2.0 license.
// See accompanying LICENSE file for details.
//

/**
 * This example demonstrates when the open and close calls will be
 * called by the DebugMsgs implmentation (which is based on CascadePrinter).
 */

#include <Arduino.h>
#include "src/DebugMsgs.h"
#include "src/PrintWrapper.h"

bool printOpenAndCloseCalls = false;

// Just a simple example of a subclass that implements open/close
class PrintWrapperWithOpenClose : public PrintWrapper {
  public:
    PrintWrapperWithOpenClose(Print* print) : PrintWrapper(print) { }

    virtual int open(void) {
      // in the real world this method would be do something required at
      // the start of each message line. but for this example we do nothing
      // except maybe print this on Serial.
      if (printOpenAndCloseCalls) {
        Serial.println("open was called");
      }
      return 0;
    }

    virtual int close(void) {
      // in the real world this method would be do something required at
      // the end of each message line. but for this example we do nothing
      // except maybe print this on Serial.
      if (printOpenAndCloseCalls) {
        Serial.println("close was called");
      }
      return 0;
    }

    virtual bool requiresOpenAndClose(void) {
      // returning true means open and close are required to be called.
      return true;
    }
};

void setup() {
  Serial.begin(9600);

  // Set in a different print wrapper.
  DebugMsgs.setPrintWrapper(new PrintWrapperWithOpenClose(&Serial));

  // Enable debug level
  DebugMsgs.enableLevel(DEBUG);
  
  DebugMsgs.debug().print("Because we used serial ").println("inside the new print wrapper by default,");
  DebugMsgs.debug().print("you aren't going to see ").println("different output.");

  printOpenAndCloseCalls = true;

  DebugMsgs.debug().print("But now").print(" you are going to see").println(" open and close calls");
  // Note this line has two printlns. This will cause more calls to open and close.
  // Not a problem per se, but just calls open/close more often.
  DebugMsgs.debug().print("interspersed").println(" around the").println(" messages");
  DebugMsgs.print("Open and close ").print("are called ").println("even when debug() is not");
  DebugMsgs.debug().print("Basically open is called at the beginning of the first print() or println() call,")
    .println(" and close() is called at the end of every println() call.");
}

void loop() {
  // nothing to see here, move along.
}
