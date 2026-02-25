#include <WiFi.h>
#include <DHT.h>
#include <HTTPClient.h>

#define DHTPIN 23
#define DHTTYPE DHT11

const char* ssid = "5층";
const char* password = "48864886";

DHT dht(DHTPIN, DHTTYPE);

String host = "http://192.168.0.82:5000"; // 라즈베리파이 IP + Flask 포트

void setup() {
  Serial.begin(115200);
  dht.begin();

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi");
}

void loop() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();

  if (!isnan(t) && !isnan(h)) {
    HTTPClient http;
    String url = host + "/products/arduino?temperature=" + String(t) + "&humidity=" + String(h);
    http.begin(url);
    int httpCode = http.GET();
    if (httpCode > 0) {
      Serial.println("Sent data: " + String(t) + "°C, " + String(h) + "%");
    } else {
      Serial.println("Error sending data");
    }
    http.end();
  } else {
    Serial.println("Failed to read DHT sensor");
  }

  delay(10000); // 10초마다 전송
}