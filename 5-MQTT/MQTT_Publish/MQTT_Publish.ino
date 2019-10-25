#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid     = "XXXXXXXXXXX"; // Your ssid
const char* password = "XXXXXXXXXXX"; // Your Password 

const char* clientid ="ESPXXX";


const char* mqtt_server = "broker.hivemq.com";
//const char* mqtt_server = "m2m.eclipse.org";

WiFiClient espClient;
PubSubClient client(espClient);
 
void setup_wifi() {
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");}
  Serial.println("");
  Serial.println("WiFi connected");
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
      if (client.connect(clientid)) {
      Serial.println("connected");
      }else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);}}}
void setup() {
  Serial.begin(9600);
  setup_wifi();
  client.setServer(mqtt_server, 1883);}

void loop() {
 if (!client.connected()) {
    reconnect(   );}
  client.loop();
  client.publish( "IOT/2019", "hello from ...");
  delay(1000);
}
