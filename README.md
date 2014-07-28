RF24SN SparkCore Server
=======================


Full implementation of [RF24SN](https://github.com/VaclavSynacek/RF24SN) for the [Spark Core](https://www.spark.io/). It uses the [SparkCore port](https://community.spark.io/t/mqtt-library-and-sample/2111) of [Arduino MQTT library](http://knolleary.net/arduino-client-for-mqtt/) and [SparkCore port](https://community.spark.io/t/nrf24l01-library-ported/2286) of [Arduino RF24 library](https://maniacbug.github.io/RF24/classRF24.html).


For full description of protocol, client server setup or alternative implementations, see [RF24SN](https://github.com/VaclavSynacek/RF24SN)


Installation:
```Shell
cd your/spark/core/directory
git clone https://github.com/VaclavSynacek/RF24SN_SparkCore_Server.git
cd RF24SN_SparkCore_Server
spark compile *.h *.cpp
spark flash <your_core_name> firmware*
```

Alternatively you can copy&paste all source files to [SparkCore web IDE](https://www.spark.io/build)


Usage:
just power up the Spark Core


## Wiring

![Wiring](https://raw.githubusercontent.com/VaclavSynacek/RF24SN_SparkCore_Server/master/RF24SN-SparkCore_bb.png "Wiring")

The SPI wires (yellow) have to go exactly to their counterparts:
* MOSI to MOSI
* MISO to MISO
* SCK to SC(L)K

The VCC (red) has to go to any 3.3V pin.

GRN (black) can go to any ground.

The CE and CSN (cyan) go to A2 and D6 respectively. Different pins may be used, but the code above assumes this wiring.

IRQ is not used in this implementation

