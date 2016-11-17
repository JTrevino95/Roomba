
/* This is a quick program to monitor the status of the encoders
to measure the 'ticks' per revolution */

int encoderLeft = 2; // left encoder is on anaog pin A0, which will function as a digital pin
int encoderRight = 3; // right encoder is on analog pin A1, which will function as a digital pin
volatile unsigned int count_left = 0; // start the count at 0
volatile unsigned int count_right = 0;
void setup() 
{
// put your setup code here, to run once:
pinMode(encoderLeft,INPUT);
pinMode(encoderRight,INPUT);
Serial.begin(9600);
attachInterrupt(digitalPinToInterrupt(encoderRight),counter_right,RISING); //buzz
attachInterrupt(digitalPinToInterrupt(encoderLeft),counter_left,RISING); // count the amount of ticks in one revolution

}

void loop() 
{
     // put your main code here, to run repeatedly:
    
    // read the state of the encoder pins
    //int encoderLeftStatus = digitalRead(encoderLeft);
    //int encoderRightStatus = digitalRead(encoderRight);
    
    // print to the serial monitor to see what's going on
    //Serial.print("Left: ");Serial.print(encoderLeftStatus); 
    //Serial.print("\t Right: ");Serial.println(encoderRightStatus);

    Serial.print(count_right);
    Serial.print("\t");
    Serial.print(count_left);
    Serial.print("\n");

    delay(20);
    
}

void counter_right()
{
  count_right = count_right + 1;
  //Serial.print("Right: "); legacy, makes the interrupt not work as intended because of time to execute
  //Serial.println(count_right); ''   ''
}

//increments a counter
void counter_left()
{
  count_left = count_left + 1;
  //Serial.print("Left: "); same as counter_right reasons
  //Serial.println(count_left);
  
}




// distance traveled = (circumfrence)*(#revolutions)
//revolutions = (distance)/(circumfrence)
// #ticks = (ticks/revolution) * (#revolutions)
// wheel diameter is 2.3 - 2.5 inches
// circumference is roughly (2.4)pi = 7.536 inches
