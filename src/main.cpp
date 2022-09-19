#include <Arduino.h>

/*
I, Mychaylo Tatarynov, student number 000800271, certify that all code submitted is my own work; 
that I have not copied it from any other source. 
I also certify that I have not allowed my work to be copied by others.

2022/09/19
*/

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);

  Serial.println("\n\nName: Mychaylo Tatarynov (000800271)");
  Serial.println("ESP8266 Chip Id: " + String(ESP.getChipId()));
  Serial.println("Flash Chip Id: " + String(ESP.getFlashChipId()) + "\n");
}

void loop() {
  int analog = analogRead(A0);
  double temperature = (double)analog / 1024 * 50;
  String judgement;

  if (temperature < 10) {
    judgement = "Cold!";
  } else if (temperature < 15) {
    judgement = "Cool";
  } else if (temperature < 25) {
    judgement = "Perfect";
  } else if (temperature < 30) {
    judgement = "Warm";
  } else if (temperature < 35 ) {
    judgement = "Hot";
  } else {
    judgement = "Too Hot!";
  }
  
  Serial.println("Digitized output of " + String(analog) + " is equivalent to a temperature of " + String(temperature) + " deg. C, which is " + judgement);
  delay(2000);
}