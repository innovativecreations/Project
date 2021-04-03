#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);

float xAxis;
float yAxis;
int in;

int o1 = 12;
int o2 = 11;
int o3 = 10;
int inp = 9;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  pinMode(o1,OUTPUT);
  pinMode(o2,OUTPUT);
  pinMode(o3,OUTPUT);
  pinMode(inp,INPUT);
}

void loop() {
  mpu6050.update();
  xAxis = mpu6050.getAngleX();
  yAxis = mpu6050.getAngleY();
  in = digitalRead(inp);
  if(in == HIGH){
    if(yAxis >= 25){
      digitalWrite(o1,LOW);
      digitalWrite(o2,LOW);
      digitalWrite(o3,HIGH);
      Serial.println("001");
    }
    else if(yAxis <= -25){
      digitalWrite(o1,LOW);
      digitalWrite(o2,HIGH);
      digitalWrite(o3,LOW);
      Serial.println("010");
    }
    else if(xAxis >= 25){
      digitalWrite(o1,LOW);
      digitalWrite(o2,HIGH);
      digitalWrite(o3,HIGH);
      Serial.println("011");
    }
    else if(xAxis <= -25){
      digitalWrite(o1,HIGH);
      digitalWrite(o2,LOW);
      digitalWrite(o3,LOW);
      Serial.println("100");
    }
    else{
      digitalWrite(o1,LOW);
      digitalWrite(o2,LOW);
      digitalWrite(o3,LOW);   
      Serial.println("no movement");   
    }
    }
   else{
      digitalWrite(o1,LOW);
      digitalWrite(o2,LOW);
      digitalWrite(o3,LOW);      
      
      Serial.println("nothing from mini");
    }

} 
