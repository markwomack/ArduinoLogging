//
// Licensed under Apache 2.0 license.
// See accompanying LICENSE file for details.
//

#ifndef UDPPRINTWRAPPER_H
#define UDPPRINTWRAPPER_H

#include <Udp.h>

#include "PrintWrapper.h"

/**
 * UDPPrintWrapper is a class that prints to a remote UDP port.
 * It also demonstrates the use of the open, close, and requiresOpenAndClose
 * methods.
 *
 * Notes on remote UDP debugging
 * -----------------------------
 *
 * If you don't already have something on the receiving end of the UDP packets
 * being sent by the UDPPrintWrapper, and you are using linux, then you can
 * use netcat from the command line to print the UDP messages:
 *
 *     nc -ulp <PORT# TO LISTEN TO>
 *
 **/
class UDPPrintWrapper : public PrintWrapper {
    
  public:
    UDPPrintWrapper(
      UDP* udp, IPAddress remoteIP, uint16_t remotePort) : PrintWrapper(udp) {
      _udp = udp;
      _remoteIP = remoteIP;
      _remotePort = remotePort;
    }

    virtual int open(void) {
      return _udp->beginPacket(_remoteIP, _remotePort);
    }
    
    virtual int close(void) {
      return _udp->endPacket();
    }
    
    virtual bool requiresOpenAndClose() {
      return true;
    }
  
  private:
    UDP* _udp;
    IPAddress _remoteIP;
    uint16_t _remotePort;
};

#endif
