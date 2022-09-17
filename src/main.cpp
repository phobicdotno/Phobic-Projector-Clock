#include <Arduino.h>
#include <NTPClient.h>
// change next line to use with another board/shield
//#include <ESP8266WiFi.h>
//#include <WiFi.h> // for WiFi shield
//#include <WiFi101.h> // for WiFi 101 shield or MKR1000
#include <WiFiUdp.h>


 /*
  AsyncElegantOTA Demo Example - This example will work for both ESP8266 & ESP32 microcontrollers.
  -----
  Author: Ayush Sharma ( https://github.com/ayushsharma82 )
  
  Important Notice: Star the repository on Github if you like the library! :)
  Repository Link: https://github.com/ayushsharma82/AsyncElegantOTA
*/

#if defined(ESP8266)
  #include <ESP8266WiFi.h>
  #include <ESPAsyncTCP.h>
#elif defined(ESP32)
  #include <WiFi.h>
  #include <AsyncTCP.h>
#endif

#include <ESPAsyncWebServer.h>
#include <AsyncElegantOTA.h>

AsyncWebServer server(80);
const char *ssid     = "COVID-21 6G Test Replicator 2.4G";
const char *password = "bdxCugDF";
 
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

// Variables
int nowSec, lastSec, nowMin, nowHour;

void setup(){
  Serial.begin(115000);
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
      lastSec = nowSec;
      Serial.print("... Blink ");  // Blink center light
      Serial.print(nowMin%20);  // Blink LED 1
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
            Serial.println("Five minutes");  // Set LED 8
            break;
          case 10:
            Serial.println("Ten minutes");  // Set LED 9
            break;
          case 15:
            Serial.println("Ten minutes");  // Set LED 10
            break;
          case 20:
            Serial.println("Twenty minutes");  // Set LED 11
            break;
          case 25:
            Serial.println("Twenty minutes");  // Set LED 12
            break;
          case 30:
            Serial.println("Thirty minutes");  // Set LED 13
            break;
          case 35:
            Serial.println("Thirty minutes");  // Set LED 14
            break;
          case 40:
            Serial.println("Forty minutes");  // Set LED 15
            break;
          case 45:
            Serial.println("Forty minutes");  // Set LED 16
            break;
          case 50:
            Serial.println("Fifty minutes");  // Set LED 17
            break;
          case 55:
            Serial.println("Fifty minutes");  // Set LED 18
            break;
          case 0:
            Serial.println("Sixty minutes");  // Set LED 19
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
  timeClient.getHours();
}

