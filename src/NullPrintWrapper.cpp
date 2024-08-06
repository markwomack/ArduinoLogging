//
// Licensed under Apache 2.0 license.
// See accompanying LICENSE file for details.
//

#include <Arduino.h>

#include "NullPrintWrapper.h"


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
    
size_t NullPrintWrapper::write(uint8_t b) {
  // does nothing
  return 0;
}

void NullPrintWrapper::flush() {
  // does nothing
}
