#include <SPI.h>
#include <SD.h>

File myFile;

int trigPin = 6;
int echoPin = 5;

long pingTravelTime;
float distanceToTravel;

int chipSelect = 10;

void setup() 
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  if (!SD.begin(chipSelect)) 
  {
    Serial.println("Initialization failed!");
    while (1);
  }

  Serial.println("Initialization done.");
}

void loop() 
{
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pingTravelTime = pulseIn(echoPin, HIGH);

  distanceToTravel = (pingTravelTime * 0.0133) / 2;
  Serial.print(distanceToTravel);
  Serial.println(" inches");

  if (distanceToTravel < 10)
  {
    unsigned long entryTime = millis();
    while (true)
    {
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      pingTravelTime = pulseIn(echoPin, HIGH);
      distanceToTravel = (pingTravelTime * 0.0133) / 2;
      if (distanceToTravel>10)
        break;
    }
    unsigned long exitTime = millis();
    myFile = SD.open("data.txt", FILE_WRITE);
    if (myFile)
    {
      myFile.print("EntryTime: ");
      myFile.print(entryTime);

      myFile.print(" ExitTime: ");
      myFile.println(exitTime);

      myFile.close(); 
      
    }
    else
    {
      Serial.println("Error opening file");
    }
  }

  delay(200);
}
