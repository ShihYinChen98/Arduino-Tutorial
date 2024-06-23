#define BLYNK_TEMPLATE_ID "TMPL6yT9dVA4g"
#define BLYNK_TEMPLATE_NAME "Coin Bank"
#define BLYNK_AUTH_TOKEN "57W5Ehi30MIawC4XVUP9CJ4Er6yiXyea"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SoftwareSerial.h>

SoftwareSerial UnoSerial(D1, D0); // RX, TX (D2接到UNO的TX, D1接到UNO的RX)

char ssid[] = "SC_iPhone";
char pass[] = "asdfghjkl";

BlynkTimer timer;

BLYNK_WRITE(V5) {
  int buttonState = param.asInt();
  if (buttonState == 1) {
    Blynk.virtualWrite(V4, 0);
  }
}

void sendData() {
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');
    if (data.startsWith("C:")) {
      int coinCount = data.substring(2).toInt();
      Blynk.virtualWrite(V1, coinCount);
      Blynk.virtualWrite(V2, coinCount);
    }
  }
}

void setup() {
  Serial.begin(9600);
  UnoSerial.begin(9600);      // Initialize software serial port to communicate with UNO
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  // while (Blynk.connect() == false) {
  //   // Wait until connected
  // }
  timer.setInterval(1000L, sendData);  // Set a timer to send data every second
}

void loop() {
  Blynk.run();
  timer.run();
  
  if (UnoSerial.available() > 0) {
    String data = UnoSerial.readStringUntil('\n');  // Read the data from UNO
    Serial.print("Received from UNO: ");            // Print received data to Serial Monitor
    Serial.println(data);
  }
}
