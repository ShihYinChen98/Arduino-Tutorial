#define BLYNK_TEMPLATE_ID "TMPL6pQj2av3n"
#define BLYNK_TEMPLATE_NAME "LED Control"
#define BLYNK_AUTH_TOKEN "qkd_gZFmrQVKX7j57RBXzh5Z2fyweLpV"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "SC_iPhone";
char pass[] = "asdfghjkl";

WidgetLED led1(V0);
BlynkTimer timer;

const int ledPin = D2; // LED connected to digital pin D2

// V1 LED Widget is blinking
void blinkLedWidget()
{
  if (led1.getValue()) {
    led1.off();
    digitalWrite(ledPin, LOW); // Turn off the physical LED
    Serial.println("LED on V1: off");
  } else {
    led1.on();
    digitalWrite(ledPin, HIGH); // Turn on the physical LED
    Serial.println("LED on V1: on");
  }
}

void setup()
{
  // Debug console
  Serial.begin(115200);

  // Set the ledPin as an output
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW); // Ensure the LED is off initially

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  // You can also specify server:
  // Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  // Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, IPAddress(192,168,1,100), 8080);

  timer.setInterval(1000L, blinkLedWidget);
}

void loop()
{
  Blynk.run();
  timer.run();
}
