
float lecture_echo;
float cm;

void setup()
{
pinMode(A0, OUTPUT);
digitalWrite(A0, LOW);
pinMode(A2, INPUT);
Serial.begin(9600);
}

void loop()
{
digitalWrite(A0, HIGH);
delayMicroseconds(100);
digitalWrite(A0, LOW);
lecture_echo = pulseIn(A2, HIGH);
cm = lecture_echo / 58;
Serial.print("Distance : ");
Serial.println(cm);
delay(1);
}
