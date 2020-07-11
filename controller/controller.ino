#include <Servo.h>
#include <HCSR04.h>

Servo servo;

int rPinLed = 8;
int gPinLed = 9;
int bPinLed = 10;

int ultrasonicTriggerPin = 11;
int ultrasonicEchoPin = 12;
HCSR04 hc(ultrasonicTriggerPin, ultrasonicEchoPin);

int buzzerPin = 6;

void setup() {
  servo.attach(7);
  
  pinMode(rPinLed, OUTPUT);
  pinMode(gPinLed, OUTPUT);
  pinMode(bPinLed, OUTPUT);

  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);
}
 

void loop() {
  Serial.println( hc.dist() );
  setRGBColor(0, 0, 0);
  // servo.write(10);
  // tone(buzzerPin, 500);
  delay(500);
  // noTone(buzzerPin);
  // servo.write(30);
  setRGBColor(0, 0, 0);
  delay(500);
}

void setRGBColor(int red, int green, int blue) {
  analogWrite(rPinLed, red);
  analogWrite(gPinLed, green);
  analogWrite(bPinLed, blue);
}
