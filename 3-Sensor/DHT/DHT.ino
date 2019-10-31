#include "DHTesp.h"

#define DHTPIN 5

DHTesp dht;

void setup()
{
  Serial.begin(9600);
  Serial.println();
  dht.setup(DHTPIN, DHTesp::DHT11); 
}

void loop()
{
  delay(dht.getMinimumSamplingPeriod());
  float h = dht.getHumidity();
  float t = dht.getTemperature();

  Serial.print(dht.getStatusString());
  Serial.print("\t");
  Serial.print("Temperature: ");
  Serial.print( t);
  Serial.print("\t");
  Serial.print("Humidity: ");
  Serial.println(h);
  delay(1000);
}
