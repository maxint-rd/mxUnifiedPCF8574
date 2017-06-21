#ifndef _MXUNIFIEDPCF8574_H
#define _MXUNIFIEDPCF8574_H

//#define _MXUNIFIEDIO_DEBUG 1

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include "pins_arduino.h"
#endif
#include "mxUnifiedIO.h"
#include <Wire.h>

class mxUnifiedPCF8574 : public mxUnifiedIO
{
 public:
#if defined(ESP8266)
  mxUnifiedPCF8574(uint8_t uI2C_address, uint8_t nPinSDA = SDA, uint8_t nPinSCL = SCL);
#else
 	mxUnifiedPCF8574(uint8_t uI2C_address); // Constructor
#endif

  // These are be overridden by this subclass to provide device-specific
  // optimized code.  Otherwise 'generic' versions are used.
#if defined(ESP8266)
  void begin(uint32_t i2c_speed=1000000L);
#else
  void begin(uint32_t i2c_speed=400000L);
#endif
  void send8Bits(bool fClosedTransmission=true);
  void sendBits(void);
  void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t value);
  void startTransmission(void);
  void endTransmission(void);
  
 	void digitalWrite(uint8_t nPin, uint8_t nVal);

 private:
 	uint8_t _i2c_address, _i2c_error;
	uint32_t _i2c_speed;
 	uint8_t _i2c_sda;
 	uint8_t _i2c_scl;
};

#endif // _MXUNIFIEDPCF8574_H
