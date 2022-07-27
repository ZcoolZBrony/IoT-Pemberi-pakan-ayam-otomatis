#include <Servo.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

Servo servo;
int servoAngle = 0;
int val = 0;
int mde = 0;

#define BLYNK_PRINT Serial
#define BLYNK_AUTH_TOKEN "De5dAnfbN3t8JiNYFtmLW-ND5hbN8Ope" //Enter blynk auth token
#define PIR 0 //D3

char auth[] = BLYNK_AUTH_TOKEN; //Enter Blynk Auth Token
char ssid[] = "LAPTOPRAIF";          //Enter WIFI SSID
char pass[] = "12345678";      //Enter WIFI password


void setup()
{
  pinMode(PIR, INPUT);
  servo.attach(4); //D2
  
  //Initialize the Blynk library
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  Serial.begin(9600);
}


void loop()
{
  Blynk.run();

  while( !digitalRead(PIR) == HIGH){
    Blynk.run();
    mde = 0;
  }
    
  if (mde != 1) {
    servo.write(servoAngle = 150);
    Serial.println("1");
    delay(500);
    servo.write(servoAngle = 5);
    delay(500);
    mde = 1;
  }
}

BLYNK_WRITE(V0) {
  if(param.asInt() == 1){
    servo.write(servoAngle = 180);
  } //Opened
  else{
    servo.write(servoAngle = 5);
  } //Closed
}

BLYNK_WRITE(V1) {
  servo.write(param.asInt());
}

BLYNK_WRITE(V2) {
//  servo.write(servoAngle = 5);
}

BLYNK_WRITE(V3) {
//  servo.write(servoAngle = 180);
}
