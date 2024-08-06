//
// Licensed under Apache 2.0 license.
// See accompanying LICENSE file for details.
//

/**
 * This example demonstrates a simple example of switching the logging output
 * from Serial to a file on an SD card and back to serial. No specific code
 * for SD files is required for logging since PrintWrapper supports the generic
 * Print interface implemented by the SD File class.
 */
 
#include <Arduino.h>
#include <SD.h>

#include "src/DebugMsgs.h"
#include "src/PrintWrapper.h"

#define MY_FILE_NAME "myfile.txt"

void setup() {
  // Serial needs to be initialized prior to messages being printed
  Serial.begin(9600);

  DebugMsgs.enableAll();

  // Initialize the SD library
  if (!SD.begin(BUILTIN_SDCARD)) {
    DebugMsgs.error().println("Unable to access SD card");
    return;
  }

  DebugMsgs.debug().println("Opened SD card");

  // Delete any existing file
  if (SD.exists(MY_FILE_NAME)) {
    if (SD.remove(MY_FILE_NAME)) {
      DebugMsgs.debug().printfln("Removed existing file %s", MY_FILE_NAME);
    } else {
      DebugMsgs.debug().printfln("Could not remove existing file %s", MY_FILE_NAME);
    }
  }
  
  File sdFile;
  
  // Open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  sdFile = SD.open(MY_FILE_NAME, FILE_WRITE);

  if (!sdFile) {
    DebugMsgs.error().printfln("Unable to open file %s", MY_FILE_NAME);
  }

  DebugMsgs.debug().printfln("Successfully opened file %s, switching logging output to file", MY_FILE_NAME);

  // Create an PrintWrapper that wraps the file, set it into DebugMsgs
  PrintWrapper* oldPrintWrapper = DebugMsgs.setPrintWrapper(new PrintWrapper(&sdFile));

  // Output logging messages that will get written to the file
  DebugMsgs.debug().println("this should print");
  DebugMsgs.warning().println("this should print");
  DebugMsgs.error().println("this should print");
  DebugMsgs.notification().println("this should print");
  DebugMsgs.status().println("this should print");
  DebugMsgs.debug().print("This is ").print("a compound ").println("message line!");
  DebugMsgs.debug().print("This is another compound message line made up of numbers (")
    .print(1).print(", ").print(3.0).print(", ").print(-5).println(')');
  DebugMsgs.debug().printfln("A message with value %s, %d, %f", "a string", 4321, 3.1456);
  DebugMsgs.print("this should ").println("print, but without the pre header");
  DebugMsgs.printfln("No preheader, A message with some value: %s, %d, %08X, %.2lf", "A string", 1234, 56999999, 1.23567);
  DebugMsgs.printf("No preheader, A variable %d; ", 1234).printf("Another variable %s; ", "StRiNg").printfln("And another variable %02d;", 5);
  DebugMsgs.debug().println("Test complete");
  DebugMsgs.flush();

  // Switch logging back to the original print wrapper (ie Serial).
  DebugMsgs.setPrintWrapper(oldPrintWrapper);

  DebugMsgs.debug().println("Logging to SD card is complete. Closing file.");

  // Close the file.
  sdFile.close();

  DebugMsgs.debug().println("Done");

//  SD.end();
}

void loop() {
  // nothing to see here, move along.
}
