
long cmL,cmC,cmR, durationL, durationC,durationR;
const int echoPinL = 8;
const int echoPinC = 10;
const int echoPinR = 12;
const int trigPinL = 9;	//Defining pins
const int trigPinC = 11;
const int trigPinR = 13;

const int lm1 = 6;
const int lm2 = 7;
const int rm1 = 4;
const int rm2 = 5;
  
void setup()
{
  pinMode(lm1, OUTPUT); 	//defining mode of communication
  pinMode(lm2, OUTPUT);
  pinMode(rm1, OUTPUT);
  pinMode(rm2, OUTPUT);
 
  pinMode(trigPinL, OUTPUT);
  pinMode(trigPinC, OUTPUT);
  pinMode(trigPinR, OUTPUT);
  pinMode(echoPinL, INPUT);
  pinMode(echoPinC, INPUT);
  pinMode(echoPinR, INPUT);
  
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trigPinC, LOW);		
  delayMicroseconds(2);
  digitalWrite(trigPinC, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinC, LOW);
  
  durationC = pulseIn(echoPinC, HIGH);
    cmC = durationC*0.034/2;
  
  Serial.print("Centre: ");
  Serial.println(cmC);
  
  if(cmC>30)
  {
    //go_straight();
    delay(1000);
  }
  else
  {
   digitalWrite(trigPinL, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinL, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinL, LOW);
  
  durationL = pulseIn(echoPinL, HIGH);
    cmL = durationL*0.034/2;
    
 Serial.print("Left: ");   
  Serial.println(cmL);
    
    digitalWrite(trigPinR, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinR, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinR, LOW);
  
  durationR = pulseIn(echoPinR, HIGH);
    cmR = durationR*0.034/2;
  
    Serial.print("Right: ");
  Serial.println(cmR);
    
    if(cmL>cmR)
    {
      //go_left();
       delay(1000);
    }
    else
    {
      //go_right();
      delay(1000);
    }
  }
 
}
void go_straight()
{
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
} 
void stop_bot()
{

  
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
}
void go_left()
{

  
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,HIGH);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
}

void go_right()
{

  
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,HIGH);
}
