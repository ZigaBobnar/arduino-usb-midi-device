#include <Arduino.h>
#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

#define MIDI_CHANNEL 4

const int cols_pins[] = { 30, 40, 42, 44, 46, 48, 50, 52 };
const int cols_count = 8;
const int rows_pins[] = { 10, 11, 12, 13 };
const int rows_count = 4;

void setup() {
  MIDI.begin(MIDI_CHANNEL);

  Serial.begin(9600);

  for (int i = 0; i < cols_count; ++i) {
    pinMode(cols_pins[i], OUTPUT);
  }

  for (int i = 0; i < rows_count; ++i) {
    pinMode(rows_pins[i], INPUT_PULLUP);
  }
}

void loop() {


  delay(100);
}
