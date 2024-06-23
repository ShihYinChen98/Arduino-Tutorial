void setup() {
  // Start the serial communication at 9600 baud rate
  Serial.begin(9600);
}

void loop() {
  // Print "Hello Arduino" to the serial monitor
  Serial.println("Hello Arduino");

  // Wait for a second (1000 milliseconds) before repeating
  delay(1000);
}
