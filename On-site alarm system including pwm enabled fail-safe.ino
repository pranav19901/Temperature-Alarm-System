#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int sensorPin = 0;
float tempC;
void setup() {
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(9, INPUT);
  pinMode(6,OUTPUT);
lcd.begin(16, 2);
Serial.begin(9600);
}
void loop() {
tempC = get_temperature(sensorPin);
lcd.setCursor(0,0);
lcd.print("Temperature: "); 
lcd.setCursor(0,1);
lcd.print (tempC, 1); lcd.print(" "); lcd.print("C");
delay(200);
Serial.print(tempC);
Serial.print("  ");
 if (tempC <= 5){
    digitalWrite(8, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(13, LOW);
     for(int i=254; i<255; i++){
       analogWrite(6, i);}
    noTone(9);
   
  }
 else if (tempC > 105){
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(13, HIGH);
    digitalWrite(6,LOW);
    tone(9, 440, 250);
    delay(500);
    
  }
  else {
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(13, LOW);
     for(int i=119; i<120; i++){
       analogWrite(6, i);}
    noTone(9);
  } 
 
}
float get_temperature(int pin) {
float temperature = analogRead(pin);
float voltage = temperature * 5.0;
voltage = voltage / 1024.0;
return ((voltage - 0.5) * 100);
}
