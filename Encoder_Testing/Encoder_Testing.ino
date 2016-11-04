
/* This is a quick program to monitor the status of the encoders
to measure the 'ticks' per revolution */

int encoderLeft = A0; // left encoder is on anaog pin A0, which will function as a digital pin
int encoderRight = A1; // right encoder is on analog pin A1, which will function as a digital pin
int count = 0; // start the count at 0

void setup() 
{
// put your setup code here, to run once:
pinMode(encoderLeft,INPUT);
pinMode(encoderRight,INPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
// read the state of the encoder pins

int encoderLeftStatus = digitalRead(encoderLeft);
int encoderRightStatus = digitalRead(encoderRight);

// print to the serial monitor to see what's going on
Serial.print("Left: ");Serial.print(encoderLeftStatus); 
Serial.print("\t Right: ");Serial.println(encoderRightStatus);

/*Counting the amount of 1s that pass by on encoderLeft
so we can count the amount of ticks in one revolution,
it should be equal for both encoders, but the if statement 
can be changed to count for encoderRight*/
if (encoderLeftStatus == 1)
  {
    counter();
  }
  
//print the amount of ticks
Serial.print("Counter: "); Serial.println(count);

}

//increments a counter
void counter()
{
  count++;
}
// distance traveled = (circumfrence)*(#revolutions)
// #ticks = (ticks/revolution) * (#revolutions)
// wheel diameter is 2.3 - 2.5 inches
// circumfrence is roughly (2.4)pi = 7.536 inches
