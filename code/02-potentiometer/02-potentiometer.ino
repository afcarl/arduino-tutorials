/*

POTENTIOMETER

  Measure the position of a potentiometer and use it to
  control the blink rate of an LED. Turn the knob to make
  it blink faster or slower!

What's a potentiometer?

  A potentiometer, or "pot" for short, is a control knob.
  It's the same type of control you'd use to change volume, 
  dim a lamp, etc. A potentiometer changes resistance as it
  is turned. By using it as a "voltage divider", the Arduino
  can sense the position of the knob, and use that value to
  control whatever you wish (like the blink rate of an LED,
  as we're doing here).

Hardware connections:

  Potentiometer:
	
    Potentiometers have three pins. When we're using it as a
    voltage divider, we connect the outside pins to power and
    ground. The middle pin will be the signal (a voltage which
    varies from 0 Volts to 5 Volts depending on the position of
    the knob).

    Connect the middle pin to ANALOG IN pin 0 on the Arduino.
    Connect one of the outside pins to 5V.
    Connect the other outside pin to GND.

    (TIP: if once your program is running, the knob feels
    "backwards", you can swap the 5V and GND pins to reverse
    the direction.)
		
  LED:

    Most Arduinos already have an LED and resistor connected to
    pin 13, so you may not need any additional circuitry.

    But if you'd like to connect a second LED to pin 13, or use
    a different pin, follow these steps:

      Connect the positive side of your LED (longer leg) to
      Arduino digital pin 13 (or another digital pin, but don't
      forget to change the code to match).
      
      Connect the negative side of your LED (shorter leg) to a
      330 Ohm resistor (orange-orange-brown).
      
      Connect the other side of the resistor to ground.
*/

const int sensorPin = 0;  // analog pin 0
const int ledPin = 13; // The LED is connected to digital pin 13

void 
setup() {
    // configure ledPin as OUTPUT
    pinMode(ledPin, OUTPUT);

    // You might be wondering why we're not also configuring
    // sensorPin as an input. The reason is that this is an
    // "analog in" pin. These pins have the special ability to
    // read varying voltages from sensors like the potentiometer.
    // Since they're always used as inputs, there is no need to
    // specifically configure them.
}


void 
loop() {
    // First we'll declare another integer variable
    // to store the value of the potentiometer:

    int sensorValue;

    // The potentiometer is set up as a voltage divider, so that
    // when you turn it, the voltage on the center pin will vary
    // from 0V to 5V. We've connected the center pin on the
    // potentiometer to the Arduino's analog input 0.

    // The Arduino can read external voltages on the analog input
    // pins using a built-in function called analogRead(). This
    // function takes one input value, the analog pin we're using
    // (sensorPin, which we earlier set to 0). It returns an integer
    // number that ranges from 0 (0 Volts) to 1023 (5 Volts).
    // We're sticking this value into the sensorValue variable:

    // analogRead() gets a 10 bit reading from sensor
    // 0 - 5V in 1024th increments
    sensorValue = analogRead(sensorPin);  

    digitalWrite(ledPin, HIGH);
    delay(sensorValue);
    digitalWrite(ledPin, LOW);
    delay(sensorValue);            
}
