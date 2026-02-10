int led = 9;          // PWM 핀
int analogPin = A3;  // 가변저항
int val = 0;         // ADC 값
int brightness = 0;  // PWM 값

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  val = analogRead(analogPin);               // 0~1023
  brightness = map(val, 0, 1023, 0, 255);     // 0~255 변환

  analogWrite(led, brightness);

  Serial.print("ADC: ");
  Serial.print(val);
  Serial.print("  PWM: ");
  Serial.println(brightness);

  delay(10);
}