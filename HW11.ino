// bool =  can only hold true (0) and false (1) values
// store current state of each LED
bool pinState12;  // clear (1-10s)
bool pinState8;   // red (10-20s)
bool pinState5;   // green (20-30s)
bool pinState4;   // blue (30-40s)
bool pinState7;   // yellow (40-50s)
bool pinState11;  // orange (50-60s)

// int = integer = stores whole numbers
// store last state change of each LED
int lastChange12;
int lastChange8;
int lastChange5;
int lastChange4;
int lastChange7;
int lastChange11;

// unsigned = variable only stores positive values (incl. 0)
// long = can store larger int, good for storing large amount of numbers, often when dealing with millis()
unsigned long startTime12;
unsigned long startTime8;
unsigned long startTime5;
unsigned long startTime4;
unsigned long startTime7; 
unsigned long startTime11;

void setup() {
    // set output pins (e.g. pin wired to D12 is 12)
    pinMode(12, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(11, OUTPUT);

    // LOW = off, HIGH = on
    pinState12 = LOW;
    pinState8 = LOW;
    pinState5 = LOW;
    pinState4 = LOW;
    pinState7 = LOW;
    pinState11 = LOW;

    // times of last state changes starting from 0 = no changes done yet
    lastChange12 = 0;
    lastChange8 = 0;
    lastChange5 = 0;
    lastChange4 = 0;
    lastChange7 = 0;
    lastChange11 = 0;

    // start time to start from 0
    startTime12 = 0;
    startTime8 = 0;
    startTime5 = 0;
    startTime4 = 0;
    startTime7 = 0;
    startTime11 = 0;
}

void loop() {
    unsigned long now = millis();  // unsigned long named 'now' is storing millis()

    // resetting the sequence after 60s
    if (now - startTime12 > 59500) { // if current millis() - startTime12 is greater than 59500ms..
        startTime12 = now - 500;  // .. reset start time of LED, restarting the entire cycle (-500ms to remove lag time)
        
        // reset states of all LEDs to off
        pinState12 = LOW;
        pinState8 = LOW;
        pinState5 = LOW;
        pinState4 = LOW;
        pinState7 = LOW;
        pinState11 = LOW;

        // reset lastChange times so blinking and immediately start
        lastChange12 = now;
        lastChange8 = now;
        lastChange5 = now;
        lastChange4 = now;
        lastChange7 = now;
        lastChange11 = now;

        // reset all LEDs to initial state
        // digitalWrite = for setting HIGH and LOW states
        // written as 'digitalWrite(pin, value (meaning HIGH/LOW))', in this case, its mapped to LOW as declared above
        digitalWrite(12, pinState12); 
        digitalWrite(8, pinState8);
        digitalWrite(5, pinState5);
        digitalWrite(4, pinState4);
        digitalWrite(7, pinState7);
        digitalWrite(11, pinState11);
    }

    // blink clear LED every 500ms
    if (now > lastChange12 + 500) { // if it has been 500ms since the last changed state..
        pinState12 = !pinState12; // .. flip pinState (like a switch)
        lastChange12 = now; // stores time stamp of most recent state change
        if (startTime12 == 0) { // check if startTime12 is 0
            startTime12 = now;  // if 0, set startTime12 to current time (millis())
        }
        digitalWrite(12, pinState12);  // update LED to HIGH/LOW accordingly based on above
    }

    // start blinking red LED every 500ms after 9s
    if (now > startTime12 + 9000 && now > lastChange8 + 500) { // if 9000ms have passed and 500ms since last changed state..
        pinState8 = !pinState8; // .. flip pinState
        lastChange8 = now;
        digitalWrite(8, pinState8);
    }

    // start blinking green LED every 500ms after 19s
    if (now > startTime12 + 19000 && now > lastChange5 + 500) {
        pinState5 = !pinState5;
        lastChange5 = now;
        digitalWrite(5, pinState5);
    }

    // start blinking blue LED every 500ms after 29s
    if (now > startTime12 + 29000 && now > lastChange4 + 500) {
        pinState4 = !pinState4;
        lastChange4 = now;
        digitalWrite(4, pinState4);
    }

    // start blinking yellow LED every 500ms after 39s
    if (now > startTime12 + 39000 && now > lastChange7 + 500) {
        pinState7 = !pinState7;
        lastChange7 = now;
        digitalWrite(7, pinState7);
    }

    // start blinking orange LED every 500ms after 49s
    if (now > startTime12 + 49000 && now > lastChange11 + 500) {
        pinState11 = !pinState11;
        lastChange11 = now;
        digitalWrite(11, pinState11);
    }
}

