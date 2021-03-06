
int encoderLeft = 2; // encoder for left motor
int motorLeftFWD = 12; //if 1 and REV = 0 then go forward
int motorLeftREV = 11; //if 1 and FWD = 0 then go reverse
int motorLeftSpeed = 5; 
volatile unsigned int count_left = 0; 


int encoderRight = 3; // encoder for left motor
int motorRightFWD = 9; //if 1 and REV = 0 then go forward
int motorRightREV = 8; //if 1 and FWD = 0 then go reverse
int motorRightSpeed = 6; 
volatile unsigned int count_right = 0; 

void setup() 
{
  pinMode(encoderLeft,INPUT);
  pinMode(motorLeftFWD,OUTPUT);
  pinMode(motorLeftREV,OUTPUT);
  pinMode(motorLeftSpeed,OUTPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(encoderLeft),counter_left,RISING); //count the amount of ticks in one revolution on Left motor 
 // attachInterrupt(digitalPinToInterrupt(encoderRight),counter_right,RISING); //count the amount of ticks in one revolution on Right motor
 }

void loop() {
  
 //Serial.println(count_left); // print the amount of ticks

  

    if ((count_left/3600)%(2) == 0)
    {
        //go forward
        analogWrite(motorLeftSpeed,255);// set speed
        digitalWrite(motorLeftFWD,HIGH);
        digitalWrite(motorLeftREV, LOW);
        
       //go forward
        analogWrite(motorRightSpeed,255);// set speed
        digitalWrite(motorRightFWD,HIGH);
        digitalWrite(motorRightREV, LOW);
     
    } 
    else
    {
      digitalWrite(motorLeftFWD,LOW);
      digitalWrite(motorLeftREV,HIGH);

      digitalWrite(motorRightFWD,LOW);
      digitalWrite(motorRightREV,HIGH);
    }
 
  //delay(2000);

  
}

void counter_left()
{
  count_left = count_left + 1;
}

void counter_right()
{
  count_right = count_right + 1;
}

