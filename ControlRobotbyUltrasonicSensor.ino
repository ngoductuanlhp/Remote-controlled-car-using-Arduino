const int trig = 8;     
const int echo = 7;    
int inA=13;
int inB=12;
int inC=11;
int inD=10;
int ledR=6;
int ledL=5;
int v1=9;
int v2=3;
int s1=250;
int s2=130;
char c;
int s=0;
void setup()
{
    Serial.begin(9600);     
    pinMode(trig,OUTPUT); 
    pinMode(echo,INPUT);    
    pinMode(inA, OUTPUT);
pinMode(inB, OUTPUT);
pinMode(inC, OUTPUT);
pinMode(inD, OUTPUT);
pinMode(v1, OUTPUT);
pinMode(v2, OUTPUT);
pinMode(ledR, OUTPUT);
pinMode(ledL, OUTPUT);
}
 
void loop()
{
    unsigned long duration;
    int distance;           
    

    digitalWrite(trig,0);   
    delayMicroseconds(2);
    digitalWrite(trig,1);   
    delayMicroseconds(5);   
    digitalWrite(trig,0);  
    
    duration = pulseIn(echo,HIGH);  
    distance = int(duration/2/29.412);
    if(distance >15 && distance <1000)
    {
      s=0;
      runmotor(1,1,s1);
      runmotor(2,1,s1);
    }
    else if(distance<=15 && distance>0)
    {
      if(s%6<3)
      {
      digitalWrite(ledL, HIGH);
      delay(100);
      digitalWrite(ledL, LOW);
      delay(100);
      runmotor(1,1,s2);
      runmotor(2,-1,s2);
      s++;
      }
      else if(s%6>=3)
      {
      digitalWrite(ledR, HIGH);
      delay(100);
      digitalWrite(ledR, LOW);
      delay(100);
      runmotor(1,-1,s2);
      runmotor(2,1,s2);
      s++;
      }
    }
    
    Serial.print(distance);
    Serial.println("cm");
    delay(100);
}

void runmotor(int a,int b, int c)
{
  if(a==1&&b==1)
  {
    digitalWrite(inB,HIGH);
    digitalWrite(inA,LOW);
    analogWrite(v1,c);
  }
    if(a==2&&b==1)
  {
    digitalWrite(inD,HIGH);
    digitalWrite(inC,LOW);
    analogWrite(v2,c);
    
  }
    if(a==1&&b==-1)
  {
    digitalWrite(inB,LOW);
    digitalWrite(inA,HIGH);
    analogWrite(v1,c);
  }
      if(a==2&&b==-1)
  {
    digitalWrite(inD,LOW);
    digitalWrite(inC,HIGH);
    analogWrite(v2,c);
  }
      if(a==1&&b==0)
  {
    digitalWrite(inA, LOW);
    digitalWrite(inB, LOW);
  }
        if(a==2&&b==0)
  {
    digitalWrite(inC, LOW);
    digitalWrite(inD, LOW);
  }
 }

