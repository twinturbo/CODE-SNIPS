
int LEDPIN = 3;
boolean blackout = false;
int blckvalue = 0;
int dmxvalue = 0;
const int DEBOUNCE_DELAY = 50;   // the debounce time; increase if the output flickers

// Variables will change:

int lastSteadyState[4] = {HIGH,HIGH,HIGH,HIGH};       // the previous steady state from the input pin
int lastFlickerableState[4] = {HIGH,HIGH,HIGH,HIGH} ;  // the previous flickerable state from the input pin
int currentState[4] = {HIGH,HIGH,HIGH,HIGH};                // the current reading from the input pin
unsigned long lastDebounceTime[4] = {0,0,0,0} ;  // the last time the output pin was toggled


void setup (){
   Serial.begin(9600);
   pinMode(LEDPIN, OUTPUT);
   pinMode(2, INPUT_PULLUP);
   
   //attachInterrupt(digitalPinToInterrupt(2), interrupt, RISING);
}

void loop (){
  //dmx_master,setChannelValue(7, dmxvalue - blckvalue); //////simple for testing
  //delay(500);
  //Serial.print("button ");
  //Serial.println(digitalRead(2));
  debounce(2);
  debounce(3);
  
  Serial.print("Blackout value = ");
  Serial.print(blckvalue);
  Serial.print("---- Blackout state = ");
  Serial.println(blackout);
}
