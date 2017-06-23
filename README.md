# mxUnifiedPCF8574
mxUnifiedIO child library for Arduino. Use device specific drivers with PCF8574 I2C I/O expanders using a unified API.

This library (Arduino IDE version 1.6 and higher) is a child library of the mxUnifiedIO library. It provides a unified
API to drive PCF8574 I2C I/O expanders via the dedicated I2C SDA/SCL or (on ESP826) using selected pins. 

By using this library, setting a pin of the shift-register is as easy as calling Arduino's digitalWrite().
The library implements shiftOut() to allow device specific drivers using the expanded pins of the I/O expander
to be used as easy as those on the MCU.

# Features & limitations
- The current version of this library supports ESP8266 and Atmel ATmega328 and ATmega168 MCUs. Other Atmel processors may work as well, but they've not been tested yet. For some MCUs the library will require modification. Please let me know if you've successfully used this library with other MCUs.
- In the current version of this library only OUTPUT mode is supported. digitalWrite() and shiftOut() are used to set the output pins. digitalRead() can be used to query the status of an output pin. The PCF8574 has limited input posibilities which may be supported by future versions of this library.
- Using digitalWrite() to change one expanded pin requires sending a whole byte to the I/O expander using the serial I2C protocol. Therefor the maximum speed that can be achieved is much lower than using direct MCU pins.
- Best speeds can be obtained by by using a fast MCU. The ESP8266 has a higher clock-speed than an ATmega328.
- shiftOUt() can be used as software SPI on expanded pins, where you can choose which pin to use for MOSI and SCK. Please note that shifting one byte out requires 16 changes of the clock pin, so this is much slower than using direct MCU pins. However, the Nokia LCD examples shows that the results can still be quite usable. See https://github.com/maxint-rd/mxUnifiedPCD8544_Nokia_5110_LCD for more info and the specific examples.

# Disclaimer
- All code on this GitHub account, including this library is provided to you on an as-is basis without guarantees and with all liability dismissed. It may be used at your own risk. Unfortunately I have no means to provide support.

