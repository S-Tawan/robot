// Motor A pins (enableA = enable motor, pinA1 = forward, pinA2 = backward)
int enableA = 6;
int pinA1 = 7;
int pinA2 = 8;

//Motor B pins (enabledB = enable motor, pinB2 = forward, pinB2 = backward)
int enableB = 11;
int pinB1 = 12;
int pinB2 = 13;

int Speed = 150; 
int sensor[5] = {0, 0, 0, 0, 0};
int c = 0;

char way[50];
int index = -1,i;

void setup()
{
  Serial.begin(9600);
  pinMode(enableA,OUTPUT);
  pinMode(pinA1, OUTPUT);
  pinMode(pinA2, OUTPUT);

  pinMode(enableB, OUTPUT);
  pinMode(pinB1, OUTPUT);
  pinMode(pinB2, OUTPUT);
  pinMode (13,OUTPUT);

  for(i=0;i<50;i++){
    way[i] = ' ';
  }
}

void loop()
{
  Serial.println("KUY");
  enableMotors();
  speedMotor(Speed);

  sensor[0] = digitalRead(A1);
  sensor[1] = digitalRead(A2);
  sensor[2] = digitalRead(A3);
  sensor[3] = digitalRead(A4);
  sensor[4] = digitalRead(A5);
   if(c  == 0 ){
  if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1))                     //ปกติ
    forward(1); 
    else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 1))               //ติดหมด
    {
       
       forward(1);
       scan();
//       if((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 1)){
//         while(!((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 0))){
//             scan();  
//     turnLeft(1); 
//        }
//        brake(200);
//        scan();
//            while(!((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1)))
//      {     
//        scan();  
//     turnLeft(1); 
//       }
//       way[++index] = 'U';
//       }
       
    }
    
     else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 0))                //ดับหมด
    {
       
       forward(100);
       scan();
      
      if(((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1))||((sensor[0] == 1) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1))||((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 1))){
         while(!((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 0))){
             scan();  
            turnLeft(1); 
        }
        //brake(200);
            while(!((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1)))
      {     
        scan();  
     turnRight(1); 
       }
        way[++index] = 'L';
     }
 
       else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 0)){
        brake(5000);
       c++;
        
       }
       
    }
    
  else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 0) && (sensor[4] == 1))               //ซ้ายนิด
    turnLeftNit(1);    
  else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 1))               //ซ้ายนิด
   turnLeftNit(1);    
  else if ((sensor[0] == 1) && (sensor[1] == 0) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 1))               //ขวานิด
   turnRightNit(1);
  else if ((sensor[0] == 1) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1))               //ขวานิด
   turnRightNit(1);  
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 1))               //ขวา90
  {
 
    forward(100);
       scan();
       if(((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1))||((sensor[0] == 1) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1))||((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 1))){
            while(!((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1)))
      {     
       scan();  
       forward(1);
       }
      way[++index] = 'S';
       }
       else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 1)){
         while(!((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1)))
      {     
       scan();  
        turnLeft(1);
       }
        way[++index] = 'R';
    }
  }
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1))               //ขวา90
  {
       forward(100);
       scan();
       if(((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1))||((sensor[0] == 1) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1))||((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 1))){
            while(!((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1)))
      {     
       scan();  
       forward(1);
       }
         way[++index] = 'S';
       }
       else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 1)){
         while(!((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1)))
      {     
       scan();  
        turnLeft(1);
       }
        way[++index] = 'R';
    }
  }
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 1))               //ขวา90
   {
  
      
     /* forward(250);
       scan();
       if(((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1))||((sensor[0] == 1) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1))||((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 1))){
            while(!((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1)))
      {     
       scan();  
       forward(250);
       }

       }
       else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 1)){
         while(!((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1)))
      {     
       scan();  
       turnRight(1); 
       }
    }
    */
      speedMotor(100);
      turnLeft(1);
      
    speedMotor(150);
   }
  
 
  else if ((sensor[0] == 0) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 1))                //ซ้าย90
   {
  
      
      speedMotor(100);
      turnRight(1); 
      
    speedMotor(150);
  }
  else if ((sensor[0] == 1) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 0))                //ซ้าย90
    {
    
     
    
    forward(250);
       scan();
       if(((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1))||((sensor[0] == 1) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1))||((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 1))){
       while(!((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 0))){
             scan();  
     turnRight(1); 
        }
            while(!((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1)))
      {     
        scan();  
     turnRight(1); 
       }
        way[++index] = 'L';
       }
       else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 1)){
         while(!((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1)))
      {     
       scan();  
     turnRight(1); 
       }
       way[++index] = 'L';
  }
    }
  else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 0))                //ซ้าย90
    {
    
    
   
     
     
    forward(250);
       scan();
       if(((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1))||((sensor[0] == 1) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1))||((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 1))){
        while(!((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 0))){
            scan();  
     turnRight(1); 
        }
           
            while(!((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1)))
      {     
       scan();  
    turnRight(1); 
       }
         way[++index] = 'L'; 
       }
       else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 1)){
         while(!((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1)))
      {     
       scan();  
      turnRight(1); 
       }
       way[++index] = 'L';
    }
    }
  
  else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 0) && (sensor[4] == 0))                //ซ้าย90
     {
   
     
       forward(250);
       scan();
       if(((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1))||((sensor[0] == 1) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1))||((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 1))){
        while(!((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 0))){
            scan();  
     turnRight(1); 
        }
           
            while(!((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1)))
      {     
       scan();  
     turnRight(1);  
       }

       }
       else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 1)){
         while(!((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1)))
      {     
       scan();  
      turnRight(1); 
       }
    }
    }
  else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 0))                //ซ้าย90
     {
   
      
      speedMotor(100);
      turnLeft(1);
     
    speedMotor(150);
     }
  else{
    forward(1);

     }
    }
    else {
      int ass = 0;
      char bss ;
  
      
      while(way[ass]!=' '){
        bss = way[ass++];
      Serial.print(bss);
       
     }
     Serial.print(" ");
    }
}

//Define high-level H-bridge commands
void speedMotor(int speedMotor){
  analogWrite(enableA, speedMotor+20);  // ถ้าน้อยกว่าจะไปขวา
  analogWrite(enableB, speedMotor-15);  // ปรับค่าความเร็วของหุ่นยนต์
}
void enableMotors()
{
  motorAOn();
  motorBOn();
}
void scan(){
    sensor[0] = digitalRead(A1);
       sensor[1] = digitalRead(A2);
       sensor[2] = digitalRead(A3);
       sensor[3] = digitalRead(A4);
       sensor[4] = digitalRead(A5);
}
void disableMotors()
{
  motorAOff();
  motorBOff();
}

void forward(int time)
{
  motorAForward(3);
  motorBForward(3);

  delay(time);
}

void backward(int time)
{
  motorABackward(3);
  motorBBackward(3);
  delay(time);
}

void turnLeft(int time)
{
 // analogWrite(enableB,Speed+20);
  motorABackward(3);
  motorBForward(3);
 
  delay(time);
}

void turnRight(int time)
{
 // analogWrite(enableA,Speed+20);
  motorAForward(3);
  motorBBackward(3);
  delay(time);
}
void turnLeftNit(int time)
{ analogWrite(enableA,Speed+25);
  motorAForward(2);
  motorBForward(3);
  delay(time);
}

void turnRightNit(int time)
{
// analogWrite(enableB,Speed+25);
  motorAForward(3);
  motorBForward(2);
  delay(time);
}

void coast(int time)
{
  motorACoast();
  motorBCoast();
  delay(time);
}

void brake(int time)
{
  motorABrake();
  motorBBrake();
  delay(time);
}
//Define low-level H-bridge commands

//enable motors
void motorAOn()
{
  digitalWrite(enableA, HIGH);
}

void motorBOn()
{
  digitalWrite(enableB, HIGH);
}

//disable motors
void motorAOff()
{
  digitalWrite(enableB, LOW);
}

void motorBOff()
{
  digitalWrite(enableA, LOW);
}

//motor A controls
void motorAForward(int i)
{
   if(i==1){
     analogWrite(enableA,10);
     digitalWrite(pinA1, HIGH);
  digitalWrite(pinA2, LOW);
  }
  else if(i==2){
     analogWrite(enableA, Speed*3/4);
  digitalWrite(pinA1, HIGH);
  digitalWrite(pinA2, LOW);
  }
  
  else {
    
   digitalWrite(pinA1, HIGH);
   digitalWrite(pinA2, LOW);
  }

}

void motorABackward(int i)
   if(i==1){
     analogWrite(enableA,10);
     digitalWrite(pinA1, LOW);
  digitalWrite(pinA2, HIGH);
  }
  else if(i==2){
     analogWrite(enableA, Speed*3/4);
  digitalWrite(pinA1, LOW);
  digitalWrite(pinA2, HIGH);
  }
  
  else {
   digitalWrite(pinA1, LOW);
  digitalWrite(pinA2, HIGH);
  }

//motor B controls
void motorBForward(int i)
{
  if(i==1){
   analogWrite(enableB,10);
  digitalWrite(pinB1, HIGH);
  digitalWrite(pinB2, LOW);
  }
  else if(i==2){
    analogWrite(enableB,Speed*3/4);
    digitalWrite(pinB1, HIGH);
    digitalWrite(pinB2, LOW);
  }
  
  else {
    
    digitalWrite(pinB1, HIGH);
  digitalWrite(pinB2, LOW);
  }
}

void motorBBackward(int i)
{
 if(i==1){
   analogWrite(enableB,10);
  digitalWrite(pinB1, LOW);
  digitalWrite(pinB2, HIGH);
  }
  else if(i==2){
    analogWrite(enableB,Speed*3/4);
    digitalWrite(pinB1, LOW);
  digitalWrite(pinB2, HIGH);
  }
  
  else {
    
    digitalWrite(pinB1, LOW);
  digitalWrite(pinB2, HIGH);
  }
}

//coasting and braking
void motorACoast()
{
  digitalWrite(pinA1, LOW);
  digitalWrite(pinA2, LOW);
}

void motorABrake()
{
  digitalWrite(pinA1, HIGH);
  digitalWrite(pinA2, HIGH);
}

void motorBCoast()
{
  digitalWrite(pinB1, LOW);
  digitalWrite(pinB2, LOW);
}

void motorBBrake()
{
  digitalWrite(pinB1, HIGH);
  digitalWrite(pinB2, HIGH);
}
