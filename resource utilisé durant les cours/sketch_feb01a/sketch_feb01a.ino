#include <Servo.h>  // on inclut la bibliothèque servo
Servo servoMoteur;
Servo servo2;// on crée un objet servo appelé servoMoteur
float Sensibilidad = 0.066;
int analogInput = A1;
float vout = 0.0;
float vin = 0.0;
float R1 = 30000.0; // 
float R2 = 7500.0; // 
int value = 0;
void setup(){
 Serial.begin(9600);
  servoMoteur.attach(5);
  servo2.attach(4);
}

void loop(){
  voltmetre();
  toutDroit();
}
void ampere(){
        double voltajeSensor = analogRead(A0)*0.0048828125;
  //(5.0 / 1023.0); //Pour la lecture du capteur 
    double I=((voltajeSensor - 2.499999) / Sensibilidad); //Formule pour obtenir le courant ou   l'intensité mesuré avec les cordons connectés au module ACS712
    /*5000mV (tension de référence analogique - c'est la valeur par défaut (30.0 ->   30000Mv)*/
  /*adcValue = analogRead(currentPin);
    adcVoltage = (adcValue / 1024.0) * 5000;
    currentValue = ((adcVoltage - offsetVoltage) / sensitivity);*/
    Serial.print(voltajeSensor);
    Serial.print(" ");
    Serial.print(analogRead(A0));
    Serial.print(" ");
    Serial.print("La intensidad en Amperios es de: ");
    Serial.println(I,3); 
    delay(200);       
  }
void voltmetre(){
  value = analogRead(A1);
  vout = value * 0.0048828125; // tensiion de sortie convertie à l'entrée d'analogread()
  vin = vout / (R2/(R1+R2)); // tension d'entrée trouvée en convertissant la formule 
  Serial.print("INPUT V= ");
  Serial.println(vin,2);
  delay(500);    
}
void Arriere(){
  servoMoteur.write(110);
  servo2.write(80);
  delay(1000);
}
void toutDroit(){
  servoMoteur.write(10);
  servo2.write(100);
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
