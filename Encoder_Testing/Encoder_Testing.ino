
/* This is a quick program to monitor the status of the encoders
to measure the 'ticks' per revolution */

int encoderLeft = 2; // left encoder is on anaog pin A0, which will function as a digital pin
int encoderRight = 3; // right encoder is on analog pin A1, which will function as a digital pin
int count = 0; // start the count at 0
int encoderLeftLast = 0;
int encoderRightLast = 0;
void setup() 
{
// put your setup code here, to run once:
pinMode(encoderLeft,INPUT);
pinMode(encoderRight,INPUT);
Serial.begin(9600);
attachInterrupt(digitalPinToInterrupt(encoderLeft),counter,RISING); // count the amount of ticks in one revolution
}

void loop() 
{
     // put your main code here, to run repeatedly:
    
    // read the state of the encoder pins
    int encoderLeftStatus = digitalRead(encoderLeft);
    int encoderRightStatus = digitalRead(encoderRight);
    
    // print to the serial monitor to see what's going on
    //Serial.print("Left: ");Serial.print(encoderLeftStatus); 
    //Serial.print("\t Right: ");Serial.println(encoderRightStatus);
    
}

//increments a counter
void counter()
{
  count = count + 1;
  Serial.println(count);
}


// distance traveled = (circumfrence)*(#revolutions)
//revolutions = (distance)/(circumfrence)
// #ticks = (ticks/revolution) * (#revolutions)
// wheel diameter is 2.3 - 2.5 inches
// circumfrence is roughly (2.4)pi = 7.536 inches
