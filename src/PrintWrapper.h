//
// Licensed under Apache 2.0 license.
// See accompanying LICENSE file for details.
//

#ifndef PRINTWRAPPER_H
#define PRINTWRAPPER_H

#include <Arduino.h>
#include <Print.h>
#include <inttypes.h>

/**
 * PrintWrapper is the class that calls the matching print and println methods
 * of the Print object it wraps. PrintWrapper is used by the CascadePrint class
 * to print content to the underlying Print instance.
 *
 * Initialization of the Print instance should be completed before it is
 * printed to. For example, Serial.begin() should be called before any print
 * methods are called.
 *
 * The default implementations of open, close, and requiresOpenAndClose methods
 * effectively do nothing since most Print instances do not require any extra
 * code to print to them. But some Print instances, such as UDP, require some
 * sort of open to start printing, and close to end printing. In these cases
 * the methods can be overridden by a subclass to provide for that case.
 *
 **/
class PrintWrapper : public Print
{
  public:
    PrintWrapper(Print* print);
    
    /**
     * Called before performing any print() or println() calls.
     * Default implementation does nothing, subclasses should
     * override with their own version if needed.
     * Returned value of 0 means no error, 1 indicates error.
     **/
    virtual int open(void);
    
    /**
     * Called after performing all print() or println() calls.
     * Default implementation does nothing, subclasses should
     * override with their own version if needed.
     * Returned value of 0 means no error, 1 indicates error.
     **/
    virtual int close(void);

    /**
     * Should return true if the open and close methods
     * are required to bracket the print methods.
     * Default implementation returns false.
     */
    virtual bool requiresOpenAndClose();
    
    // These methods mirror the methods found in Print.
    // Each one calls the same method found in Print.
    virtual size_t print(const __FlashStringHelper *);
    virtual size_t print(const String &);
    virtual size_t print(const char[]);
    virtual size_t print(char);
    virtual size_t print(unsigned char, int = DEC);
    virtual size_t print(int, int = DEC);
    virtual size_t print(unsigned int, int = DEC);
    virtual size_t print(long, int = DEC);
    virtual size_t print(unsigned long, int = DEC);
    virtual size_t print(double, int = 2);
    virtual size_t print(const Printable&);

    virtual size_t println(const __FlashStringHelper *);
    virtual size_t println(const String &s);
    virtual size_t println(const char[]);
    virtual size_t println(char);
    virtual size_t println(unsigned char, int = DEC);
    virtual size_t println(int, int = DEC);
    virtual size_t println(unsigned int, int = DEC);
    virtual size_t println(long, int = DEC);
    virtual size_t println(unsigned long, int = DEC);
    virtual size_t println(double, int = 2);
    virtual size_t println(const Printable&);
    virtual size_t println(void);
    
    virtual size_t write(uint8_t);
    virtual void flush(); 
  
  protected:
    // This is the underlying Print instance that is called
    Print* _print;
};

/**
 * SerialPrintWrapper is a class that prints everything to 
 * the Serial port.
 *
 **/
class SerialPrintWrapper : public PrintWrapper {
  public:
    SerialPrintWrapper() : PrintWrapper(&Serial) { }
};

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

#endif
