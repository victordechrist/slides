# Lab Title: Play a Melody using the tone() function

*(File → Examples → 02.Digital → toneMelody, or the page you linked)*

## What it does

It plays a short melody (a familiar tune) on a piezo buzzer or speaker using the `tone()` function. Notes and durations are defined in arrays, and the `pitches.h` file supplies the frequency values for each note.

## Hardware required

- Arduino board
- Piezo buzzer (or small speaker)
- Jumper wires

## Circuit

- One pin of the piezo → digital pin 8
- Other pin of the piezo → GND

(No resistor is needed for a piezo buzzer. Most Arduino kits include a passive piezo that works directly.)

## Steps in the Arduino IDE

1. Create a new sketch and paste the main code (or open **File → Examples → 02.Digital → toneMelody**).
2. Create the `pitches.h` file:
   1. Click the downward arrow next to the sketch tab (or use `Ctrl+Shift+N`).
   2. Choose **New Tab**.
   3. Name it exactly `pitches.h`.
   4. Paste the note definitions into that tab:

```cpp
/*************************************************

 * Public Constants

 *************************************************/

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
```

## Main sketch (ready to use)

```cpp
/*
  Melody
  Plays a melody
  circuit:
  - 8 ohm speaker on digital pin 8
  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe
  This example code is in the public domain.
  https://www.arduino.cc/en/Tutorial/Tone
*/

#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    // to calculate the note duration, take one second divided by the note type.
    // e.g. quarter note = 1000 / 4, eighth note = 1000 / 8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);

    // stop the tone playing:
    noTone(8);
  }
}

void loop() {
  // no need to repeat the melody.
}
```

3. Upload the sketch (same board and port as before).

## Expected result

The piezo plays a short 8-note melody once after upload (or after reset). It does not loop because the code is only in `setup()`.

## Tips

- If you hear nothing, double-check the piezo is on pin 8 and GND, and that it is a passive piezo (active buzzers only make one tone).
- To make it repeat, move the `for` loop into `loop()` (and add a short `delay()` at the end if desired).
- You can change the notes in the `melody[]` array or the durations to play something else.
- The `pitches.h` content is the standard note table used by this example. Once both files are in the sketch, it is ready to upload.

---

## Explanation: the code step by step

Here's a clear, step-by-step explanation of how the sketch works.

### 1. Include the note frequencies

```cpp
#include "pitches.h"
```

This brings in a file full of constants such as `NOTE_C4`, `NOTE_G3`, `NOTE_A3`, etc.

Each constant is a frequency in Hz (e.g. middle C is about 262 Hz).

Without this file the names `NOTE_C4` etc. would be unknown.

### 2. Define the melody

```cpp
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};
```

This array lists the notes to play, in order.

- `NOTE_C4` = middle C
- `NOTE_G3` = G below middle C
- `0` = a rest (silence)

There are 8 notes (including the rest).

### 3. Define how long each note lasts

```cpp
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};
```

These numbers are relative durations:

- `4` = quarter note
- `8` = eighth note

The array must be the same length as `melody[]`.

### 4. Play the melody (inside `setup()`)

The whole melody is played once when the board starts, because the code is in `setup()`, not `loop()`.

```cpp
for (int thisNote = 0; thisNote < 8; thisNote++) {
```

Loops once for each of the 8 notes.

**Calculate the duration in milliseconds**

```cpp
int noteDuration = 1000 / noteDurations[thisNote];
```

- Quarter note (4) → 1000 / 4 = 250 ms
- Eighth note (8) → 1000 / 8 = 125 ms

**Play the note**

```cpp
tone(8, melody[thisNote], noteDuration);
```

- Pin 8 is the piezo
- `melody[thisNote]` is the frequency (or 0 for silence)
- `noteDuration` is how long the tone should sound

**Add a short pause between notes**

```cpp
int pauseBetweenNotes = noteDuration * 1.30;
delay(pauseBetweenNotes);
```

The pause is 30% longer than the note itself. This gap stops the notes from blurring together.

**Stop the tone**

```cpp
noTone(8);
```

Turns the sound off before the next note starts.

(Even though `tone()` was given a duration, calling `noTone()` is good practice.)

### 5. `loop()` is empty

```cpp
void loop() {
  // no need to repeat the melody.
}
```

The melody plays only once (right after upload or reset). If you want it to keep repeating, move the `for` loop into `loop()`.

## Summary of the flow

1. Load the note frequencies.
2. Store the sequence of notes and their relative lengths.
3. For each note:
   - Convert the relative length into milliseconds
   - Play that frequency for that time on pin 8
   - Wait a little longer so the notes are distinct
   - Turn the sound off
4. Stop (because everything is in `setup()`).

That's the complete logic of the classic Arduino melody example.
