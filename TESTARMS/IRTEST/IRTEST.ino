int eiei = 0 ;
void setup() {
pinMode(8,INPUT);
pinMode(9,OUTPUT);
pinMode(A0,INPUT);
// digitalWrite(8,HIGH);    //according to your connection from motor to the motor driver
  digitalWrite(9,LOW);
Serial.begin(9600);       //Enable Serial Communications
}

void loop() {
  eiei = analogRead(A0);
//eiei = digitalRead(8 );
//eiei = digitalRead(A0);
Serial.println(eiei);
//delay(200); 
}
