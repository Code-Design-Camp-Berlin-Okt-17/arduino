#include<Servo.h>

Servo motor1;
String code = "333444555666";
String a;
static int contr = 1;

void setup(){
  motor1.attach(9);
  Serial.begin(9600); 
}

void loop(){

if(contr == 1){
  Serial.println("Bitte Code eingeben");
  contr=0;
}

while(a == 0 || a != code){
  a = Serial.readString();
}

if(a==code){ 
  Serial.println("Open");
  motor1.write(100);  
  delay(5000); 
  Serial.println("Closed");
  motor1.write(-100);
  a = 0;
  contr=1;
  }
}
