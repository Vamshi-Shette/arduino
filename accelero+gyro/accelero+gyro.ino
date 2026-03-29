#include <Wire.h>
#include <DFRobot_BMI160.h>

DFRobot_BMI160 bmi160;
int16_t accel[3];
int16_t gyro[3];

void setup() {
  Serial.begin(9600);
  Wire.begin();

  if (bmi160.I2cInit() != BMI160_OK) {
    Serial.println("BMI160 init failed!");
    while(1);
  }

  Serial.println("BMI160 Ready!");
}

void loop() {
  bmi160.getAccelGyroData(accel, gyro);

  Serial.print("Accel: ");
  Serial.print(accel[0]); Serial.print(", ");
  Serial.print(accel[1]); Serial.print(", ");
  Serial.print(accel[2]);

  Serial.print(" | Gyro: ");
  Serial.print(gyro[0]); Serial.print(", ");
  Serial.print(gyro[1]); Serial.print(", ");
  Serial.println(gyro[2]);

  delay(500);
}