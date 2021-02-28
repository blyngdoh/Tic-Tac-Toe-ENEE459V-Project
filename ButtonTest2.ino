/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Button
*/

// constants won't change. They're used here to set pin numbers:
const int leftButton = 1;     // the number of the pushbutton pin
const int rightButton = 2;
const int topButton = 3;     // the number of the pushbutton pin
const int bottomButton = 4;

int ledPin[] =  {5,6,7,8,9};      // the number of the LED pin
int pinNumber = 2; // Will index the ledPin[] array

void setup() {
  // initialize the pushbutton pin as an input:
  pinMode(leftButton, INPUT);
  pinMode(rightButton, INPUT);
  pinMode(topButton, INPUT);
  pinMode(bottomButton, INPUT);

  for(int i = 0; i <= 4; i++) {
    pinMode(ledPin[i], OUTPUT);
  }
}

void loop() {

    digitalWrite(ledPin[pinNumber], HIGH); // Turn on current LED
    
    if(digitalRead(rightButton) == HIGH) {
      //Select LED to the right of the current one
      delay(200); // Delay to since void loop() will keep reading every milisecond or something.
      digitalWrite(ledPin[pinNumber], LOW); //make the current led LOW
      pinNumber++;//go to the next LED
    }

    if(digitalRead(leftButton) == HIGH) {
      //Select LED to the left of the current one
      delay(200); // Delay to since void loop() will keep reading every milisecond or something.
      digitalWrite(ledPin[pinNumber], LOW); //make the current led LOW
      pinNumber--;//go to the next LED
    }

    if(pinNumber > 4) {
      pinNumber = 0;
    }
    if(pinNumber < 0) {
      pinNumber = 4;
    }
 

}
