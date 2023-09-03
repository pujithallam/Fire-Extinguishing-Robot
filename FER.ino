#include <Servo.h>
Servo myservo; 
#define motor1  2
#define motor1a 3
#define motor2  4
#define motor2a 5

#define s1 A3
#define s2 A4
#define s3 A5
#define pump 12
#define buzzer 11
int fire1=0,fire2=0,fire3=0;
void setup() 
{
 Serial.begin(9600);
 pinMode(motor1, OUTPUT); 
 pinMode(motor2, OUTPUT); 
 pinMode(motor1a,OUTPUT); 
 pinMode(motor2a,OUTPUT); 
 pinMode(buzzer, OUTPUT);
 pinMode(pump, OUTPUT);
 pinMode(s1, INPUT);
 pinMode(s2, INPUT);
 pinMode(s3, INPUT);
 digitalWrite(pump, HIGH);
 myservo.attach(6); 
 myservo.write(90);
 delay(3000);
}
 
void forward()
{   
digitalWrite(motor1, HIGH); 
 digitalWrite(motor1a, LOW); 
 digitalWrite(motor2, HIGH); 
 digitalWrite(motor2a, LOW);
}
 
void stopp()
{
 digitalWrite(motor1, LOW); 
 digitalWrite(motor1a, LOW); 
 digitalWrite(motor2, LOW); 
 digitalWrite(motor2a, LOW);
}
void left()
{
 digitalWrite(motor1, HIGH); 
 digitalWrite(motor1a, LOW); 
digitalWrite(motor2, LOW); 
 digitalWrite(motor2a, HIGH);
}
void right()
{
 digitalWrite(motor1, LOW); 
 digitalWrite(motor1a, HIGH); 
 digitalWrite(motor2, HIGH); 
 digitalWrite(motor2a, LOW);
}
//-----------------------------------------------------------------------// 
void loop() 
{
 fire1=digitalRead(s1);
 fire2=digitalRead(s2);
 fire3=digitalRead(s3);
 Serial.println(fire1);
 Serial.println(fire2);
 Serial.println(fire3);
 delay(1000);
 if(fire1==LOW)
 {
  digitalWrite(buzzer,HIGH);
  forward();
  delay(500);
  stopp();
  myservo.write(90);
  delay(500);
  digitalWrite(pump,LOW); 
  init_sms();
  Serial.println("Warning : fire alert");
  send_sms();
  delay(5000); 
  digitalWrite(pump,HIGH); 
digitalWrite(buzzer,LOW);
 }
 
 else if(fire2==LOW)
 {
  digitalWrite(buzzer,HIGH);
  left();
  delay(500);
  stopp();
  digitalWrite(pump,LOW); 
  myservo.write(110);
  delay(300);
  myservo.write(150);
  delay(300);
  myservo.write(160);
  delay(300);
  digitalWrite(pump,LOW);
 // init_sms();
 // Serial.println("Warning : fire alert");
 // send_sms();
 // delay(5000);
  digitalWrite(buzzer,LOW);
 }
 else if(fire3==LOW)
 {
  digitalWrite(buzzer,HIGH);
  right();
  delay(500);
  stopp();
  digitalWrite(pump,LOW); 
  myservo.write(70);
  delay(300);
  myservo.write(40);
  delay(300);
  myservo.write(10);
  delay(300);
  
 // init_sms();
  //Serial.println("Warning : fire alert");
  //send_sms();
  //delay(5000);
  //init_sms1();
  //Serial.println("Warning : fire alert");
  //send_sms();
  //delay(5000);
  digitalWrite(buzzer,LOW);
 }
 else
 {
  
  stopp();
digitalWrite(pump,HIGH);
  myservo.write(90);
 }
}

 void init_sms()
 {
  Serial.println("AT+CMGF=1");
  delay(300);
  Serial.println("AT+CMGS=\"+917013171753\"");   // use your 10 digit cell no. here
  delay(300);
 }
void init_sms1()
 {
  Serial.println("AT+CMGF=1");
  delay(300);
  Serial.println("AT+CMGS=\"+917013171753\"");   // use your 10 digit cell no. here
delay(300);
 }
void send_sms()
{
 Serial.write(26);
}