int ip1 = 10;
int ip2 = 11;
int ip3 = 12;

int r1 = 9;
int r2 = 8;
int r3 = 7;
int r4 = 6;

int i1;
int i2;
int i3;
int i4;


void setup() {

  Serial.begin(9600);

  pinMode(ip1, INPUT);
  pinMode(ip2, INPUT);
  pinMode(ip3, INPUT);

  pinMode(r1,OUTPUT);
  pinMode(r2,OUTPUT);
  pinMode(r3,OUTPUT);
  pinMode(r4,OUTPUT);
  
}

void loop() {

  i1 = digitalRead(ip1);
  i2 = digitalRead(ip2);
  i3 = digitalRead(ip3);

  if(i1 == LOW && i2 == LOW && i3 == LOW){
    stp();
    }
  
  else if(i1 == LOW && i2 == LOW && i3 == HIGH){
    fwd();
  }
  
  else if(i1 == LOW && i2 == HIGH && i3 == LOW){
    bkd();
  }
  
  else if(i1 == LOW && i2 == HIGH && i3 == HIGH){
    left();
  }
  
  else if(i1 == HIGH && i2 == LOW && i3 == LOW){
    right();
  }
  
}



void stp(){
    digitalWrite(r1,LOW);
    digitalWrite(r2,LOW);
    digitalWrite(r3,LOW);
    digitalWrite(r4,LOW);
}
void fwd(){
    digitalWrite(r1,HIGH);
    digitalWrite(r2,LOW);
    digitalWrite(r3,HIGH);
    digitalWrite(r4,LOW);
}
void bkd(){  
    digitalWrite(r1,LOW);
    digitalWrite(r2,HIGH);
    digitalWrite(r3,LOW);
    digitalWrite(r4,HIGH);
}
void left(){  
    digitalWrite(r1,LOW);
    digitalWrite(r2,HIGH);
    digitalWrite(r3,HIGH);
    digitalWrite(r4,LOW);
}
void right(){  
    digitalWrite(r1,HIGH);
    digitalWrite(r2,LOW);
    digitalWrite(r3,LOW);
    digitalWrite(r4,HIGH);
}
