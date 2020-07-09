#include <Servo.h>

// Initialize variables
Servo servo;

void setup() {
  // Initialize servo
  servo.attach(0);
  servo.write(10);
}
 
// the loop function runs over and over again forever
void loop() {
  servo.write(170);
  delay(2000);
  servo.write(10);
}
