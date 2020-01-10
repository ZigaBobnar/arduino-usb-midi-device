#include <Arduino.h>
#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

#define MIDI_CHANNEL 4

void setup() {
  MIDI.begin(MIDI_CHANNEL);

  Serial.begin(9600);

  pinMode(13, OUTPUT);
  pinMode(3, INPUT_PULLUP);
}

void loop() {
  digitalWrite(13, LOW);

  digitalWrite(13, HIGH);

  Serial.println(digitalRead(3));

  digitalWrite(13, LOW);

  delay(100);
}
