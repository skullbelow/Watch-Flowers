/*********
  Rui Santos & Sara Santos - Random Nerd Tutorials
  Complete project details at https://RandomNerdTutorials.com/esp32-servo-motor-web-server-arduino-ide/
  Based on the ESP32Servo Sweep Example
*********/

#include <ESP32Servo.h>

static const int servoPin = 10;
static const int servoSpeed = 20;
static const int servoPause = 2000;
static const int fullyOpenedAngle = 100;

Servo servo1;

void setup() {
  randomSeed(analogRead(0));
  Serial.begin(115200);
  servo1.attach(servoPin);
  // servo1.write(0); //set servo to beginning
}

void loop() {
  normalAnim();
}

void openEye()
{
  for(int posDegrees = 0; posDegrees <= fullyOpenedAngle; posDegrees++) {
    servo1.write(posDegrees);
    // Serial.println(posDegrees);
  }
}

void closeEye()
{
  for(int posDegrees = fullyOpenedAngle; posDegrees >= 0; posDegrees--) {
    servo1.write(posDegrees);
    // Serial.println(posDegrees);
  }
}

void sleep()
{
  closeEye();
  delay(1000* random(10, 61)); //asleep
}

void blink() 
{
  // blink() is only a true single blink if eye is open before blink() is called.
  // otherwise if eye is closed before blink() is called, a double blink is performed.
  openEye();
  delay(125);
  closeEye();
  delay(90);
  openEye();
}

void sleepy() 
{ // Assume eye is open
  for(int posDegrees = fullyOpenedAngle; posDegrees >= fullyOpenedAngle/2; posDegrees--) {
    servo1.write(posDegrees);
    delay(20);
    // Serial.println(posDegrees);
  }
  delay(1000* random(3, 5)); // Only able to stay awake for 3 to 5 seconds
}


void normalAnim()
{
  sleep();
  blink(); // double blink awake from sleep
  delay(1000* random(10, 21));
  int numAwakeBlinks = random(2,5); // How many times we must blink before we are allowed to go to sleep (currently 2-4)
  for(int i = 0; i<numAwakeBlinks; i++){
    blink();
    delay(1000* random(10, 21)); //At least wait 10 seconds before next blink (or going to sleep if last blink), but no longer than 20 seconds
  }

  sleepy();

}
