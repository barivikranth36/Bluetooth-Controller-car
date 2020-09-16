int leftMotorEna = 9;
int leftMotorIn1 = 8;
int leftMotorIn2 = 7;

int rightMotorIn3 = 10;
int rightMotorIn4 = 12;
int rightMotorEnb = 11;

int motorSpeed = 254;
//int turnSpeed = 230;
int turnDelay = 10;

int appValue;

void setup() {
  // put your setup code here, to run once:
  pinMode(leftMotorIn1, OUTPUT);
  pinMode(leftMotorIn2, OUTPUT);
  pinMode(leftMotorEna, OUTPUT);

  pinMode(rightMotorIn3, OUTPUT);
  pinMode(rightMotorIn4, OUTPUT);
  pinMode(rightMotorEnb, OUTPUT);

  Serial.begin(9600);

}

void loop() {

  if(Serial.available() > 0) {
    int c = Serial.read();
    //appValue += c;
    Serial.println(c);
    //appValue = "";
   
    //  FORWARD
    if(c == 49) {
  
      Serial.println("Moving Forward");
      digitalWrite(leftMotorIn1, HIGH);
      digitalWrite(leftMotorIn2, LOW);
      digitalWrite(rightMotorIn3, HIGH);
      digitalWrite(rightMotorIn4, LOW);
  
      analogWrite(leftMotorEna, motorSpeed);
      analogWrite(rightMotorEnb, motorSpeed);
  
      delay(100);
    }
  

    //  TURNING RIGHT
    else if(c == 51) {
  
      Serial.println("Moving Right");
      digitalWrite(leftMotorIn1, HIGH);
      digitalWrite(leftMotorIn2, LOW);
      digitalWrite(rightMotorIn3, LOW);
      digitalWrite(rightMotorIn4, LOW);
      
      analogWrite(leftMotorEna, motorSpeed);
      analogWrite(rightMotorEnb, 0);
  
      delay(100);
    }
  
    //  TURNING LEFT
    else if(c == 52) {
  
      Serial.println("Moving Left");
      digitalWrite(leftMotorIn1, LOW);
      digitalWrite(leftMotorIn2, LOW);
      digitalWrite(rightMotorIn3, HIGH);
      digitalWrite(rightMotorIn4, LOW);

      analogWrite(leftMotorEna, 0);
      analogWrite(rightMotorEnb, motorSpeed);
      
      delay(100);
    }

    else if(c == 50) {
      //  BACKWARD
      Serial.println("Moving Back");
      digitalWrite(leftMotorIn1, LOW);
      digitalWrite(leftMotorIn2, HIGH);
      
      digitalWrite(rightMotorIn3, LOW);
      digitalWrite(rightMotorIn4, HIGH);
      
      analogWrite(leftMotorEna, motorSpeed);
      analogWrite(rightMotorEnb, motorSpeed);
      Serial.println("TEst");
      delay(1000);
    }
  
    //  STOP
    else {
      digitalWrite(leftMotorIn1, LOW);
      digitalWrite(leftMotorIn2, LOW);
      digitalWrite(rightMotorIn3, LOW);
      digitalWrite(rightMotorIn4, LOW);
  
      analogWrite(leftMotorEna, 0);
      analogWrite(rightMotorEnb, 0);
  
      delay(100);
    }
  }
}
