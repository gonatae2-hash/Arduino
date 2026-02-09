const int ledPin1 = 12;
const int ledPin2 = 8;
const int buttonPin = 2;
int sensorPin = A0;
int sensorValue = 0;
int buttonState = 0;
int lastButtonState = LOW;

void setup() {
  pinMode(ledPin1, OUTPUT); 
  pinMode(ledPin2, OUTPUT); 
  pinMode(buttonPin, INPUT);

  Serial.begin(9600); // 초당 전송되는 데이터의 비트(보드레이트)
}

void loop() {
  buttonState = digitalRead(buttonPin);
  //Serial.println(buttonState);
  sensorValue = analogRead(sensorPin);
  if (buttonState == HIGH)  // 버튼 눌렀을 때 LED1 켜짐
  {
    digitalWrite(ledPin1, HIGH);
    delay(sensorValue);
    digitalWrite(ledPin1, LOW);  
    digitalWrite(ledPin2, LOW);
    delay(100);
  }
  else
  {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
    delay(sensorValue);
    digitalWrite(ledPin2, LOW);
    delay(100);
  }
  if (buttonState != lastButtonState)
  {
    if (buttonState == HIGH)
    {
      Serial.println("LED1 ON");
      Serial.println("LED2 OFF");
    } 
    else 
    {
      Serial.println("LED2 ON");
      Serial.println("LED1 OFF");
    }
    Serial.println("===========");
  }
  lastButtonState = buttonState;
  //digitalWrite(ledPin, HIGH);
  //delay(1000);

  //digitalWrite(ledPin, LOW);
  //delay(1000);

}
