/*

BLINKING A LED

  Turn an LED on for one second, off for one second,
  and repeat forever.

Hardware connections:

  Most Arduinos already have an LED and resistor connected to
  pin 13, so you may not need any additional circuitry.

  But if you'd like to connect a second LED to pin 13, or use
  a different pin, follow these steps:

    Connect the positive side of your LED (longer leg) to Arduino
    digital pin 13 (or another digital pin, don't forget to change
    the code to match).
  
    Connect the negative side of your LED (shorter leg) to a 
    330 Ohm resistor (orange-orange-brown). Connect the other side
    of the resistor to ground.

    pin 13 _____ + LED - _____ 330 Ohm _____ GND
	
    (We always use resistors between the Arduino and and LEDs
    to keep the LEDs from burning out due to too much current.)
*/

const int LED_PIN = 13;	// connected to LED as OUTPUT
const int SECOND = 1000;  // in ms

void
setup() {
	// The Arduino has 13 digital input/output pins. These pins
	// can be configured as either inputs or outputs. We set this
	// up with a built-in function called pinMode().

	// The pinMode() function takes two values, which you type in
	// the parenthesis after the function name. The first value is
	// a pin number, the second value is the word INPUT or OUTPUT.

	// Here we'll set up pin 13 (the one connected to a LED) to be
	// an output. We're doing this because we need to send voltage
	// "out" of the Arduino to the LED.
    pinMode(LED_PIN, OUTPUT);
}


void
loop() {
	digitalWrite(LED_PIN, HIGH);
	delay(SECOND);
	digitalWrite(LED_PIN, LOW);
	delay(SECOND);
}

