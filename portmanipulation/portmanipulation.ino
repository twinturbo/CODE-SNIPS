void setup() {
  // put your setup code here, to run once:
 pinMode(13,OUTPUT);
 Serial.begin(9600);
 }

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(13,HIGH);
  PORTB = PORTB | B00100000;
  //PINB = bit (5,6);
  Serial.println("LOW b");
  Serial.print("Timer 1 TCCR1A ");
  Serial.println(TCCR1A, HEX);
  delay(1000);
  PORTB = PORTB & B00100000;
  //PINB = bit (5,6);
  //digitalWrite(13,LOW);
  Serial.println("HIGH b");
  delay(1000);
}
