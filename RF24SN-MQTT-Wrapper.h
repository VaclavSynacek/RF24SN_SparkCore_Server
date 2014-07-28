#ifndef RF24SN_MQTT_Wrapper_h
#define RF24SN_MQTT_Wrapper_h

#include <application.h>

void onMessage(char* topic, byte* payload, unsigned int length);
void mqttSetup(void);
void mqttPublish(int nodeId, int sensorId, float value);
float mqttRequest(int nodeId, int sensorId);
String mqttTopic(int nodeId, int sensorId, bool in);
void mqttLoop(void);

#endif
