//
// Licensed under Apache 2.0 license.
// See accompanying LICENSE file for details.
//

#include <Arduino.h>
#include "CascadeDebugger.h"
#include "SerialPrintWrapper.h"

CascadeDebugger::CascadeDebugger() : CascadePrinter(new SerialPrintWrapper()) {
  _msgLevel = NONE;
  _nullPrinter = new NullPrinter();
}

CascadeDebugger::CascadeDebugger(PrintWrapper* print) : CascadePrinter(print) {
  _msgLevel = NONE;
  _nullPrinter = new NullPrinter();
}

void CascadeDebugger::disableAll(void) { 
  _msgLevel = NONE; 
}

void CascadeDebugger::enableAll(void) { 
  _msgLevel = ALL; 
}

bool CascadeDebugger::isAnyLevelEnabled(void) {
  return _msgLevel != NONE;
}

void CascadeDebugger::enableLevel(MsgLevel level) { 
  if (level == NONE || level == ALL) {
    _msgLevel = level;
  } else {
   _msgLevel = _msgLevel | level;
  }
}

void CascadeDebugger::disableLevel(MsgLevel level) {
  if (level == ALL) {
    _msgLevel = NONE;
  } else if (level == NONE) {
    _msgLevel = ALL;
  } else {
    _msgLevel = _msgLevel & ~level;
  }
}

void CascadeDebugger::toggleLevel(MsgLevel level) {
  if ((_msgLevel & level) == level){
    disableLevel(level);
  } else {
    enableLevel(level);
  }
}

bool CascadeDebugger::isLevelEnabled(MsgLevel level) {
  if (level == NONE || level == ALL) {
    return (_msgLevel == level);
  } else {
    return (_msgLevel & level) == level;
  }
}

void CascadeDebugger::printLevelStart(const char levelStr[]) {
  print(millis()).print(" ").print(levelStr).print(" - ");
}

CascadePrinter& CascadeDebugger::debug(void) {
  if (!isLevelEnabled(DEBUG)) {
    return *_nullPrinter;
  }
  
  printLevelStart("DEBUG");
  return *this;
}
    
CascadePrinter& CascadeDebugger::debug(boolean test) {
  if (!test || !isLevelEnabled(DEBUG)) {
    return *_nullPrinter;
  }
  
  printLevelStart("DEBUG");
  return *this;
}

CascadePrinter& CascadeDebugger::warning(void) {
  if (!isLevelEnabled(WARNING)) {
    return *_nullPrinter;
  }
  
  printLevelStart("WARNING");
  return *this;
}

CascadePrinter& CascadeDebugger::warning(boolean test) {
  if (!test || !isLevelEnabled(WARNING)) {
    return *_nullPrinter;
  }
  
  printLevelStart("WARNING");
  return *this;
}

CascadePrinter& CascadeDebugger::error(void) {
  if (!isLevelEnabled(ERROR)) {
    return *_nullPrinter;
  }
  
  printLevelStart("ERROR");
  return *this;
}

CascadePrinter& CascadeDebugger::error(boolean test) {
  if (!test || !isLevelEnabled(ERROR)) {
    return *_nullPrinter;
  }
  
  printLevelStart("ERROR");
  return *this;
}

CascadePrinter& CascadeDebugger::notification(void) {
  if (!isLevelEnabled(NOTIFICATION)) {
    return *_nullPrinter;
  }
  
  printLevelStart("NOTIFICATION");
  return *this;
}

CascadePrinter& CascadeDebugger::notification(boolean test) {
  if (!test || !isLevelEnabled(NOTIFICATION)) {
    return *_nullPrinter;
  }
  
  printLevelStart("NOTIFICATION");
  return *this;
}

CascadePrinter& CascadeDebugger::status(void) {
  if (!isLevelEnabled(STATUS)) {
    return *_nullPrinter;
  }
  
  printLevelStart("STATUS");
  return *this;
}

CascadePrinter& CascadeDebugger::status(boolean test) {
  if (!test || !isLevelEnabled(STATUS)) {
    return *_nullPrinter;
  }
  
  printLevelStart("STATUS");
  return *this;
}

