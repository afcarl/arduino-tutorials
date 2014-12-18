/*
RGB LED

  Make an RGB LED display a rainbow of colors!
  
Hardware connections:

  An RGB LED is actually three LEDs (red, green, and blue) in
  one package. When you run them at different brightnesses,
  the red, green and blue mix to form new colors.
  
  Starting at the flattened edge of the flange on the LED,
  the pins are ordered RED, COMMON, GREEN, BLUE.
  
  Connect RED to a 330 Ohm resistor. Connect the other end
  of the resistor to Arduino digital pin 9.

  Connect COMMON pin to GND.

  Connect GREEN to a 330 Ohm resistor. Connect the other end
  of the resistor to Arduino digital pin 10.

  Connect BLUE to a 330 Ohm resistor. Connect the other end
  of the resistor to Arduino digital pin 11.

*/

// digital output pins
const int RED_PIN = 9;
const int GREEN_PIN = 10;
const int BLUE_PIN = 11;

const int SECOND = 1000;  // in ms
int DISPLAY_TIME = 100;  // in ms

void 
setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}


void 
loop() {
  // In this sketch, we'll start writing our own functions.
  // This makes the sketch easier to follow by dividing up
  // the sketch into sections, and not having everything in
  // setup() or loop().

  // We'll show you two ways to run the RGB LED.

  // The first way is to turn the individual LEDs (red, blue,
  // and green) on and off in various combinations. This gives you
  // a total of eight colors (if you count "black" as a color).
	
  // We've written a function called mainColors() that steps
  // through all eight of these colors. We're only "calling" the
  // function here (telling it to run). The actual function code
  // is further down in the sketch.

  mainColors();
  
  // The above function turns the individual LEDs full-on and
  // full-off. If you want to generate more than eight colors,
  // you can do so by varying the brightness of the individual
  // LEDs between full-on and full-off.
  
  // The analogWrite() function lets us do this. This function
  // lets you dim a LED from full-off to full-on over 255 steps.
  
  // We've written a function called showSpectrum() that smoothly
  // steps through all the colors. Again we're just calling it
  // here; the actual code is further down in this sketch.

  showSpectrum();
}


// Here's the mainColors() function we've written.

// This function displays the eight "main" colors that the RGB LED
// can produce. If you'd like to use one of these colors in your 
// own sketch, you cancopy and paste that section into your code.

void 
mainColors() {
    /*
    Displays eight main colors:
      ->  off, red, green, blue, yellow
          cyan, purple, white
    */

    // Off (all LEDs off):
    digitalWrite(RED_PIN, LOW);
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(BLUE_PIN, LOW);
    delay(SECOND);

    // Red (turn just the red LED on):
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(BLUE_PIN, LOW);
    delay(SECOND);

    // Green (turn just the green LED on):
    digitalWrite(RED_PIN, LOW);
    digitalWrite(GREEN_PIN, HIGH);
    digitalWrite(BLUE_PIN, LOW);
    delay(SECOND);

    // Blue (turn just the blue LED on):
    digitalWrite(RED_PIN, LOW);
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(BLUE_PIN, HIGH);
    delay(SECOND);

    // Yellow (turn red and green on):
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(GREEN_PIN, HIGH);
    digitalWrite(BLUE_PIN, LOW);
    delay(SECOND);

    // Cyan (turn green and blue on):
    digitalWrite(RED_PIN, LOW);
    digitalWrite(GREEN_PIN, HIGH);
    digitalWrite(BLUE_PIN, HIGH);
    delay(SECOND);

    // Purple (turn red and blue on):
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(BLUE_PIN, HIGH);
    delay(SECOND);

    // White (turn all the LEDs on):
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(GREEN_PIN, HIGH);
    digitalWrite(BLUE_PIN, HIGH);
    delay(SECOND);
}

void 
showSpectrum() {
    /*
        Cycle continuously through the RGB
        spectrum starting with RED. 
    */
    int spectrum_delay = SECOND / 100; // 10 ms
    for (int x = 0; x < 768; x++) {
        showRGB(x);
        delay(spectrum_delay);
    }
}

// showRGB()

// This function translates a number between 0 and 767 into a
// specific color on the RGB LED. If you have this number count
// through the whole range (0 to 767), the LED will smoothly
// change color through the entire spectrum.

// The "base" numbers are:
// 0   = pure red
// 255 = pure green
// 511 = pure blue
// 767 = pure red (again)

// Numbers between the above colors will create blends. For
// example, 640 is midway between 512 (pure blue) and 767
// (pure red). It will give you a 50/50 mix of blue and red,
// resulting in purple.

// If you count up from 0 to 767 and pass that number to this
// function, the LED will smoothly fade between all the colors.
// (Because it starts and ends on pure red, you can start over
// at 0 without any break in the spectrum).


void 
showRGB(int color) {
    int redIntensity;
    int greenIntensity;
    int blueIntensity;

    if (color <= 255) {
        redIntensity = 255 - color;    // red goes from on to off
        greenIntensity = color;        // green goes from off to on
        blueIntensity = 0;             // blue is always off

    } else if (color <= 511) {
        redIntensity = 0;                     // red is always off
        greenIntensity = 255 - (color - 256); // green on to off
        blueIntensity = (color - 256);        // blue off to on

    } else  {
        redIntensity = (color - 512);         // red off to on
        greenIntensity = 0;                   // green is always off
        blueIntensity = 255 - (color - 512);  // blue on to off
    }

    // set respective LED intensity values
    analogWrite(RED_PIN, redIntensity);
    analogWrite(BLUE_PIN, blueIntensity);
    analogWrite(GREEN_PIN, greenIntensity);
}
