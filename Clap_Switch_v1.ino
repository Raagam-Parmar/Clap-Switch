int ledPin = 13;
int oldVal, newVal, soundValue, clapTime = 0;
int clapVal = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  newVal = digitalRead(A0);
}

void loop() {
  oldVal = newVal;

  soundValue = analogRead(A0);
  Serial.println(soundValue);
//  Serial.print(",");
//  Serial.println(clapTime);
  newVal = soundValue;

  //  if (newVal > oldVal) {
  //    Serial.println("Rising");
  //  } else if (newVal < oldVal) {
  //    Serial.println("Falling");
  //  }

  if (newVal >= 900 and newVal > oldVal and clapVal == 0) {
    clapTime = millis();
    clapVal = 1;
//    digitalWrite(ledPin, HIGH);
//    delay(10);
//    digitalWrite(ledPin, LOW);
  }

  if ((clapVal == 1) and (millis() - clapTime >= 39) and (millis() - clapTime <= 1000) and (newVal >= 900) and (newVal > oldVal)) {
    digitalWrite(ledPin, !digitalRead(ledPin));
    clapVal = 0;
  }

  if (millis() - clapTime >= 1000) {
    clapVal = 0;
  }
}
