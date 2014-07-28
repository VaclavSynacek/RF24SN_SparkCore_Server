#include "RF24SN.h"

#include "RF24SN-Packet.h"
#include "RF24SN-MQTT-Wrapper.h"
#include "RF24SN-RF24-Wrapper.h"

#include <application.h>


void setup(void)
{
	mqttSetup();
	RF24Setup(&processPacket);
}

void processPacket(Packet packet)
{
	
	if (packet.packetType == PUBLISH_PACKET) processPublishPacket(packet);
	else if (packet.packetType == REQUEST_PACKET) processRequestPacket(packet);
	else
	{
		printPacket(packet);
	}	
	
}

void processPublishPacket(Packet packet)
{
	printPacket(packet);
	packet.packetType = PUBACK_PACKET;
	sendPacket(packet);
		
	mqttPublish(packet.nodeId, packet.sensorId, packet.value);
}

void processRequestPacket(Packet packet)
{
	printPacket(packet);
	packet.packetType = RESPONSE_PACKET;
	
	packet.value = mqttRequest(packet.nodeId, packet.sensorId);
	
	sendPacket(packet);
}

void loop(void)
{
	RF24Loop();
	mqttLoop();
}

