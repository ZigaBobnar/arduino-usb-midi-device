#include <Arduino.h>
#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

#define MIDI_CHANNEL 4

void setup() {
  MIDI.begin(MIDI_CHANNEL);
}

void loop() {

}
