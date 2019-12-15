#include <SoftwareSerial.h> // a library that enables connection from software to hardware and vice versa, RX(Receiver) and TX (Transmitter)
SoftwareSerial BLU(0,1);

// Defined the colors according to the way they are connected to the digital pin.
// RGB1
#define redPin 5
#define greenPin 2
#define bluePin 4
// RGB2
#define redPin1 6
#define greenPin1 8
#define bluePin1 9
// RGB3
#define redPin2 10
#define greenPin2 12
#define bluePin2 13

void setup()
{
  Serial.begin(9600);  
  BLU.begin(9600);

  pinMode(redPin, OUTPUT); // RedPin
  pinMode(greenPin, OUTPUT); // GreenPin
  pinMode(bluePin, OUTPUT); // BluePin
  
  pinMode(redPin1, OUTPUT); // RedPin1
  pinMode(greenPin1, OUTPUT);// GreenPin1
  pinMode(bluePin1, OUTPUT); // BluePin1
  
  pinMode(redPin2, OUTPUT); // RedPin2
  pinMode(greenPin2, OUTPUT);// GreenPin2
  pinMode(bluePin2, OUTPUT); // BluePin2
  
  // set the color of the lights when the arduino is connected to electricity before the loop, and a 1 second delay after powered on.
  setColor(185, 0, 0, 157, 0, 0, 170, 0, 0); 
  delay(1000);
  setColor(0, 125, 0, 0, 175, 0, 0, 161, 0);
  delay(1000);
  setColor(0, 0, 155, 0, 0, 185, 0, 0, 155);
  delay(1000);
  setColor(155, 245, 188, 185, 174, 205, 145, 181, 152);
}

void loop()
{
  while (BLU.available() > 0)
  {
    // To get inputs 
    // we pass in a string an return back an integer.
    int redInt = BLU.parseInt(); 
    int greenInt = BLU.parseInt();
    int blueInt = BLU.parseInt();
    int redInt1 = BLU.parseInt();
    int greenInt1 = BLU.parseInt();
    int blueInt1 = BLU.parseInt();
    int redInt2 = BLU.parseInt();
    int greenInt2 = BLU.parseInt();
    int blueInt2 = BLU.parseInt();
    
    // The constrain gets the numbers between the a defined range.
    // R,G,B goes from 0 - 255
    redInt = constrain(redInt, 0, 255); 
    greenInt = constrain(greenInt, 0, 255);
    blueInt = constrain(blueInt, 0, 255);
    redInt1 = constrain(redInt1, 0, 255);
    greenInt1 = constrain(greenInt1, 0, 255);
    blueInt1 = constrain(blueInt1, 0, 255);
    redInt2 = constrain(redInt1, 0, 255);
    greenInt2 = constrain(greenInt1, 0, 255);
    blueInt2 = constrain(blueInt1, 0, 255);
    
    if (BLU.available() > 0) // we check if the bluetooth is available
    {
      setColor(redInt, greenInt, blueInt, redInt1, greenInt1, blueInt1, redInt2, greenInt2, blueInt2);
      BLU.flush(); // Waits for the transmission of outgoing serial data to complete. 
    }
  }
}

void setColor(int red, int green, int blue, int red1, int green1, int blue1, int red2, int green2, int blue2)
{
  // we write an analog value(PWM) to a pin.
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
  analogWrite(redPin1, red1);
  analogWrite(greenPin1, green1);
  analogWrite(bluePin1, blue1);
  analogWrite(redPin2, red2);
  analogWrite(greenPin2, green2);
  analogWrite(bluePin2, blue2);
}
