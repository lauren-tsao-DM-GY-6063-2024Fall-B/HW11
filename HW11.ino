void setup() {
  pinMode(12, OUTPUT); // LED on pin 12
  pinMode(11, OUTPUT); // LED on pin 11 (not used in this example, but available)
}

void loop() {
  int now = millis();

  for (int i = 0; i < 7; i++) {  // i starts from 0, it will loop 100 times
    int blinkCount = i % 7;  // Modulo operation: reset i after it reaches 6
    blink(blinkCount);  // Pass the number of blinks (i % 7) to the blink function
    delay(10000 - i*200);  // Wait 10 seconds before next iteration
  }
}

void blink(int times) {
  for (int j = 0; j < times; j++) {  // Blink 'times' number of times
    digitalWrite(12, HIGH);   // Turn the LED on
    delay(100);               // Wait for a quarter of a second
    digitalWrite(12, LOW);    // Turn the LED off
    delay(100);               // Wait for a quarter of a second
  }
}
