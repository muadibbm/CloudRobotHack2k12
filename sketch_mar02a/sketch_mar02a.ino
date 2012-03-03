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
//  spiral(leftspeed, rightspeed);
  switch(val)
  {
    case 'w':
      forward(leftspeed, rightspeed);
      break;
    case 's':
      reverse(leftspeed, rightspeed);
      break;
    case 'a':
      left(leftspeed, rightspeed);
      break;
    case 'd':
      right(leftspeed, rightspeed);
      break;
    default:
      stop();
      break;
  }
}

void spiral(char a, char b)
{
  while(a != b)
  {
    analogWrite(E1, a);
    digitalWrite(M1, HIGH);
    analogWrite(E2, b);
    digitalWrite(M2, HIGH);
    delay(250);
    a -= 1;
    b += 1;
  }
}

void stop(void) //Stops
{
  digitalWrite(E1, LOW);
  digitalWrite(E2, LOW);
}

void forward(char a, char b)
{
  analogWrite(E1, a);
  digitalWrite(M1, LOW);
  analogWrite(E2, b);
  digitalWrite(M2, LOW);
}

void reverse(char a, char b)
{
  analogWrite(E1, a);
  digitalWrite(M1, HIGH);
  analogWrite(E2, b);
  digitalWrite(M2, HIGH);
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
