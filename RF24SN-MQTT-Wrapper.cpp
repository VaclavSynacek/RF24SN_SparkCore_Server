#include "RF24SN-MQTT-Wrapper.h"

#include "PubSubClient.h"

#include <application.h>


TCPClient tcpClient;
byte ip[] = { 192, 168, 69, 100 };
PubSubClient client(ip, 1883, onMessage, tcpClient);


void onMessage(char* topic, byte* payload, unsigned int length) 
{
    //if (msg == NULL) { return; }

    float value = 3;
    //const char* pch = ((char *)msg->payload);
    //stringstream(pch) >> value;

    //string topic = "test";msg->topic;

    //messageStore[topic] = value;
	Serial.println("received MQTT");
}

void mqttSetup(void)
{
	if (client.connect("Spark")) {
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
    //string topic = mqttTopic(nodeId, sensorId, true);
 ///	return messageStore[topic];
	return -1;
}


void mqttLoop(void)
{

    client.loop();

}
