#include "DHT.h"

#define DHTPIN 2     // memilih pin yang akan digunakan
#define DHTTYPE DHT11   // menggunakan device sensor DHT 11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("BlueCore Tech Temperature and Humidity");

  dht.begin();
}

void loop() {
  // Untuk menentukan delaynya memunculkan suhuh dan kelembabannya
  delay(1000);

  
  float kelem = dht.readHumidity();
  // Membaca celcius
  float celci = dht.readTemperature();
  // Membaca fahrenheit (isFahrenheit = true)
  float fahren = dht.readTemperature(true);

  // Mengecek kesalahan
  if (isnan(kelem) || isnan(celci) || isnan(fahren)) {
    Serial.println("Tidak bisa membaca dari sensor!");
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(fahren, kelem);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(celci, kelem, false);

  Serial.println("Humidity: ");
  Serial.print(kelem);
  Serial.println(" %.");
  Serial.println("  ");
  Serial.println("Temperature: ");
  Serial.print(celci);
  Serial.println(" Degree ");
}
