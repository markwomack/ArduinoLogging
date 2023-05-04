//
// Licensed under Apache 2.0 license.
// See accompanying LICENSE file for details.
//

#ifndef CASCADEPRINTER_H
#define CASCADEPRINTER_H

#include "PrintWrapper.h"

/**
 * CascadePrinter provides the cascading print methods to print messages.
 *
 * It uses instances of the PrintWrapper class to print the content. If the
 * PrintWrapper requires open and close when printing, CascadePrinter will
 * automatically make the correct calls to those methods when printing. It
 * will call open() on the first print() or println() call, and it will call
 * close() on the first println() call. In this way it prints the content
 * in chunks, typically an entire line.
 **/
class CascadePrinter
{
  public:
    CascadePrinter();
    CascadePrinter(PrintWrapper* print);
    
    /**
     * Sets the PrintWrapper to use when printing messages.
     * Returns the PrintWrapper the new one replaced.
     **/
    PrintWrapper* setPrint(PrintWrapper* print);
    
    // These methods exactly mirror the methods provided by the PrintWrapper
    // class, which in turn mirrors the methods provided by the Print
    // interface.
    virtual CascadePrinter& print(const __FlashStringHelper *);
    virtual CascadePrinter& print(const String &);
    virtual CascadePrinter& print(const char[]);
    virtual CascadePrinter& print(char);
    virtual CascadePrinter& print(unsigned char, int = DEC);
    virtual CascadePrinter& print(int, int = DEC);
    virtual CascadePrinter& print(unsigned int, int = DEC);
    virtual CascadePrinter& print(long, int = DEC);
    virtual CascadePrinter& print(unsigned long, int = DEC);
    virtual CascadePrinter& print(double, int = 2);
    virtual CascadePrinter& print(const Printable&);
    virtual CascadePrinter& println(const __FlashStringHelper *);
    virtual CascadePrinter& println(const String &s);
    virtual CascadePrinter& println(const char[]);
    virtual CascadePrinter& println(char);
    virtual CascadePrinter& println(unsigned char, int = DEC);
    virtual CascadePrinter& println(int, int = DEC);
    virtual CascadePrinter& println(unsigned int, int = DEC);
    virtual CascadePrinter& println(long, int = DEC);
    virtual CascadePrinter& println(unsigned long, int = DEC);
    virtual CascadePrinter& println(double, int = 2);
    virtual CascadePrinter& println(const Printable&);
    virtual CascadePrinter& println(void);
    virtual void flush();
    
    // These methods are in addition to the Print
    // interface methods.
    virtual CascadePrinter& printf(const char* format, ...);
    virtual CascadePrinter& printfln(const char* format, ...);

  protected:
    PrintWrapper* _print;

  private:
    void open(void);
    bool isOpen(void);
    void close(void);
    
    void checkIfOpen();
    void autoOpen(void);
    void autoClose(void);
    
    bool _requiresOpenAndClose;
    bool _isOpen;
};

// NullPrinter is a class that prints nothing.
class NullPrinter : public CascadePrinter {
  public:
    NullPrinter() : CascadePrinter(new NullPrintWrapper()) { }
};

#endif
