//
// Licensed under Apache 2.0 license.
// See accompanying LICENSE file for details.
//

#include <Arduino.h>
#include "CascadeDebugger.h"

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
  _msgLevel = _msgLevel | level; 
}

void CascadeDebugger::disableLevel(MsgLevel level) {
  _msgLevel = _msgLevel & ~level; 
}

void CascadeDebugger::toggleLevel(MsgLevel level) {
  if ((_msgLevel & level) == level){
    disableLevel(level);
  } else {
    enableLevel(level);
  }
}

bool CascadeDebugger::isLevelEnabled(MsgLevel level) {
  return (_msgLevel & level) == level;
}
    
CascadePrinter& CascadeDebugger::debug(void) {
  if (!isLevelEnabled(DEBUG)) {
    return *_nullPrinter;
  }
  print(millis()).print(" - ").print("DEBUG - ");
  return *this;
}
    
CascadePrinter& CascadeDebugger::debug(boolean test) {
  if (!test || !isLevelEnabled(DEBUG)) {
    return *_nullPrinter;
  }
  print(millis()).print(" - ").print("DEBUG - ");
  return *this;
}

CascadePrinter& CascadeDebugger::warning(void) {
  if (!isLevelEnabled(WARNING)) {
    return *_nullPrinter;
  }
  print(millis()).print(" - ").print("WARNING - ");
  return *this;
}

CascadePrinter& CascadeDebugger::warning(boolean test) {
  if (!test || !isLevelEnabled(WARNING)) {
    return *_nullPrinter;
  }
  print(millis()).print(" - ").print("WARNING - ");
  return *this;
}

CascadePrinter& CascadeDebugger::error(void) {
  if (!isLevelEnabled(ERROR)) {
    return *_nullPrinter;
  }
  print(millis()).print(" - ").print("ERROR - ");
  return *this;
}

CascadePrinter& CascadeDebugger::error(boolean test) {
  if (!test || !isLevelEnabled(ERROR)) {
    return *_nullPrinter;
  }
  print(millis()).print(" - ").print("ERROR - ");
  return *this;
}

CascadePrinter& CascadeDebugger::notification(void) {
  if (!isLevelEnabled(NOTIFICATION)) {
    return *_nullPrinter;
  }
  print(millis()).print(" - ").print("NOTIFICATION - ");
  return *this;
}

CascadePrinter& CascadeDebugger::notification(boolean test) {
  if (!test || !isLevelEnabled(NOTIFICATION)) {
    return *_nullPrinter;
  }
  print(millis()).print(" - ").print("NOTIFICATION - ");
  return *this;
}

CascadePrinter& CascadeDebugger::status(void) {
  if (!isLevelEnabled(STATUS)) {
    return *_nullPrinter;
  }
  print(millis()).print(" - ").print("STATUS - ");
  return *this;
}

CascadePrinter& CascadeDebugger::status(boolean test) {
  if (!test || !isLevelEnabled(STATUS)) {
    return *_nullPrinter;
  }
  print(millis()).print(" - ").print("STATUS - ");
  return *this;
}

CascadePrinter& CascadeDebugger::print(const __FlashStringHelper *h) {
  if (!isAnyLevelEnabled()) {
    return *_nullPrinter;
  }
  
  return CascadePrinter::print(h);
}

CascadePrinter& CascadeDebugger::print(const String &s) {
  if (!isAnyLevelEnabled()) {
    return *_nullPrinter;
  }
  
  return CascadePrinter::print(s);
}

CascadePrinter& CascadeDebugger::print(const char c[]) {
  if (!isAnyLevelEnabled()) {
    return *_nullPrinter;
  }
  
  return CascadePrinter::print(c);
}

CascadePrinter& CascadeDebugger::print(char c) {
  if (!isAnyLevelEnabled()) {
    return *_nullPrinter;
  }
  
  return CascadePrinter::print(c);
}

CascadePrinter& CascadeDebugger::print(unsigned char n, int base) {
  if (!isAnyLevelEnabled()) {
    return *_nullPrinter;
  }
  
  return CascadePrinter::print(n, base);
}

CascadePrinter& CascadeDebugger::print(int n, int base) {
  if (!isAnyLevelEnabled()) {
    return *_nullPrinter;
  }
  
  return CascadePrinter::print(n, base);
}

CascadePrinter& CascadeDebugger::print(unsigned int n, int base) {
  if (!isAnyLevelEnabled()) {
    return *_nullPrinter;
  }
  
  return CascadePrinter::print(n, base);
}

CascadePrinter& CascadeDebugger::print(long n, int base) {
  if (!isAnyLevelEnabled()) {
    return *_nullPrinter;
  }
  
  return CascadePrinter::print(n, base);
}

CascadePrinter& CascadeDebugger::print(unsigned long n, int base) {
  if (!isAnyLevelEnabled()) {
    return *_nullPrinter;
  }
  
  return CascadePrinter::print(n, base);
}

CascadePrinter& CascadeDebugger::print(double d, int places) {
  if (!isAnyLevelEnabled()) {
    return *_nullPrinter;
  }
  
  return CascadePrinter::print(d, places);
}

CascadePrinter& CascadeDebugger::print(const Printable& p) {
  if (!isAnyLevelEnabled()) {
    return *_nullPrinter;
  }
  
  return CascadePrinter::print(p);
}

CascadePrinter& CascadeDebugger::println(const __FlashStringHelper *h) {
  if (!isAnyLevelEnabled()) {
    return *_nullPrinter;
  }
  
  return CascadePrinter::println(h);
}

CascadePrinter& CascadeDebugger::println(const String &s) {
  if (!isAnyLevelEnabled()) {
    return *_nullPrinter;
  }
  
  return CascadePrinter::println(s);
}

CascadePrinter& CascadeDebugger::println(const char c[]) {
  if (!isAnyLevelEnabled()) {
    return *_nullPrinter;
  }
  
  return CascadePrinter::println(c);
}

CascadePrinter& CascadeDebugger::println(char c) {
  if (!isAnyLevelEnabled()) {
    return *_nullPrinter;
  }
  
  return CascadePrinter::println(c);
}
    
CascadePrinter& CascadeDebugger::println(unsigned char n, int base) {
  if (!isAnyLevelEnabled()) {
    return *_nullPrinter;
  }
  
  return CascadePrinter::println(n, base);
}

CascadePrinter& CascadeDebugger::println(int n, int base) {
  if (!isAnyLevelEnabled()) {
    return *_nullPrinter;
  }
  
  return CascadePrinter::println(n, base);
}

CascadePrinter& CascadeDebugger::println(unsigned int n, int base) {
  if (!isAnyLevelEnabled()) {
    return *_nullPrinter;
  }
  
  return CascadePrinter::println(n, base);
}

CascadePrinter& CascadeDebugger::println(long n, int base) {
  if (!isAnyLevelEnabled()) {
    return *_nullPrinter;
  }
  
  return CascadePrinter::println(n, base);
}

CascadePrinter& CascadeDebugger::println(unsigned long n, int base) {
  if (!isAnyLevelEnabled()) {
    return *_nullPrinter;
  }
  
  return CascadePrinter::println(n, base);
}

CascadePrinter& CascadeDebugger::println(double d, int places) {
  if (!isAnyLevelEnabled()) {
    return *_nullPrinter;
  }
  
  return CascadePrinter::println(d, places);
}

CascadePrinter& CascadeDebugger::println(const Printable& p) {
  if (!isAnyLevelEnabled()) {
    return *_nullPrinter;
  }
  
  return CascadePrinter::println(p);
}

CascadePrinter& CascadeDebugger::println(void) {
  if (!isAnyLevelEnabled()) {
    return *_nullPrinter;
  }
  
  return CascadePrinter::println();
}

void CascadeDebugger::flush() {
  if (!isAnyLevelEnabled()) {
    return;
  }
  
  CascadePrinter::flush();
}

CascadeDebugger DebugMsgs;

