#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int count = 0;
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x3F, 20, 4);

void setup() {
  Serial.begin(9600);
  Serial.println(__FILE__);
  lcd.init();
  lcd.backlight();

}




void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("V");
  Serial.println("V");

  delay(150);
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("A");
  Serial.println("A");

  delay(150);
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("L");
  delay(150);
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("K");
  delay(150);
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("I");
  delay(150);
  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print("R");
  delay(150);
  lcd.clear();
  lcd.setCursor(6, 0);
  lcd.print("I");
  delay(150);
  lcd.clear();
  lcd.setCursor(7, 0);
  lcd.print("A");
  delay(150);
  }
