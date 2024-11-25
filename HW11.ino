// for 10 second LEDs
bool pinState11; // blue (1-15s)
bool pinState12; // green (15-30s)
bool pinState3;  // red (30-45s)
bool pinState2;  // red (45-60s)

int lastChange11;
int lastChange12;
int lastChange3;
int lastChange2;

unsigned long startTime11; // Variable to store when pinState11 starts blinking
unsigned long startTime12; // Variable to store when pinState12 starts blinking
unsigned long startTime3;  // Variable to store when pinState3 starts blinking
unsigned long startTime2;  // Variable to store when pinState2 starts blinking

// For minute LED (pin 5)
unsigned long lastMinuteChange = 0; // To store last time pin 5 was toggled
bool pinState5 = LOW;               // Current state of pin 5 (on or off)

void setup() {
    // for 10 second LEDs (PWM pins)
    pinMode(11, OUTPUT);  // blue
    pinMode(12, OUTPUT);  // green
    pinMode(3, OUTPUT);   // red
    pinMode(2, OUTPUT);   // red

    pinState11 = LOW;
    pinState12 = LOW;
    pinState3 = LOW;
    pinState2 = LOW;

    lastChange11 = 0;
    lastChange12 = 0;
    lastChange3 = 0;
    lastChange2 = 0;

    startTime11 = 0; // Initialize the start time of pinState11
    startTime12 = 0; // Initialize the start time of pinState12
    startTime3 = 0;  // Initialize the start time of pinState3
    startTime2 = 0;  // Initialize the start time of pinState2

    // for minute LED (pin 5)
    pinMode(5, OUTPUT);  // sets pin 5 as output
}

void loop() {
    unsigned long now = millis();  // Get current time in milliseconds

    // Blinking blue LED (pin 11) every 500ms
    if (now > lastChange11 + 500) {
        pinState11 = !pinState11;
        lastChange11 = now;
        if (startTime11 == 0) {
            startTime11 = now;  // Record the start time of pinState11 blinking
        }
    }

    // Blink green LED (pin 12) after 15 seconds
    if (now > startTime11 + 15000 && now > lastChange12 + 500) {
        pinState12 = !pinState12;
        lastChange12 = now;
    }

    // Blink red LED (pin 3) after 30 seconds
    if (now > startTime11 + 30000 && now > lastChange3 + 500) {
        pinState3 = !pinState3;
        lastChange3 = now;
    }

    // Blink red LED (pin 2) after 45 seconds
    if (now > startTime11 + 45000 && now > lastChange2 + 500) {
        pinState2 = !pinState2;
        lastChange2 = now;
    }

    // Write the states to the pins with PWM for brightness control
    analogWrite(11, pinState11 ? 10 : 0);  // 50% brightness for blue (pin 11)
    analogWrite(12, pinState12 ? 10 : 0);  // 50% brightness for green (pin 12)
    analogWrite(3, pinState3 ? 10 : 0);    // 50% brightness for red (pin 3)
    analogWrite(2, pinState2 ? 10 : 0);    // 50% brightness for red (pin 2)

    // For minute LED (pin 5), toggle every minute
    if (now - lastMinuteChange >= 60000) {  // 60,000 milliseconds = 1 minute
        pinState5 = !pinState5;              // Toggle the state of pin 5
        lastMinuteChange = now;              // Update the last change time
    }

    // Set the brightness of pin 5 (analogWrite allows brightness control)
    analogWrite(5, pinState5 ? 10 : 0);  // 50% brightness for pin 5

    delay(60);  // Delay for smooth operation
}
