#define BLYNK_TEMPLATE_ID "TMPL6yT9dVA4g"
#define BLYNK_TEMPLATE_NAME "Coin Bank"
#define BLYNK_AUTH_TOKEN "57W5Ehi30MIawC4XVUP9CJ4Er6yiXyea"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;  // Blynk Auth Token
char ssid[] = "SC_iPhone";  // Your WiFi SSID
char pass[] = "asdfghjkl";  // Your WiFi Password

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  if (Serial.available() > 0) {
    int coinCount = Serial.parseInt();
    Blynk.virtualWrite(V1, coinCount);  // Send coin count to Blynk virtual pin V1
  }
  Blynk.run();
}
