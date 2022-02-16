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
 * being sent by the UDPPrintWrapper, here are some commands you can use on
 * linux.
 *
 * 1) Use this command to create a virtual serial port
 *
 *      socat -d -d PTY,raw,echo=0,link=/tmp/ttyVSerial0 \
 *      PTY,raw,echo=0,link=/tmp/ttyVSerial1
 *
 * 2) Use this command to listen to a port for UDP data and then forward the
 *    data to the virtual serial port. Make sure this is the UDP port you are
 *    sending the data to from the Arduino.
 *
 *      socat -v udp4-listen:<THE PORT #> pty,link=/tmp/ttyVSerial0,raw,\
 *      nonblock,waitlock=/tmp/s0.locak,echo=0,b115200,crnl
 *
 * 3) Wait for the first UDP message to be sent. If you try the next step
 *    before the first message is sent, then nothing will be displayed. I
 *    think that this is because the connection defined in step 2 is not
 *    actually created until data is received.
 *
 * 4) Once the first message has been sent, then you can run the following
 *    command to see the messages in realtime.
 
 *      cat < /tmp/ttyVSerial0
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
