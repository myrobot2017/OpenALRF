#pragma once

#include <cstdint>
#include <string>

namespace OpenALRF
{
   typedef int64_t timestamp_t;

   enum status_t { statStopped = 0, statRunning = 1, statWaiting = 2 };

   enum module_t { modVoid = 0, modRemotePilot = 1, modAutoPilot = 2, modCamera = 3, modFancy = 5, modSystem = 9 };
   
   enum action_t {
      actVoid = 0,
      actRemotePilotForward = 11, actRemotePilotBackward = 12, actRemotePilotLeft = 13, actRemotePilotRight = 14, actRemotePilotStop = 15,
      actCameraCapture = 31,
      actFancyBlink1 = 51, actFancyBlink2 = 51,
      actSystemReboot = 91, actSystemRestartNetIF = 92, actSystemInfoReport = 93, actSystemResume = 94, actSystemWait = 95, actSystemStop = 96
   };

   enum order_t {
      ordAny = 0,
      ordStart = 1,
      ordStop = 2
   };

   struct Command
   {
      module_t Module;
      action_t Action;
      int16_t param1;
      int16_t param2;
      std::string param3;
   };

   struct OrderedCommand
   {
      int16_t Order;
      order_t Type;
      Command Cmd;
   };
};
