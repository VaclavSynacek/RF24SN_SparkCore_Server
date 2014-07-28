#include "RF24SN-MQTT-Wrapper.h"

#include "PubSubClient.h"

#include <application.h>

#include <map>

TCPClient tcpClient;
byte ip[] = { 192, 168, 69, 100 };
PubSubClient client(ip, 1883, onMessage, tcpClient);

std::map<uint16_t, float> messageStore; 

void onMessage(char* topic, byte* payload, unsigned int length) 
{

	char payloadBuffer [length + 1];
	memcpy ( payloadBuffer, payload, length );
	payloadBuffer[length] = '\0'; 
    	float value = atof( ((char*)(payloadBuffer)) );

	String topicParse = String(topic);
	int lastSlash = topicParse.lastIndexOf("/");
	int lastButOneSlash = topicParse.substring(0, lastSlash -1).lastIndexOf("/"); 
	String sensorIdString = topicParse.substring( lastSlash + 1, topicParse.length() );
	String nodeIdString = topicParse.substring( lastButOneSlash + 1, lastSlash);

	uint8_t sensorId = sensorIdString.toInt();
	uint8_t nodeId = nodeIdString.toInt();

	uint16_t key = (nodeId * 256) + sensorId;

	messageStore[key] = value;
}

void mqttSetup(void)
{

	if (client.connect("RF24SN on SparkCore")) {
    		client.publish("RF24SN/status","I'm Alive...");
    		client.subscribe("RF24SN/out/+/+");
	}
}

String mqttTopic(int nodeId, int sensorId, bool in)
{
        String topic = "RF24SN/";
        topic = topic + (in?"in":"out") + "/" + nodeId + "/" + sensorId;
        return topic;
}


extern char *dtostrf (double val, signed char width, unsigned char prec, char *sout);

void mqttPublish(int nodeId, int sensorId, float value)
{
	String topic = mqttTopic(nodeId, sensorId, 1==1);
	char valBuf[10];
	dtostrf(value,1,3,valBuf);

	char topicBuf[20];
	topic.toCharArray(topicBuf,20);

	client.publish(topicBuf,valBuf);
}

float mqttRequest(int nodeId, int sensorId)
{
     uint16_t key = (nodeId * 256) + sensorId;
	return messageStore[key];
}


void mqttLoop(void)
{

    client.loop();

}
