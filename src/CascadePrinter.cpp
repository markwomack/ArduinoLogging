//
// Licensed under Apache 2.0 license.
// See accompanying LICENSE file for details.
//

#include <Arduino.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <math.h>

#include "CascadePrinter.h"

CascadePrinter::CascadePrinter() {
  setPrint(new NullPrintWrapper());
}

CascadePrinter::CascadePrinter(PrintWrapper* print) {
  setPrint(print);
}

PrintWrapper* CascadePrinter::setPrint(PrintWrapper* print) {
  PrintWrapper* oldPrint = _print;
  _print = print;
  _isOpen = false;
  _requiresOpenAndClose = _print->requiresOpenAndClose();
  return oldPrint;
}
    
void CascadePrinter::open(void) {
  if (!_requiresOpenAndClose) {
    return;
  }
  
  if (isOpen()) {
    _print->println();
    _print->println();
    _print->println("*****CascadePrinter: open called twice with no close*****");
    _print->println();
    _print->println();
  } else {
    _print->open();
  }
  _isOpen = true;
}

bool CascadePrinter::isOpen(void) {
  return _isOpen;
}

void CascadePrinter::checkIfOpen() {
  if (!_requiresOpenAndClose) {
    return;
  }

  if (!isOpen()) {
    _print->open();
    _print->println();
    _print->println();
    _print->println("*****CascadePrinter: open not called before printing*****");
    _print->println();
    _print->println();
    _print->close();
  }
}

void CascadePrinter::close(void) {
  if (!_requiresOpenAndClose) {
    return;
  }

  if (!isOpen()) {
    _print->open();
    _print->println();
    _print->println();
    _print->println("*****CascadePrinter: close called with no open*****");
    _print->println();
    _print->println();
    _print->close();
  } else {
    _print->close();
  }
  _isOpen = false;
}

void CascadePrinter::autoOpen(void) {
  if (!_requiresOpenAndClose) {
    return;
  }

  if (!isOpen()) {
    open();
  }
}

void CascadePrinter::autoClose(void) {
  if (!_requiresOpenAndClose) {
    return;
  }

  if (isOpen()) {
    close();
  }
}
    
CascadePrinter& CascadePrinter::print(const __FlashStringHelper *h) {
  autoOpen();
  checkIfOpen();
  _print->print(h);
  return *this;
}

CascadePrinter& CascadePrinter::print(const String &s) {
  autoOpen();
  checkIfOpen();
  _print->print(s);
  return *this;
}

CascadePrinter& CascadePrinter::print(const char c[]) {
  autoOpen();
  checkIfOpen();
  _print->print(c);
  return *this;
}

CascadePrinter& CascadePrinter::print(char c) {
  autoOpen();
  checkIfOpen();
  _print->print(c);
  return *this;
}

CascadePrinter& CascadePrinter::print(unsigned char n, int base) {
  autoOpen();
  checkIfOpen();
  _print->print(n, base);
  return *this;
}

CascadePrinter& CascadePrinter::print(int n, int base) {
  autoOpen();
  checkIfOpen();
  _print->print(n, base);
  return *this;
}

CascadePrinter& CascadePrinter::print(unsigned int n, int base) {
  autoOpen();
  checkIfOpen();
  _print->print(n, base);
  return *this;
}

CascadePrinter& CascadePrinter::print(long n, int base) {
  autoOpen();
  checkIfOpen();
  _print->print(n, base);
  return *this;
}

CascadePrinter& CascadePrinter::print(unsigned long n, int base) {
  autoOpen();
  checkIfOpen();
  _print->print(n, base);
  return *this;
}

CascadePrinter& CascadePrinter::print(double d, int places) {
  autoOpen();
  checkIfOpen();
  _print->print(d, places);
  return *this;
}

CascadePrinter& CascadePrinter::print(const Printable& p) {
  autoOpen();
  checkIfOpen();
  _print->print(p);
  return *this;
}

CascadePrinter& CascadePrinter::println(const __FlashStringHelper *h) {
  autoOpen();
  checkIfOpen();
  _print->println(h);
  autoClose();
  return *this;
}

CascadePrinter& CascadePrinter::println(const String &s) {
  autoOpen();
  checkIfOpen();
  _print->println(s);
  autoClose();
  return *this;
}

CascadePrinter& CascadePrinter::println(const char c[]) {
  autoOpen();
  checkIfOpen();
  _print->println(c);
  autoClose();
  return *this;
}

CascadePrinter& CascadePrinter::println(char c) {
  autoOpen();
  checkIfOpen();
  _print->println(c);
  autoClose();
  return *this;
}
    
CascadePrinter& CascadePrinter::println(unsigned char n, int base) {
  autoOpen();
  checkIfOpen();
  _print->println(n, base);
  autoClose();
  return *this;
}

CascadePrinter& CascadePrinter::println(int n, int base) {
  autoOpen();
  checkIfOpen();
  _print->println(n, base);
  autoClose();
  return *this;
}

CascadePrinter& CascadePrinter::println(unsigned int n, int base) {
  autoOpen();
  checkIfOpen();
  _print->println(n, base);
  autoClose();
  return *this;
}

CascadePrinter& CascadePrinter::println(long n, int base) {
  autoOpen();
  checkIfOpen();
  _print->println(n, base);
  autoClose();
  return *this;
}

CascadePrinter& CascadePrinter::println(unsigned long n, int base) {
  autoOpen();
  checkIfOpen();
  _print->println(n, base);
  autoClose();
  return *this;
}

CascadePrinter& CascadePrinter::println(double d, int places) {
  autoOpen();
  checkIfOpen();
  _print->println(d, places);
  autoClose();
  return *this;
}

CascadePrinter& CascadePrinter::println(const Printable& p) {
  autoOpen();
  checkIfOpen();
  _print->println(p);
  autoClose();
  return *this;
}

CascadePrinter& CascadePrinter::println(void) {
  autoOpen();
  checkIfOpen();
  _print->println();
  autoClose();
  return *this;
}

void CascadePrinter::flush() {
  autoOpen();
  checkIfOpen();
  _print->flush();
  autoClose();
}
