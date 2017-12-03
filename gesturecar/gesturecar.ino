//define the pins
int av1=A3; //analog input for accelerometers 
int av2=A4;
int ledpin1=8;//input1
int ledpin2=9;//input2
int ledpin3=7;//input3
int ledpin4=6;//input4

int a,b,x,y;

void setup() {
  // put your setup code here, to run once:
  //Set the  pins to output mode
  pinMode(ledpin1,OUTPUT);
  pinMode(ledpin2,OUTPUT);
  pinMode(ledpin3,OUTPUT);
  pinMode(ledpin4,OUTPUT);
  a=analogRead(av1); // To store the INITIAL (REFERENCE) VALUES
  b=analogRead(av2);
}

void loop() {
  x=analogRead(av1);
  y=analogRead(av2);
  
  //Initially set all the ledpins to LOW

  if(a-x>50) //left
  {
    digitalWrite(ledpin1,HIGH);
    digitalWrite(ledpin2,LOW);
    digitalWrite(ledpin3,LOW);
    digitalWrite(ledpin4,HIGH);
    analogWrite(11,abs(a-x)); //pwm
    analogWrite(10,abs(a-x)); //pwm
  }
 
  else if(x-a>50) //right
  {
    digitalWrite(ledpin1,LOW); 
    digitalWrite(ledpin2,HIGH);
    digitalWrite(ledpin3,HIGH);
    digitalWrite(ledpin4,LOW);
    analogWrite(11,abs(a-x)); //pwm
    analogWrite(10,abs(a-x)); //pwm
  }
  

  else if(b-y>50) //back
  {
    digitalWrite(ledpin1,LOW); 
    digitalWrite(ledpin2,HIGH);
    digitalWrite(ledpin3,LOW);
    digitalWrite(ledpin4,HIGH);
    analogWrite(10,abs(b-y)); //pwm
    analogWrite(11,abs(b-y)); //pwm
  }
 
  else if(y-b>50) //forward
  {
    digitalWrite(ledpin1,HIGH);
    digitalWrite(ledpin2,LOW);
    digitalWrite(ledpin3,HIGH);
    digitalWrite(ledpin4,LOW);
    analogWrite(10,abs(b-y)); //pwm
    analogWrite(11,abs(b-y)); //pwm
  } 
  else //no movement at centre
  {
    digitalWrite(ledpin1,LOW);
    digitalWrite(ledpin2,LOW);
    digitalWrite(ledpin3,LOW);
    digitalWrite(ledpin4,LOW);
    }
}
