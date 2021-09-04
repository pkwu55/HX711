#include <Arduino.h>
#include <HX711.h>

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 9;
const int LOADCELL_SCK_PIN = 8;
const int GAIN = 128;
const long SCALE = 407.1;
const float LAMBDA = 0.22;
HX711 scale;

void setup() {
  Serial.begin(9600);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN, GAIN);
  scale.set_scale(SCALE);
  scale.set_lambda(LAMBDA);
  scale.tare(20);  
  Serial.print("Scale tared.\n");
  Serial.print(scale.get_offset());
  Serial.println();
}

void loop() {
  // Serial.print(scale.read());
  // Serial.println();
  Serial.print("Reading: ");
  int temp = 100 * scale.get_units(10);
  Serial.print(float(temp/10)/10, 1);
  Serial.println();
}