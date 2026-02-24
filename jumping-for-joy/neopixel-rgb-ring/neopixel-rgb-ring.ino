#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        12 // Data IN pin

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 12 // NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRBW + NEO_KHZ800);

int potPin = A0;    // The potentiometer is connected to A0
int potPin2 = A1; 
int potPin3 = A2; // blue

void setup() {
  Serial.begin(9600); // sets up serial monitor
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {
  int potVal1 = analogRead(potPin); 
  int brightness1 = map(potVal1, 0, 1023, 0, 200);

  int potVal2 = analogRead(potPin2);   
  int brightness2 = map(potVal2, 0, 1023, 0, 200);

  int potVal3 = analogRead(potPin3);
  int brightness3 = map(potVal3, 75, 910, 0, 200);

  if (potVal3 < 75) { //blue
    brightness3 = 0;
  }

   if (potVal3 > 910) { 
    brightness3 = 200;
  }

   if (potVal2 < 75) { //green
    brightness2 = 0;
  }

   if (potVal2 > 910) {
    brightness2 = 200;
  }
   if (potVal1 < 75) { //red
    brightness1 = 0;
  }

   if (potVal1 > 910) {
    brightness1 = 200;
  }
  uint32_t color = pixels.Color(brightness1, brightness2, brightness3);
  setAllPixels(color);
  pixels.show();   // Send the updated pixel colors to the hardware.

 
  Serial.print(potVal1);
  Serial.print(", ");
  Serial.print(potVal2);
  Serial.print(", ");
  Serial.println(potVal3);
  
  delay(20);
}

void setAllPixels(uint32_t color) {
  for(int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, color); // Set each pixel to the same color
  }
  pixels.show();                    // Send the updated colors to the hardware
}
