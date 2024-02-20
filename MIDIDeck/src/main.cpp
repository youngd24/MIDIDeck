/******************************************************************************
 * 
 * Adruino Pro Micro MIDI Controller
 *
 * (C) 2022-2024 Darren Young [youngd24@gmail.com]
 * 
 * https://github.com/youngd24/MIDIDeck
 * 
 ******************************************************************************
 * 
 * CHANGELOG:
 * 
 * 19-Feb-2024
 * -----------
 *   - Adjusted for XL 12 button version
 *   - Increased delay to 250 (made it a const)
 *
 ******************************************************************************
 *
 * TODO:
 * 
 * Refactor all chunks of 1-8 stuff
 * Change delay to be a constant or #define
 * Add dev and release envs
 * Move debug prints to only happen in the dev env
 * Move functions into their own cpp file
 * Refactor main loop to act on an array of buttons (access by index)
 * Test removing pitchToNote.h
 * 
 *****************************************************************************/

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
//   row[0] = 1,2,3,4,5,6
//   row[1] = 7,8,9,10,11,12
const int button1pin = 4;
const int button2pin = 5;
const int button3pin = 6;
const int button4pin = 7;
const int button5pin = 8;
const int button6pin = 9;
const int button7pin = 10;
const int button8pin = 16;
const int button9pin = 14;
const int button10pin = 15;
const int button11pin = 18;
const int button12pin = 19;


// Button state tracking
int button1state;
int button2state;
int button3state;
int button4state;
int button5state;
int button6state;
int button7state;
int button8state;
int button9state;
int button10state;
int button11state;
int button12state;

// Vars
const int DELAY = 250;


// ----------------------------------------------------------------------------
// Functions
// ----------------------------------------------------------------------------

// ****************************************************************************
// NAME        : noteOn
// DESCRIPTION : Send MIDI note on message
// ARGUMENTS   : byte channel (1-16)
//             : byte pitch (note number)
//             : byte velocity (1-127)
// RETURN      : void
// STATUS      : Stable
// NOTES       : None
// ****************************************************************************
void noteOn(byte channel, byte pitch, byte velocity) {

  // First parameter is the event type (0x09 = note on, 0x08 = note off).
  // Second parameter is note-on/note-off, combined with the channel.
  // Channel can be anything between 0-15. Typically reported to the user as 1-16.
  // Third parameter is the note number (48 = middle C).
  // Fourth parameter is the velocity (64 = normal, 127 = fastest).
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}

// ****************************************************************************
// NAME        : noteOdd
// DESCRIPTION : Send MIDI note off message
// ARGUMENTS   : byte channel (1-16)
//             : byte pitch (note number)
//             : byte velocity (1-127)
// RETURN      : void
// STATUS      : Stable
// NOTES       : None
// ****************************************************************************
void noteOff(byte channel, byte pitch, byte velocity) {

  // First parameter is the event type (0x09 = note on, 0x08 = note off).
  // Second parameter is note-on/note-off, combined with the channel.
  // Channel can be anything between 0-15. Typically reported to the user as 1-16.
  // Third parameter is the note number (48 = middle C).
  // Fourth parameter is the velocity (64 = normal, 127 = fastest).
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}

// ****************************************************************************
// NAME        : controlChange
// DESCRIPTION : Change sound control
// ARGUMENTS   : byte channel
//             : byte control
//             : byte value
// RETURN      : void
// STATUS      : Stable
// NOTES       : None
// ****************************************************************************
void controlChange(byte channel, byte control, byte value) {

  // First parameter is the event type (0x0B = control change).
  // Second parameter is the event type, combined with the channel.
  // Third parameter is the control number number (0-119).
  // Fourth parameter is the control value (0-127).
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
  pinMode(button9pin, INPUT_PULLUP);  
  pinMode(button10pin, INPUT_PULLUP);  
  pinMode(button11pin, INPUT_PULLUP);  
  pinMode(button12pin, INPUT_PULLUP);  

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
  button9state = digitalRead(button9pin);  
  button10state = digitalRead(button10pin);  
  button11state = digitalRead(button11pin);  
  button12state = digitalRead(button12pin);  


  // Button 1
  if (button1state == LOW) {
    Serial.println("BTN1: PRESSED");
    Serial.println("Sending note on");
    noteOn(0, 48, 64);
    MidiUSB.flush();
    delay(DELAY);
  }

  // Button 2
  if (button2state == LOW) {
    Serial.println("BTN2: PRESSED");
    Serial.println("Sending note on");
    noteOn(0, 50, 64);
    MidiUSB.flush();
    delay(DELAY);
  }

  // Button 3
  if (button3state == LOW) {
    Serial.println("BTN3: PRESSED");
    Serial.println("Sending note on");
    noteOn(0, 52, 64);
    MidiUSB.flush();
    delay(DELAY);
  }

  // Button 4
  if (button4state == LOW) {
    Serial.println("BTN4: PRESSED");
    Serial.println("Sending note on");
    noteOn(0, 54, 64);
    MidiUSB.flush();
    delay(DELAY);
  }

  // Button 5
  if (button5state == LOW) {
    Serial.println("BTN5: PRESSED");
    Serial.println("Sending note on");
    noteOn(0, 56, 64);
    MidiUSB.flush();
    delay(DELAY);
  }

  // Button 6
  if (button6state == LOW) {
    Serial.println("BTN6: PRESSED");
    Serial.println("Sending note on");
    noteOn(0, 58, 64);
    MidiUSB.flush();
    delay(DELAY);
  }

  // Button 7
  if (button7state == LOW) {
    Serial.println("BTN7: PRESSED");
    Serial.println("Sending note on");
    noteOn(0, 60, 64);
    MidiUSB.flush();
    delay(DELAY);
  }

  // Button 8
  if (button8state == LOW) {
    Serial.println("BTN8: PRESSED");
    Serial.println("Sending note on");
    noteOn(0, 62, 64);
    MidiUSB.flush();
    delay(DELAY);
  } 

  // Button 9
  if (button9state == LOW) {
    Serial.println("BTN9: PRESSED");
    Serial.println("Sending note on");
    noteOn(0, 64, 64);
    MidiUSB.flush();
    delay(DELAY);
  }

  // Button 10
  if (button10state == LOW) {
    Serial.println("BTN10: PRESSED");
    Serial.println("Sending note on");
    noteOn(0, 66, 64);
    MidiUSB.flush();
    delay(DELAY);
  }

  // Button 11
  if (button11state == LOW) {
    Serial.println("BTN11: PRESSED");
    Serial.println("Sending note on");
    noteOn(0, 68, 64);
    MidiUSB.flush();
    delay(DELAY);
  }

  // Button 12
  if (button12state == LOW) {
    Serial.println("BTN12: PRESSED");
    Serial.println("Sending note on");
    noteOn(0, 70, 64);
    MidiUSB.flush();
    delay(DELAY);
  }
}

// never get here