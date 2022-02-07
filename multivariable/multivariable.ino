#define SwitchN 5
int Switch[SwitchN] = {0,2,1,1,1};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print(" Switch 0 is ");
  Serial.println(Switch[0]);
  Serial.print(" Switch 1 is ");
  Serial.println(Switch[1]);
  Serial.print(" Switch 2 is ");
  Serial.println(Switch[2]);
  Serial.print(" Switch 3 is ");
  Serial.println(Switch[3]);
  Serial.print(" Switch 4 is ");
  Serial.println(Switch[4]);
  delay(5000);
  Switch[0] = 10;
  Switch[1] = 11;
  Switch[2] = 12;
  Switch[3] = 13;
  Switch[4] = 14;
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(500);
  Serial.print(" Switch 0 is ");
  Serial.println(Switch[0]);
  Serial.print(" Switch 1 is ");
  Serial.println(Switch[1]);
  Serial.print(" Switch 2 is ");
  Serial.println(Switch[2]);
  Serial.print(" Switch 3 is ");
  Serial.println(Switch[3]);
  Serial.print(" Switch 4 is ");
  Serial.println(Switch[4]);
}
