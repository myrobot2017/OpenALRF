#include "Sensors.h"
#include "../Common/Timing.h"
#include <cstring>

OpenALRF::ISensor::ISensor(OpenALRF::sensorid_t AIdentifier) : IModule()
{
   Identifier = AIdentifier;
   Type = sensorUnknown;
   UsedUnit = unitUnknown;
   memset(&LatestSensorData, 0, sizeof(Sensor3DData));
}

OpenALRF::sensorunit_t OpenALRF::ISensor::GetUsedUnit()
{
   return UsedUnit;
}

OpenALRF::sensor_t OpenALRF::ISensor::GetSensorType()
{
   return Type;
}

std::string OpenALRF::ISensor::GetStatusInfo()
{
   std::string info;

   char val[1024];

   sprintf(val, "<ID>%d</ID>", Identifier);
   info += val;

   sprintf(val, "<Type>%d</Type>", Type);
   info += val;

   sprintf(val, "<UsedUnit>%d</UsedUnit>", UsedUnit);
   info += val;

   if (LatestSensorData.Timestamp != 0)
   {
      info += "<LatestSensorData>";
      info += Sensor3DDataAsXML(LatestSensorData);
      info += "</LatestSensorData>";
   }
   else
   {
      info += "<LatestSensorData />";
   }

   return info;
}

OpenALRF::sensorid_t OpenALRF::ISensor::GetIdentifier()
{
   return Identifier;
}

std::string OpenALRF::Sensor3DDataAsXML(const OpenALRF::Sensor3DData AValue)
{
   std::string xml;

   char data[1024] = "";

   auto timestampstr = GetTimestampAsString(AValue.Timestamp);
   timestampstr = timestampstr.replace(timestampstr.find(' '), 1, "T");

   sprintf(data, "<Timestamp>%s</Timestamp>", timestampstr.c_str());
   xml += data;

   sprintf(data, "<Data1>%f</Data1>", AValue.Data1);
   xml += data;

   sprintf(data, "<Data2>%f</Data2>", AValue.Data2);
   xml += data;

   sprintf(data, "<Data3>%f</Data3>", AValue.Data3);
   xml += data;

   return xml;
}
