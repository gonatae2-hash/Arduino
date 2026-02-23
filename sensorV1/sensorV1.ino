/*
DHT11

This example reads a DHT11 sensor hooked up on pin D7. Reads both
temperature and humidity and sends it to the Serial port


created in Feb 2019 by D. Cuartielles
based on work by F. Vanzati (2011) and M. Loglio (2013)

This example code is in the public domain.
*/

// include the EduIntro library
#include <EduIntro.h>

DHT11 dht11(A0);  // creating the object sensor on pin 'A0'

int C;   // 섭씨 온도
int H;   // 습도

void setup()
{
  // initialize serial communications at 9600 bps
  Serial.begin(9600);
}

void loop()
{
  dht11.update();

  C = dht11.readCelsius();     	// Reading the temperature in Celsius degrees and store in the C variable
  H = dht11.readHumidity();     // Reading the humidity index

  // Print the collected data in a row on the Serial Monitor
  
  Serial.print(H);
  Serial.print(",");
  Serial.println(C);


  delay(2000);                // Wait one second before get another temperature reading
}
