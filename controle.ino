

//librarie
 
#include <Wire.h>
#include <Servo.h> 
#include <Adafruit_MotorShield.h>

// Déclare le motor shield 

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

// Déclaration des moteur le chiffre corresponds au port utilié sur le moteur shield. 

Adafruit_DCMotor *myMotor = AFMS.getMotor(1);
Adafruit_DCMotor *myMotor2 = AFMS.getMotor(2);
Adafruit_DCMotor *myMotor3 = AFMS.getMotor(3);
Adafruit_DCMotor *myMotor4 = AFMS.getMotor(4);

int i=0;
// Déclaration ( type puis le nom ) 
Servo servo1;
Servo servo2;
Servo servo3;

//Phase initial 
void setup() {
  
  Serial.begin(9600);           
  

  

  AFMS.begin();  
  
  
  // servo sur pin pwm, elles sont reliées. 
 
 
  servo1.attach(10);
  servo2.attach(9);
  servo3.attach(4);
   
//  Set the speed (max 250) 
 
  myMotor->setSpeed(100);
  myMotor2->setSpeed(100);
  myMotor3->setSpeed(100);
  myMotor4->setSpeed(100);
  

  
   
}


void loop() {
 
 
 
 
 
  for(i=0;i!=255;i++){
    servo1.write(map(i,0,255,0,180));
    servo2.write(map(i,0,255,0,180));
   }

   for(i=255;i!=0;i++){

    servo1.write(map(i,0,255,0,180));
    servo2.write(map(i,0,255,0,180));
   }

  // set the speed
   
  myMotor->setSpeed(200);
  myMotor2->setSpeed(200);
  myMotor3->setSpeed(200);
  myMotor4->setSpeed(200);
  
 // diresction 
   myMotor->run(FORWARD);
  myMotor2->run(FORWARD);
  myMotor3->run(FORWARD);
  myMotor4->run(FORWARD);
  delay(1250);
  
 //Imporetant de mettre la vitesse a 0 avant l'arret et un delay 
 
  myMotor->setSpeed(0);
  myMotor2->setSpeed(0);
  myMotor3->setSpeed(0);
  myMotor4->setSpeed(0);
   myMotor->run(RELEASE);
  myMotor2->run(RELEASE);
  myMotor3->run(RELEASE);
  myMotor4->run(RELEASE);
 delay(1250);
 
 
 // en arrière
  myMotor->setSpeed(200);
  myMotor2->setSpeed(200);
  myMotor3->setSpeed(200);
  myMotor4->setSpeed(200);
  
  myMotor->run(BACKWARD);
  myMotor2->run(BACKWARD);
  myMotor3->run(BACKWARD);
  myMotor4->run(BACKWARD);
  
   delay(1250);
   
  

  myMotor->run(RELEASE);
  myMotor2->run(RELEASE);
  myMotor3->run(RELEASE);
  myMotor4->run(RELEASE);
   delay(1250);

  




  
  
 
}
