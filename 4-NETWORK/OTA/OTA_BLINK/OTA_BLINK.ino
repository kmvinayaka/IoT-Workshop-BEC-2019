#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

const char* ssid     = "XXXXXXXXX";
const char* password = "XXXXXXXXX";


void setup() {
 Serial.begin(9600);
 Serial.println("Booting");
 WiFi.mode(WIFI_STA);
 WiFi.begin(ssid, password);
 while (WiFi.waitForConnectResult() != WL_CONNECTED) {
 Serial.println("Connection Failed! Rebooting...");
 delay(5000);
 ESP.restart();
 }


ArduinoOTA.onStart([]() {
 Serial.println("Start");
 });
 ArduinoOTA.onEnd([]() {
 Serial.println("\nEnd");
 });
 ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
 Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
 });
 ArduinoOTA.onError([](ota_error_t error) {
 Serial.printf("Error[%u]: ", error);
 if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
 else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
 else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
 else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
 else if (error == OTA_END_ERROR) Serial.println("End Failed");
 });
 ArduinoOTA.begin();
 Serial.println("Ready");
 Serial.print("IPess: ");
 Serial.println(WiFi.localIP());
 pinMode(2, OUTPUT);
}

void loop() {
 ArduinoOTA.handle();
 digitalWrite(2, HIGH); // turn the LED on (HIGH is the voltage level)
 delay(500); // wait for 2 second
 digitalWrite(2, LOW); // turn the LED off by making the voltage LOW
 delay(500); 
}
