//
// Licensed under Apache 2.0 license.
// See accompanying LICENSE file for details.
//

#ifndef FLUSHINGPRINTWRAPPER_H
#define FLUSHINGPRINTWRAPPER_H

#include "PrintWrapper.h"

/**
 * FlushingPrintWrapper performs exactly like PrintWrapper
 * and it calls the flush() method whenever the close()
 * method is called. This takes advantage of the implementation
 * of the OpenClosePrintWrapper used in CascadePrinter that
 * calls the close method of a PrintWrapper on all println()
 * and printfln() calls.
 **/
class FlushingPrintWrapper : public PrintWrapper {
  public:
    FlushingPrintWrapper(PrintWrapper* printWrapper);
    
    int open(void);
    int close(void);
    bool requiresOpenAndClose();
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
    
  protected:
    // This print wrapper is wrapped by the FlushingPrintWrapper,
    // and will be called for actual functionality.
    PrintWrapper* _printWrapper;
};

#endif // FLUSHINGPRINTWRAPPER_H
