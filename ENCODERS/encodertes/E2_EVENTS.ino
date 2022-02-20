
void encoder_increment2(i2cEncoderMiniLib* obj) {
  Serial.print("Increment 2: ");
  Serial.println(Encoder2.readCounterByte());
}

//Callback when the CVAL is decremented
void encoder_decrement2(i2cEncoderMiniLib* obj) {
  Serial.print("Decrement 2: ");
  Serial.println(Encoder2.readCounterByte());
}

//Callback when CVAL reach MAX
void encoder_max2(i2cEncoderMiniLib* obj) {
  Serial.print("Maximum 2 threshold: ");
  Serial.println(Encoder2.readCounterByte());
}

//Callback when CVAL reach MIN
void encoder_min2(i2cEncoderMiniLib* obj) {
  Serial.print("Minimum 2 threshold: ");
  Serial.println(Encoder2.readCounterByte());
}

//Callback when the encoder is pushed
void encoder_push2(i2cEncoderMiniLib* obj) {
  Serial.println("Encoder 2 is pushed!");
}

//Callback when the encoder is released
void encoder_released2(i2cEncoderMiniLib* obj) {
  Serial.println("Encoder 2 is released");
}

//Callback when the encoder is double pushed
void encoder_double_push2(i2cEncoderMiniLib* obj) {
  Serial.println("Encoder is 2 double pushed!");
}

//Callback when the encoder is long pushed
void encoder_long_push2(i2cEncoderMiniLib* obj) {
  Serial.println("Encoder is 2 long pushed!");
}
