//#define _MXUNIFIEDOUTPUT_DEBUG 0
#include <mxUnifiedPCF8574.h>

mxUnifiedPCF8574 unio = mxUnifiedPCF8574();

void setup()
{
  Serial.begin(115200);
  Serial.println(F("mxUnifiedPCF8574 Blink"));

  unio.begin(0x27);     // start using the PCF874 I2C output expander on address 0x27
}

void loop()
{
  Serial.print(F("."));
  unio.digitalWrite(3, HIGH);   // set expanded pin 3 high
  delay(250);
  unio.digitalWrite(3, LOW);   // set expanded pin 3 low
  delay(250);
}

