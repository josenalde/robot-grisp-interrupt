#include <Arduino.h>
#include "utilsfunc.h"
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C LCD = LiquidCrystal_I2C(0x27, 16, 2);

void controlGrisp(bool state) {
  digitalWrite(GRISP_PIN, state);
}

void initDisplay() {
  LCD.init();
  LCD.clear();
  LCD.backlight();
  LCD.setCursor(0, 0);
  LCD.print("PPGMECA-UFRN");
  LCD.setCursor(0, 1);
  LCD.print("Robot-Grisp");
}

void initRobot() {
    for (int pos = 0; pos <= 180; pos++) { 
      myservo.write(pos);              
      delay(10);                       
    }
    for (int pos = 180; pos >= 0; pos--) { 
      myservo.write(pos);              
      delay(10);                       
    }
    delay(15);
}

void moveRobot(long startPos, long endPos) {
  long diffPos = startPos - endPos;
  
  displayMsg(startPos, endPos);
  controlGrisp(1);
  if (diffPos == 0) { //if robot already in endPos
    myservo.write(0); //do nothing
    delay(10);
  } else if (diffPos < 0) {
      for (int pos = (startPos-1)*BASE_MOTOR_ANGLE; pos <= (startPos-1)*BASE_MOTOR_ANGLE + (-diffPos*BASE_MOTOR_ANGLE); pos += 1) { 
        myservo.write(pos);              
        delay(10);                       
      }
  } else if (diffPos > 0) {
      for (int pos = (startPos-1)*BASE_MOTOR_ANGLE; pos >= (startPos-1)*BASE_MOTOR_ANGLE - diffPos*BASE_MOTOR_ANGLE; pos -= 1) { 
        myservo.write(pos);              
        delay(10);                       
      }
  }
  controlGrisp(0);
  startPoint = endPos;
}

void displayMsg(long s, long e) {
  LCD.clear();
  LCD.setCursor(0, 0);
  LCD.print("Moving...");
  LCD.setCursor(0, 1);
  
  String P = "P";
  P += s;
  String T = "-P";
  P += T;
  P += e;
  LCD.print(P);
}
 