#include <Servo.h>  // on inclut la bibliothèque servo
  Servo servoMoteur;
  Servo servo2;// on crée un objet servo appelé servoMoteurq
  float lecture_echo;
  float cm;
void setup(){
  
  servoMoteur.attach(5);
  servo2.attach(4);
  pinMode(A0, OUTPUT);
  digitalWrite(A0, LOW);
  pinMode(A2, INPUT);
  Serial.begin(9600);
}

void loop(){
  if(ultraSon()<= 40){
      toutDroit();
      droite();
      toutDroit();
      droite();
      toutDroit();
      droite();
      toutDroit();
      gauche();
      toutDroit();
      gauche();
      toutDroit();
      gauche();
      toutDroit();
      gauche();
      toutDroit();
   }else{
      Arriere();
    }
 
}
void Arriere(){
  servoMoteur.write(100);
  servo2.write(25);
  delay(1000);
}
void toutDroit(){
  servoMoteur.write(10);
  servo2.write(115);
  delay(1000);   
}
void droite(){
  
  servo2.write(100);
  servoMoteur.write(150);
  delay(750);
}
void gauche(){
  servo2.write(70);
  servoMoteur.write(10);
  delay(680);  
}
float ultraSon(){
  // put your main code here, to run repeatedly:
  digitalWrite(A0, HIGH);
  delayMicroseconds(10);
  digitalWrite(A0, LOW);
  lecture_echo = pulseIn(A2, HIGH);
  cm = lecture_echo / 58;
  Serial.print("Distance : ");
  Serial.println(cm);
  delay(1000);
  
}
