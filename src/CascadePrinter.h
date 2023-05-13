//
// Licensed under Apache 2.0 license.
// See accompanying LICENSE file for details.
//

#ifndef CASCADEPRINTER_H
#define CASCADEPRINTER_H

#include "PrintWrapper.h"

/**
 * A special PrintWrapper class that will automatically call the open and
 * close methods of a print wrapper if required. If the PrintWrapper
 * requires open and close when printing, CascadePrinter will automatically
 * make the correct calls to those methods when printing. It will call
 * open() on the first print() or println() call, and it will call
 * close() on the first println() call. In this way it prints the content
 * in chunks, typically an entire line.
 **/
class OpenClosePrintWrapper : public PrintWrapper {
  public:
    OpenClosePrintWrapper(PrintWrapper* printWrapper);
    
    PrintWrapper* getPrintWrapper();

    bool requiresOpenAndClose(void);
    int open(void);
    int close(void);
    
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
    
  private:
    PrintWrapper* _printWrapper;
    
    bool isOpen(void);
    void checkIfOpen();
    void autoOpen(void);
    void autoClose(void);
    
    bool _requiresOpenAndClose;
    bool _isOpen;
};

/**
 * CascadePrinter provides the cascading print methods to print messages.
 *
 * It uses instances of the PrintWrapper class to print the content. It
 * uses the OpenClosePrintWrapper to automatically call open and close
 * on the print wrapper if required.
 **/
class CascadePrinter
{
  public:
    CascadePrinter();
    CascadePrinter(PrintWrapper* printWrapper);
    
    /**
     * Sets the PrintWrapper to use when printing messages.
     * Returns the PrintWrapper the new one replaced.
     **/
    PrintWrapper* setPrintWrapper(PrintWrapper* printWrapper);
    
    /**
     * Gets a Print* for the underlying Print obejct that still
     * calls open() and close() if required.
     **/
    Print* getPrint();
    
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
    virtual CascadePrinter& write(uint8_t);
    virtual void flush();
    
    // These methods are in addition to the Print
    // interface methods.
    virtual CascadePrinter& printf(const char* format, ...);
    virtual CascadePrinter& printfln(const char* format, ...);

  protected:
    OpenClosePrintWrapper* _openClosePrintWrapper;
};

// NullPrinter is a class that prints nothing.
class NullPrinter : public CascadePrinter {
  public:
    NullPrinter() : CascadePrinter(new NullPrintWrapper()) { }
};

#endif
