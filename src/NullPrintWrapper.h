//
// Licensed under Apache 2.0 license.
// See accompanying LICENSE file for details.
//

#ifndef NULLPRINTWRAPPER_H
#define NULLPRINTWRAPPER_H

#include "PrintWrapper.h"

/**
 * NullPrintWrapper is a class that prints nothing.
 *
 **/
class NullPrintWrapper : public PrintWrapper {
  public:
    NullPrintWrapper() : PrintWrapper(0) { }
    size_t print(const __FlashStringHelper *);
    size_t print(const String &);
    size_t print(const char[]);
    size_t print(char);
    size_t print(unsigned char, int = DEC);
    size_t print(int, int = DEC);
    size_t print(unsigned int, int = DEC);
    size_t print(long, int = DEC);
    size_t print(unsigned long, int = DEC);
    size_t print(double, int = 2);
    size_t print(const Printable&);
    size_t println(const __FlashStringHelper *);
    size_t println(const String &s);
    size_t println(const char[]);
    size_t println(char);
    size_t println(unsigned char, int = DEC);
    size_t println(int, int = DEC);
    size_t println(unsigned int, int = DEC);
    size_t println(long, int = DEC);
    size_t println(unsigned long, int = DEC);
    size_t println(double, int = 2);
    size_t println(const Printable&);
    size_t println(void);
    
    size_t write(uint8_t);
    void flush();
};

#endif // NULLPRINTWRAPPER_H
