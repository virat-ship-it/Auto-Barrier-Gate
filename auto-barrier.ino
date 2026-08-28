#include<Servo.h>
Servo s1;
int trig=3;
int echo=2;
int dist;
long duration;

void setup() {
s1.attach(9);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
Serial.begin(9600);

}

void loop() {
 
 digitalWrite(trig,HIGH);
 delayMicroseconds(10);
 digitalWrite(trig,LOW);

duration=pulseIn(echo,HIGH);

dist=(duration*0.034)/2;
Serial.print("Distance:");
Serial.println(dist);
delay(100);

if(dist<=20){
  s1.write(100);
  delay(2000);
  s1.write(0);
}
}
