bool pinState12;  // clear (1-10s)
bool pinState8;   // red (10-20s)
bool pinState5;   // green (20-30s)
bool pinState4;   // blue (30-40s)
bool pinState7;   // yellow (40-50s)
bool pinState11;  // orange (50-60s)

int lastChange12;
int lastChange8;
int lastChange5;
int lastChange4;
int lastChange7;
int lastChange11;

unsigned long startTime12;
unsigned long startTime8;
unsigned long startTime5;
unsigned long startTime4;
unsigned long startTime7; 
unsigned long startTime11;

void setup() {
    pinMode(12, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(11, OUTPUT);

    pinState12 = LOW;
    pinState8 = LOW;
    pinState5 = LOW;
    pinState4 = LOW;
    pinState7 = LOW;
    pinState11 = LOW;

    lastChange12 = 0;
    lastChange8 = 0;
    lastChange5 = 0;
    lastChange4 = 0;
    lastChange7 = 0;
    lastChange11 = 0;

    startTime12 = 0;
    startTime8 = 0;
    startTime5 = 0;
    startTime4 = 0;
    startTime7 = 0;
    startTime11 = 0;
}

void loop() {
    unsigned long now = millis();  // Get current time in milliseconds

    // If 60 seconds have passed, reset the entire sequence
    if (now - startTime12 > 60000) { // if current millis() - startTime12 is greater than 60s
        startTime12 = now - 500;  // Reset start time for clear LED (start new cycle)
        
        // Reset the states for all LEDs
        pinState12 = LOW;
        pinState8 = LOW;
        pinState5 = LOW;
        pinState4 = LOW;
        pinState7 = LOW;
        pinState11 = LOW;

        // Reset last change times to allow immediate blinking
        lastChange12 = now;
        lastChange8 = now;
        lastChange5 = now;
        lastChange4 = now;
        lastChange7 = now;
        lastChange11 = now;

        // Reset all LEDs to their initial state
        digitalWrite(12, pinState12);
        digitalWrite(8, pinState8);
        digitalWrite(5, pinState5);
        digitalWrite(4, pinState4);
        digitalWrite(7, pinState7);
        digitalWrite(11, pinState11);
    }

    // Blink clear LED every 500ms
    if (now > lastChange12 + 500) {
        pinState12 = !pinState12;
        lastChange12 = now;
        if (startTime12 == 0) {
            startTime12 = now;  // Record the start time for clear LED
        }
        digitalWrite(12, pinState12);  // Update LED state
    }

    // Blink red LED every 500ms after 19s
    if (now > startTime12 + 9000 && now > lastChange8 + 500) {
        pinState8 = !pinState8;
        lastChange8 = now;
        digitalWrite(8, pinState8);  // Update LED state
    }

    // Blink green LED every 500ms after 29s
    if (now > startTime12 + 19000 && now > lastChange5 + 500) {
        pinState5 = !pinState5;
        lastChange5 = now;
        digitalWrite(5, pinState5);  // Update LED state
    }

    // Blink blue LED every 500ms after 39s
    if (now > startTime12 + 29000 && now > lastChange4 + 500) {
        pinState4 = !pinState4;
        lastChange4 = now;
        digitalWrite(4, pinState4);  // Update LED state
    }

    // Blink yellow LED every 500ms after 49s
    if (now > startTime12 + 39000 && now > lastChange7 + 500) {
        pinState7 = !pinState7;
        lastChange7 = now;
        digitalWrite(7, pinState7);  // Update LED state
    }

    // Blink orange LED every 500ms after 49s
    if (now > startTime12 + 49000 && now > lastChange11 + 500) {
        pinState11 = !pinState11;
        lastChange11 = now;
        digitalWrite(11, pinState11);  // Update LED state
    }
}

