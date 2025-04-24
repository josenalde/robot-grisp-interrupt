#ifndef UTILSFUNC_H
#define UTILSFUNC_H


//by Josenalde Oliveira 2025.april
#define BTN_P1 19
#define BTN_P2 18
#define BTN_P3 12
#define GRISP_PIN 4
#define TIME_TO_POINT 1500
#define RESET 0x00
#define TEMPO_DEBOUNCE 100 * 1000 //ms
#define BASE_MOTOR_ANGLE 90
#include <ESP32Servo.h>
extern long startPoint;
extern long endPoint;
extern Servo myservo;


// functions signatures
void moveRobot(long startPos, long endPos);
void initDisplay();
void displayMsg(long s, long e);
void initRobot(); //initial movement to stabilize servo
void controlGrisp(bool state);

#endif