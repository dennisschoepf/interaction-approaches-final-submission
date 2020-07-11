#include <SR04.h>
#include <Servo.h>

static boolean executedHostile = false;
Servo servo;

int rPinLed = 8;
int gPinLed = 9;
int bPinLed = 10;

int ultrasonicTriggerPin = 11;
int ultrasonicEchoPin = 12;
SR04 sr04 = SR04(ultrasonicEchoPin, ultrasonicTriggerPin);
long distance;

int buzzerPin = 2;

void setup() {
  servo.write(90);
  servo.attach(13);
  
  pinMode(rPinLed, OUTPUT);
  pinMode(gPinLed, OUTPUT);
  pinMode(bPinLed, OUTPUT);

  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  distance = sr04.Distance();

  if (distance < 7) {
    if (executedHostile == false) {
      hostileBehavior();
      executedHostile = true;
    }
  }
}

void setRGBColor(int red, int green, int blue) {
  analogWrite(rPinLed, red);
  analogWrite(gPinLed, green);
  analogWrite(bPinLed, blue);
}

void hostileBehavior() {
  servo.write(0);

  for (int i = 0; i < 3; i++) {
    for (int i = 0; i < 255; i++) {
      setRGBColor(i,0,0);
      tone(buzzerPin, i*2 + 440, 50);
      delay(5);
    }

    servo.write(20);
  
    for (int i = 255; i > 0; i--) {
      setRGBColor(i,0,0);
      tone(buzzerPin, i*2 + 440, 50);
      delay(5);
    }

    servo.write(40);
  }
}
