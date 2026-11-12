# Lab Title: Blink without Delay

## 1. Check USB permissions (required to upload)

Add your user to the `dialout` group:

```bash
sudo usermod -aG dialout $USER
```

Then log out and back in (or reboot). Enable in sudo, then reboot.

Verify with `groups`. It should show:

```
mike@fedora:~$ groups
mike wheel dialout
mike@fedora:~$
```

## 2. Run the sketch

```cpp
/*
 Blink without Delay - 5 second interval

 Turns on and off a light emitting diode (LED) connected to a digital pin,
 without using the delay() function. This means that other code can run at the
 same time without being interrupted by the LED code.

 The circuit:
 - Use the onboard LED.
 - Note: Most Arduinos have an on-board LED you can control. On the UNO, MEGA
   and ZERO it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN
   is set to the correct LED pin independent of which board is used.

 created 2005
 by David A. Mellis
 modified 8 Feb 2010
 by Paul Stoffregen
 modified 11 Nov 2013
 by Scott Fitzgerald
 modified 9 Jan 2017
 by Arturo Guadalupi

 This example code is in the public domain.

 https://docs.arduino.cc/built-in-examples/digital/BlinkWithoutDelay/
*/

// constants won't change. Used here to set a pin number:
const int ledPin = LED_BUILTIN;  // the number of the LED pin

// Variables will change:
int ledState = LOW;  // ledState used to set the LED

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;  // will store last time LED was updated

// constants won't change:
const long interval = 1000;  // interval at which to blink (milliseconds) — 5 seconds

void setup() {
 // set the digital pin as output:
 pinMode(ledPin, OUTPUT);
}

void loop() {
 // here is where you'd put code that needs to be running all the time.

 // check to see if it's time to blink the LED; that is, if the difference
 // between the current time and last time you blinked the LED is bigger than
 // the interval at which you want to blink the LED.
 unsigned long currentMillis = millis();

 if (currentMillis - previousMillis >= interval) {
   // save the last time you blinked the LED
   previousMillis = currentMillis;

   // if the LED is off turn it on and vice-versa:
   if (ledState == LOW) {
     ledState = HIGH;
   } else {
     ledState = LOW;
   }

   // set the LED with the ledState of the variable:
   digitalWrite(ledPin, ledState);
 }
}
```

## 3. Upload and run

1. Connect the Arduino via USB.
2. In the IDE: **Tools → Board** → select your board.
3. **Tools → Port** → select the correct port (usually `/dev/ttyACM0` or `/dev/ttyUSB0`).
4. Click **Upload**.
5. The onboard LED should blink every second without blocking the program.

## 4. Changing the blink interval

`interval` is in milliseconds, so:

| Value | Duration |
|-------|----------|
| `1000` | 1 second |
| `5000` | 5 seconds |
| `500` | 0.5 seconds (faster) |
| `2000` | 2 seconds |

Upload the sketch again after the change. The onboard LED will now toggle every 5 seconds (when `interval = 5000`).
