// note: establish a unit to run by (inches, feet...)

#include <AFMotor.h>
AF_DCMotor motorLeft(3);
AF_DCMotor motorRight(4);
int encoderLeft = A0;
int encoderRight = A1;
//int ticksPerRev = ;//insert value here
float wheelCircumfrence; //circumfrence of the wheel
void runForward(float distance, char whichMotor);
int ticksPerRev; 
void setup() {
  // put your setup code here, to run once:
  
Serial.begin(9600);

motorRight.setSpeed(255);
motorLeft.setSpeed(255);
pinMode(encoderLeft, INPUT);
pinMode(encoderRight,INPUT);

}

void loop() 
{ 
runForward(12,"left");
delay(3000);
}

// how far do we want to go and which motor do we want to turn
void runForward(float distance, char whichMotor) 
{
  int count = 0;
  int ticks = round((ticksPerRev)*(distance/wheelCircumfrence));
  
  //this if statement will decide which motor to turn on
  if (whichMotor == "left" or whichMotor == "Left")
    {
      while (count != (ticks + 1))// run the loop until the rotation is complete
      {
       motorLeft.run(FORWARD);
          if (count == ticks)
           {
            motorLeft.run(RELEASE);
           count == 0; //to ensure the count gets reset when the motor is done running
           }
           else 
          count++;
      }  
  if (whichMotor == "right" or whichMotor == "Right")
      {
        while (count != (ticks + 1))// run the loop until the rotation is complete
          {
          motorRight.run(FORWARD);
            if (count == ticks)
             {
            motorRight.run(RELEASE);
             count == 0; //to ensure the count gets reset when the motor is done running
            }
             else 
            count++;
          }
      }

     }
}

