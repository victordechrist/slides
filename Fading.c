/*

  Fading

  This example shows how to fade an LED using the analogWrite() function.

  The circuit:

  - LED attached from digital pin 9 to ground.

  created 1 Nov 2008

  by David A. Mellis

  modified 30 Aug 2011

  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/Fading

*/

int ledPin = 9;    // LED connected to digital pin 9

void setup() {

  // nothing happens in setup
}

void loop() {

  // fade in from min to max in increments of 5 points:

  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {

    // sets the value (range from 0 to 255):

    analogWrite(ledPin, fadeValue);

    // wait for 30 milliseconds to see the dimming effect

    delay(30);

  }

  // fade out from max to min in in…
https://docs.arduino.cc/built-in-examples/communication/Dimmer/
https://docs.arduino.cc/built-in-examples/communication/PhysicalPixel/
https://docs.arduino.cc/built-in-examples/digital/Debounce/
https://docs.arduino.cc/built-in-examples/digital/StateChangeDetection/
https://docs.arduino.cc/built-in-examples/digital/toneMelody/
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

 https://docs.arduino.cc/built-in-examples/…
https://docs.arduino.cc/built-in-examples/digital/StateChangeDetection/
https://docs.arduino.cc/built-in-examples/digital/StateChangeDetection/
