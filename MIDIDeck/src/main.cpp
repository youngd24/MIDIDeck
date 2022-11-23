/*
 * Adruino Pro Micro MIDI Prototyper
 *
 * (C) 2022 Darren Young
 * 
 */

// ----------------------------------------------------------------------------
// Program configuration
// ----------------------------------------------------------------------------

// Includes
#include <Arduino.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <midi-parser.h>

#include "MIDIUSB.h"
#include "pitchToNote.h"

// Constants
const int button1Pin = 15;
const int button2Pin = 14;

// states
int button1State;
int button2State;

// First parameter is the event type (0x09 = note on, 0x08 = note off).
// Second parameter is note-on/note-off, combined with the channel.
// Channel can be anything between 0-15. Typically reported to the user as 1-16.
// Third parameter is the note number (48 = middle C).
// Fourth parameter is the velocity (64 = normal, 127 = fastest).
void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}

// First parameter is the event type (0x09 = note on, 0x08 = note off).
// Second parameter is note-on/note-off, combined with the channel.
// Channel can be anything between 0-15. Typically reported to the user as 1-16.
// Third parameter is the note number (48 = middle C).
// Fourth parameter is the velocity (64 = normal, 127 = fastest).
void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}

// First parameter is the event type (0x0B = control change).
// Second parameter is the event type, combined with the channel.
// Third parameter is the control number number (0-119).
// Fourth parameter is the control value (0-127).
void controlChange(byte channel, byte control, byte value) {
  midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
  MidiUSB.sendMIDI(event);
}


// ----------------------------------------------------------------------------
// Setup
// ----------------------------------------------------------------------------
void setup() {

  // Serial port setup
  Serial.begin(115200);
  
  // Input pin setup
  pinMode(button1Pin, INPUT_PULLUP); 
  pinMode(button2Pin, INPUT_PULLUP);
}

// ----------------------------------------------------------------------------
// Main loop
// ----------------------------------------------------------------------------
void loop() {

  // button1 state read
  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);

  if (button1State == LOW) {
    Serial.println("BTN1: PRESSED");
    Serial.println("Sending note on");
    noteOn(0, 48, 64);   // Channel 0, middle C, normal velocity
    MidiUSB.flush();
    delay(500);

    Serial.println("Sending note off");
    noteOff(0, 48, 64);  // Channel 0, middle C, normal velocity
    MidiUSB.flush();
    delay(500);
  }

  if (button2State == LOW) {
    Serial.println("BTN2: PRESSED");
    Serial.println("Sending note on");
    noteOn(0, 50, 64);   // Channel 0, middle C, normal velocity
    MidiUSB.flush();
    delay(500);

    Serial.println("Sending note off");
    noteOff(0, 50, 64);  // Channel 0, middle C, normal velocity
    MidiUSB.flush();
    delay(500);
  }
}


// never get here