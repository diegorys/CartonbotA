#include <Servo.h>

/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 11;
int ldr = A5;
int buzz = 15;

Servo servoDcho;
Servo servoIzdo;

int THRESHOLD = 30;

int luz = 0;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
  pinMode(buzz, OUTPUT);
  Serial.begin(9600);
  servoDcho.attach(3);
  servoIzdo.attach(5);
  servoDcho.write(1);
  servoIzdo.write(1);
}

// the loop routine runs over and over again forever:
void loop() {
  luz = analogRead(ldr);
  Serial.println(luz);
  if(luz > 800) luz = 800;
  testOjos();
  testBrazos();
  testBoca();
  delay(100);
}

void testOjos(){
  int brillo = luz > THRESHOLD? LOW : HIGH;
  digitalWrite(led, brillo);
  delay(100);
}

void testBoca(){
  int tono = map(luz, 0, 800, 500, 2000);
  if(luz < 10){
    tone(buzz, tono, 100);
    delay(100);
    noTone(buzz);
  }
}

void testBrazos(){
  int giro = map(luz, 0, 800, 1, 179);
  servoDcho.write(giro);
  servoIzdo.write(giro);
  //delay(2000);
}
