// for 10 second LEDs
bool pinState2;  // bool variables hold either HIGH (1 = on) / LOW (0 = off)
bool pinState3;

int lastChange2;
int lastChange3;
unsigned long startTime2; // Variable to store when pinState2 starts blinking

// for minute LED
int ledVal;  // LED value
int ledVel;  // LED velocity

void setup() {
    // for 10 second LEDs
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    
    pinState2 = LOW;
    pinState3 = LOW;

    lastChange2 = 0;
    lastChange3 = 0;

    startTime2 = 0; // Initialize the start time of pinState2

    // for min LED
    pinMode(4, OUTPUT);    // sets the digital pin 4 as output
    ledVal = 255;  // Start with the LED at maximum brightness
    ledVel = 1;    // Speed of fading
}

void loop() {
    int now = millis();  // Get current time in milliseconds

    // for pinState2 (LED on pin 2)
    if (now > lastChange2 + 500) {
        pinState2 = !pinState2;
        lastChange2 = now;
        if (startTime2 == 0) {
            startTime2 = now;  // Record the start time of pinState2 blinking
        }
    }

    // for pinState3 (LED on pin 3)
    if (now > startTime2 + 9700 && now > lastChange3 + 500) {  // Start pinState3 10s after pinState2
        pinState3 = !pinState3;
        lastChange3 = now;
    }

    // Write the states to the pins
    digitalWrite(2, pinState2);  // Write pinState2 to pin 2
    digitalWrite(3, pinState3);  // Write pinState3 to pin 3

    // for min LED (LED on pin 4)
    analogWrite(4, ledVal);  // Set the LED brightness
    ledVal = (ledVal - ledVel) % 256;  // Decrease brightness until it reaches 0

    // If ledVal becomes negative (due to the modulo operation), reset it to 255 to keep it positive
    if (ledVal < 0) {
        ledVal = 255;
    }

    delay(60);  // Delay for smooth fading
}
