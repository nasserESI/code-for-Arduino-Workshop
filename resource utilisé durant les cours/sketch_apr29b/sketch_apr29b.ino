int trig = 8;
int echo = 7;
float lecture_echo;
float cm;
void setup() {
  // put your setup code here, to run once:
pinMode(A0, OUTPUT);
digitalWrite(A0, LOW);
pinMode(A2, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(A0, HIGH);
delayMicroseconds(10);
digitalWrite(A0, LOW);
lecture_echo = pulseIn(A2, HIGH);
cm = lecture_echo / 58;
Serial.print("Distance : ");
Serial.println(cm);
delay(1);
}
