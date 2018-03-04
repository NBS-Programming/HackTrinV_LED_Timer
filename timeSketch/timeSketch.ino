// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
//#ifdef __AVR__
#include <avr/power.h>
#include <TimeLib.h>
 
// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN             6 
#define PIN_2           2
#define PIN_3           4

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS1      24
#define NUMPIXELS2      15
#define NUMPIXELS3      15

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels1 = Adafruit_NeoPixel(NUMPIXELS1, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2 = Adafruit_NeoPixel(NUMPIXELS2, PIN_2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels3 = Adafruit_NeoPixel(NUMPIXELS3, PIN_3, NEO_GRB + NEO_KHZ800);

long delayval = 1000; // delay for half a second

int count = 0;
int mincount;

void setup() {
  Serial.begin(9600);
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  pixels1.begin(); // This initializes the NeoPixel library.
  pixels2.begin();
  pixels3.begin();
}
void loop() {

      for (int i = 0; i < NUMPIXELS3; i++) {

 //   pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      pixels3.setPixelColor(i, pixels3.Color(255, 0, 0)); // Moderately bright green color.
      pixels3.show(); // This sends the updated pixel color to the hardware.
      delay(delayval); // Delay for a period of time (in milliseconds).
      pixels3.setPixelColor(i, pixels3.Color(0,0,0));
      pixels3.show();
      count = count + 1;
            Serial.println(count);

    }

  for (int i = 0; i < NUMPIXELS2; i++) {
      //pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      pixels2.setPixelColor(i, pixels2.Color(255, 0, 0)); // Moderately bright green color.
     pixels2.show(); // This sends the updated pixel color to the hardware.
      delay(delayval); // Delay for a period of time (in milliseconds).
      pixels2.setPixelColor(i, pixels2.Color(0,0,0));
      pixels2.show();
      count = count + 1;
      Serial.println(count);
    
  }


if(count%60 == 0) { 
    Serial.println(mincount);
    pixels1.setPixelColor(mincount, pixels1.Color(0, 0, 255)); // Moderately bright green color.
    pixels1.show(); // This sends the updated pixel color to the hardware.
    mincount++;
}

   }


