#include <Wire.h>
#include <DFRobot_BMI160.h>

DFRobot_BMI160 bmi160;

int16_t data[6];  // accel + gyro

void setup() {
  Serial.begin(9600);
  Wire.begin();

  if (bmi160.I2cInit(0x69) != BMI160_OK) {
    Serial.println("BMI160 init failed!");
    while (1);
  }

  Serial.println("BMI160 Ready!");
}

void loop() {
  bmi160.getAccelGyroData(data);

  // Accelerometer values
  Serial.print("Accel X: ");
  Serial.print(data[0]);

  Serial.print(" | Y: ");
  Serial.print(data[1]);

  Serial.print(" | Z: ");
  Serial.print(data[2]);

  Serial.println();

  delay(500);
}