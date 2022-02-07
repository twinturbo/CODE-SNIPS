void setup() {
 bootmessage();


}  // put your setup code here, to run once:


void loop() {
     Serial.println("BLANK DUINO");
     //Serial.println("ATMEGA328P(OLD BOOT LOADER)");
     Serial.println(analogRead(A5));
     
  delay(1000);
  
}
