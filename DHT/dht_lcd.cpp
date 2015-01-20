#include "DHT.h"
DHT dht;

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                      // initialize the lcd 
  dht.setup(2); // data pin 2
  // Print a message to the LCD.
  lcd.backlight();
  Serial.begin(9600);
  lcd.print("DHT11 Test!!");
}

void loop()
{
  //delay(dht.getMinimumSamplingPeriod());
  delay(2000);
  
  float humidity = dht.getHumidity();
  float temperature = dht.getTemperature();
  lcd.clear();
  lcd.print("Temp: "); lcd.print(temperature,1);
  lcd.setCursor(0, 1);
  lcd.print(" Hum: "); lcd.print(humidity,1);
}
