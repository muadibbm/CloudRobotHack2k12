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
  while(getLight() >= 12)
  {
    Serial.print(getLight());
    Serial.println(" % Light");
    int n = random(1,5);
    switch(n)
    {
      case 1:
        forward(leftspeed, rightspeed);
        break;
      case 2:
        reverse(leftspeed, rightspeed);
        break;
      case 3:
        left(leftspeed, rightspeed);
        break;
      case 4:
        right(leftspeed, rightspeed);
        break;
      default:
        forward(leftspeed, rightspeed);
        delay(500);
        reverse(leftspeed, rightspeed);
        delay(500);
        forward(leftspeed, rightspeed);
        delay(500);
        right(leftspeed, rightspeed);
        delay(500);
        break;
    }
    delay(2500);
  }
  stop();
  while(getLight() < 12)
  {
    Serial.print(getLight());
    Serial.println(" % Light");
    reverse(leftspeed, rightspeed);
    delay(5000);
  }
  left(leftspeed, rightspeed);
  delay(2500);
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
