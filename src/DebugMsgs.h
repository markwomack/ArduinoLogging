//
// Licensed under Apache 2.0 license.
// See accompanying LICENSE file for details.
//

#ifndef DEBUGMSGS_H
#define DEBUGMSGS_H

#ifndef INCLUDE_LOGGING
#define INCLUDE_LOGGING true
#endif

#if(INCLUDE_LOGGING == true)

#include "CascadeDebugger.h"

// Use this global variable to print all debugging messages
extern CascadeDebugger DebugMsgs;

#define LOG_ENABLE(...) DebugMsgs.enableLevel(__VA_ARGS__);
#define LOG_DEBUG(...) DebugMsgs.debug().printfln(__VA_ARGS__);
#define LOG_WARNING(...) DebugMsgs.warning().printfln(__VA_ARGS__);
#define LOG_ERROR(...) DebugMsgs.error().printfln(__VA_ARGS__);
#define LOG_NOTIFICATION(...) DebugMsgs.notification().printfln(__VA_ARGS__);
#define LOG_STATUS(...) DebugMsgs.status().printfln(__VA_ARGS__);
#define LOG(...) DebugMsgs.printfln(__VA_ARGS__);

#else

// If logging is not included, then these macros will evaluate to nothing,
// thus removing all logging code from the executable.
#define LOG_ENABLE(...) ;
#define LOG_DEBUG(...) ;
#define LOG_WARNING(...) ;
#define LOG_ERROR(...) ;
#define LOG_NOTIFICATION(...) ;
#define LOG_STATUS(...) ;
#define LOG(...) ;

#endif // (INCLUDE_LOGGING == true)
#endif // DEBUGMSGS_H

