//
// Licensed under Apache 2.0 license.
// See accompanying LICENSE file for details.
//

#include <Arduino.h>

#include "FlushingPrintWrapper.h"


FlushingPrintWrapper::FlushingPrintWrapper(PrintWrapper* printWrapper) : PrintWrapper(0) {
  _printWrapper = printWrapper;
}
    
int FlushingPrintWrapper::open(void) {
  // if the underlying printwrapper needs open/close, call open
  if (_printWrapper->requiresOpenAndClose()) {
    return _printWrapper->open();
  } else {
    return 0;
  }
}

int FlushingPrintWrapper::close(void) {

  // flush before closing anything
  flush();
  
  // if the underlying printwrapper needs open/close, call close
  if (_printWrapper->requiresOpenAndClose()) {
    return _printWrapper->close();
  } else {
    return 0;
  }
}

bool FlushingPrintWrapper::requiresOpenAndClose() {
  return true;
}

size_t FlushingPrintWrapper::print(const __FlashStringHelper* h) {
  return _printWrapper->print(h);
}

size_t FlushingPrintWrapper::print(const String& s) {
  return _printWrapper->print(s);
}

size_t FlushingPrintWrapper::print(const char c[]) {
  return _printWrapper->print(c);

}

size_t FlushingPrintWrapper::print(char c) {
  return _printWrapper->print(c);
}

size_t FlushingPrintWrapper::print(unsigned char c, int  i) {
  return _printWrapper->print(c, i);
}

size_t FlushingPrintWrapper::print(int x, int i) {
  return _printWrapper->print(x, i);
}

size_t FlushingPrintWrapper::print(unsigned int x, int i) {
  return _printWrapper->print(x, i);
}

size_t FlushingPrintWrapper::print(long x, int i) {
  return _printWrapper->print(x, i);
}

size_t FlushingPrintWrapper::print(unsigned long x, int i) {
  return _printWrapper->print(x, i);
}

size_t FlushingPrintWrapper::print(double x, int i) {
  return _printWrapper->print(x, i);
}

size_t FlushingPrintWrapper::print(const Printable& p) {
  return _printWrapper->print(p);
}

size_t FlushingPrintWrapper::println(const __FlashStringHelper * h) {
  return _printWrapper->println(h);
}

size_t FlushingPrintWrapper::println(const String &s) {
  return _printWrapper->println(s);
}

size_t FlushingPrintWrapper::println(const char c[] ) {
  return _printWrapper->println(c);
}

size_t FlushingPrintWrapper::println(char c) {
  return _printWrapper->println(c);
}

size_t FlushingPrintWrapper::println(unsigned char c, int i) {
  return _printWrapper->println(c, i);
}

size_t FlushingPrintWrapper::println(int x, int i) {
  return _printWrapper->println(x, i);
}

size_t FlushingPrintWrapper::println(unsigned int x, int i) {
  return _printWrapper->println(x, i);
}

size_t FlushingPrintWrapper::println(long x, int i) {
  return _printWrapper->println(x, i);
}

size_t FlushingPrintWrapper::println(unsigned long x, int i) {
  return _printWrapper->println(x, i);
}

size_t FlushingPrintWrapper::println(double x, int i) {
  return _printWrapper->println(x, i);
}

size_t FlushingPrintWrapper::println(const Printable& p) {
  return _printWrapper->println(p);
}

size_t FlushingPrintWrapper::println(void) {
  return _printWrapper->println();
}
    
size_t FlushingPrintWrapper::write(uint8_t b) {
  return _printWrapper->write(b);
}

void FlushingPrintWrapper::flush() {
  _printWrapper->flush();
}
