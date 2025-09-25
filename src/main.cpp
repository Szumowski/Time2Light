#include <Arduino.h>
#include <WiFi.h>
#include "time.h"

const int gatePin = 26;

const char* ssid = "SSID";
const char* password = "PASSWORD";

const char* ntpServer = "pool.ntp.org";
const long gmtOffset_sec = 3600;
const int daylightOffset_sec = 3600;

void setup(){
  Serial.begin(9600);
  pinMode(gatePin, OUTPUT);
  digitalWrite(gatePin, LOW);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("Wifi connected.");

  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
}

void loop(){
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Time retrieval error");
    delay(1000);
    return;
  }

int hour = timeinfo.tm_hour;
int minute = timeinfo.tm_min;

Serial.printf("Time: %02d:%02d\n", hour, minute);

if(hour >= 17 && hour <24){
  digitalWrite(gatePin, HIGH);
} else {
    digitalWrite(gatePin, LOW);
}

delay(60000);

}


