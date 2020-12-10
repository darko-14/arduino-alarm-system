const int sensorMin = 0;     // minimalna vrednost na senzorot
const int sensorMax = 1024;  // maksimalna vrednost na senzorot
const int ledPin = 13;
const int buzzPin = 11;
void setup() {
  Serial.begin(9600);  // inicijalizacija na seriska komunikacija na 9600 baudi (standard)
  pinMode(ledPin, OUTPUT);
  pinMode(buzzPin, OUTPUT);
}
void loop() {
  int sensorValue = analogRead(A1);
  int range = map(sensorValue, sensorMin, sensorMax, 0, 3);
  switch (range) {
  case 0:    // plamenot e blizu
    Serial.println("Blizok plamen");
    closeFlame();
    break;
  case 1:    // Oddalecen plamen
    Serial.println("Oddalecen plamen");
    distantFlame();
    break;
  case 2:    // Nema plamen
    Serial.println("Nema plamen");
    digitalWrite(buzzPin, LOW);
    digitalWrite(ledPin, LOW);
    break;
  }
  delay(1);  // delay pomegu citanje na vrednost od senzorot
}
// funkcija za oddalecen plamen
void distantFlame(){
  digitalWrite(buzzPin, HIGH);
  tone(buzzPin, 1500);
  delay(200);
  noTone(buzzPin);
  delay(150);
  digitalWrite(ledPin, LOW);
  delay(200);
  digitalWrite(ledPin, HIGH);
  delay(150);
}
//funkcija za blizok plamen
void closeFlame(){
  digitalWrite(buzzPin, HIGH);
  tone(buzzPin, 1500);
  delay(150);
  noTone(buzzPin);
  delay(30);
  digitalWrite(ledPin, HIGH);
  delay(150);
  digitalWrite(ledPin, LOW);
  delay(30);
}
