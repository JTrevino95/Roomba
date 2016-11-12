
int encoderLeft = 2; // encoder for left motor
int motorLeftFWD = 0; //if 1 and REV = 0 then go forward
int motorLeftREV = 1; //if 1 and FWD = 0 then go reverse
int motorLeftSpeed = 5; 
volatile unsigned int count_left = 0; 

void setup() 
{
  pinMode(encoderLeft,INPUT);
  pinMode(motorLeftFWD,OUTPUT);
  pinMode(motorLeftREV,OUTPUT);
  pinMode(motorLeftSpeed,OUTPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(encoderLeft),counter_left,RISING); //count the amount of ticks in one revolution on left motor 
 }

void loop() {
  
  //Serial.println(count_left); // print the amount of ticks #triggered

    //go forward
    digitalWrite(motorLeftFWD,HIGH); 
    digitalWrite(motorLeftREV, LOW);
    digitalWrite(motorLeftSpeed,HIGH);
   
 
 
 
 
  //delay(5);

  
}

void counter_left()
{
  count_left = count_left + 1;
}

