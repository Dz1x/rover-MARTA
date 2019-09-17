/*Haroun Khalfi for PolyOrbite education program*/

#include <Wire.h>
#include <Servo.h> 
#include <Adafruit_MotorShield.h>

const int bluetooth=2;
 int vitesse;
int state;

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

Adafruit_DCMotor *motorFR = AFMS.getMotor(1);
Adafruit_DCMotor *motorFL = AFMS.getMotor(2);
Adafruit_DCMotor *motorRR = AFMS.getMotor(3);
Adafruit_DCMotor *motorRL = AFMS.getMotor(4);
// DC hobby servo
Servo servoFR;
Servo servoFL;
Servo servoRR;
Servo servoRL;



void setup() {
  
  pinMode(bluetooth,INPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  Serial.begin(9600);           
  Serial.println("Motor test!");
  AFMS.begin();  
  // turn on servo
  servoFR.attach(9);
  servoFL.attach(10);
  servoRR.attach(6);
  servoRL.attach(5);
   motorFR->setSpeed(150);
  motorFL->setSpeed(150);
  motorRR->setSpeed(150);
  motorRL->setSpeed(150);
   
  
  
  
}




void loop() {

  if (digitalRead(bluetooth)==LOW){state='S';}
  
 if(Serial.available()>0){

   state=Serial.read();
   

 
  
Serial.println(state);

if (state == '0'){
      vitesse=0;}
    else if (state == '1'){
      vitesse=100;}
    else if (state == '2'){
      vitesse=180;}
    else if (state == '3'){
      vitesse=200;}
    else if (state == '4'){
      vitesse=255;}



switch (state){
  case'F':

servoFR.write(90);
servoFL.write(90);
servoRR.write(90);
servoRL.write(90);
  
    
  motorFR->run(FORWARD);
  motorFL->run(FORWARD);
  motorRR->run(FORWARD);
  motorRL->run(FORWARD);
    
    
    
   
    break;
case'B':

   servoFR.write(90);
   servoFL.write(90);
   servoRR.write(90);
   servoRL.write(90);
    
  motorFR->run(BACKWARD);
  motorFL->run(BACKWARD);
  motorRR->run(BACKWARD);
  motorRL->run(BACKWARD);
    
    
    
   
    break;



case'I':


servoFR.write(120);
servoFL.write(120);

 motorFR->run(FORWARD);
 motorFL->run(FORWARD);
 motorRR->run(FORWARD);
 motorRL->run(FORWARD);

  
break;

case 'G':


  servoFR.write(60);
  servoFL.write(60);

 motorFR->run(FORWARD);
 motorFL->run(FORWARD);
 motorRR->run(FORWARD);
 motorRL->run(FORWARD);


break;


case'R':




servoFR.write(60);
servoFL.write(120);
servoRR.write(120);
servoRL.write(60);

motorFR->run(BACKWARD);
motorFL->run(FORWARD);
motorRR->run(BACKWARD);
motorRL->run(FORWARD);
  

break;

case'L':



servoFR.write(60);
servoFL.write(120);
servoRR.write(120);
servoRL.write(60);

motorFR->run(FORWARD);
motorFL->run(BACKWARD);
motorRR->run(FORWARD);
motorRL->run(BACKWARD);
  

break;


case'H':




servoRL.write(120);
servoRR.write(120);

  motorFR->run(BACKWARD);
  motorFL->run(BACKWARD);
  motorRR->run(BACKWARD);
  motorRL->run(BACKWARD);



break;


case'J':



servoRR.write(60);
servoRL.write(60);

  motorFR->run(BACKWARD);
  motorFL->run(BACKWARD);
  motorRR->run(BACKWARD);
  motorRL->run(BACKWARD);
break;






case'S':


servoFR.write(90);
servoFL.write(90);
servoRR.write(90);
servoRL.write(90);

  motorFR->run(RELEASE);
  motorFL->run(RELEASE);
  motorRR->run(RELEASE);
  motorRL->run(RELEASE);
  
  
  break;
}


 }



  
}
