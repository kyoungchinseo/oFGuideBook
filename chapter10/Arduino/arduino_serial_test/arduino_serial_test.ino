int SENSOR_ROTATION = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(SENSOR_ROTATION));
  delay(50);
}
