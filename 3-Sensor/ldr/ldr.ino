#define sensor_pin A0

void setup() 
{
  Serial.begin(9600);
}
void loop() 
{
  int s = analogRead(sensor_pin);   // read the input on analog pin 0:
  Serial.println(s);        // display the values of 
  delay(1000);
}
