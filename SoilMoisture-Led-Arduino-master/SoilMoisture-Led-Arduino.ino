int soilHumidity = 0;
const int sensorPin = A0;

void setup() {
  Serial.begin(9600);
  
  pinMode(3, OUTPUT); // green led
  pinMode(4, OUTPUT); // yellow led
  pinMode(5, OUTPUT); // blue led

}

void loop() {
  soilHumidity = analogRead(sensorPin);
  soilHumidity = map(soilHumidity, 0, 1023, 100, 0);

  Serial.print("Soil Humidity: ");
  Serial.print(soilHumidity);
  Serial.println(" %");

  // The plant has enough water. No watering needed.
  if (soilHumidity >= 40 && soilHumidity <= 60 ) {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);

  // The plant has too dry. Watering needed.
  }else if (soilHumidity < 40) {
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);

  // The plant is overwatered. Wait with watering until the yellow led is shining. 
  }else if (soilHumidity > 60) {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
  }

  delay(1000);
}
