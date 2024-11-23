// for 10 second LEDs
// bool variables hold either HIGH (1 = on) / LOW (0 = off)
bool pinState11; // blue (10th sec)
bool pinState12; // green (20th sec)
bool pinState3;  // red (30th sec)
bool pinState2;  // yellow (40th sec)
bool pinState4; // clear (50th sec)

int lastChange11;
int lastChange12;
int lastChange3;
int lastChange2;
int lastChange4;

unsigned long startTime11; // Variable to store when pinState11 starts blinking
unsigned long startTime12; // Variable to store when pinState11 starts blinking
unsigned long startTime3; // Variable to store when pinState11 starts blinking
unsigned long startTime2; // Variable to store when pinState11 starts blinking
unsigned long startTime4; // Variable to store when pinState11 starts blinking

// for minute LED
int ledVal;  // LED value
int ledVel;  // LED velocity

void setup() {
    // for 10 second LEDs
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(4, OUTPUT);
    
    pinState11 = LOW;
    pinState12 = LOW;
    pinState3 = LOW;
    pinState2 = LOW;
    pinState4 = LOW;
   

    lastChange11 = 0;
    lastChange12 = 0;
    lastChange3 = 0;
    lastChange2 = 0;
    lastChange4 = 0;

    startTime11 = 0; // Initialize the start time of pinState11
    startTime12 = 0; // Initialize the start time of pinState11
    startTime3 = 0; // Initialize the start time of pinState11
    startTime2 = 0; // Initialize the start time of pinState11
    startTime4 = 0; // Initialize the start time of pinState11
    

    // for min LED
    pinMode(5, OUTPUT);    // sets the digital pin 5 as output
    ledVal = 255;  // Start with the LED at maximum brightness
    ledVel = 1;    // Speed of fading
}

void loop() {
    int now = millis();  // Get current time in milliseconds

       if (now > lastChange11 + 500) {
        pinState11 = !pinState11;
        lastChange11 = now;
        if (startTime11 == 0) {
            startTime11 = now;  // Record the start time of pinState2 blinking
        }
    }

     if (now > startTime11 + 9700 && now > lastChange12 + 500) {  // Start pinState3 10s after pinState2
        pinState12 = !pinState12;
        lastChange12 = now;
    }
    
       // for pinState2 (LED on pin 2)
    if (now > startTime11 + 19330 && now > lastChange3 + 500) {
        pinState3 = !pinState3;
        lastChange3 = now;
    }
    
    if (now > startTime11 + 29500 && now > lastChange2 + 500) {
        pinState2 = !pinState2;
        lastChange2 = now;
    }

    if (now > startTime11 + 39500 && now > lastChange4 + 500) {
      pinState4 = !pinState4;
      lastChange4 = now;
    }

    // Write the states to the pins
    digitalWrite(11, pinState11);  // Write pinState3 to pin 3
    digitalWrite(12, pinState12);  // Write pinState3 to pin 3
    digitalWrite(3, pinState3);  // Write pinState3 to pin 3
    digitalWrite(2, pinState2);  // Write pinState2 to pin 2
    digitalWrite(4, pinState4);  // Write pinState3 to pin 3

    // for min LED (LED on pin 5)
     analogWrite(5, ledVal);  // Set the LED brightness
     ledVal = (ledVal - ledVel) % 256;  // Decrease brightness until it reaches 0

     // If ledVal becomes negative (due to the modulo operation), reset it to 255 to keep it positive
     if (ledVal < 0) {
        ledVal = 255;
     }

     delay(60);  // Delay for smooth fading
}
