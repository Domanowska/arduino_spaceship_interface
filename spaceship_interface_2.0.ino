/*
  SPACESHIP INTERFACE
*/

int hyperdriveSwitchState = 0;
int lastHyperdriveSwitchState = 0;

int scannerSwitchState = 0;

void startSystem();
void hyperdrive(int);
void scanner();

void setup() {
  pinMode(2, OUTPUT); // Red LED
  pinMode(3, OUTPUT); // Yellow LED
  pinMode(4, OUTPUT); // Green LED
  pinMode(5, OUTPUT); // Hyperdrive LED
  pinMode(6, OUTPUT); // Hyperdrive LED
  pinMode(9, OUTPUT); // Scanner LED
  pinMode(7, INPUT);  // Hyperdrive Button
  pinMode(8, INPUT);  // Scanner Button

  startSystem();
}

void loop() {
  hyperdriveSwitchState = digitalRead(7);
  scannerSwitchState = digitalRead(8);

  if (lastHyperdriveSwitchState > hyperdriveSwitchState) startSystem();
  
  if (hyperdriveSwitchState == LOW) {
    lastHyperdriveSwitchState = hyperdriveSwitchState;

    if (scannerSwitchState == HIGH) {
      // Make sure Hyperdrive LEDs are off
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      scanner();  
    }

    // Hyperdrive is ready, blink slowly
    hyperdrive(450);
  } else {
    lastHyperdriveSwitchState = hyperdriveSwitchState;

    // Turn off system ready
    digitalWrite(4, LOW);

    // Hyperdrive is engaged, blink fast
    hyperdrive(150);
  }
}

void startSystem() {
  // Make sure Hyperdrive LEDs are off
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);

  delay(500);
  
  // Start up systems
  digitalWrite(2, HIGH);
  delay(1500);
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  delay(1500);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  delay(1500);
}

void hyperdrive(int blink_delay) {
  // Blink: Hyperdrive Ready
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  delay(blink_delay);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  delay(blink_delay);
}

void scanner(){
  for (int x = 0; x < 5; x++){
    digitalWrite(9, HIGH);
    delay(150);
    digitalWrite(9, LOW);
    delay(2000);
  }
  digitalWrite(9, HIGH);
  delay(3000);
  digitalWrite(9, LOW);
}
