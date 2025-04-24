#include <Arduino.h>
#include <ESP32Servo.h>
#include "utilsfunc.h"

long startPoint, endPoint;
volatile byte btnMask = RESET;
Servo myservo;
//p1: 00000001 1
//p2: 00000010 2
//p3: 00000011 3
//volatile unsigned long timestamp_last_button = micros();

void IRAM_ATTR isrP1() {
  btnMask = RESET;
  //if ( (micros() - timestamp_last_button) >= TEMPO_DEBOUNCE ) {
    btnMask = 0x01;
    //timestamp_last_button = micros();
  }
//}
void IRAM_ATTR isrP2() {
  btnMask = RESET;
  //if ( (micros() - timestamp_last_button) >= TEMPO_DEBOUNCE ) {
    btnMask = 0x02;
    //   timestamp_last_button = micros();
  }
//}
void IRAM_ATTR isrP3() {
  btnMask = RESET;
  //if ( (micros() - timestamp_last_button) >= TEMPO_DEBOUNCE ) {
    btnMask = 0x03;
  //  timestamp_last_button = micros();
  }
//}

void setup() {
  Serial.begin(115200);
  pinMode(BTN_P1, INPUT_PULLUP);
  pinMode(BTN_P2, INPUT_PULLUP);
  pinMode(BTN_P3, INPUT_PULLUP);
  pinMode(GRISP_PIN, OUTPUT);
  pinMode(14, OUTPUT);
  randomSeed(analogRead(35));
  myservo.attach(14);   
  attachInterrupt(digitalPinToInterrupt(BTN_P1), isrP1, FALLING);
  attachInterrupt(digitalPinToInterrupt(BTN_P2), isrP2, FALLING);
  attachInterrupt(digitalPinToInterrupt(BTN_P3), isrP3, FALLING);

  initDisplay();
  //close grisp
  controlGrisp(1);
  //set random initial position
  endPoint = random(1,4);
  startPoint = 1;
  
  initRobot();
  controlGrisp(0);
  moveRobot(startPoint,endPoint);
}
 
void loop() {
  
  switch(btnMask) {
    case 1: {
      moveRobot(startPoint, btnMask);
      btnMask = RESET;
      break;
    }
    case 2: {
      moveRobot(startPoint, btnMask);
      btnMask = RESET;
      break;
    }
    case 3: {
      moveRobot(startPoint, btnMask);
      btnMask = RESET;
      break;
    } default: Serial.println("...");
  }

  delay(400);
}

