#include <SoftwareSerial.h>

SoftwareSerial UnoSerial(D2, D1); // RX, TX (D2接到UNO的TX, D1接到UNO的RX)

void setup() {
  Serial.begin(9600);         // Initialize hardware serial port for debugging
  UnoSerial.begin(9600);      // Initialize software serial port to communicate with UNO
}

void loop() {
  if (UnoSerial.available() > 0) {
    String data = UnoSerial.readStringUntil('\n');  // Read the data from UNO
    Serial.print("Received from UNO: ");            // Print received data to Serial Monitor
    Serial.println(data);
  }
}
