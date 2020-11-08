#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int pinBuzzer=8;

void setup()
{
 lcd.begin(20,4);
 Serial.begin(9600);
 lcd.setCursor(0,0);
 lcd.print("Room temperature");
 lcd.setCursor(0,1);
 lcd.print("control System");
 delay(1000);
 pinMode(pinBuzzer,OUTPUT);
 delay(1000);
}
// the loop routine runs over and over again forever:
void loop() 
{
int TEMP_sensor_BYTE=Serial.read();
Serial.print("TEMPERATURESENSOR:");
Serial.println(TEMP_sensor_BYTE);
 lcd.setCursor(0,2);
 lcd.print("Temperature 0C:");
 lcd.setCursor(0,3);
 lcd.print(TEMP_sensor_BYTE);
 if (TEMP_sensor_BYTE > 32) {
    digitalWrite(pinBuzzer, HIGH);    
    delay(200);                       
    digitalWrite(pinBuzzer, LOW);     
    delay(200);                       
    digitalWrite(pinBuzzer, HIGH);    
    delay(200);                       
    digitalWrite(pinBuzzer, LOW);    
    delay(1000);
  }else{
    digitalWrite(pinBuzzer, LOW);
  }
  delay(100);
 }
