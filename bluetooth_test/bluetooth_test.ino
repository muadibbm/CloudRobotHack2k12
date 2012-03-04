int incomingByte;
int count = 0;
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  if(Serial.available() > 0)
  {
    incomingByte = Serial.read();

    if(incomingByte == 'R')
    {
      Serial.println("RESET");
      count = 0;
    }
    Serial.flush();
  }
  
  Serial.println(count);
  count++;
    
  delay(250);
}
