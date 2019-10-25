
const int RED_PIN = 5;
const int GREEN_PIN = 4;
const int BLUE_PIN = 0;

int DISPLAY_TIME = 10;  // In milliseconds

void setup()
{
// Here we'll configure the Arduino pins we're using to
// drive the LED to be outputs:

pinMode(RED_PIN, OUTPUT);
pinMode(GREEN_PIN, OUTPUT);
pinMode(BLUE_PIN, OUTPUT);
}

void loop()
{


mainColors();
showSpectrum();
}

void mainColors()
{
// Off (all LEDs off):

digitalWrite(RED_PIN, LOW);
digitalWrite(GREEN_PIN, LOW);
digitalWrite(BLUE_PIN, LOW);

delay(1000);

// Red (turn just the red LED on):

digitalWrite(RED_PIN, HIGH);
digitalWrite(GREEN_PIN, LOW);
digitalWrite(BLUE_PIN, LOW);

delay(1000);

// Green (turn just the green LED on):

digitalWrite(RED_PIN, LOW);
digitalWrite(GREEN_PIN, HIGH);
digitalWrite(BLUE_PIN, LOW);

delay(1000);

// Blue (turn just the blue LED on):

digitalWrite(RED_PIN, LOW);
digitalWrite(GREEN_PIN, LOW);
digitalWrite(BLUE_PIN, HIGH);

delay(1000);

// Yellow (turn red and green on):

digitalWrite(RED_PIN, HIGH);
digitalWrite(GREEN_PIN, HIGH);
digitalWrite(BLUE_PIN, LOW);

delay(1000);

// Cyan (turn green and blue on):

digitalWrite(RED_PIN, LOW);
digitalWrite(GREEN_PIN, HIGH);
digitalWrite(BLUE_PIN, HIGH);

delay(1000);

// Purple (turn red and blue on):

digitalWrite(RED_PIN, HIGH);
digitalWrite(GREEN_PIN, LOW);
digitalWrite(BLUE_PIN, HIGH);

delay(1000);

// White (turn all the LEDs on):

digitalWrite(RED_PIN, HIGH);
digitalWrite(GREEN_PIN, HIGH);
digitalWrite(BLUE_PIN, HIGH);

delay(1000);
}

void showSpectrum()
{
int x;  // define an integer variable called "x"


for (x = 0; x < 768; x++)

// Each time we loop (with a new value of x), do the following:

{
showRGB(x);  // Call RGBspectrum() with our new x
delay(DISPLAY_TIME);   // Delay for 10 ms (1/100th of a second)
}
}

void showRGB(int color)
{
int redIntensity;
int greenIntensity;
int blueIntensity;

if (color <= 255)          // zone 1
{
redIntensity = 255 - color;    // red goes from on to off
greenIntensity = color;        // green goes from off to on
blueIntensity = 0;             // blue is always off
}
else if (color <= 511)     // zone 2
{
redIntensity = 0;                     // red is always off
greenIntensity = 255 - (color - 256); // green on to off
blueIntensity = (color - 256);        // blue off to on
}
else // color >= 512       // zone 3
{
redIntensity = (color - 512);         // red off to on
greenIntensity = 0;                   // green is always off
blueIntensity = 255 - (color - 512);  // blue on to off
}

// Now that the brightness values have been set, command the LED
// to those values

analogWrite(RED_PIN, redIntensity);
analogWrite(BLUE_PIN, blueIntensity);
analogWrite(GREEN_PIN, greenIntensity);
}
