int trigPin = 3;
int echoPin = 2;
int pwm = 0;
int leds[] = {11, 10, 9, 6, 5};

void turnOn(int amount){
  for(int i = 0; i < amount; i++){
    digitalWrite(leds[4 - i], HIGH);
  }
}

int calcPwm(float distObj, float distInt){
  float pwm =  -25.5 * (distObj - distInt) + 255; // Valor maximo igual a 255 e mínimo igual a 0
  return pwm;
}

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

  if(distance < 0 || distance > 50){
    for(int i = 0; i < 5; i++){
      digitalWrite(leds[i], LOW);
    }
  }

  if(distance <= 10){ // Vermelho 2
    turnOn(4);
    analogWrite(leds[0], calcPwm(distance, 0));
  }
  else if(distance <= 20){ // Vermelho 1
    turnOn(3);
    analogWrite(leds[1], calcPwm(distance, 10));
  }
  else if(distance <= 30){ // Laranja 
    turnOn(2);
    analogWrite(leds[2], calcPwm(distance, 20));
  }
  else if(distance <= 40){ // Amarelo
    turnOn(1);
    analogWrite(leds[3], calcPwm(distance, 30));
  }
  else if(distance <= 50){ // Verde
    turnOn(0);
    analogWrite(leds[4], calcPwm(distance, 40));
  }
}