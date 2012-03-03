/* DFRobotShop Rover bare minimum

Left and right are determined as though driving a car
with the USB and power ports in the rear. If you want
to test code without driving it off your desk, simply
remove the tank treads!

Board Type: Arduino Duemilanove ATMega328
Motor Drivers: L293B dual H bridge

Motors run at 4.5v nominal, but the whole board can
be powered from 3.78v to 9V.

pin 5; //Right Speed Control (analogWrite 0-255)
pin 6; //Left Speed Control (analogWrite 0-255)
pin 7; //Right Direction Control (HIGH=forward, LOW=back)
pin 8; //Left Direction Control (HIGH=forward, LOW=back)

Ambient Light pin on Analog 0
Thermal Sensor (LM35) on Analog 1

*/
int lightPin = A0;
int thermoPin = A1;
int rightMotorPin = 5;
int leftMotorPin = 6;
int rightDirectionPin = 7;
int leftDirectionPin = 8;
int leftspeed = 255; //255 is maximum speed
int rightspeed = 255;

void setup(){
pinMode(lightPin, INPUT);
pinMode(thermoPin, INPUT);
pinMode(rightMotorPin, OUTPUT);
pinMode(leftMotorPin, OUTPUT);
pinMode(rightDirectionPin, OUTPUT);
pinMode(leftDirectionPin, OUTPUT);
Serial.begin(9600); //
}

void loop(){
// Everything in here is just an example of how to use the functions below.
forward (leftspeed,rightspeed); //Go Forward
delay(2500);
left (leftspeed,rightspeed); // Turn Left
delay(2500);
reverse (leftspeed,rightspeed); // Go Backward
delay(2500);
right (leftspeed,rightspeed); // Turn Right
delay(2500);
stop(); // Full Stop
delay(2500);
float TempC = getTemp();
Serial.print(TempC);
Serial.println(" degrees C");
delay(500);
float light = getLight();
Serial.print(light);
Serial.println(" percent readable light");
delay(500);

}

// Everything below this line can be deleted or you can re-use the code

void stop(void) //Stop
{
digitalWrite(leftMotorPin,LOW);
digitalWrite(rightMotorPin,LOW);
}

void forward(char a,char b)
{
analogWrite (leftMotorPin,a);
digitalWrite(leftDirectionPin,LOW);
analogWrite (rightMotorPin,b);
digitalWrite(rightDirectionPin,LOW);
}

void reverse (char a,char b)
{
analogWrite (leftMotorPin,a);
digitalWrite(leftDirectionPin,HIGH);
analogWrite (rightMotorPin,b);
digitalWrite(rightDirectionPin,HIGH);
}

void left (char a,char b)
{
analogWrite (leftMotorPin,a);
digitalWrite(leftDirectionPin,HIGH);
analogWrite (rightMotorPin,b);
digitalWrite(rightDirectionPin,LOW);
}

void right (char a,char b)
{
analogWrite (leftMotorPin,a);
digitalWrite(leftDirectionPin,LOW);
analogWrite (rightMotorPin,b);
digitalWrite(rightDirectionPin,HIGH);
}

float getTemp ()
{
float sensorRead = analogRead(thermoPin); // Get reading
float tempRead = (5.0 * sensorRead * 100.0)/1024.0; // 5V
return tempRead;
}

float getLight()
{
float lightRead = analogRead(lightPin);
float lightPercent = map(lightRead, 1024, 0, 0, 100); // to percent of light reading
return lightPercent;
}
