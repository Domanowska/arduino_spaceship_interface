/*
  SPACESHIP INTERFACE
*/

int switchState = 0;

void setup() {
  // Configure digital pins to be either inputs or outputs
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  // Check voltage level on input pin
  // If there is voltage on the pin = HIGH or 1
  // If there is NO voltage on the pin = LOW or 0
  switchState = digitalRead(2);

  // If the button is not pressed
  //    turn the green LED on
  //    turn the red LEDs off
  // If the button is pressed
  //    turn the green LED off
  //    turn the red LEDs on
  if (switchState == LOW){
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    
    // Alternate blinking red lights
    int delay_time = 500;
    
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    delay(delay_time);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(delay_time);

  } else {
    // Blink red lights faster
    int pressed_delay_time = 150;
    
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    delay(pressed_delay_time);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(pressed_delay_time);
  }

}
