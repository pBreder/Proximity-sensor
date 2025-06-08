int trigPin = 3;
int echoPin = 2;
int leds[] = {10, 9, 6, 5, 4};

void setup()
{
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  for (int i = 0; i < 5; i++) {
    pinMode(leds[i], OUTPUT);
  }
  digitalWrite(trigPin, LOW);
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  float distance = 0.034 * duration / 2;

  Serial.print("Distância: ");
  Serial.print(distance);
  Serial.println(" cm");

  for (int i = 0; i < 5; i++) {
    digitalWrite(leds[i], LOW);
  }

  if (distance <= 5) {
    digitalWrite(leds[0], HIGH);
    digitalWrite(leds[1], HIGH);
    digitalWrite(leds[2], HIGH);
    digitalWrite(leds[3], HIGH);
    digitalWrite(leds[4], HIGH);
  }
  else if (distance > 5 && distance <= 10) {
    digitalWrite(leds[0], HIGH);
    digitalWrite(leds[1], HIGH);
    digitalWrite(leds[2], HIGH);
    digitalWrite(leds[3], HIGH);
  }
  else if (distance > 10 && distance <= 15) {
    digitalWrite(leds[0], HIGH);
    digitalWrite(leds[1], HIGH);
    digitalWrite(leds[2], HIGH);
  }
  else if (distance > 15 && distance <= 20) {
    digitalWrite(leds[0], HIGH);
    digitalWrite(leds[1], HIGH);
  }
  else if (distance > 20 && distance <= 25) {
    digitalWrite(leds[0], HIGH);
  }


  delay(300);
}