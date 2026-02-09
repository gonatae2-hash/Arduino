const int ledPin = 13;
const int buttonPin = 2;

int buttonState = 0;

void setup() {
  pinMode(ledPin, OUTPUT);  
  pinMode(buttonPin, INPUT);
  Serial.begin(9600); // 초당 전송되는 데이터의 비트(보드레이트)
}

void loop() {
  buttonState = digitalRead(buttonPin);
  serial.printlnP(buttonState);
  if (buttonState == LOW)
  {
    digitalWrite(ledPin, HIGH);
    delay(500);
  }
  else
  {
    digitalWrite(ledPin, LOW); 
    delay(500);
  }
  //digitalWrite(ledPin, HIGH);
  //delay(1000);

  //digitalWrite(ledPin, LOW);
  //delay(1000);

}
