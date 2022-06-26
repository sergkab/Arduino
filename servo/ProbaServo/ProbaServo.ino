/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int potpin = A0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

int butt7 = 7;
int led05 = 5;
int led06 = 6;

void setup() {
  pinMode(butt7, INPUT);  
  pinMode(led05, OUTPUT);  
  pinMode(led06, OUTPUT);  
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  //val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  //val = map(val, 0, 1023, 0, 180);     // scale it for use with the servo (value between 0 and 180)
  if (digitalRead(butt7)==LOW) myservo.write(10);                  // sets the servo position according to the scaled value
  digitalWrite(led05, 0);
  digitalWrite(led06, 1);
  delay(3000);                           // waits for the servo to get there
  if (digitalRead(butt7)==LOW) myservo.write(60);                  // sets the servo position according to the scaled value
  digitalWrite(led05, 1);
  digitalWrite(led06, 0);
  delay(3000);                           // waits for the servo to get there
}
