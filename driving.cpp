#include "driving.h"
#include <Arduino.h>

#define PWMB_FRONT_LEFT 4 //Yellow
#define BIN1_FRONT_LEFT 5 //Orange
#define BIN2_FRONT_LEFT 6 //Orange

#define PWMA_FRONT_RIGHT 1 //Yellow
#define AIN1_FRONT_RIGHT 2 //Orange
#define AIN2_FRONT_RIGHT 3 //Orange

#define PWMB_BACK_LEFT 10 //Yellow
#define BIN1_BACK_LEFT 9 //Orange
#define BIN2_BACK_LEFT 8 //Orange

#define PWMA_BACK_RIGHT 13 //Yellow
#define AIN1_BACK_RIGHT 12 //Orange
#define AIN2_BACK_RIGHT 11 //Orange

/* KEY!!
 Forward: AIN1 = HIGH, AIN2 = LOW
 Backward: AIN1 = LOW, AIN2 = HIGH
 Stop: AIN1 = LOW, AIN2 = LOW (Alternatively you can write PWM for each wheel as 0)
 PWM = choose from 0 to 255
 */
 
void driveForward() {
  digitalWrite(AIN1_FRONT_RIGHT, HIGH);
  digitalWrite(AIN2_FRONT_RIGHT, LOW);
  analogWrite(PWMA_FRONT_RIGHT, 50);

  digitalWrite(BIN1_FRONT_LEFT, HIGH);
  digitalWrite(BIN2_FRONT_LEFT, LOW);
  analogWrite(PWMB_FRONT_LEFT, 50);

  digitalWrite(AIN1_BACK_RIGHT, HIGH);
  digitalWrite(AIN2_BACK_RIGHT, LOW);
  analogWrite(PWMA_BACK_RIGHT, 50);

  digitalWrite(BIN1_BACK_LEFT, HIGH);
  digitalWrite(BIN2_BACK_LEFT, LOW);
  analogWrite(PWMB_BACK_LEFT, 50);
}

void driveBackward() {
  digitalWrite(AIN1_FRONT_RIGHT, LOW);
  digitalWrite(AIN2_FRONT_RIGHT, HIGH);
  analogWrite(PWMA_FRONT_RIGHT, 50);

  digitalWrite(BIN1_FRONT_LEFT, LOW);
  digitalWrite(BIN2_FRONT_LEFT, HIGH);
  analogWrite(PWMB_FRONT_LEFT, 50);

  digitalWrite(AIN1_BACK_RIGHT, LOW);
  digitalWrite(AIN2_BACK_RIGHT, HIGH);
  analogWrite(PWMA_BACK_RIGHT, 50);

  digitalWrite(BIN1_BACK_LEFT, LOW);
  digitalWrite(BIN2_BACK_LEFT, HIGH);
  analogWrite(PWMB_BACK_LEFT, 50);  
}

void driveRight(){
  //Left forward
  digitalWrite(BIN1_FRONT_LEFT, HIGH);
  digitalWrite(BIN2_FRONT_LEFT, LOW);
  analogWrite(PWMB_FRONT_LEFT, 100);

  digitalWrite(BIN1_BACK_LEFT, HIGH); 
  digitalWrite(BIN2_BACK_LEFT, LOW);
  analogWrite(PWMB_BACK_LEFT, 100);

  //Right backward
  digitalWrite(AIN1_BACK_RIGHT, LOW);
  digitalWrite(AIN2_BACK_RIGHT, HIGH);
  analogWrite(PWMA_BACK_RIGHT, 100);

  digitalWrite(AIN1_FRONT_RIGHT, LOW);
  digitalWrite(AIN2_FRONT_RIGHT, HIGH);
  analogWrite(PWMA_FRONT_RIGHT, 100);
}

void driveLeft() {
  //Right forward
  digitalWrite(AIN1_FRONT_RIGHT, HIGH);
  digitalWrite(AIN2_FRONT_RIGHT, LOW);
  analogWrite(PWMA_FRONT_RIGHT, 100);

  digitalWrite(AIN1_BACK_RIGHT, HIGH);
  digitalWrite(AIN2_BACK_RIGHT, LOW);
  analogWrite(PWMA_BACK_RIGHT, 100);

  //Left backward
  digitalWrite(BIN1_FRONT_LEFT, LOW);
  digitalWrite(BIN2_FRONT_LEFT, HIGH);
  analogWrite(PWMB_FRONT_LEFT, 100);

  digitalWrite(BIN1_BACK_LEFT, LOW);
  digitalWrite(BIN2_BACK_LEFT, HIGH);
  analogWrite(PWMB_BACK_LEFT, 100);
}

void stopMotors() {
  analogWrite(PWMA_FRONT_RIGHT, 0);
  analogWrite(PWMB_FRONT_LEFT, 0);
  analogWrite(PWMA_BACK_RIGHT, 0);
  analogWrite(PWMB_BACK_LEFT, 0);
}

void setUpMotors() {
  pinMode(PWMA_FRONT_RIGHT, OUTPUT);
  pinMode(AIN1_FRONT_RIGHT, OUTPUT);
  pinMode(AIN2_FRONT_RIGHT, OUTPUT);

  pinMode(PWMB_FRONT_LEFT, OUTPUT);
  pinMode(BIN1_FRONT_LEFT, OUTPUT);
  pinMode(BIN2_FRONT_LEFT, OUTPUT);

  pinMode(PWMA_BACK_RIGHT, OUTPUT);
  pinMode(AIN1_BACK_RIGHT, OUTPUT);
  pinMode(AIN2_BACK_RIGHT, OUTPUT);

  pinMode(PWMB_BACK_LEFT, OUTPUT);
  pinMode(BIN1_BACK_LEFT, OUTPUT);
  pinMode(BIN2_BACK_LEFT, OUTPUT);
}