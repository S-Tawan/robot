int ser_top = 3 ;
int ser = 9;
int i =0 ;
int up = 155;
int down = 80;
int on = 70;
int off = 180;
int EnA= 6;
int EnB=11;
int PinA1 = 7;
int  PinA2 = 8;
int  PinB1 = 12;
int PinB2 = 13;
int speed_motor ;
int start = 12;


void setup() {

pinMode(2,INPUT);
pinMode(EnA,OUTPUT);
pinMode(EnB,OUTPUT);
pinMode(PinA1 ,OUTPUT);
pinMode(PinA2,OUTPUT);
pinMode(PinB1,OUTPUT);
pinMode(PinB2,OUTPUT);

pinMode(ser_top,OUTPUT);
pinMode(ser,OUTPUT);
  Serial.begin(9600);       //Enable Serial Communications
 
}

void loop() {
  int go = digitalRead(start);
  Serial.println(go);
////  if(go==1){
// analogWrite(EnA,150);
//  analogWrite(EnB,150);
  digitalWrite(PinA1 ,HIGH);
   digitalWrite(PinA2,LOW);
    digitalWrite(PinB1,HIGH);
   digitalWrite(PinB2,LOW);
analogWrite(ser,up);
analogWrite(ser_top,on);
delay(1000);
analogWrite(ser,down);
delay(500);
while(digitalRead(2)!=0){
  analogWrite(EnA,100+15);
  analogWrite(EnB,100);
}
digitalWrite(PinA1 ,LOW);
   digitalWrite(PinA2,HIGH);
    digitalWrite(PinB1,LOW);
   digitalWrite(PinB2,HIGH);
   delay(100);
analogWrite(EnA,0);
  analogWrite(EnB,0);
analogWrite(ser_top,off);
delay(1000);
analogWrite(ser,up);
delay(1000);
analogWrite(ser,down+20);
delay(400);
int i = down+20;
while(i>down){
  analogWrite(ser,i);
  i--;
  delay(25);
}
analogWrite(ser,down);
delay(200);
analogWrite(ser_top,on);
delay(1000);
//analogWrite(3,off);
go = 0;
//}
//else{
//    
// analogWrite(EnA,0);
//  analogWrite(EnB,0);
//    Serial.println(go);
//}
}
void motor(){
  
}
