#pragma once

#include <cstdint>
#include "../Sensors/Sensors.h"
#include "../Sensors/SensorTypes.h"

namespace OpenALRF
{
   #define ALLSENSORS 0

   typedef int8_t sensorid_t;

   struct SensorConfig
   {
      sensorid_t ID;
      std::string IPAddress;
   };

   enum sensororigin_t
   {
      sensoriLocal = 0,
      sensoriRemote = 1
   };

   struct SensorBusData3D
   {
      sensororigin_t Origin;
      sensor_t Type;
      sensorid_t ID;
      sensorunit_t UnitUsed;
      Sensor3DData Data;
   };
};
