#include <Servo.h> 

#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04
float Sensibilidad = 0.066; //Sensibilité en Volts/Ampère pour capteur de 5A à 185mV/A -> ,0.185yv
  Servo servoMoteur;
  Servo servo2;// on crée un objet servo appelé servoMoteur
  // defines variables
 long duration; // variable for the duration of sound wave travel
 float distance; // variable for the distance measurement
 
void setup() {
   pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  // put your setup code here, to run once:
  servoMoteur.attach(5);
  pinMode(A0, OUTPUT);
  digitalWrite(A0, LOW);
  pinMode(A2, INPUT);
  Serial.begin(9600);
}

void loop() {
  if(ultraSon()>30){
     toutDroit(); 
  }else{
     Arriere();
     gauche();  
  }
  
  
}
void ampereMetre(){
    double voltajeSensor = analogRead(A5)*0.0048828125;
  //(5.0 / 1023.0); //Pour la lecture du capteur 
    double I=((voltajeSensor - 2.499999) / Sensibilidad); //Formule pour obtenir le courant ou   l'intensité mesuré avec les cordons connectés au module ACS712
    /*5000mV (tension de référence analogique - c'est la valeur par défaut (30.0 ->   30000Mv)*/
  /*adcValue = analogRead(currentPin);
    adcVoltage = (adcValue / 1024.0) * 5000;
    currentValue = ((adcVoltage - offsetVoltage) / sensitivity);*/
    Serial.print(voltajeSensor);
    Serial.print(" ");
    Serial.print(analogRead(A5));
    Serial.print(" ");
    Serial.print("La intensidad en Amperios es de: ");
    Serial.println(I,3); 
    delay(200);     
  }
void Arriere(){
  servoMoteur.write(100);
  servo2.write(25);
  delay(1000);
}
void toutDroit(){
  servoMoteur.write(10);
  servo2.write(115);
  delay(1);   
}
void gauche(){
  servo2.write(40);
  servoMoteur.write(80);
  delay(600);  
}
void droite(){
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
  servo2.write(110);
  servoMoteur.write(150);
  delay(1000);
}
float ultraSon(){
  
   // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  return distance; 
}
