//
// Licensed under Apache 2.0 license.
// See accompanying LICENSE file for details.
//

#ifndef SERIALPRINTWRAPPER_H
#define SERIALPRINTWRAPPER_H

#include <Arduino.h>

#include "PrintWrapper.h"

/**
 * SerialPrintWrapper is a class that prints everything to 
 * the Serial port.
 *
 **/
class SerialPrintWrapper : public PrintWrapper {
  public:
    SerialPrintWrapper() : PrintWrapper(&Serial) { }
};

#endif // SERIALPRINTWRAPPER_H
