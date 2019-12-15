/** Made by David Praise Chukwuma Kalu. 31-January-2018 **/

int transistorPin = 9;    // connected to the base of the transistor
 
 void setup() {
   pinMode(transistorPin, OUTPUT);  // setting the transistor pin as OUTPUT.
 }
 
 void loop() {
   int sensorValueFromPotentiometer = analogRead(A0);   // reading values from the potentiometer.
   int outputValueFromPotentiometer = map(sensorValueForPotentiometer, 0, 1023, 0, 255); // from 0-1023 to 0-255 : converted digitalRead to analogRead.
   analogWrite(transistorPin, outputValueForPotentiometer);// controlling the transistor using analogWrite.
 } 
