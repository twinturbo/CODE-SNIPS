
void debounce(int but) {
  // read the state of the switch/button:
  currentState[but] = digitalRead(but);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch/button changed, due to noise or pressing:
  if (currentState != lastFlickerableState) {
    // reset the debouncing timer
    lastDebounceTime[but] = millis();
    // save the the last flickerable state
    lastFlickerableState[but] = currentState[but];
  }

  if ((millis() - lastDebounceTime[but]) > DEBOUNCE_DELAY) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (lastSteadyState[but] == HIGH && currentState[but] == LOW){
      Serial.print("The button is pressed");
      button_set(but);
      Serial.println( but );
      }
    else if (lastSteadyState[but] == LOW && currentState[but] == HIGH) {
      Serial.print("The button is released");
      Serial.println( but );
      }
    // save the the last steady state
    lastSteadyState[but] = currentState[but];
  }
  Serial.println( but );
}
