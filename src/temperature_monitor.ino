// LM35 temperature alarm - code-review corrected version.
// Target: Arduino Uno, LM35 Vout -> A0, alarm indicator -> D8 via suitable driver.
// Review only: hardware behavior and sensor-fault thresholds require validation.
const byte SENSOR_PIN = A0;
const byte ALARM_PIN = 8;
const float ADC_REFERENCE_V = 5.0f; // Verify actual analog reference on hardware.
const float TRIP_C = 35.0f;
const float CLEAR_C = 33.0f;
const float MIN_PLAUSIBLE_C = 0.0f;
const float MAX_PLAUSIBLE_C = 100.0f;
bool alarmActive = false;
void setup() {
  Serial.begin(9600);
  pinMode(ALARM_PIN, OUTPUT);
  digitalWrite(ALARM_PIN, LOW);
}
void loop() {
  const int raw = analogRead(SENSOR_PIN);
  const float voltage = raw * (ADC_REFERENCE_V / 1023.0f);
  const float tempC = voltage * 100.0f; // LM35 nominal 10 mV/C.
  // Plausibility alone cannot reliably detect a disconnected LM35.
  const bool plausible = tempC >= MIN_PLAUSIBLE_C && tempC <= MAX_PLAUSIBLE_C;
  if (!plausible) {
    alarmActive = false;
    digitalWrite(ALARM_PIN, LOW);
    Serial.println("SENSOR_READING_OUT_OF_RANGE");
  } else {
    if (!alarmActive && tempC >= TRIP_C) alarmActive = true;
    if (alarmActive && tempC <= CLEAR_C) alarmActive = false;
    digitalWrite(ALARM_PIN, alarmActive ? HIGH : LOW);
    Serial.print("Temperature C: "); Serial.println(tempC, 2);
  }
  delay(1000);
}
