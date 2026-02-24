// Constants:
const int rLedPin = 9;
const int gLedPin = 6;
const int bLedPin = 3;

const int rPotPin = A0;
const int gPotPin = A2;
const int bPotPin = A4;

const int potMin = 100;
const int potMax = 1000;

void setup() {
  Serial.begin(9600);

  pinMode(rLedPin, OUTPUT);
  pinMode(gLedPin, OUTPUT);
  pinMode(bLedPin, OUTPUT);
}

void loop() {
  updateRed();
  updateGreen();
  updateBlue();

  delay(200);  // Main loop delay
}

// Reads averaged analog value over a short duration
int readAveragedAnalog(int pin, int durationMs) {
  unsigned long startTime = millis();
  long total = 0;
  int count = 0;

  while (millis() - startTime < durationMs) {
    total += analogRead(pin);
    count++;
    delay(5);  // Small delay between samples
  }

  return total / count;
}

void updateRed() {
  int valueRedPot = readAveragedAnalog(rPotPin, 50);  // Averaging over 50 ms
  int valueRed = map(valueRedPot, potMin, potMax, 0, 255);
  if (valueRedPot <= potMin) valueRed = 0;
  if (valueRedPot >= potMax) valueRed = 255;

  Serial.print("RedPot: ");
  Serial.println(valueRedPot);
  Serial.print("RedLEDVal: ");
  Serial.println(valueRed);
  Serial.println("----------");

  analogWrite(rLedPin, valueRed);
}

void updateGreen() {
  int valueGreenPot = readAveragedAnalog(gPotPin, 50);
  int valueGreen = map(valueGreenPot, potMin, potMax, 0, 255);
  if (valueGreenPot <= potMin) valueGreen = 0;
  if (valueGreenPot >= potMax) valueGreen = 255;

  analogWrite(gLedPin, valueGreen);
}

void updateBlue() {
  int valueBluePot = readAveragedAnalog(bPotPin, 50);
  int valueBlue = map(valueBluePot, potMin, potMax, 0, 255);
  if (valueBluePot <= potMin) valueBlue = 0;
  if (valueBluePot >= potMax) valueBlue = 255;

  analogWrite(bLedPin, valueBlue);
}