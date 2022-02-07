#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0); 

 void setup(void) {
   u8g2.begin();
   bootmessage();

}

 void loop(void) {
   int xl = 0;
   while ( xl  <= 50 ){
   u8g2.clearBuffer();          // clear the internal memory
   u8g2.setFont(u8g2_font_logisoso28_tr);  // choose a suitable font at https://github.com/olikraus/u8g2/wiki/fntlistall
   u8g2.drawFrame(1,1,127,31);
   u8g2.drawStr(xl,30,"KATE");  // write something to the internal memory
   u8g2.sendBuffer();         // transfer internal memory to the display
   delay(10);
   xl++;
   }
   while ( xl  >= 1 ){
   u8g2.clearBuffer();          // clear the internal memory
   u8g2.setFont(u8g2_font_logisoso28_tr);  // choose a suitable font at https://github.com/olikraus/u8g2/wiki/fntlistall
   u8g2.drawFrame(1,1,127,31);
   u8g2.drawStr(xl,30,"KATE");  // write something to the internal memory
   u8g2.sendBuffer();         // transfer internal memory to the display
   delay(10);
   xl--;
   }
   /*u8g2.clearBuffer();         // clear the internal memory
   u8g2.setFont(u8g2_font_logisoso28_tr);  // choose a suitable font at https://github.com/olikraus/u8g2/wiki/fntlistall
   u8g2.drawStr(6,29,"KATE");  // write something to the internal memory
   u8g2.sendBuffer();         // transfer internal memory to the display
   delay(800);

   u8g2.clearBuffer();         // clear the internal memory
   u8g2.setFont(u8g2_font_logisoso28_tr);  // choose a suitable font at https://github.com/olikraus/u8g2/wiki/fntlistall
   u8g2.drawStr(10,29,"KATE");  // write something to the internal memory
   u8g2.sendBuffer();         // transfer internal memory to the display
   delay(800);

   u8g2.clearBuffer();         // clear the internal memory
   u8g2.setFont(u8g2_font_logisoso28_tr);  // choose a suitable font at https://github.com/olikraus/u8g2/wiki/fntlistall
   u8g2.drawStr(14,29,"KATE");  // write something to the internal memory
   u8g2.sendBuffer();         // transfer internal memory to the display
   delay(800);*/
  }
