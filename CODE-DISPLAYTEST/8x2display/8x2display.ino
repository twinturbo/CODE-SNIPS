#include <Wire.h>
#define TCAADDR 0x70
#include <U8g2lib.h>
/*********************Programmed by SyntheMafia(06_06_15018)**********************/
int xl ;

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0); 

#include <SimpleTimer.h>
#


SimpleTimer timer;
int count = 0;

void setup() {
  for (uint8_t t=0; t<8; t++) {
      TCA9548A(t);
      u8g2.begin();
  }
   
  Serial.begin(9600);
  Serial.println(__FILE__);

}

void TCA9548A(uint8_t bus)
{
  Wire.beginTransmission(0x70);  // TCA9548A address is 0x70
  Wire.write(1 << bus);          // send byte to select bus
  Wire.endTransmission();
  Serial.println(bus);
}


void loop() {
   TCA9548A(1);
   xl = 0;
   while ( xl  <= 50 ){
    Serial.println(xl); 
   u8g2.clearBuffer();          // clear the internal memory
   u8g2.setFont(u8g2_font_logisoso28_tr);  // choose a suitable font at https://github.com/olikraus/u8g2/wiki/fntlistall
   u8g2.drawFrame(1,1,127,31);
   u8g2.drawStr(xl,30,"KATE");  // write something to the internal memory
   u8g2.sendBuffer();         // transfer internal memory to the display
   delay(5);
   xl++;
   }
   while ( xl  >= 1 ){
   u8g2.clearBuffer();          // clear the internal memory
   u8g2.setFont(u8g2_font_logisoso28_tr);  // choose a suitable font at https://github.com/olikraus/u8g2/wiki/fntlistall
   u8g2.drawFrame(1,1,127,31);
   u8g2.drawStr(xl,30,"KATE");  // write something to the internal memory
   u8g2.sendBuffer();         // transfer internal memory to the display
   delay(5);
   xl--;
   }
   
  Serial.println("next");  
  TCA9548A(2);
  xl = 0;
   while ( xl  <= 50 ){
   Serial.println(xl);
   u8g2.clearBuffer();          // clear the internal memory
   u8g2.setFont(u8g2_font_logisoso28_tr);  // choose a suitable font at https://github.com/olikraus/u8g2/wiki/fntlistall
   u8g2.drawFrame(1,1,127,31);
   u8g2.drawStr(xl,30,"KATE");  // write something to the internal memory
   u8g2.sendBuffer();         // transfer internal memory to the display
   delay(5);
   xl++;
   }
   while ( xl  >= 1 ){
   u8g2.clearBuffer();          // clear the internal memory
   u8g2.setFont(u8g2_font_logisoso28_tr);  // choose a suitable font at https://github.com/olikraus/u8g2/wiki/fntlistall
   u8g2.drawFrame(1,1,127,31);
   u8g2.drawStr(xl,30,"KATE");  // write something to the internal memory
   u8g2.sendBuffer();         // transfer internal memory to the display
   delay(5);
   xl--;
   }
  
  delay(500);  
  
 
  
  /*TCA9548A(2);
  lcd.setCursor(0, 0);
  lcd.clear();
  lcd.print("TWO"); 
  Serial.println("TWO");
  delay(1500); 
  TCA9548A(3);
  lcd.setCursor(0, 0);
  lcd.clear();
  lcd.print("THREE"); 
  Serial.println("THREE");
  delay(1500); 
  TCA9548A(1);
  lcd.setCursor(0, 0);
  lcd.clear();
  lcd.print("ONE ONE"); 
  Serial.println("ONE");
  delay(1500);  
  TCA9548A(2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("TWO TWO"); 
  Serial.println("TWO");
  delay(1500); 
  TCA9548A(3);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("THREE"); 
  Serial.println("THREE THREE");
  delay(1500); 
*/  
  
  
  
  }
