// ---------------------------------------------------------------- //
// Arduino Ultrasoninc Sensor HC-SR04
// Re-writed by Arbi Abdul Jabbaar
// Using Arduino IDE 1.8.7
// Using HC-SR04 Module
// Tested on 17 September 2019
// ---------------------------------------------------------------- //

/*
   YF-S201 Hall Effect Water Flow Meter / Sensor
   http://www.hobbytronics.co.uk/yf-s201-water-flow-meter
   
   Read Water Flow Meter and output reading in litres/hour

*/

volatile int  flow_frequency;  // Measures flow meter pulses
unsigned int  l_hour;          // Calculated litres/hour                      
unsigned char flowmeter = 7;  // Flow Meter Pin number
unsigned long currentTime;
unsigned long cloopTime;

#include <SPI.h>
#include <WiFiNINA.h>
#include <BlynkSimpleWifi.h>

#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "tiFjvOE3bt7NCI0ucEUBdGVPvfrpd9v8";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "G8P3X128";
char pass[] = "yeeyeeland";

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

BlynkTimer timer;

// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V5, distance);
}

void flow ()                  // Interrupt function
{ 
   flow_frequency++;
}

void setup() {
//  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
//  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
//  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
//  Serial.println("with Arduino UNO R3");
//
//  Blynk.begin(auth, ssid, pass);
//  // You can also specify server:
//  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
//  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
//
//  // Setup a function to be called every second
//  timer.setInterval(1000L, myTimerEvent);

  pinMode(flowmeter, INPUT);
  Serial.begin(9600); 
  attachInterrupt(0, flow, RISING); // Setup Interrupt 
                                     // see http://arduino.cc/en/Reference/attachInterrupt
  sei();                            // Enable interrupts  
  currentTime = millis();
  cloopTime = currentTime;

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
//  // Clears the trigPin condition
//  digitalWrite(trigPin, LOW);
//  delayMicroseconds(2);
//  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
//  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(10);
//  digitalWrite(trigPin, LOW);
//  // Reads the echoPin, returns the sound wave travel time in microseconds
//  duration = pulseIn(echoPin, HIGH);
//  // Calculating the distance
//  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
////  // Displays the distance on the Serial Monitor
////  Serial.print("Distance: ");
////  Serial.print(distance);
////  Serial.println(" cm");
//
//  Blynk.run();
//  timer.run();

  currentTime = millis();
  // Every second, calculate and print litres/hour
  if(currentTime >= (cloopTime + 1000)) {     
    cloopTime = currentTime;              // Updates cloopTime
    // Pulse frequency (Hz) = 7.5Q, Q is flow rate in L/min. (Results in +/- 3% range)
    l_hour = (flow_frequency * 60 / 7.5) * 3600; // (Pulse frequency x 60 min) / 7.5Q = flow rate in L/hour 
    flow_frequency = 0;                   // Reset Counter
    Serial.print(l_hour, DEC);            // Print litres/hour
    Serial.println(" L/sec");

    if (l_hour > 0) {
      digitalWrite(LED_BUILTIN, HIGH);
    } else {
      digitalWrite(LED_BUILTIN, LOW);
    }
  }
}
