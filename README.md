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


