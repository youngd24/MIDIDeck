/*
 * Adruino Pro Micro MIDI Prototyper
 *
 * (C) 2022 Darren Young
 * 
 */

// ----------------------------------------------------------------------------
// Program configuration
// ----------------------------------------------------------------------------

// System includes
#include <Arduino.h>

// Local/internal includes
#include "MIDIUSB.h"
#include "pitchToNote.h"

// Button Arduino pin assignments, based on what you did on the hardware
// On the prototype board these are laid out as:
//   row[0] = 1,2,3,4
//   row[1] = 5,6,7,8
const int button1pin = 6;
const int button2pin = 7;
const int button3pin = 9;
const int button4pin = 8;
const int button5pin = 10;
const int button6pin = 16;
const int button7pin = 14;
const int button8pin = 15;

// Button state tracking
int button1state;
int button2state;
int button3state;
int button4state;
int button5state;
int button6state;
int button7state;
int button8state;


// ----------------------------------------------------------------------------
// Functions
// ----------------------------------------------------------------------------

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
  pinMode(button1pin, INPUT_PULLUP); 
  pinMode(button2pin, INPUT_PULLUP);
  pinMode(button3pin, INPUT_PULLUP);
  pinMode(button4pin, INPUT_PULLUP);
  pinMode(button5pin, INPUT_PULLUP); 
  pinMode(button6pin, INPUT_PULLUP);
  pinMode(button7pin, INPUT_PULLUP);
  pinMode(button8pin, INPUT_PULLUP);  
}

// ----------------------------------------------------------------------------
// Main loop
// ----------------------------------------------------------------------------
void loop() {

  // button1 state read
  button1state = digitalRead(button1pin);
  button2state = digitalRead(button2pin);
  button3state = digitalRead(button3pin);
  button4state = digitalRead(button4pin);  
  button5state = digitalRead(button5pin);
  button6state = digitalRead(button6pin);
  button7state = digitalRead(button7pin);
  button8state = digitalRead(button8pin);  

  //
  if (button1state == LOW) {
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

  //
  if (button2state == LOW) {
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

  //
  if (button3state == LOW) {
    Serial.println("BTN3: PRESSED");
    Serial.println("Sending note on");
    noteOn(0, 52, 64);   // Channel 0, middle C, normal velocity
    MidiUSB.flush();
    delay(500);

    Serial.println("Sending note off");
    noteOff(0, 52, 64);  // Channel 0, middle C, normal velocity
    MidiUSB.flush();
    delay(500);
  }
  //
  if (button4state == LOW) {
    Serial.println("BTN4: PRESSED");
    Serial.println("Sending note on");
    noteOn(0, 54, 64);   // Channel 0, middle C, normal velocity
    MidiUSB.flush();
    delay(500);

    Serial.println("Sending note off");
    noteOff(0, 54, 64);  // Channel 0, middle C, normal velocity
    MidiUSB.flush();
    delay(500);
  }

  if (button5state == LOW) {
    Serial.println("BTN5: PRESSED");
    Serial.println("Sending note on");
    noteOn(0, 56, 64);   // Channel 0, middle C, normal velocity
    MidiUSB.flush();
    delay(500);

    Serial.println("Sending note off");
    noteOff(0, 56, 64);  // Channel 0, middle C, normal velocity
    MidiUSB.flush();
    delay(500);
  }

  //
  if (button6state == LOW) {
    Serial.println("BTN6: PRESSED");
    Serial.println("Sending note on");
    noteOn(0, 58, 64);   // Channel 0, middle C, normal velocity
    MidiUSB.flush();
    delay(500);

    Serial.println("Sending note off");
    noteOff(0, 58, 64);  // Channel 0, middle C, normal velocity
    MidiUSB.flush();
    delay(500);
  }

  //
  if (button7state == LOW) {
    Serial.println("BTN7: PRESSED");
    Serial.println("Sending note on");
    noteOn(0, 60, 64);   // Channel 0, middle C, normal velocity
    MidiUSB.flush();
    delay(500);

    Serial.println("Sending note off");
    noteOff(0, 60, 64);  // Channel 0, middle C, normal velocity
    MidiUSB.flush();
    delay(500);
  }
  //
  if (button8state == LOW) {
    Serial.println("BTN8: PRESSED");
    Serial.println("Sending note on");
    noteOn(0, 62, 64);   // Channel 0, middle C, normal velocity
    MidiUSB.flush();
    delay(500);

    Serial.println("Sending note off");
    noteOff(0, 62, 64);  // Channel 0, middle C, normal velocity
    MidiUSB.flush();
    delay(500);
  }  
}


// never get here