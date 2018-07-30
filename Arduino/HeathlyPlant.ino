#include <dht.h>
#define DHT_PIN 4 //D4 
#define LIGHT_SENSOR_PIN A1
#define MOISTURE_PIN A2
#define VERIFYCODE 231

void disoplay_temperature(){
  dht DHT;
  DHT.read22(DHT_PIN);
    
  Serial.print("humidity ");
  Serial.print(DHT.humidity/100); // %

  delay(1000);
  Serial.print("temperature ");
  Serial.print(DHT.temperature); // C
  delay(1000);//Wait 5 seconds before accessing sensor again.
}

void display_light(){
  Serial.print("light ");
  Serial.print(analogRead(LIGHT_SENSOR_PIN)/787.0); // Max light value = 787, return the %
  delay(1000);
}

void display_moisture(){
  Serial.print("moisture ");
  Serial.print(analogRead(MOISTURE_PIN)/950.0);
  delay(1000);
}

void notify_sensor_value(){
  disoplay_temperature();
  display_light();
  display_moisture();
}

void setup()
{
   Serial.begin(9600);
}

void loop()
{
  if (Serial.available()){
    if (Serial.read() == VERIFYCODE){
      Serial.print("connected");
      delay(1000);
    }
  }else{
    notify_sensor_value();
  }
}



