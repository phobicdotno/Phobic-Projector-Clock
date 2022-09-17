#include <Arduino.h>
#include "19pix.h"      // All the pixel stuff
#include "wifiStuff.h"  // All Wifi-stuff, NTP, OTA


// Variables
int nowSec, lastSec, nowMin, nowHour;
bool secOn, secOff;

void setup(){
  Serial.begin(115000);

  // This resets all the neopixels to an off state
  strip.Begin();
  strip.Show();

  WiFi.mode(WIFI_STA);

  WiFi.begin(ssid, password);

  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }
  timeClient.begin();
  timeClient.setTimeOffset(7200);

    // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
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
    nowHour = timeClient.getHours();

    if (nowSec != lastSec){   // Only do something every second
      if(! secOn){
        secOn = true;
        strip.SetPixelColor(0, blue);
        Serial.println("ON");  // DEBUG
      }
      else {
        secOn = false;
        strip.SetPixelColor(0, hslBlack);
        Serial.println("OFF");  // DEBUG
      }
      lastSec = nowSec;
      Serial.print("... Blink ");  // Blink center light - LED 1
        switch (nowSec) {
          case 10:
            Serial.println("Ten seconds");  // Set LED 2
            break;
          case 20:
            Serial.println("Twenty seconds");  // Set LED 3
            break;
          case 30:
            Serial.println("Thirty seconds");  // Set LED 4
            break;
          case 40:
            Serial.println("Forty seconds");  // Set LED 5
            break;
          case 50:
            Serial.println("Fifty seconds");  // Set LED 6
            break;
          case 0:
            Serial.println("Sixty seconds");  // Set LED 7
            break;
          default:
            // statements
            break;
        }

            switch (nowMin) {
          case 5:
            Serial.println("5 minutes");  // Set LED 8
            break;
          case 10:
            Serial.println("10 minutes");  // Set LED 9
            break;
          case 15:
            Serial.println("15 minutes");  // Set LED 10
            break;
          case 20:
            Serial.println("20 minutes");  // Set LED 11
            break;
          case 25:
            Serial.println("25 minutes");  // Set LED 12
            break;
          case 30:
            Serial.println("30 minutes");  // Set LED 13
            break;
          case 35:
            Serial.println("35 minutes");  // Set LED 14
            break;
          case 40:
            Serial.println("40 minutes");  // Set LED 15
            break;
          case 45:
            Serial.println("45 minutes");  // Set LED 16
            break;
          case 50:
            Serial.println("50 minutes");  // Set LED 17
            break;
          case 55:
            Serial.println("55 minutes");  // Set LED 18
            break;
          case 0:
            Serial.println("0 minutes");  // Set LED 19
            break;
          default:
            // statements
            break;
        } // Switch nowMin
    } // Every second
  } // Ensures correct time
  else {
    // Do lots of blinky stuff as error message
  }
  strip.Show();
}
