/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-ultrasonic-sensor-servo-motor
 */

#include <Servo.h>

// constants won't change
const int TRIG_PIN  = 6;  // Arduino pin connected to Ultrasonic Sensor's TRIG pin
const int ECHO_PIN  = 7;  // Arduino pin connected to Ultrasonic Sensor's ECHO pin
const int SERVO_PIN = 9; // Arduino pin connected to Servo Motor's pin
const int DISTANCE_THRESHOLD = 50; // centimeters

Servo servo; // create servo object to control a servo

// variables will change:
float duration_us, distance_cm;



const int buzzer = 3; 
const int sensor = 4;
 
int state; // 0 close - 1 open switch


void setup() {
  Serial.begin (9600);       // initialize serial port
  pinMode(TRIG_PIN, OUTPUT); // set arduino pin to output mode
  pinMode(ECHO_PIN, INPUT);  // set arduino pin to input mode
  servo.attach(SERVO_PIN);   // attaches the servo on pin 9 to the servo object
  servo.write(0);



  pinMode(sensor, INPUT_PULLUP);
}

void loop() {
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(ECHO_PIN, HIGH);
  // calculate the distance
  distance_cm = 0.100 * duration_us;

  if(distance_cm < DISTANCE_THRESHOLD){
    servo.write(0);  // rotate servo motor to 0 degree
  }
  else{
    
    servo.write(90); // rotate servo motor to 90 degree

  }
  // print the value to Serial Monitor
  Serial.print("distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  delay(500);





  state = digitalRead(sensor);
  
  if (state == HIGH){
    tone(buzzer, 400);
  }
  else{
    noTone(buzzer);
  }
  delay(200);
  
}
