extern volatile unsigned long timer0_millis;

int irp = 3;
int o = 10;

unsigned long ontime = 0;
unsigned long offt = 0;
unsigned long currentt = 0;
unsigned long previoust = 0;
int x = 0;



int ir; 

void setup() {

  pinMode(irp,INPUT);
  pinMode(o,OUTPUT);
  Serial.begin(9600);
  digitalWrite(o,HIGH);
  
}

void loop() {

  ir = digitalRead(irp);
  currentt = millis() / 1000UL;

  if(ir == HIGH){
    if(x == 0){
      offt = 0;
      ontime = currentt - previoust;
      x = 0;
      Serial.println("eye is off"); 
    }
    else if(x == 1){
      previoust = currentt;
      x = 0;
    }
  }
  else if(ir == LOW){
    if(x == 1){
      ontime = 0;
      offt = currentt - previoust;
      Serial.println("eye is on");
      x = 1;
    }
    else if(x == 0){
      previoust = currentt;
      x = 1;
    }
  }
  
  if(ontime > 10UL){
    digitalWrite(o,HIGH);
    Serial.println("on");
  }
  
  else if(offt > 5UL){
    digitalWrite(o,LOW);
    Serial.println("off");
  }
  Serial.print("on time: ");
  Serial.println(ontime);
  Serial.print("off time: ");
  Serial.println(offt);
  
}
