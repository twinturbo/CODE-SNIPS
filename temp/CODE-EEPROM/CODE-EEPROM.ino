#include <EEPROM.h>





int address = 0;
int out = 0;
int inp = 0;
//byte two = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(2000);
  Serial.println("Name pre -load =");
  Serial.println(inp);
  delay(2000);
  Serial.println("Name post -load =");
  inp = (EEPROM.read(0 + 1) << 8);
  inp |= EEPROM.read(0);
  Serial.println("read");
  Serial.println(inp);
   delay(5000);
}

void loop() {
  Writelong();
  Readlong();
}

void Readlong(){
  //two = EEPROM.read(address);
  //one = EEPROM.read(address + 1);
  inp = (EEPROM.read(0 + 1) << 8);
  inp |= EEPROM.read(0);
  Serial.println("read");
  Serial.println(inp);
  Serial.println("done");
  delay(1000);
  
  
  
}

void Writelong() {
  //byte two = (0xF0);
  //byte one = (0xE0);
  out = 500; 
  EEPROM.write(0, out);
  EEPROM.write(0 + 1, out >> 8);
}
