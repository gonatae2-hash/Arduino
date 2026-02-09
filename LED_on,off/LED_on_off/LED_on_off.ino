void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH); // LED 켜기 HIGH=(1)
  delay(5000); // 5초 1000ms=1초
  digitalWrite(LED_BUILTIN, LOW); // LED 끄기 LOW =(0)
  delay(1000);
}
