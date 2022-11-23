# MIDI Deck

What is it? an Arduino Pro Micro MIDI controller, connected via USB, that can send MIDI messages to a host on button press. The idea is to automate apps on the host, in my primary use case, OBS. Press button, things happen.

The design is as dead simple as possible so it's easy to build, total cost is under $20 (likely less).

## Why?

There were 2 main drivers I had for building this, the first is when I'm recording for YouTube videos. I use OBS with several cameras and other inputs and rather than flipping between them in editing I switch while recording. Why? I hate editing and this saves time there.

Second is for streaming, the keyboad combos I ended up using in OBS were awkward to use and I was always forgetting them. There's a reason the StreamDeck exists, this serves the same function.

## Goals

For the initial version, I had the following objectives:

* All command comms use MIDI (rather than HID)
* Prefer an Arduino platform
* Be as simple as possible to build
* Low cost

### MIDI

So why MIDI and not HID? Well, mainly because I have some other projects that I want to use MIDI on an Arduino for, this was the chance to have a super simple project to learn how to do it. My learning process tends to be additive and cumulative, I start with simple ideas, learn it thoroughly, then grow and learn more.

### Arduino

Why Arduino and not a, say, ESP32 or even a Raspberry Pi? The Pi could certainly do this but as of this writing, late 2022, they're still difficult to find and tend to be costly due to the [chip chortage](https://www.youtube.com/watch?v=vGjQcPUfBdM).
