#include <AFMotor.h>
AF_DCMotor motorLeft(3, MOTOR12_64KHZ);
AF_DCMotor motorRight(4, MOTOR12_64KHZ);

void setup() {
  // put your setup code here, to run once:
  
Serial.begin(9600);

motorRight.setSpeed(255);
motorLeft.setSpeed(255);

}

void loop() {
  // put your main code here, to run repeatedly:
  
motorLeft.run(FORWARD);
motorRight.run(FORWARD);
/*delay(2000);
motorLeft.run(FORWARD);
motorRight.run(BACKWARD);
delay(1000);*/

}
