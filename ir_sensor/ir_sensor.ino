#include <Wire.h>

//interfacing IR sensor
#include <IRremote.h>

int IRpin = 9;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IRpin);  // start receiver
}

void loop() {
  if (IrReceiver.decode()) {
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    delay(1500);
    IrReceiver.resume();  // receive next value
    
  }
}
