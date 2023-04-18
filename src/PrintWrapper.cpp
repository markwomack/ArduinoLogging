//
// Licensed under Apache 2.0 license.
// See accompanying LICENSE file for details.
//

#include <Arduino.h>

#include "PrintWrapper.h"

PrintWrapper::PrintWrapper(Print* print) {
  _print = print;
}

bool PrintWrapper::requiresOpenAndClose(void) {
  return false;
}

int PrintWrapper::PrintWrapper::open(void) {
  // default implementation does nothing, subclasses should override if needed.
  return 0;
}

int PrintWrapper::PrintWrapper::close(void) {
  // default implementation does nothing, subclasses should override if needed.
  return 0;
}

// These methods mirror the methods found in Print.
// Each one calls the same method found in Print.
size_t PrintWrapper::print(const __FlashStringHelper* h) {
  return _print->print(h);
}

size_t PrintWrapper::print(const String& s) {
  return _print->print(s);
}

size_t PrintWrapper::print(const char c[]) {
  return _print->print(c);
}

size_t PrintWrapper::print(char c) {
  return _print->print(c);
}

size_t PrintWrapper::print(unsigned char n, int base) {
  return _print->print(n, base);
}

size_t PrintWrapper::print(int n, int base) {
  return _print->print(n, base);
}

size_t PrintWrapper::print(unsigned int n, int base) {
  return _print->print(n, base);
}

size_t PrintWrapper::print(long n, int base) {
  return _print->print(n, base);
}

size_t PrintWrapper::print(unsigned long n, int base) {
  return _print->print(n, base);
}

size_t PrintWrapper::print(double d, int places) {
  return _print->print(d, places);
}

size_t PrintWrapper::print(const Printable& p) {
  return _print->print(p);
}

size_t PrintWrapper::println(const __FlashStringHelper *h) {
  return _print->println(h);
}

size_t PrintWrapper::println(const String& s) {
  return _print->println(s);
}

size_t PrintWrapper::println(const char c[]) {
  return _print->println(c);
}

size_t PrintWrapper::println(char c) {
  return _print->println(c);
}

size_t PrintWrapper::println(unsigned char n, int base) {
  return _print->println(n, base);
}

size_t PrintWrapper::println(int n, int base) {
  return _print->println(n, base);
}

size_t PrintWrapper::println(unsigned int n, int base) {
  return _print->println(n, base);
}

size_t PrintWrapper::println(long n, int base) {
  return _print->println(n, base);
}

size_t PrintWrapper::println(unsigned long n, int base) {
  return _print->println(n, base);
}

size_t PrintWrapper::println(double d, int places) {
  return _print->println(d, places);
}

size_t PrintWrapper::println(const Printable& p) {
  return _print->println(p);
}

size_t PrintWrapper::println(void) {
  return _print->println();
}

void PrintWrapper::flush() {
  _print->flush();
}

size_t NullPrintWrapper::print(const __FlashStringHelper *h) {
  // does nothing
  return 0;
}

size_t NullPrintWrapper::print(const String &s) {
  // does nothing
  return 0;
}

size_t NullPrintWrapper::print(const char c[]) {
  // does nothing
  return 0;
}

size_t NullPrintWrapper::print(char c) {
  // does nothing
  return 0;
}

size_t NullPrintWrapper::print(unsigned char n, int base) {
  // does nothing
  return 0;
}

size_t NullPrintWrapper::print(int n, int base) {
  // does nothing
  return 0;
}

size_t NullPrintWrapper::print(unsigned int n, int base) {
  // does nothing
  return 0;
}

size_t NullPrintWrapper::print(long n, int base) {
  // does nothing
  return 0;
}

size_t NullPrintWrapper::print(unsigned long n, int base) {
  // does nothing
  return 0;
}

size_t NullPrintWrapper::print(double d, int places) {
  // does nothing
  return 0;
}

size_t NullPrintWrapper::print(const Printable& p) {
  // does nothing
  return 0;
}

size_t NullPrintWrapper::println(const __FlashStringHelper *h) {
  // does nothing
  return 0;
}

size_t NullPrintWrapper::println(const String &s) {
  // does nothing
  return 0;
}

size_t NullPrintWrapper::println(const char c[]) {
  // does nothing
  return 0;
}

size_t NullPrintWrapper::println(char c) {
  // does nothing
  return 0;
}

size_t NullPrintWrapper::println(unsigned char n, int base) {
  // does nothing
  return 0;
}

size_t NullPrintWrapper::println(int n, int base) {
  // does nothing
  return 0;
}

size_t NullPrintWrapper::println(unsigned int n, int base) {
  // does nothing
  return 0;
}

size_t NullPrintWrapper::println(long n, int base) {
  // does nothing
  return 0;
}

size_t NullPrintWrapper::println(unsigned long n, int base) {
  // does nothing
  return 0;
}

size_t NullPrintWrapper::println(double d, int places) {
  // does nothing
  return 0;
}

size_t NullPrintWrapper::println(const Printable& p) {
  // does nothing
  return 0;
}

size_t NullPrintWrapper::println(void) {
  // does nothing
  return 0;
}

void NullPrintWrapper::flush() {
  // does nothing
}
