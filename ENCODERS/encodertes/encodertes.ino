#include <Wire.h>
#include <i2cencoderMiniLib.h>

/*This is a basic example for using the I2C encoder mini
  The counter is set to work between +10 to -10, at every encoder click the counter value is printed on the terminal.
  It's also printet when the push button is pressed, or released or double pushed.
  The callback are used instead of the switch case

  Connections with Arduino UNO:
  - -> GND
  + -> 5V
  SDA -> A4
  SCL -> A5
  INT -> A3
*/

int E1 = 0;
int E2 = 0;

const int IntPin = A3; /* Definition of the interrupt pin. You can change according to your board */
//Class initialization with the I2C addresses
//i2cencoderMiniLib encoder_1(0x20); /* A0 is soldered */
//i2cencoderMiniLib encoder_2(0x21);
#define encoder_N 2
i2cencoderMiniLib encoder[encoder_N] = { i2cencoderMiniLib(0x20), i2cencoderMiniLib(0x21)};



//Callback when the CVAL is incremented

void setup(void) {
  pinMode(IntPin, INPUT);
  Wire.begin();
  Serial.begin(115200);
  Serial.println("**** I2C encoder Mini basic example ****");
  encoder1.reset();
  encoder2.reset();
  encoder1.begin(i2cencoderMiniLib::WRAP_DISABLE
                | i2cencoderMiniLib::DIRE_LEFT | i2cencoderMiniLib::IPUP_ENABLE
                | i2cencoderMiniLib::RMOD_X1 );
  encoder2.begin(i2cencoderMiniLib::WRAP_DISABLE
                | i2cencoderMiniLib::DIRE_LEFT | i2cencoderMiniLib::IPUP_ENABLE
                | i2cencoderMiniLib::RMOD_X1 );

  encoder1.writeCounter((int32_t) 0); /* Reset the counter value */
  encoder1.writeMax((int32_t) 20); /* Set the maximum threshold*/
  encoder1.writeMin((int32_t) - 20); /* Set the minimum threshold */
  encoder1.writeStep((int32_t) 1); /* Set the step to 1*/
  encoder1.writeDoublePushPeriod(50); /*Set a period for the double push of 500ms */
  encoder2.writeCounter((int32_t) 0); /* Reset the counter value */
  encoder2.writeMax((int32_t) 20); /* Set the maximum threshold*/
  encoder2.writeMin((int32_t) - 20); /* Set the minimum threshold */
  encoder2.writeStep((int32_t) 1); /* Set the step to 1*/
  encoder2.writeDoublePushPeriod(50); /*Set a period for the double push of 500ms */


  // Definition of the events
  encoder1.onIncrement = encoder_increment;
  encoder1.onDecrement = encoder_decrement;
  encoder1.onMax = encoder_max;
  encoder1.onMin = encoder_min;
  encoder1.onButtonPush = encoder_push;
  encoder1.onButtonRelease = encoder_released;
  encoder1.onButtonDoublePush = encoder_double_push;
  encoder1.onButtonLongPush = encoder_long_push;

  encoder2.onIncrement = encoder_increment2;
  encoder2.onDecrement = encoder_decrement2;
  encoder2.onMax = encoder_max2;
  encoder2.onMin = encoder_min2;
  encoder2.onButtonPush = encoder_push2;
  encoder2.onButtonRelease = encoder_released2;
  encoder2.onButtonDoublePush = encoder_double_push2;
  encoder2.onButtonLongPush = encoder_long_push2;

  /* Enable the I2C encoder V2 interrupts according to the previus attached callback */
  encoder1.autoconfigInterrupt();
  encoder2.autoconfigInterrupt();

}

void loop() {
  Serial.print("E1 = ");
  Serial.println(E1);
  if (digitalRead(IntPin) == LOW) {
    /* Check the status of the encoder and call the callback */
    encoder_1.updateStatus();
    encoder_2.updateStatus();
  }
}
