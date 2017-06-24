#include <mxUnifiedPCF8574.h>

mxUnifiedPCF8574 unio = mxUnifiedPCF8574(0x27);     // use the PCF874 I2C output expander on address 0x27
//mxUnifiedPCF8574 unio = mxUnifiedPCF8574(0x27, 2, 0);     // on ESP8266 you can also use software I2C. the ESP-01 has only 4 pins available. If you dont use serial you can use 1 (TX) and 3 (RX)

// Please note that the pins on the PCF8574 are intended to be used for data.
// They cannot deliver much current. When connecting LEDs to the pins, they
// may not light up very brightly.
#define NUMPINS 8

void setup()
{
  Serial.begin(115200);
  Serial.println(F("mxUnifiedPCF8574 Blink8"));

  unio.begin();            // start using the I/O expander
  //unio.begin(100000L);   // Optionally you can specify I2C speed
                           // For ESP default speed is 1MHz for ATmega it's 400KHz

  for(int nPin=0; nPin<NUMPINS; nPin++)
    unio.digitalWrite(nPin, LOW);   // set expanded pin low
}

void loop()
{
  for(int nPin=0; nPin<NUMPINS; nPin++)
  {
    Serial.print(nPin);
    Serial.print(F(" "));
    unio.digitalWrite(nPin, HIGH);   // set expanded pin high
    delay(50);
    unio.digitalWrite(nPin, LOW);   // set expanded pin low
    //delay(100);
  }
  Serial.println(F("."));
  delay(200);
}

