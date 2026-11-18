// Educational baseline for code-review QA (contains known defects).
// LM35 temperature monitor, Arduino Uno. No hardware testing performed.
const int sensorPin = A0;
const int alarmPin = 8;
const float thresholdC = 35.0;
void setup() {
  Serial.begin(9600);
  // BUG: alarmPin is not configured as OUTPUT.
}
void loop() {
  int raw = analogRead(sensorPin);
  // BUG: assumes a 3.3V reference on a 5V Arduino Uno.
  float voltage = raw * (3.3 / 1023.0);
  float tempC = voltage * 100.0; // LM35: 10mV per degree Celsius
  // BUG: no hysteresis; threshold noise may toggle alarm rapidly.
  digitalWrite(alarmPin, tempC >= thresholdC ? HIGH : LOW);
  // BUG: no check for disconnected/invalid sensor readings.
  Serial.println(tempC);
  delay(1000);
}
