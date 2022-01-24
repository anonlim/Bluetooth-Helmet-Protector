#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2,3);   //bluetooth module Tx:Digital 2 Rx:Digital 3
int a;
unsigned long long int last_time;//toggled된 마지막 시간
void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
  Serial.println("ATcommand");  //ATcommand Start
  a = digitalRead(5);
  pinMode(5,INPUT);//sw
  pinMode(4,OUTPUT);//led +
}
void loop() {
  func();
}

void func  (){ 
  // put your main code here, to run repeatedly:
 if (BTSerial.available())
    Serial.write(BTSerial.read());
  if (Serial.available())
    BTSerial.write(Serial.read());
  if(a!=digitalRead(5)){
    if(a==HIGH){
      a = LOW;
      digitalWrite(4,LOW);
     BTSerial.write(" Safe Ride");
     //BTSerial.write((last_time - millis())/1000+48);
     //last_time = (last_time - millis());
    }
    else{
      a = HIGH;
      BTSerial.write(" Returned");
      digitalWrite(4,HIGH);
      //BTSerial.write((last_time - millis())/1000+48);
      //last_time = (last_time - millis());
    }
  }
  delay(100);
}
