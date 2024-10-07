/*
 * Arduino Code for Flood Sensor Team 1
 * Written by: Suraj Dhulipalla, Delaney Eisen and Dominic Ritchey
 * 
 * TODO: Add attributions
 */

#include <SPI.h>
#include <WiFiNINA.h>
#include <BlynkSimpleWifi.h>

#define ECHO_PIN 2
#define TRIG_PIN 3

#define BLYNK_PRINT Serial // Comment this out to disable prints and save space

char authToken[] = "tiFjvOE3bt7NCI0ucEUBdGVPvfrpd9v8";
char wifiSsid[] = "G8P3X128";
char wifiPassword[] = "yeeyeeland";

long duration; // Duration of sound wave travel
int distance; // Distance measurement (in cm)

//int distances[100];
//int distancesIndex;

BlynkTimer updateBlynkTimer;

//// Polls ultrasonic sensor for value every 8 seconds and calls ::updateBlynk every 10 minutes (600 seconds)
//void pollAndUpdate() {
//  distances[distancesIndex] = distance;
//
//  if (distancesIndex == 99) {
//    updateBlynk();
//    distancesIndex = 0;
//  } else {
//    distancesIndex++;
//  }
//}

//// Updates Blynk with median sensor value and notifications every 10 minutes (600 seconds)
//void updateBlynk() {
//  // TODO
//}

void pollAndUpdate() {
  Blynk.virtualWrite(V5, distance);
  Blynk.virtualWrite(V6, distance);

  if (distance > 183) {
    Blynk.notify("Flash flooding imminent--evacuate flood area!");
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, OUTPUT);
  
  Serial.begin(9600);

  Blynk.begin(authToken, wifiSsid, wifiPassword);

//  distancesIndex = 0;

//  // Timer calls ::pollAndUpdate every 8 seconds
//  updateBlynkTimer.setInterval(8000L, pollAndUpdate);

  updateBlynkTimer.setInterval(1000L, pollAndUpdate);
}

void loop() {
  // Clears TRIG_PIN condition
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  // Sets TRIG_PIN HIGH (active) for 10 microseconds
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Reads ECHO_PIN and returns the sound wave travel time in microseconds
  duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate distance (speed of sound wave divided by 2 [go and back])
  distance = duration * 0.034 / 2;

  Blynk.run();
  updateBlynkTimer.run();
}
