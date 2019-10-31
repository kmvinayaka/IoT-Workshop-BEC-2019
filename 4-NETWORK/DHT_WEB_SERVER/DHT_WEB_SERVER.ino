#include <ESP8266WiFi.h>
#include "DHTesp.h"

#define DHTPIN 5

DHTesp dht;

const char* ssid     = "xxxxxxxx";                               // Your ssid
const char* password = "xxxxxxxx";                            // Your Password


WiFiServer server(80);


void setup() {
 dht.setup(DHTPIN, DHTesp::DHT11); 
Serial.begin(9600);
delay(10);
Serial.println();

// Connect to WiFi network
WiFi.mode(WIFI_STA);
Serial.println();
Serial.print("Connecting to ");
Serial.println(ssid);

WiFi.begin(ssid, password);

while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}
Serial.println("");
Serial.println("WiFi connected");

// Start the server
server.begin();
Serial.println("Server started");

// Print the IP address
Serial.println(WiFi.localIP());
}

void loop() {

delay(dht.getMinimumSamplingPeriod());
float humidityTemp = dht.getHumidity();
float celsiusTemp = dht.getTemperature();
float fahrenheitTemp=dht.toFahrenheit(celsiusTemp);

WiFiClient client = server.available();
client.println("HTTP/1.1 200 OK");
client.println("Content-Type: text/html");
client.println("Connection: close");  // the connection will be closed after completion of the response
client.println();
client.println("<!DOCTYPE html>");
client.println("<H1>ESP8266 Temperature & Humidity DHT11 Sensor</H1>");
client.println("</head>\n<body>");
client.println("<H2>ESP8266 & DHT11 Sensor</H2>");
client.println("<H3>Humidity / Temperature</H3>");
client.println("<pre>");
client.print("Humidity (%)       : ");
client.println((float)humidityTemp, 2);
client.print("Temperature (°C)  : ");
client.println((float)celsiusTemp, 2);
client.print("Temperature (°F)  : ");
client.println(fahrenheitTemp, 2);
client.println("</pre>");
client.print("</body>\n</html>");
delay(1000); //delay for reread


}
