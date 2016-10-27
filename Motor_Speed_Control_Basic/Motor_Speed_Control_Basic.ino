/* This alternates the speed on a DC motor */
//adding comment to teach joe
int base = 3;

// the setup function runs once when you press reset or power the board
void setup() {
  
  pinMode(base, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(base, HIGH);   // motor max
  delay(5000);              // wait for 5 seconds
  analogWrite(base, 125);    // motor roughly in the middle range
  delay(5000);              // wait for 5 seconds
  
}
