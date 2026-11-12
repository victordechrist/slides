# Lab Title: Debounce

## 1. Sketch

```cpp
/*
  Debounce

  Each time the input pin goes from LOW to HIGH (e.g. because of a push-button
  press), the output pin is toggled from LOW to HIGH or HIGH to LOW. There's a
  minimum delay between toggles to debounce the circuit (i.e. to ignore noise).

  The circuit:
  - LED attached from pin 13 to ground through 220 ohm resistor
  - pushbutton attached from pin 2 to +5V
  - 10 kilohm resistor attached from pin 2 to ground

  - Note: On most Arduino boards, there is already an LED on the board connected
    to pin 13, so you don't need any extra components for this example.

  created 21 Nov 2006
  by David A. Mellis
  modified 30 Aug 2011
  by Limor Fried
  modified 28 Dec 2012
  by Mike Walters
  modified 30 Aug 2016
  by Arturo Guadalupi

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/digital/Debounce/
*/

const int buttonPin = 2;  // the number of the pushbutton pin
const int ledPin = 13;    // the number of the LED pin

int ledState = HIGH;        // the current state of the output pin
int buttonState;            // the current reading from the input pin
int lastButtonState = LOW;  // the previous reading from the input pin

unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // set initial LED state
  digitalWrite(ledPin, ledState);
}

void loop() {
  int reading = digitalRead(buttonPin);

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    if (reading != buttonState) {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        ledState = !ledState;
      }
    }
  }

  digitalWrite(ledPin, ledState);
  lastButtonState = reading;
}
```

## 2. Explanation

The debounce logic filters out the rapid mechanical noise (bounce) that happens when a physical button is pressed or released. It only accepts a button state change after the reading has stayed stable for longer than `debounceDelay` (50 ms by default).

### Key variables

| Variable | Meaning |
|----------|---------|
| `reading` | The raw value just read from the button pin (`digitalRead`). |
| `lastButtonState` | The previous raw reading. |
| `lastDebounceTime` | The timestamp (`millis()`) of the last time the raw reading changed. |
| `debounceDelay` | How long the reading must stay the same before we trust it (50 ms). |
| `buttonState` | The last accepted (debounced) state of the button. |
| `ledState` | The LED's current on/off state. |

### How the logic works (step by step)

**1. Read the button**

```cpp
int reading = digitalRead(buttonPin);
```

**2. Detect any change (including bounce noise)**

```cpp
if (reading != lastButtonState) {
  lastDebounceTime = millis();   // reset the timer
}
```

Every time the raw reading differs from the previous raw reading, the debounce timer is restarted. Bounce causes many rapid changes, so the timer keeps getting reset.

**3. Check if the reading has been stable long enough**

```cpp
if ((millis() - lastDebounceTime) > debounceDelay) {
  // the reading has been the same for longer than debounceDelay
  if (reading != buttonState) {          // the *debounced* state actually changed
    buttonState = reading;

    if (buttonState == HIGH) {           // only act on a press (LOW → HIGH)
      ledState = !ledState;              // toggle the LED
    }
  }
}
```

Only after the raw reading has stayed constant for more than 50 ms do we accept it as the real button state. Then we toggle the LED only on a rising edge (press).

**4. Update for the next loop**

```cpp
digitalWrite(ledPin, ledState);
lastButtonState = reading;
```

## 3. Why this works

- During the bounce period the raw signal flips many times → the timer is repeatedly reset → the code never enters the "stable" block.
- Once the contacts settle, the reading stays the same → the timer is no longer reset → after 50 ms the code accepts the new state and toggles the LED once.
- This is non-blocking: it uses `millis()` instead of `delay()`, so the rest of your program can keep running while waiting for the button to settle.

> If the LED still double-toggles on one press, increase `debounceDelay` (e.g. to 100 or 150).
