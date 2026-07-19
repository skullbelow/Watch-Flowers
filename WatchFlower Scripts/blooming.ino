/*********
  Rui Santos & Sara Santos - Random Nerd Tutorials
  Complete project details at https://RandomNerdTutorials.com/esp32-servo-motor-web-server-arduino-ide/
  Based on the ESP32Servo Sweep Example
*********/

#include <ESP32Servo.h>

static const int servoPin = 10;
static const int servoSpeed = 10;
static const int servoPause = 5000;
static const int fullyOpenedAngle = 85;
static int swing1 = 5;
static int swing2 = 5;

Servo servo1;

void setup() {
  randomSeed(analogRead(0));
  Serial.begin(115200);
  servo1.attach(servoPin);
  // servo1.write(0); //set servo to beginning
}

void loop() {
  swing1 = servoSpeed * random(1,2);
  for(int posDegrees = 0; posDegrees <= fullyOpenedAngle; posDegrees++) {
    servo1.write(posDegrees);
    // Serial.println(swing1);
    delay(random(20,40));
  }
  delay(1000* random(3, 10));

  swing2 = servoSpeed * random(1,2);
  for(int posDegrees = fullyOpenedAngle; posDegrees >= 0; posDegrees--) {
    servo1.write(posDegrees);
    // Serial.println(swing2);
    delay(random(20,40));
  }
  delay(1000* random(3, 10));
}
