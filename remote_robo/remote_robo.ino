int E1 = 6; //M1 Speed Control
int E2 = 5; //M2 Speed Control
int M1 = 8; //M1 Direction Control
int M2 = 7; //M2 Direction Control

void setup(void)
{
  for(int i = 5; i <= 8; i++)
  {
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
}

void loop(void)
{
  while(Serial.available() < 1) {}
  char val = Serial.read();
  int leftspeed = 255;
  int rightspeed  = 255;

  switch(val)
  {
    case 'w':
      forward(leftspeed-50, rightspeed);
      break;
    case 's':
      reverse(leftspeed, rightspeed);
      break;
    case 'a':
      left(100, rightspeed);
      break;
    case 'd':
      right(leftspeed, (rightspeed - 100));
      break;
    default:
      stop();
      break;
  }
  Serial.flush();
  delay(250);
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
  digitalWrite(M2, HIGH);
}

void right(char a, char b)
{
  analogWrite(E1, a);
  digitalWrite(M1, HIGH);
  analogWrite(E2, b);
  digitalWrite(M2, HIGH);
}
