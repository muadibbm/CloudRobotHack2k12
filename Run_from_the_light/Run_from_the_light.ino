int lightPin = A0;
int thermoPin = A1;
int E2 = 5;
int E1 = 6;
int M2 = 7;
int M1 = 8;
int leftspeed = 255; //255 is maximum speed
int rightspeed = 255;

void setup(){
pinMode(lightPin, INPUT);
pinMode(thermoPin, INPUT);
pinMode(E2, OUTPUT);
pinMode(E1, OUTPUT);
pinMode(M2, OUTPUT);
pinMode(M1, OUTPUT);
Serial.begin(115200); //
}

void loop()
{
  Serial.print(getLight());
  Serial.println(" % Light");
  while(getLight() >= 30)
  {
    Serial.print(getLight());
    Serial.println(" % Light");
    forward(leftspeed, rightspeed);
  }
  stop();
}

void stop(void) //Stops
{
  digitalWrite(E1, LOW);
  digitalWrite(E2, LOW);
}

void forward(char a, char b)
{
  analogWrite(E1, a);
  digitalWrite(M1, HIGH);
  analogWrite(E2, b);
  digitalWrite(M2, HIGH);
}

void reverse(char a, char b)
{
  analogWrite(E1, a);
  digitalWrite(M1, LOW);
  analogWrite(E2, b);
  digitalWrite(M2, LOW);
}

void left(char a, char b)
{
  analogWrite(E1, a);
  digitalWrite(M1, HIGH);
  analogWrite(E2, b);
  digitalWrite(M2, LOW);
}

void right(char a, char b)
{
  analogWrite(E1, a);
  digitalWrite(M1, HIGH);
  analogWrite(E2, b);
  digitalWrite(M2, LOW);
}

float getLight()
{
  float lightRead = analogRead(lightPin);
  float lightPercent = map(lightRead, 1024, 0, 0, 100);
  return lightPercent;
}
