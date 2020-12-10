const int sensorMin = 0;     // minimalna vrednost na senzorot
const int sensorMax = 1024;  // maksimalna vrednost na senzorot
const int ledPin = 13;
const int buzzPin = 11;
int onTime;
int offTime;

void setup() {
  Serial.begin(9600);  // inicijalizacija na seriska komunikacija na 9600 baudi (standard)
  pinMode(ledPin, OUTPUT);
  pinMode(buzzPin, OUTPUT);
}
void loop() {
  int sensorValue = analogRead(A4);
  
  int range = map(sensorValue, sensorMin, sensorMax, 0, 3);

  
  switch (range) {
  case 0:    // plamenot e blizu
    Serial.println("Blizok plamen");
    alarmSound(100,50);
    break;
  case 1:    // Oddalecen plamen
    Serial.println("Oddalecen plamen");
    alarmSound(150,100);
    break;
  case 2:    // Nema plamen
    Serial.println("Nema plamen");
    digitalWrite(buzzPin, LOW);
    digitalWrite(ledPin, LOW);
    break;
  }
  delay(1);  // delay pomegu citanje na vrednost od senzorot
}
int alarmSound (onTime,offTime) {
  digitalWrite(buzzPin, HIGH);
  tone(buzzPin, 1500);
  delay(onTime);
  noTone(buzzPin);
  delay(offTime);
  digitalWrite(ledPin, LOW);
  delay(offTime);
  digitalWrite(ledPin, HIGH);
  delay(onTime);
}
