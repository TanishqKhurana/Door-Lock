#include <DHT.h>
#define DHTPIN D2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
void setup() {
Serial.begin(115200);
dht.begin();
}
void loop() {
float temp = dht.readTemperature();
if (isnan(temp)) {
 Serial.println("Failed to read from DHT sensor!");
 return;
}
Serial.print("Temperature: ");
Serial.println(temp);
delay(2000);
}

