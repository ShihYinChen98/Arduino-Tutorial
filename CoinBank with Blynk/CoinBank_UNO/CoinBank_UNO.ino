#include <Servo.h>
#include <SoftwareSerial.h>

Servo myservo;
const int buttonPin = A1;  // the pin that the button is attached to (analog pin A1 used as digital)
const int servoPin = A2;   // the pin that the servo is attached to (analog pin A2 used as digital)

int buttonState = 1;       // variable for reading the button status
int coinCount = 0;

SoftwareSerial EspSerial(2, 3); // RX, TX

void setup() {
  pinMode(buttonPin, INPUT);  // initialize the button pin as an input
  myservo.attach(servoPin);  // attaches the servo on pin A2 to the servo object
  myservo.write(0);  // Initial position of servo
  Serial.begin(9600);  // start serial communication at 9600 baud rate
  EspSerial.begin(9600);  // start software serial communication at 9600 baud rate
}

void loop() {
  buttonState = digitalRead(buttonPin);  // read the state of the button

  if (buttonState == LOW) {  // check if the button is pressed
    myservo.write(90);  // set servo to 90 degrees
    delay(1000);  // wait for 1 second
    myservo.write(0);  // reset servo to 0 degrees

    // Coin Count
    coinCount++;  // increment coin count
    EspSerial.print("C:");  // send coin count to the software serial
    EspSerial.println(coinCount);  // send coin count to the software serial
    Serial.print("Sent coin count: ");  // Debug output
    Serial.println(coinCount);
    delay(200); // short delay to debounce the button
  }
}
