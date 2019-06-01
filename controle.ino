


 #include <Wire.h>
#include <Servo.h> 
#include <Adafruit_MotorShield.h>

int servopin=10;

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

Adafruit_DCMotor *myMotor = AFMS.getMotor(1);
Adafruit_DCMotor *myMotor2 = AFMS.getMotor(2);
Adafruit_DCMotor *myMotor3 = AFMS.getMotor(3);
Adafruit_DCMotor *myMotor4 = AFMS.getMotor(4);

int i=0;
Servo servo1;
Servo servo2;
Servo servo3;


void setup() {
  
  Serial.begin(9600);           
  

  

  AFMS.begin();  
  
  
  
  servo1.attach(10);
  servo2.attach(9);
  servo3.attach(4);
   

  myMotor->setSpeed(100);
  myMotor2->setSpeed(100);
  myMotor3->setSpeed(100);
  myMotor4->setSpeed(100);
  

  myMotor->run(RELEASE);
  myMotor2->run(RELEASE);
  myMotor3->run(RELEASE);
  myMotor4->run(RELEASE);
  
   
}


void loop() {
 
 
 
 
 
 servo1.write(90);
 servo2.write(90);

   
   
  myMotor->setSpeed(200);
  myMotor2->setSpeed(200);
  myMotor3->setSpeed(200);
  myMotor4->setSpeed(200);
  
   myMotor->run(FORWARD);
  myMotor2->run(FORWARD);
  myMotor3->run(FORWARD);
  myMotor4->run(FORWARD);
  delay(1250);
  servo1.write( 110);
    servo2.write(110);
  myMotor->setSpeed(0);
  myMotor2->setSpeed(0);
  myMotor3->setSpeed(0);
  myMotor4->setSpeed(0);
   myMotor->run(RELEASE);
  myMotor2->run(RELEASE);
  myMotor3->run(RELEASE);
  myMotor4->run(RELEASE);
 delay(1250);
 servo1.write( 90);
  servo2.write(90);
  myMotor->setSpeed(200);
  myMotor2->setSpeed(200);
  myMotor3->setSpeed(200);
  myMotor4->setSpeed(200);
  
  myMotor->run(BACKWARD);
  myMotor2->run(BACKWARD);
  myMotor3->run(BACKWARD);
  myMotor4->run(BACKWARD);
  
   delay(1250);
   servo1.write(110);
    servo2.write(110);
  

  myMotor->run(RELEASE);
  myMotor2->run(RELEASE);
  myMotor3->run(RELEASE);
  myMotor4->run(RELEASE);
   delay(1250);

  




  
  
 
}
