//
// Licensed under Apache 2.0 license.
// See accompanying LICENSE file for details.
//

#include <Arduino.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <inttypes.h>
#include <math.h>

#include "CascadePrinter.h"


OpenClosePrintWrapper::OpenClosePrintWrapper(PrintWrapper* printWrapper) : PrintWrapper(0) {
  _printWrapper = printWrapper;
  _isOpen = false;
  _requiresOpenAndClose = _printWrapper->requiresOpenAndClose();
}
    
PrintWrapper* OpenClosePrintWrapper::getPrintWrapper() {
  return _printWrapper;
}

bool OpenClosePrintWrapper::requiresOpenAndClose(void) {
  return _printWrapper->requiresOpenAndClose();
}

int OpenClosePrintWrapper::open(void) {
  if (!_requiresOpenAndClose) {
    return 0;
  }
  
  if (isOpen()) {
    _printWrapper->println();
    _printWrapper->println();
    _printWrapper->println("*****CascadePrinter: open called twice with no close*****");
    _printWrapper->println();
    _printWrapper->println();
  } else {
    _printWrapper->open();
  }
  _isOpen = true;
  
  return 0;
}

bool OpenClosePrintWrapper::isOpen(void) {
  return _isOpen;
}

void OpenClosePrintWrapper::checkIfOpen() {
  if (!_requiresOpenAndClose) {
    return;
  }

  if (!isOpen()) {
    _printWrapper->open();
    _printWrapper->println();
    _printWrapper->println();
    _printWrapper->println("*****CascadePrinter: open not called before printing*****");
    _printWrapper->println();
    _printWrapper->println();
    _printWrapper->close();
  }
  
  return;
}

int OpenClosePrintWrapper::close(void) {
  if (!_requiresOpenAndClose) {
    return 0;
  }

  if (!isOpen()) {
    _printWrapper->open();
    _printWrapper->println();
    _printWrapper->println();
    _printWrapper->println("*****CascadePrinter: close called with no open*****");
    _printWrapper->println();
    _printWrapper->println();
    _printWrapper->close();
  } else {
    _printWrapper->close();
  }
  _isOpen = false;
  
  return 0;
}

void OpenClosePrintWrapper::autoOpen(void) {
  if (!_requiresOpenAndClose) {
    return;
  }

  if (!isOpen()) {
    open();
  }
}

void OpenClosePrintWrapper::autoClose(void) {
  if (!_requiresOpenAndClose) {
    return;
  }

  if (isOpen()) {
    close();
  }
}
    
size_t OpenClosePrintWrapper::print(const __FlashStringHelper *h) {
  autoOpen();
  checkIfOpen();
  return _printWrapper->print(h);
}

size_t OpenClosePrintWrapper::print(const String &s) {
  autoOpen();
  checkIfOpen();
  return _printWrapper->print(s);
}

size_t OpenClosePrintWrapper::print(const char c[]) {
  autoOpen();
  checkIfOpen();
  return _printWrapper->print(c);
}

size_t OpenClosePrintWrapper::print(char c) {
  autoOpen();
  checkIfOpen();
  return _printWrapper->print(c);
}

size_t OpenClosePrintWrapper::print(unsigned char n, int base) {
  autoOpen();
  checkIfOpen();
  return _printWrapper->print(n, base);
}

size_t OpenClosePrintWrapper::print(int n, int base) {
  autoOpen();
  checkIfOpen();
  return _printWrapper->print(n, base);
}

size_t OpenClosePrintWrapper::print(unsigned int n, int base) {
  autoOpen();
  checkIfOpen();
  return _printWrapper->print(n, base);
}

size_t OpenClosePrintWrapper::print(long n, int base) {
  autoOpen();
  checkIfOpen();
  return _printWrapper->print(n, base);
}

size_t OpenClosePrintWrapper::print(unsigned long n, int base) {
  autoOpen();
  checkIfOpen();
  return _printWrapper->print(n, base);
}

size_t OpenClosePrintWrapper::print(double d, int places) {
  autoOpen();
  checkIfOpen();
  return _printWrapper->print(d, places);
}

size_t OpenClosePrintWrapper::print(const Printable& p) {
  autoOpen();
  checkIfOpen();
  return _printWrapper->print(p);
}

size_t OpenClosePrintWrapper::println(const __FlashStringHelper *h) {
  autoOpen();
  checkIfOpen();
  size_t retVal = _printWrapper->println(h);
  autoClose();
  return retVal;
}

size_t OpenClosePrintWrapper::println(const String &s) {
  autoOpen();
  checkIfOpen();
  size_t retVal = _printWrapper->println(s);
  autoClose();
  return retVal;
}

size_t OpenClosePrintWrapper::println(const char c[]) {
  autoOpen();
  checkIfOpen();
  size_t retVal = _printWrapper->println(c);
  autoClose();
  return retVal;
}

size_t OpenClosePrintWrapper::println(char c) {
  autoOpen();
  checkIfOpen();
  size_t retVal = _printWrapper->println(c);
  autoClose();
  return retVal;
}
    
size_t OpenClosePrintWrapper::println(unsigned char n, int base) {
  autoOpen();
  checkIfOpen();
  size_t retVal = _printWrapper->println(n, base);
  autoClose();
  return retVal;
}

size_t OpenClosePrintWrapper::println(int n, int base) {
  autoOpen();
  checkIfOpen();
  size_t retVal = _printWrapper->println(n, base);
  autoClose();
  return retVal;
}

size_t OpenClosePrintWrapper::println(unsigned int n, int base) {
  autoOpen();
  checkIfOpen();
  size_t retVal = _printWrapper->println(n, base);
  autoClose();
  return retVal;
}

size_t OpenClosePrintWrapper::println(long n, int base) {
  autoOpen();
  checkIfOpen();
  size_t retVal = _printWrapper->println(n, base);
  autoClose();
  return retVal;
}

size_t OpenClosePrintWrapper::println(unsigned long n, int base) {
  autoOpen();
  checkIfOpen();
  size_t retVal = _printWrapper->println(n, base);
  autoClose();
  return retVal;
}

size_t OpenClosePrintWrapper::println(double d, int places) {
  autoOpen();
  checkIfOpen();
  size_t retVal = _printWrapper->println(d, places);
  autoClose();
  return retVal;
}

size_t OpenClosePrintWrapper::println(const Printable& p) {
  autoOpen();
  checkIfOpen();
  size_t retVal = _printWrapper->println(p);
  autoClose();
  return retVal;
}

size_t OpenClosePrintWrapper::println(void) {
  autoOpen();
  checkIfOpen();
  size_t retVal = _printWrapper->println();
  autoClose();
  return retVal;
}
    
size_t OpenClosePrintWrapper::write(uint8_t b) {
  autoOpen();
  checkIfOpen();
  return _printWrapper->write(b);
}

void OpenClosePrintWrapper::flush() {
  autoOpen();
  checkIfOpen();
  _printWrapper->flush();
  autoClose();
}
    
CascadePrinter::CascadePrinter() {
  _openClosePrintWrapper = 0;
  setPrintWrapper(new NullPrintWrapper());
}

CascadePrinter::CascadePrinter(PrintWrapper* printWrapper) {
  _openClosePrintWrapper = 0;
  setPrintWrapper(printWrapper);
}

PrintWrapper* CascadePrinter::setPrintWrapper(PrintWrapper* printWrapper) {
  PrintWrapper* oldPrintWrapper = 0;
  if (_openClosePrintWrapper) {
    oldPrintWrapper = _openClosePrintWrapper->getPrintWrapper();
    free(_openClosePrintWrapper);
  }
  _openClosePrintWrapper = new OpenClosePrintWrapper(printWrapper);
  return oldPrintWrapper;
}

Print* CascadePrinter::getPrint() {
  return _openClosePrintWrapper;
}
    
CascadePrinter& CascadePrinter::print(const __FlashStringHelper *h) {
  _openClosePrintWrapper->print(h);
  return *this;
}

CascadePrinter& CascadePrinter::print(const String &s) {
  _openClosePrintWrapper->print(s);
  return *this;
}

CascadePrinter& CascadePrinter::print(const char c[]) {
  _openClosePrintWrapper->print(c);
  return *this;
}

CascadePrinter& CascadePrinter::print(char c) {
  _openClosePrintWrapper->print(c);
  return *this;
}

CascadePrinter& CascadePrinter::print(unsigned char n, int base) {
  _openClosePrintWrapper->print(n, base);
  return *this;
}

CascadePrinter& CascadePrinter::print(int n, int base) {
  _openClosePrintWrapper->print(n, base);
  return *this;
}

CascadePrinter& CascadePrinter::print(unsigned int n, int base) {
  _openClosePrintWrapper->print(n, base);
  return *this;
}

CascadePrinter& CascadePrinter::print(long n, int base) {
  _openClosePrintWrapper->print(n, base);
  return *this;
}

CascadePrinter& CascadePrinter::print(unsigned long n, int base) {
  _openClosePrintWrapper->print(n, base);
  return *this;
}

CascadePrinter& CascadePrinter::print(double d, int places) {
  _openClosePrintWrapper->print(d, places);
  return *this;
}

CascadePrinter& CascadePrinter::print(const Printable& p) {
  _openClosePrintWrapper->print(p);
  return *this;
}

CascadePrinter& CascadePrinter::println(const __FlashStringHelper *h) {
  _openClosePrintWrapper->println(h);
  return *this;
}

CascadePrinter& CascadePrinter::println(const String &s) {
  _openClosePrintWrapper->println(s);
  return *this;
}

CascadePrinter& CascadePrinter::println(const char c[]) {
  _openClosePrintWrapper->println(c);
  return *this;
}

CascadePrinter& CascadePrinter::println(char c) {
  _openClosePrintWrapper->println(c);
  return *this;
}
    
CascadePrinter& CascadePrinter::println(unsigned char n, int base) {
  _openClosePrintWrapper->println(n, base);
  return *this;
}

CascadePrinter& CascadePrinter::println(int n, int base) {
  _openClosePrintWrapper->println(n, base);
  return *this;
}

CascadePrinter& CascadePrinter::println(unsigned int n, int base) {
  _openClosePrintWrapper->println(n, base);
  return *this;
}

CascadePrinter& CascadePrinter::println(long n, int base) {
  _openClosePrintWrapper->println(n, base);
  return *this;
}

CascadePrinter& CascadePrinter::println(unsigned long n, int base) {
  _openClosePrintWrapper->println(n, base);
  return *this;
}

CascadePrinter& CascadePrinter::println(double d, int places) {
  _openClosePrintWrapper->println(d, places);
  return *this;
}

CascadePrinter& CascadePrinter::println(const Printable& p) {
  _openClosePrintWrapper->println(p);
  return *this;
}

CascadePrinter& CascadePrinter::println(void) {
  _openClosePrintWrapper->println();
  return *this;
}

CascadePrinter& CascadePrinter::write(uint8_t b) {
  _openClosePrintWrapper->write(b);
  return *this;
}

void CascadePrinter::flush() {
  _openClosePrintWrapper->flush();
}

CascadePrinter& CascadePrinter::printf(const char* format, ...) {
  char buffer[256];
  va_list args;
  va_start (args, format);
  vsnprintf (buffer, 255, format, args);
  _openClosePrintWrapper->print(buffer);
  va_end (args);
  return *this;
}

CascadePrinter& CascadePrinter::printfln(const char* format, ...) {
  char buffer[256];
  va_list args;
  va_start (args, format);
  vsnprintf (buffer, 255, format, args);
  _openClosePrintWrapper->println(buffer);
  va_end (args);
  return *this;
}
