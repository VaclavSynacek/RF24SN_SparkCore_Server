#include "PubSubClient.h"


// Update these with values suitable for your network.
byte ip[] = { 192, 168, 69, 100 };
int LED = D7; // for demo only

void callback(char* topic, byte* payload, unsigned int length) {
  // handle message arrived - we are only subscribing to one topic so assume all are led related

    byte ledOn[] = {0x6F, 0x6E}; // hex for on
    byte ledOff[] = {0x6F, 0x66, 0x66}; // hex for off
    byte ledFlash[] ={0x66, 0x6C, 0x61, 0x73, 0x68}; // hex for flash

    if (!memcmp(ledOn, payload, sizeof(ledOn)))
        digitalWrite(LED, HIGH);

    if (!memcmp(ledOff, payload, sizeof(ledOff)))
        digitalWrite(LED, LOW);

    if (!memcmp(ledFlash, payload, sizeof(ledFlash))) {
        for (int flashLoop=0;flashLoop < 3; flashLoop++) {
            digitalWrite(LED, HIGH);
            delay(250);
            digitalWrite(LED, LOW);
            delay(250);

        }
    }
}


TCPClient tcpClient;
PubSubClient client(ip, 1883, callback, tcpClient);


// Simple MQTT demo to allow the blue led (D7) to be turned on or off. Send message to topic "led" with payload of "on" or "off"

void setup()
{

    pinMode(LED, OUTPUT); // Use for a simple test of the led on or off by subscribing to a topical called led

  if (client.connect("Spark")) { // Anonymous authentication enabled
  //if (client.connect("spark", "userid", "password")) { // uid:pwd based authentication
    client.publish("Spark Status","I'm Alive...");
    client.subscribe("led");
  }
}

void loop()
{
  client.loop();
}