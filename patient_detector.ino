#define EchoPIN1 3 
#define TriggerPIN1 8 
#define EchoPIN2 4 
#define TriggerPIN2 9 
#define EchoPIN3 5 
#define TriggerPIN3 10 
#define EchoPIN4 6
#define TriggerPIN4 11 
#define maxdistance 330

int distance(int sensor){
  int trigpin = sensor+7;
  int echopin = sensor+2;
  digitalWrite(trigpin,LOW);
  delay(2);
  digitalWrite(trigpin,HIGH);
  delay(2);
  digitalWrite(trigpin,LOW);

  long timedelay = pulseIn(echopin,HIGH);
  int distance = 0.0343*(timedelay/2);
  return distance;
}

void setup(){
  
  pinMode(TriggerPIN1,OUTPUT);
  pinMode(EchoPIN2,INPUT);
  pinMode(TriggerPIN2,OUTPUT);
  pinMode(EchoPIN2,INPUT);
  pinMode(TriggerPIN3,OUTPUT);
  pinMode(EchoPIN3,INPUT);
  pinMode(TriggerPIN4,OUTPUT);
  pinMode(EchoPIN4,INPUT);
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
  Serial.begin(9600); 
  }

void loop(){  
  int distance1 = distance(1);
  delay(2);
  int distance2 = distance(2);
  delay(2);
  int distance3 = distance(3);
  delay(2);
  int distance4 = distance(4);
  delay(2);
  if ((distance1>5&&distance1<maxdistance&&distance2>5&&distance2<maxdistance&&distance3>5&&distance3<maxdistance)||(distance4>5&&distance4<maxdistance&&distance2>5&&distance2<maxdistance&&distance3>5&&distance3<maxdistance)){
  delay(2000);
  int distance1 = distance(1);
  delay(2);
  int distance2 = distance(2);
  delay(2);
  int distance3 = distance(3);
  delay(2);
  int distance4 = distance(4);
  delay(2);
    if ((distance1>5&&distance1<maxdistance&&distance2>5&&distance2<maxdistance&&distance3>5&&distance3<maxdistance)||(distance4>5&&distance4<maxdistance&&distance2>5&&distance2<maxdistance&&distance3>5&&distance3<maxdistance)){
      digitalWrite(13,HIGH);
    }
    else  {
      digitalWrite(13,LOW);
    }
    
  }
  else{
    digitalWrite(13,LOW);
  }
  }
