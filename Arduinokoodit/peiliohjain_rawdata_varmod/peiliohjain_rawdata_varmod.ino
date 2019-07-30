
#define joystickRotation A1
#define joystickDirection A0
#define mirrorPower 3
#define polarity 4
#define mirrorSide 5
#define orientation 6
#define defog 7
#define on  LOW
#define off HIGH

int joyDirection = 0;
int joyRotation = 0;

//when up/left, polarity on. when down/right, polarity off
//when up/down, orientation on. when left/right, orientation off

//directions are fucked up. right side mirror needs repairs on horisontal axis.


void setup()
{
  Serial.begin(9600);

  //relay-controlling pins
  pinMode(mirrorPower, OUTPUT);
  pinMode(polarity, OUTPUT);
  pinMode(mirrorSide, OUTPUT);
  pinMode(orientation, OUTPUT);
  pinMode(defog, OUTPUT);


  digitalWrite(mirrorPower, off);
  digitalWrite(polarity, off);
  digitalWrite(mirrorSide, off);
  digitalWrite(orientation, off);
  digitalWrite(defog, off);
}

void loop() {
  joyRotation = analogRead(joystickRotation);
  joyDirection = analogRead(joystickDirection);


  if (joyRotation < 100) {
    Serial.println("defog on");
    digitalWrite(defog, on);
    digitalWrite(mirrorPower, off); //cut power of mirror motors when not wanted to move
  }

  //right mirror
  else if (joyRotation < 430) {
    digitalWrite(mirrorSide, on); //controlling right mirror
    digitalWrite(defog, off);
    
    if (joyDirection < 90) {
      //middle
      digitalWrite(mirrorPower, off); //cut power of mirror motors when not wanted to move
    }
    else if (joyDirection < 170) {
      //up
      Serial.println("right mirror up \t"+ String(joyRotation)+"\t"+ String(joyDirection));
      digitalWrite(polarity, on);
      digitalWrite(orientation, off);
      digitalWrite(mirrorPower, on);
    }
    else if (joyDirection < 220) {
      //down
      Serial.println("right mirror down \t"+ String(joyRotation)+"\t"+ String(joyDirection));
      digitalWrite(polarity, off);
      digitalWrite(orientation, off);
      digitalWrite(mirrorPower, on);
    }
    else if (joyDirection < 260) {
      //right
      Serial.println("right mirror right \t"+ String(joyRotation)+"\t"+ String(joyDirection));
      digitalWrite(polarity, off);
      digitalWrite(orientation, on);
      digitalWrite(mirrorPower, on);
    }
    else if (joyDirection < 300) {
      //left
      Serial.println("right mirror left \t"+ String(joyRotation)+"\t"+ String(joyDirection));
      digitalWrite(polarity, on);
      digitalWrite(orientation, on);
      digitalWrite(mirrorPower, on);
    }
  }



  //left mirror
  else if (joyRotation < 630) {
    digitalWrite(mirrorSide, off); //controlling left mirror
    digitalWrite(defog, off);

    if (joyDirection < 90) {
      //middle
      digitalWrite(mirrorPower, off); //cut power of mirror motors when not wanted to move
    }
    else if (joyDirection < 250) {
      //up
      Serial.println("left mirror up \t\t"+ String(joyRotation)+"\t"+ String(joyDirection));
      digitalWrite(polarity, on);
      digitalWrite(orientation, off);
      digitalWrite(mirrorPower, on);
    }
    else if (joyDirection < 350) {
      //down
      Serial.println("left mirror down \t\t"+ String(joyRotation)+"\t"+ String(joyDirection));
      digitalWrite(polarity, off);
      digitalWrite(orientation, off);
      digitalWrite(mirrorPower, on);
    }
    else if (joyDirection < 400) {
      //right
      Serial.println("left mirror right \t\t"+ String(joyRotation)+"\t"+ String(joyDirection));
      digitalWrite(polarity, off);
      digitalWrite(orientation, on);
      digitalWrite(mirrorPower, on);
    }
    else if (joyDirection < 500) {
      //left
      Serial.println("left mirror left \t\t"+ String(joyRotation)+"\t"+ String(joyDirection));
      digitalWrite(polarity, on);
      digitalWrite(orientation, on);
      digitalWrite(mirrorPower, on);
    }
  }




  //Serial.println(String(joyRotation)+"\t\t"+String(joyDirection));

  delay(100);
}
