int inA=13;
int inB=12;
int inC=11;
int inD=10;
int ledR=6;
int ledL=5;
int v1=9;
int v2=3;
int s1=255;
int s2=130;
int signL=0;
int signR=0;
char c;


void setup() {
  // put your setup code here, to run once:
pinMode(inA, OUTPUT);
pinMode(inB, OUTPUT);
pinMode(inC, OUTPUT);
pinMode(inD, OUTPUT);
pinMode(v1, OUTPUT);
pinMode(v2, OUTPUT);
Serial.begin(9600);
pinMode(LED_BUILTIN, OUTPUT);
pinMode(ledR, OUTPUT);
pinMode(ledL, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()>0)
{
  c=Serial.read();
  switch(c)
  {
    case 'F':
    runmotor(1,1,s1);
    runmotor(2,1,s1);
    signL=0;
    signR=0;
    break;
    case 'B':
    runmotor(1,-1,s1);
    runmotor(2,-1,s1); 
    signL=0;
    signR=0;
    break;
    case 'L':
    runmotor(1,1,s1);
    runmotor(2,0,s1);
    signL=1;
    break;
    case 'R':
    runmotor(1,0,s1);
    runmotor(2,1,s1);
    signR=1;
    break;
    case 'G':
    runmotor(1,1,s1);
    runmotor(2,1,s2);
    signL=1;
    break;
    case 'I':
    runmotor(1,1,s2);
    runmotor(2,1,s1);
    signR=1;
    break;
    case 'H':
    runmotor(1,-1,s1);
    runmotor(2,-1,s2);
    signL=1;
    break;
    case 'J':
    runmotor(1,-1,s2);
    runmotor(2,-1,s1);
    signR=1;
    break;
    default:
    runmotor(1,0,s1);
    runmotor(2,0,s1);
    signL=0;
    signR=0;
  }
  }
  if(signL==1)
  {
    digitalWrite(ledL, HIGH);
    delay(100);
    digitalWrite(ledL, LOW);
    delay(100);
  }  
if(signR==1)
{
digitalWrite(ledR, HIGH);
    delay(100);
    digitalWrite(ledR, LOW);
    delay(100);
  
}
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


