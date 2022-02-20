
void encoder_increment(i2cEncoderMiniLib* obj) {
  Serial.print("Increment 1: ");
  E1++;
  Serial.println(Encoder1.readCounterByte());
}

//Callback when the CVAL is decremented
void encoder_decrement(i2cEncoderMiniLib* obj) {
  Serial.print("Decrement 1: ");
  E1--;
  Serial.println(Encoder1.readCounterByte());
}

//Callback when CVAL reach MAX
void encoder_max(i2cEncoderMiniLib* obj) {
  Serial.print("Maximum 1 threshold: ");
  Serial.println(Encoder1.readCounterByte());
}

//Callback when CVAL reach MIN
void encoder_min(i2cEncoderMiniLib* obj) {
  Serial.print("Minimum 1 threshold: ");
  Serial.println(Encoder1.readCounterByte());
}

//Callback when the encoder is pushed
void encoder_push(i2cEncoderMiniLib* obj) {
  Serial.println("Encoder 1 is pushed!");
}

//Callback when the encoder is released
void encoder_released(i2cEncoderMiniLib* obj) {
  Serial.println("Encoder 1 is released");
}

//Callback when the encoder is double pushed
void encoder_double_push(i2cEncoderMiniLib* obj) {
  Serial.println("Encoder is 1 double pushed!");
}

//Callback when the encoder is long pushed
void encoder_long_push(i2cEncoderMiniLib* obj) {
  Serial.println("Encoder is 1 long pushed!");
}
