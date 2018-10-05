//Code by Reichenstein7 (thejamerson.com)

//Keyboard Controls:

// 1 -Motor 1 Left

// 2 -Motor 1 Stop

// 3 -Motor 1 Right

// 4 -Motor 2 Left

// 5 -Motor 2 Stop

// 6 -Motor 2 Right

// Declare L298N Dual H-Bridge Motor Controller directly since there is not a library to load.

// Motor 1

int dir1PinA = 7;

int dir2PinA = 8;

int speedPinA = 6; // Needs to be a PWM pin to be able to control motor speed

// Motor 2

int dir1PinB = 9;

int dir2PinB = 10;

int speedPinB = 11; // Needs to be a PWM pin to be able to control motor speed

 int a = 0 ;
 int b = 0;

void setup() {  // Setup runs once per reset

            Serial.begin(9600);

//Define L298N Dual H-Bridge Motor Controller Pins

    pinMode(dir1PinA,OUTPUT);

    pinMode(dir2PinA,OUTPUT);

    pinMode(speedPinA,OUTPUT);

    pinMode(dir1PinB,OUTPUT);

    pinMode(dir2PinB,OUTPUT);

    pinMode(speedPinB,OUTPUT);
  
//  digitalWrite(speedPinA, HIGH);
//    digitalWrite(speedPinB, HIGH);
}

void loop() {
  digitalWrite(speedPinA,HIGH);
  digitalWrite(speedPinB,HIGH);
// Initialize the Serial interface:

if (Serial.available() > 0) {

int inByte = Serial.read();

int speed; // Local variable

switch (inByte) {

      //______________Motor 1______________

      case '1': // Motor 1 Forward
          analogWrite(speedPinA,255);//Sets speed variable via PWM 

          digitalWrite(dir1PinA, LOW);

          digitalWrite(dir2PinA, HIGH);

          Serial.println("Motor 1 Forward"); // Prints out â€œMotor 1 Forwardâ€ on the serial monitor

          Serial.println("   "); // Creates a blank line printed on the serial monitor
//
//              a = digitalRead(12);
//      Serial.println(a);
//       b = digitalRead(13);
//      Serial.println(b);
//      int tmp = analogRead(A0);
//      Serial.println(tmp);
      break;

 

      case '2': // Motor 1 Stop (Freespin)

          analogWrite(speedPinA, 0);

          digitalWrite(dir1PinA, LOW);

          digitalWrite(dir2PinA, HIGH);

          Serial.println("Motor 1 Stop");

          Serial.println("   ");

//              a = digitalRead(12);
//      Serial.println(a);
//       b = digitalRead(13);
//      Serial.println(b);
      break;

 

      case '3': // Motor 1 Reverse

          analogWrite(speedPinA, 255);

          digitalWrite(dir1PinA, HIGH);

          digitalWrite(dir2PinA, LOW);

          Serial.println("Motor 1 Reverse");

          Serial.println("   ");
//           a = digitalRead(12);
//      Serial.println(a);
//       b = digitalRead(13);
//      Serial.println(b);

      break;

 

      //______________Motor 2______________

 

      case '4': // Motor 2 Forward

          analogWrite(speedPinB, 255);

          digitalWrite(dir1PinB, LOW);

          digitalWrite(dir2PinB, HIGH);

          Serial.println("Motor 2 Forward");

          Serial.println("   ");

      break;

 

      case '5': // Motor 1 Stop (Freespin)

          analogWrite(speedPinB, 0);

          digitalWrite(dir1PinB, LOW);

          digitalWrite(dir2PinB, HIGH);

          Serial.println("Motor 2 Stop");

          Serial.println("   ");

      break;

 

      case '6': // Motor 2 Reverse

          analogWrite(speedPinB, 255);

          digitalWrite(dir1PinB, HIGH);

          digitalWrite(dir2PinB, LOW);

          Serial.println("Motor 2 Reverse");

          Serial.println("   ");

      break;

 

    default:

      // turn all the connections off if an unmapped key is pressed:

      for (int thisPin = 2; thisPin < 11; thisPin++) 

      {

        digitalWrite(thisPin, LOW);

      }
   
    }

  }

}
