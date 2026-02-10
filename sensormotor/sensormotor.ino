
const int trigPin = 9;
const int echoPin = 10;

long duration;
int distance;
int AA = 6; 
int AB = 7; 

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600); 
  pinMode(AA, OUTPUT);
  pinMode(AB, OUTPUT);
}
void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);
  if(distance>15)
  {
    digitalWrite(AA, HIGH);
    digitalWrite(AB, LOW);
    delay(1000);
  }
  else
  {
    digitalWrite(AA, LOW);
    digitalWrite(AB, LOW);
  }
}