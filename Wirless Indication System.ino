
#include <dht.h>
#include <SoftwareSerial.h>
SoftwareSerial bt(8, 9); // shifting UART to 8 and 9 pins of arduino


#define dht_apin A0 // Analog Pin sensor is connected to
 
dht DHT;
 
int temp;
int hum;

void setup(){
 
  Serial.begin(9600);
  bt.begin(9600); 
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(2000);
}
 
void loop(){
  //Start of Program 
 
    DHT.read11(dht_apin);
    
  hum = DHT.humidity;
  temp = DHT.temperature;
  
    
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");

    
 bt.print(temp); //Message sent to the App inventory
 bt.print(";");
 bt.print(hum); //Message sent to the App inventory
 bt.println(";");
  
    
    delay(1000);

 
}
