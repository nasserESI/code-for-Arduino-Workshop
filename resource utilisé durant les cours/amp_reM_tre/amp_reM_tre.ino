float Sensibilidad = 0.066; //Sensibilité en Volts/Ampère pour capteur de 5A à 185mV/A -> ,0.185
//Sensibilité pour 30 Amp -> 66mV/A 
void setup() {
  Serial.begin(9600);
}
 
void loop() {
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
