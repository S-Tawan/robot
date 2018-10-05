//มอเตอร์
int enableA = 6;
int pinA1 = 7;
int pinA2 = 8;
int enableB = 11;
int pinB1 = 12;
int pinB2 = 13;

// แขนกล
int ser_hand = 3;
int ser_arm = 9;

// องศาแขน
int close = 180;
int open = 70;
int up = 155;
int down = 80;

//ความเร็วมอเตอร์ล้อ
int Speed = 150;

// เซ็นเซอร์
int sensor[5] = {0, 0, 0, 0, 0};

void setup()
{
  Serial.begin(9600);
  pinMode(enableA, OUTPUT);
  pinMode(pinA1, OUTPUT);
  pinMode(pinA2, OUTPUT);

  pinMode(enableB, OUTPUT);
  pinMode(pinB1, OUTPUT);
  pinMode(pinB2, OUTPUT);
  pinMode(13, OUTPUT);

  pinMode(ser_hand, OUTPUT);
  pinMode(ser_arm, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  // arm_up(1000);
  // hand_open(1000);
  // arm_down(1000);
  // hand_close(1000);
  scan();
  if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1))
  {
    forward(1);
  }
  else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 1))
  {
    turnLeftNit(1);
  }
  else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 0) && (sensor[4] == 1))
  {
    turnLeftNit(1);
  }
  else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 0) && (sensor[4] == 0))
  {

    analogWrite(enableB, speedMotor + 10);
    turnLeftNit(1);
  }
  else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 0))
  {

    turnLeft(20);
  }
  else if ((sensor[0] == 1) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1))
  {
    turnRigthNit(1);
  }
  else if ((sensor[0] == 1) && (sensor[1] == 0) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 1))
  {
    turnRigthNit(1);
  }
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 1))
  {
    analogWrite(enableA, speedMotor + 10);
    turnRigthNit(1);
  }
  else if ((sensor[0] == 0) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 1))
  {
    turnRight(20);
  }
  else
  {
    forward(1);
  }
}

void scan()
{
  sensor[0] = digitalRead(A1);
  sensor[1] = digitalRead(A2);
  sensor[2] = digitalRead(A3);
  sensor[3] = digitalRead(A4);
  sensor[4] = digitalRead(A5);
}

//ฟังชั่นสั่งแขน
void hand_open(int time)
{
  analogWrite(ser_hand, open);
  delay(time);
}
void hand_close(int time)
{
  analogWrite(ser_hand, close);
  delay(time);
}
void arm_up(int time)
{
  analogWrite(ser_arm, up);
  delay(time);
}
void arm_down(int time)
{
  analogWrite(ser_arm, down);
  delay(time);
}

void speedMotor(int speedMotor)
{
  analogWrite(enableA, speedMotor + 20); // ถ้าน้อยกว่าจะไปขวา
  analogWrite(enableB, speedMotor - 15); // ปรับค่าความเร็วของหุ่นยนต์

  void scan()
  {
    sensor[0] = digitalRead(A1);
    sensor[1] = digitalRead(A2);
    sensor[2] = digitalRead(A3);
    sensor[3] = digitalRead(A4);
    sensor[4] = digitalRead(A5);
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
    motorABackward(3);
    motorBForward(3);

    delay(time);
  }

  void turnRight(int time)
  {
    motorAForward(3);
    motorBBackward(3);
    delay(time);
  }
  void turnLeftNit(int time)
  {
    motorAForward(2);
    motorBForward(3);
    delay(time);
  }

  void turnRightNit(int time)
  {
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

  void motorAForward(int i)
  {
    if (i == 1)
    {
      analogWrite(enableA, 10);
      digitalWrite(pinA1, HIGH);
      digitalWrite(pinA2, LOW);
    }
    else if (i == 2)
    {
      analogWrite(enableA, (Speed * 3) / 4);
      digitalWrite(pinA1, HIGH);
      digitalWrite(pinA2, LOW);
    }

    else
    {

      digitalWrite(pinA1, HIGH);
      digitalWrite(pinA2, LOW);
    }
  }

  void motorABackward(int i)
  {

    if (i == 1)
    {
      analogWrite(enableA, 10);
      digitalWrite(pinA1, LOW);
      digitalWrite(pinA2, HIGH);
    }
    else if (i == 2)
    {
      analogWrite(enableA, (Speed * 3) / 4);
      digitalWrite(pinA1, LOW);
      digitalWrite(pinA2, HIGH);
    }

    else
    {
      digitalWrite(pinA1, LOW);
      digitalWrite(pinA2, HIGH);
    }
  }

  void motorBForward(int i)
  {
    if (i == 1)
    {
      analogWrite(enableB, 10);
      digitalWrite(pinB1, HIGH);
      digitalWrite(pinB2, LOW);
    }
    else if (i == 2)
    {
      analogWrite(enableB, (Speed * 3) / 4);
      digitalWrite(pinB1, HIGH);
      digitalWrite(pinB2, LOW);
    }

    else
    {

      digitalWrite(pinB1, HIGH);
      digitalWrite(pinB2, LOW);
    }
  }

  void motorBBackward(int i)
  {
    if (i == 1)
    {
      analogWrite(enableB, 10);
      digitalWrite(pinB1, LOW);
      digitalWrite(pinB2, HIGH);
    }
    else if (i == 2)
    {
      analogWrite(enableB, (Speed * 3) / 4);
      digitalWrite(pinB1, LOW);
      digitalWrite(pinB2, HIGH);
    }

    else
    {

      digitalWrite(pinB1, LOW);
      digitalWrite(pinB2, HIGH);
    }
  }

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
