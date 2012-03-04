/* Arduino BT Configuration File  Feb 05 2007
* ------------------
* Upload and run this file <<once>> to configure the name or other variables of your BT module.
* Don't forget to reset your module so that the new commands are executed.
* ------------------
* Massimo Banzi
*/


char val; //variable to reccieve data from the serial port
int LED = 13;                                     // select the pin for the LED
int RESET = 7;                                    // BT module uses pin 7 for reset
boolean t = false;

void setup() {
  pinMode(LED,OUTPUT);                            // declare the LED and BT RESET pins as output
  //pinMode(RESET,OUTPUT);  

  Serial.begin(11520);                           // connect to the serial port

  //digitalWrite(RESET, HIGH);  
  //delay(10);
  //digitalWrite(RESET, LOW);
  //delay(2000);
  //Serial.begin(115200);
                                                   // the following "SET BT" commands are one-time commands 
                                                   // that only need to be uploaded to your BT module and run 
                                                   // when you want to change the BlueGiga's configuration.

                                                   // ok. First, the easy to change configuration commands:

   //Serial.print("AT\r\n");
   //Serial.print("AT+NAME=ShadowLove\r\n");      // you can change the name of your module here. 
                                                   // No spaces allowed in the name; names can be up to 256 charcters.
}

                                                   // and now a few blinks of the  LED, 
                                                   // so that we know the program is running.

void loop () {  

  Serial.print('H');
  if(Serial.available() > 0){
    Serial.flush();
    Serial.print("reccived"); 
    t = true;
  }
  if(t)
  {
    for(int i =0; i<10; i++)
    {
      digitalWrite(LED, HIGH);
      delay(200);
      digitalWrite(LED,LOW);
      delay(200);  
  }
    t = false;
  }else{ 
    digitalWrite(LED,HIGH);
    delay(1000);
    digitalWrite(LED,LOW);
    delay(1000);  
  }
  /*digitalWrite(LED, HIGH);
  delay(100);
  digitalWrite(LED, LOW);
  Serial.println("ciao");
  delay(1000);*/
}
