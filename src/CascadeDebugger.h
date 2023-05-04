//
// Licensed under Apache 2.0 license.
// See accompanying LICENSE file for details.
//

#ifndef CASCADEDEBUGGER_H
#define CASCADEDEBUGGER_H

#include "CascadePrinter.h"
#include "PrintWrapper.h"

/**
 * The levels used to determine which messages are printed.
 **/
enum MsgLevel {
  NONE         = 0,
  DEBUG        = 1,
  WARNING      = 2,
  ERROR        = 4,
  NOTIFICATION = 8,
  STATUS       = 16,
  ALL          = 31
};

/**
 * CascadeDebugger is the class used to provide methods for
 * printing debugging messages. Messages prefaced with a call to 'message'
 * methods (debug(), warning(), error(), notification(), status()) will
 * only be printed if the associated MsgLevel is enabled.
 **/
class CascadeDebugger : public CascadePrinter {
  public:
    CascadeDebugger();
    CascadeDebugger(PrintWrapper* print);
    
    void disableAll(void);
    void enableAll(void);
    bool isAnyLevelEnabled(void);
    void enableLevel(MsgLevel level);
    void disableLevel(MsgLevel level);
    void toggleLevel(MsgLevel level);
    bool isLevelEnabled(MsgLevel level);
    
    CascadePrinter& debug(void);
    CascadePrinter& debug(bool test);
    CascadePrinter& warning(void);
    CascadePrinter& warning(bool test);
    CascadePrinter& error(void);
    CascadePrinter& error(bool test);
    CascadePrinter& notification(void);
    CascadePrinter& notification(bool test);
    CascadePrinter& status(void);
    CascadePrinter& status(bool test);
    
    // Override of CascadePrinter methods
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
    
  private:
    int _msgLevel;
    CascadePrinter* _nullPrinter;
    
    void printLevelStart(const char levelStr[]);
};

#endif
