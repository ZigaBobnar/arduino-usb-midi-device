#include <Arduino.h>
#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

const int midi_channel = 4;
const int midi_velocity = 127;

const int cols_pins[] = { 30, 40, 42, 44, 46, 48, 50, 52 };
const int cols_count = 8;
const int rows_pins[] = { 10, 11, 12, 13 };
const int rows_count = 4;

const int key_to_midi_map[cols_count * rows_count] = {
  // TODO
  0
};

boolean previous_states[cols_count * rows_count] = { 0 };

void setup() {
  MIDI.begin(midi_channel);

  Serial.begin(9600);

  for (int i = 0; i < cols_count; ++i) {
    pinMode(cols_pins[i], OUTPUT);
    digitalWrite(cols_pins[i], LOW);
  }

  for (int i = 0; i < rows_count; ++i) {
    pinMode(rows_pins[i], INPUT_PULLUP);
  }
}

void loop() {
  for (int i = 0; i < cols_count; ++i) {
    digitalWrite(cols_pins[i], HIGH);

    for (int j = 0; j < rows_count; ++j) {
      int readout = digitalRead(rows_pins[j]);
      int map_index = i * cols_count + j;

      if (readout == HIGH) {
        if (previous_states[map_index] == false) {
          send_note_on(key_to_midi_map[map_index]);
        }
      } else {
        if (previous_states[map_index] == true) {
          send_note_off(key_to_midi_map[map_index]);
        }
      }

      previous_states[map_index] = readout == HIGH;
    }

    digitalWrite(cols_pins[i], LOW);
  }

  delay(100);
}

void send_note_on(int pitch) {
  send_midi(0x91, pitch, midi_velocity);
}

void send_note_off(int pitch) {
  send_midi(0x91, pitch, 0);
}

void send_midi(int command, int pitch, int velocity) {
  Serial.write(command);
  Serial.write(pitch);
  Serial.write(velocity);
}