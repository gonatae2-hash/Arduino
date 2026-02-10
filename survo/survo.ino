int ledPin1 = 12;
int ledPin2 = 8;

#include <Servo.h>

Servo myservo; 

int potpin = A3; 
int val; 

void setup() {
  myservo.attach(9);  
  pinMode(ledPin1, OUTPUT); 
  pinMode(ledPin2, OUTPUT); 
  Serial.begin(9600);
}
void loop()
{
  val = analogRead(potpin);            
  val = map(val, 0, 1023, 180, 0);    
  myservo.write(val);                 
  delay(15);
  if (val<30||val>150)
  {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
  } 
  else
  {
     digitalWrite(ledPin2, HIGH);
     digitalWrite(ledPin1, LOW);
  }                          
Serial.println(val);
}
