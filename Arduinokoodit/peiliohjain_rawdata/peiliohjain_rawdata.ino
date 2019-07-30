
#define joystickRotation A1
#define joystickDirection A0
#define mirrorPower 3
#define polarity 4
#define mirrorSide 5
#define orientation 6
#define defog 7
#define on  LOW
#define off HIGH


//when up/left, polarity on. when down/right, polarity off
//when up/down, orientation on. when left/right, orientation off


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

  if (analogRead(joystickRotation) < 50) {
    Serial.println("defog on");
    digitalWrite(defog, on);
    digitalWrite(mirrorPower, off); //cut power of mirror motors when not wanted to move
  }




  //10kohm
  
  //left mirror
  else if (analogRead(joystickRotation) > 900) {
    digitalWrite(mirrorSide, off); //controlling left mirror
    digitalWrite(defog, off);

    if (analogRead(joystickDirection) < 100) {
      //middle
      digitalWrite(mirrorPower, off); //cut power of mirror motors when not wanted to move
    }


    else if (analogRead(joystickDirection) > 200 && analogRead(joystickDirection) < 250) {
      //up
      Serial.println("left mirror up");
      digitalWrite(polarity, on);
      digitalWrite(orientation, on);
      digitalWrite(mirrorPower, on);
    }
    else if (analogRead(joystickDirection) > 350 && analogRead(joystickDirection) < 420) {
      //down
      Serial.println("left mirror down");
      digitalWrite(polarity, off);
      digitalWrite(orientation, on);
      digitalWrite(mirrorPower, on);
    }
    else if (analogRead(joystickDirection) > 550 && analogRead(joystickDirection) < 600) {
      //left
      Serial.println("left mirror left");
      digitalWrite(polarity, on);
      digitalWrite(orientation, off);
      digitalWrite(mirrorPower, on);
    }
    else if (analogRead(joystickDirection) > 500 && analogRead(joystickDirection) < 550) {
      //right
      Serial.println("left mirror right");
      digitalWrite(polarity, off);
      digitalWrite(orientation, off);
      digitalWrite(mirrorPower, on);
    }
  }

  //right mirror
  else if (analogRead(joystickRotation) < 550 && analogRead(joystickRotation) > 0) {
    digitalWrite(mirrorSide, on); //controlling right mirror
    digitalWrite(defog, off);

    if (analogRead(joystickDirection) < 80) {
      //middle
      digitalWrite(mirrorPower, off); //cut power of mirror motors when not wanted to move
    }


    else if (analogRead(joystickDirection) > 150 && analogRead(joystickDirection) < 200) {
      //up
      Serial.println("right mirror up");
      digitalWrite(polarity, on);
      digitalWrite(orientation, on);
      digitalWrite(mirrorPower, on);
    }
    else if (analogRead(joystickDirection) > 250 && analogRead(joystickDirection) < 300) {
      //down
      Serial.println("right mirror down");
      digitalWrite(polarity, off);
      digitalWrite(orientation, on);
      digitalWrite(mirrorPower, on);
    }
    else if (analogRead(joystickDirection) > 370 && analogRead(joystickDirection) < 400) {
      //left
      Serial.println("right mirror left");
      digitalWrite(polarity, on);
      digitalWrite(orientation, off);
      digitalWrite(mirrorPower, on);
    }
    else if (analogRead(joystickDirection) > 300 && analogRead(joystickDirection) < 350) {
      //right
      Serial.println("right mirror right");
      digitalWrite(polarity, off);
      digitalWrite(orientation, off);
      digitalWrite(mirrorPower, on);
    }
  }












  /*

    //1kohm
   
    //left mirror
    else if (analogRead(joystickRotation) >= 550 && analogRead(joystickRotation) <= 700) {
      digitalWrite(mirrorSide, off); //controlling left mirror
      digitalWrite(defog, off);

      if (analogRead(joystickDirection) < 100) {
        //middle
        digitalWrite(mirrorPower, off); //cut power of mirror motors when not wanted to move
      }


      else if (analogRead(joystickDirection) > 130 && analogRead(joystickDirection) < 160) {
        //up
        Serial.println("left mirror up");
        digitalWrite(polarity, on);
        digitalWrite(orientation, on);
        digitalWrite(mirrorPower, on);
      }
      else if (analogRead(joystickDirection) > 260 && analogRead(joystickDirection) < 280) {
        //down
        Serial.println("left mirror down");
        digitalWrite(polarity, off);
        digitalWrite(orientation, on);
        digitalWrite(mirrorPower, on);
      }
      else if (analogRead(joystickDirection) > 420 && analogRead(joystickDirection) < 450) {
        //left
        Serial.println("left mirror left");
        digitalWrite(polarity, on);
        digitalWrite(orientation, off);
        digitalWrite(mirrorPower, on);
      }
      else if (analogRead(joystickDirection) > 350 && analogRead(joystickDirection) < 400) {
        //right
        Serial.println("left mirror right");
        digitalWrite(polarity, off);
        digitalWrite(orientation, off);
        digitalWrite(mirrorPower, on);
      }
    }

    //right mirror
    else if (analogRead(joystickRotation) < 550 && analogRead(joystickRotation) > 0) {
      digitalWrite(mirrorSide, on); //controlling right mirror
      digitalWrite(defog, off);

      if (analogRead(joystickDirection) < 80) {
        //middle
        digitalWrite(mirrorPower, off); //cut power of mirror motors when not wanted to move
      }


      else if (analogRead(joystickDirection) > 80 && analogRead(joystickDirection) < 100) {
        //up
        Serial.println("right mirror up");
        digitalWrite(polarity, on);
        digitalWrite(orientation, on);
        digitalWrite(mirrorPower, on);
      }
      else if (analogRead(joystickDirection) > 150 && analogRead(joystickDirection) < 180) {
        //down
        Serial.println("right mirror down");
        digitalWrite(polarity, off);
        digitalWrite(orientation, on);
        digitalWrite(mirrorPower, on);
      }
      else if (analogRead(joystickDirection) > 240 && analogRead(joystickDirection) < 270) {
        //left
        Serial.println("right mirror left");
        digitalWrite(polarity, on);
        digitalWrite(orientation, off);
        digitalWrite(mirrorPower, on);
      }
      else if (analogRead(joystickDirection) > 200 && analogRead(joystickDirection) < 240) {
        //right
        Serial.println("right mirror right");
        digitalWrite(polarity, off);
        digitalWrite(orientation, off);
        digitalWrite(mirrorPower, on);
      }
    }




  */



  Serial.println(String(analogRead(joystickRotation))+"\t\t"+String(analogRead(joystickDirection))+"\t\t"+String(analogRead(joystickRotation) - analogRead(joystickDirection)));

  delay(100);
}


/*


  void applySetting (int setting) {
  switch (setting) {
    case 0:
      //null everything
      digitalWrite(mirrorPower, off);
      digitalWrite(polarity, off);
      digitalWrite(mirrorSide, off);
      digitalWrite(orientation, off);
      digitalWrite(defog, off);
      break;

    case 1:
      break;

    case 2:
      break;

    case 3:
      break;

    case 4:
      break;

    case 5:
      break;

    case 6:
      break;

    case 7:
      break;

    case 8:
      break;

    case 9:
      break;

    case 10:
      break;

    case 11:
      break;

    case 12:
      break;

    case 13:
      break;
  }
  }*/
