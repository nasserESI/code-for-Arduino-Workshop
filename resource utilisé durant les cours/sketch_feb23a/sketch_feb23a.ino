
int analogInput = A1;
float vout = 0.0;
float vin = 0.0;
float R1 = 30000.0; // 
float R2 = 7500.0; // 
int value = 0;
void setup(){
 Serial.begin(9600);
 Serial.print("DC VOLTMETER");
}
//dans un circuit, le courant éléctrique circule de la borne positive vers la borne négative
void loop(){
 // read the value at analog input
 value = analogRead(A1);
 vout = value * 0.0048828125; // tensiion de sortie convertie à l'entrée d'analogread()
 vin = vout / (R2/(R1+R2)); // tension d'entrée trouvée en convertissant la formule 
 
Serial.print("INPUT V= ");
Serial.println(vin,2);
delay(500);
}
