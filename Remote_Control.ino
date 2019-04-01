#include <IRremote.h>
IRsend irsend;

const int buttonPin1 = 12;
const int buttonPin2 = 11;
const int buttonPin3 = 10;

int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;

void setup(){
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  
     if(buttonState1 == HIGH) {
      irsend.sendRC5(0x12, 8);
      delay(500);
      Serial.println("Standby");
    }
    else if (buttonState2 == HIGH) {
      irsend.sendRC5(0x16, 8);
      delay(500);
      Serial.println("Volume Increase");
    }
    else if (buttonState3 == HIGH) {
      irsend.sendRC5(0x17, 8);
      delay(500);
      Serial.println("Volume Decrease");
    }
    else {
      pinMode(3, OUTPUT);
      digitalWrite(3, LOW);
    }
}
