#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup()
{
 lcd.begin(20,4);
 Serial.begin(9600);
 lcd.setCursor(0,0);
 lcd.print("Room temperature");
 lcd.setCursor(0,1);
 lcd.print("control System");
 delay(1000);
}
void loop() 
{
 int TEMP_sensor_BYTE_LEVEL = analogRead(A0);
 int TEMP_sensor_BYTE=TEMP_sensor_BYTE_LEVEL/2;
 lcd.setCursor(0,2);
 lcd.print("Temperature 0C:");
 lcd.setCursor(0,3);
 lcd.print(TEMP_sensor_BYTE);
 Serial.write(TEMP_sensor_BYTE);
 delay(100);   
}
