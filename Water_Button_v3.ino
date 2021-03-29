// constants won't change. They're used here to set pin numbers:
const int buttonPin1 = 0;     // the number of the pushbutton pin
const int buttonPin2 = 1;
const int buttonPin3 = 2;
const int buttonPin4 = 3;
const int buttonPin5 = 4;
const int buttonPin6 = 5;
const int buttonPin7 = 6;
const int ledPin1 =  7;    // the number of the LED pin
const int ledPin2 =  8;
const int ledPin3 =  9;
const int ledPin4 =  10;
const int ledPin5 =  11;
const int ledPin6 =  12;
const int ledPin7 =  13;

// variables will change:
int buttonState1 = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
int buttonState5 = 0;
int buttonState6 = 0;
int buttonState7 = 0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
  pinMode(ledPin7, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(buttonPin5, INPUT);
  pinMode(buttonPin6, INPUT);
  pinMode(buttonPin7, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
  buttonState5 = digitalRead(buttonPin5);
  buttonState6 = digitalRead(buttonPin6);
  buttonState7 = digitalRead(buttonPin7);


  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState1 == LOW) {
    // turn LED on:
    digitalWrite(ledPin1, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin1, LOW);
  }
  if (buttonState2 == LOW) {
    // turn LED on:
    digitalWrite(ledPin2, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin2, LOW);
  }
  if (buttonState3 == HIGH) {
    // turn LED on:
    digitalWrite(ledPin3, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin3, LOW);
  }
  if (buttonState4 == HIGH) {
    // turn LED on:
    digitalWrite(ledPin4, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin4, LOW);
  }
  if (buttonState5 == HIGH) {
    // turn LED on:
    digitalWrite(ledPin5, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin5, LOW);
  }
  if (buttonState6 == HIGH) {
    // turn LED on:
    digitalWrite(ledPin6, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin6, LOW);
  }
  if (buttonState7 == HIGH) {
    // turn LED on:
    digitalWrite(ledPin7, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin7, LOW);
  }
}
