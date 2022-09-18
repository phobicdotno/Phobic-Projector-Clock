#include <Arduino.h>
#include "19pix.h"      // All the pixel stuff
#include "wifiStuff.h"  // All Wifi-stuff, NTP, OTA


// Variables
int nowSec, lastSec, nowMin, nowHour;
bool secOnOff;
unsigned long previousMillis = 0;
const long interval = 500;

#define LED LED_BUILTIN //Led in NodeMCU at pin GPIO16 (D0) 

void setup(){
  pinMode(LED, OUTPUT); //LED pin as output
  Serial.begin(115000);

  // This resets all the neopixels to an off state
  strip.Begin();
  strip.Show();

  WiFi.mode(WIFI_STA);

  WiFi.begin(ssid, password);

  timeClient.begin();
  timeClient.setTimeOffset(7200);

    // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    for (int i = 7; i < 19; i++)
    {
        clearNumbers();
        strip.SetPixelColor(i, white);
        strip.Show();
        delay(100);
    }
    delay(100);
  }
  clearNumbers();
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(200, "text/plain", "Hi! please go to <IP>/update !");
  });

  AsyncElegantOTA.begin(&server);    // Start AsyncElegantOTA
  server.begin();
  Serial.println("HTTP server started");
 }

void loop() {
  timeClient.update();    // Update time

  if (timeClient.isTimeSet()){  // Ensures correct time
    nowSec = timeClient.getSeconds();
    nowMin = timeClient.getMinutes();
    nowHour = timeClient.getHours() % 12;

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    if(! secOnOff){
//      digitalWrite(LED, HIGH);  // Onboard LED
      secOnOff = true;
      strip.SetPixelColor(0, blue);
      Serial.println("ON");  // DEBUG
    }
    else {
//      digitalWrite(LED, LOW); // Onboard LED
      secOnOff = false;
      strip.SetPixelColor(0, hslBlack);
      Serial.println("OFF");  // DEBUG
    }

    // set the LED with the ledState of the variable:
//    digitalWrite(LED, secOnOff);  // Onboard LED
  }

    if (nowSec != lastSec){   // Only do something every second
      lastSec = nowSec;
      Serial.print("... Blink ");  // Blink center light - LED 1
        switch (nowSec) {
          case 10:
            Serial.println("Ten seconds");  // Set LED 2
            clearSecs();
            strip.SetPixelColor(2, red);
            break;
          case 20:
            Serial.println("Twenty seconds");  // Set LED 3
            strip.SetPixelColor(3, red);
            break;
          case 30:
            Serial.println("Thirty seconds");  // Set LED 4
            strip.SetPixelColor(4, red);
            break;
          case 40:
            Serial.println("Forty seconds");  // Set LED 5
            strip.SetPixelColor(5, red);
            break;
          case 50:
            Serial.println("Fifty seconds");  // Set LED 6
            strip.SetPixelColor(6, red);
            break;
          case 0:
            Serial.println("Sixty seconds");  // Set LED 7
            strip.SetPixelColor(1, red);
            break;
          default:
            // statements
            break;
        }

        switch (nowMin) {
          case 5:
            clearNumbers();
            one(green);
            Serial.println("5 minutes");  // Set LED 16
            break;
          case 10:
            one(green);
            two(green);
            Serial.println("10 minutes");  // Set LED 17
            break;
          case 15:
            one(green);
            two(green);
            three(green);
            Serial.println("15 minutes");  // Set LED 18
            break;
          case 20:
            one(green);
            two(green);
            three(green);
            four(green);
            Serial.println("20 minutes");  // Set LED 7
            break;
          case 25:
            one(green);
            two(green);
            three(green);
            four(green);
            five(green);
            Serial.println("25 minutes");  // Set LED 8
            break;
          case 30:
            one(green);
            two(green);
            three(green);
            four(green);
            five(green);
            six(green);
            Serial.println("30 minutes");  // Set LED 9
            break;
          case 35:
            one(green);
            two(green);
            three(green);
            four(green);
            five(green);
            six(green);
            seven(green);
            Serial.println("35 minutes");  // Set LED 10
            break;
          case 40:
            one(green);
            two(green);
            three(green);
            four(green);
            five(green);
            six(green);
            seven(green);
            eight(green);
            Serial.println("40 minutes");  // Set LED 11
            break;
          case 45:
            one(green);
            two(green);
            three(green);
            four(green);
            five(green);
            six(green);
            seven(green);
            eight(green);
            nine(green);
            Serial.println("45 minutes");  // Set LED 12
            break;
          case 50:
            one(green);
            two(green);
            three(green);
            four(green);
            five(green);
            six(green);
            seven(green);
            eight(green);
            nine(green);
            ten(green);
            Serial.println("50 minutes");  // Set LED 14
            break;
          case 55:
            one(green);
            two(green);
            three(green);
            four(green);
            five(green);
            six(green);
            seven(green);
            eight(green);
            nine(green);
            ten(green);
            eleven(green);
            Serial.println("55 minutes");  // Set LED 14
            break;
          case 0:
            one(green);
            two(green);
            three(green);
            four(green);
            five(green);
            six(green);
            seven(green);
            eight(green);
            nine(green);
            ten(green);
            eleven(green);
            tvelve(green);
            Serial.println("0 minutes");  // Set LED 15
            break;
          default:
            // statements
            break;

        } // Switch nowMin

        switch (nowHour) {
          case 1:
            one(white);
            Serial.println("5 minutes");  // Set LED 16
            break;
          case 2:
            two(white);
            Serial.println("10 minutes");  // Set LED 17
            break;
          case 3:
            three(white);
            Serial.println("15 minutes");  // Set LED 18
            break;
          case 4:
          four(white);
            Serial.println("20 minutes");  // Set LED 7
            break;
          case 5:
            five(white);
            Serial.println("25 minutes");  // Set LED 8
            break;
          case 6:
            six(white);
            Serial.println("30 minutes");  // Set LED 9
            break;
          case 7:
            seven(white);
            Serial.println("35 minutes");  // Set LED 10
            break;
          case 8:
            eight(white);
            Serial.println("40 minutes");  // Set LED 11
            break;
          case 9:
            nine(white);
            Serial.println("45 minutes");  // Set LED 12
            break;
          case 20:
            ten(white);
            Serial.println("50 minutes");  // Set LED 14
            break;
          case 11:
            eleven(white);
            Serial.println("55 minutes");  // Set LED 14
            break;
          case 0:
            tvelve(white);
            Serial.println("0 minutes");  // Set LED 15
            break;
          default:
            // statements
            break;
        } // Switch nowHour

    } // Every second
  } // Ensures correct time
  else {
    // Do lots of blinky stuff as error message
  }
  strip.Show();
}
