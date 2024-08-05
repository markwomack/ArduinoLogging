# ArduinoLogging
This is a lightweight library for logging debug messages in your Arduino code
and then controlling where the messages go.

## Acknowledgements
This library is a combination of separate code cobbled together that originally
came from Alexander Brevig (CascadeDebugger) and David A. Mellis
(CascadePrinter). But I have heavily modified and extended the code over time,
and I am releasing it as a separate, new library. But credit goes to them for
the original work.

## Contact
If you have any questions or bugs, please 
[open a new issue on github](https://github.com/markwomack/ArduinoLogging/issues).

## Overview
Like almost all developers, there comes a time where you just need to insert
debug messages that get printed out during the execution of the code. This is
especially true with Arduino code. Most of the time Serial is used directly to
print. But it's no surprise that there are many libraries out there that extend
from Serial and add a little more power. ArduinoLogging is no exception.

ArduinoLogging provides the following features:
- Defaults to printing messages to the Serial port at program start. But this
can be easily changed to print messages to other destinations, such as auxilary
serial ports or even UDP.
- Allows for "cascading" print calls to make print calls more compact.
- Supports "message levels" to be associated with print calls, and messages
will only be printed if the associated level is enabled.
- Any object that supports the `Print` interface, which includes all
`Streams`, can be used to print the debug messages. Simply reference it in a
`PrintWrapper` instance and set it for use. This works for simple destinations
like auxilary serial ports whether hardware or software based.
- While any object supporting `Print` can be used, some object types also
require some sort of open and close mechanism before and after printing to
them. This is also supported in `PrintWrapper`, allowing subclasses to
implement open and close methods that are called at the correct time when
printing debug messages. This works for more complex destinations like
a remote UDP port.
- Once a new `PrintWrapper` is applied, all subsequent messages will be
printed using it.
- Though these classes have been written to support debugging, the base
class, `CascadePrinter`, can be used separatly to implement other
situations where one needs to print to different destinations.
- All debug messages can be disabled and not printed by simply disabling
all message level in the `DebugMsgs` object (which is its default state).

## Normal Usage
To use Arduino Logging, simply include the file `DebugMsgs.h`, and then use
the `DebugMsgs` global object to print messages.

    #include <DebugMsgs.h>
    
    void setup() {
      Serial.begin(9600); // Initialization of the Serial port must be performed before usage.
      DebugMsgs.enableLevel(DEBUG);
      DebugMsgs.debug().("Some ").print("message ").print(" to be").println("printed!");
    }
    
    void loop() {
      DebugMsgs.debug().print("The current millis is ").println(millis());
      delay(1000);
    }

## Classes and relationships

### PrintWrapper
[PrinterWrapper](https://github.com/markwomack/ArduinoLogging/blob/main/src/PrintWrapper.h#L29)
is the primary class that performs the printing to the
`Print` reference that it wraps.
- In addition to the print related methods, three other methods are
`open()`, `close()`, and `requiresOpenClose()`. The default
implementations effectively do nothing and only need to be overridden
by subclasses if the `Print` type requires some kind of open and close
when printing to it.
- If a subclass returns true for `requiresOpenClose()` then the `open()`
method will be called with the first of any `print` or `println`
method called. The `close()` method will be called at the end of the
first `println` method called. In this way the messages will be sent to
the destination in chunks decided by the `print` and `println` calls,
typically line by line.
- All initialization of the `Print` reference wrapped by
`PrintWrapper` is expected to be done outside of the class. No
initialization is performed by `PrintWrapper`. For example, the
`SerialPrintWrapper` expects the `Serial` port to be initialized with
a call to the `begin(int baud)` method before messages are printed.
The `UDPPrintWrapper` expects the `UDP` instance to have been
initialized before any messages are printed.
- Examples of `PrintWrapper` subclasses are 
[SerialPrintWrapper](https://github.com/markwomack/ArduinoLogging/blob/main/src/PrintWrapper.h#L94),
[NullPrintWrapper](https://github.com/markwomack/ArduinoLogging/blob/main/src/PrintWrapper.h#L103), and 
[UDPPrintWrapper](https://github.com/markwomack/ArduinoLogging/blob/main/src/UDPPrintWrapper.h#L48).

### CascadeDebugger
[CascadeDebugger](https://github.com/markwomack/ArduinoLogging/blob/main/src/CascadeDebugger.h#L31) 
is the class used for the 
[DebugMsgs](https://github.com/markwomack/ArduinoLogging/blob/main/src/DebugMsgs.h#L9) global.
- It has all the methods related to enabling and disabling the message
levels as well as the message methods, like `debug()`. The message
methods control whether the following `print` and `println` methods will
print their contents. If the associated message level is not enabled,
then nothing will be printed.
- All message printing can be disabled by calling the `disable()` method
(which is the default at program start).
- `SerialPrintWrapper` is the default at program start, and will print
messages to the Serial port. A different `PrintWrapper` subclass can
be set at any point during the program execution. All subsequent
messages will be printed by the new `PrintWrapper` instance.

### CascadePrinter
[CascadePrinter](https://github.com/markwomack/ArduinoLogging/blob/main/src/CascadePrinter.h#L21) 
is the base class for `CascadeDebugger`.
- It has all of the `print` and `println` methods used for printing
the message contents. This set of methods exactly matches the methods
provided by the `Print` interface. These versions return a reference
to the current `CascadePrinter` so that methods can be appended
for cascaded printing.
- In addition it also supports variable insertion and formatting
methods, printf and printfln.
- It has all of the methods for handling the open and close calls
of the `PrintWrapper` class.

## Print methods supported
Four different print methods are supported for output on
`CascadePrinter` and `CascadeDebugger`.

- **print(value)** - This will print the given value to the output.
It does not print a new line. Any subsequent printing will be
started directly at the end of the value previouly printed.

- **println(value)** - This is the same as the print() method,
but it will also print a new line. Any subsequent printing will
begin on the next line.

- **printf(format string, values...)** -  This will print the
given format string with the given values inserted into the
format string. It supports all of the normal data types and data
formatting supported by C/C++. It does not print a new line. Any
subsequent printing will be started directly at the end of the
value previouly printed.

- **printfln(format string, values...)** -  This is the same as
the printf() method, but it will also print a new line. Any
subsequent printing will begin on the next line.

## LOG Macros
While all message output can be disabled by disabling all of the 
message levels, the logging code calls still exist within the
compiled code, and messages with inserted values are still being
evaluated at runtime. All logging related code can be removed
at compile time from any program by utilizing proveded LOG macros
to output logging messages. The macros will expand to appropriate
logging code in normal usage. But with the setting of a single
flag the macros will expand to nothing, and not included in the
compiled code.

- **LOG_ENABLE(MsgLevel)/LOG_DISABLE(MsgLevel)** - Enables or
disables messages printed at a given
[message level](https://github.com/markwomack/ArduinoLogging/blob/71a1ce7992577bd2fb9c20d3fbf3096a022bd0a1/src/CascadeDebugger.h#L15).
The values of ALL and NONE can be used to enable or disable all
message levels.

- **LOG_DEBUG(msg, values...)**</br>
**LOG_WARNING(msg, values...)**</br>
**LOG_ERROR(msg, values...)**</br>
**LOG_NOTIFICATION(msg, values...)**</br>
**LOG_STATUS(message, values...)** - These macros will print
  the given message, with any given values inserted, at the
  appropriate message level. It will print the message and then
  a new line. A subsequent message will appear on the next line.

- **LOG(msg, values...)** - This macro will print the given
message, with any given values inserted, regardless of any
enabled message levels. No timestamp or message level will be
printed at the beginning of the line. It will print the message
and then a new line. A subsequent message will appear on the
next line.

- **INCLUDE_LOGGING** - This is the flag that can be used to
disable and remove all LOG macros. By default it will be set
to "true" and all macros will function. But if it is set to
"false" BEFORE the include for `DebugMsgs.h`, then all LOG macros
will evaluate to nothing, and all logging code will be removed
from the code.

Below is a very simple example:

    // uncomment to remove all logging code
    //#define INCLUDE_LOGGING false
    #include <DebugMsgs.h>
    
    void setup() {
      Serial.begin(9600); // Initialization of the Serial port must be performed before usage.
      LOG_ENABLE(DEBUG);
      LOG_DEBUG("Some message to be logged");
    }
    
    void loop() {
      LOG_DEBUG("The current millis is %d", millis());
      delay(1000);
    }
