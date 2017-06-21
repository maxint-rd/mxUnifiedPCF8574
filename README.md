# mxUnifiedPCF8574
mxUnifiedIO child library for Arduino. Use device specific drivers with PCF8574 I2C I/O expanders using a unified API.

This library (Arduino IDE version 1.6 and higher) is a child library of the mxUnifiedIO library. It provides a unified
API to drive PCF8574 I2C I/O expanders via the dedicated I2C SDA/SCL or (on ESP826) using selected pins. 

By using this library, setting a pin of the shift-register is as easy as calling Arduino's digitalWrite().
The library implements shiftOut() to allow device specific drivers using the expanded pins of the I/O expander
to be used as easy as those on the MCU.

The current version of this library supports ESP8266 and Atmel ATmega328 and ATmega168 MCU's.
