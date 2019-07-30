

#define RX 0
#define TX 1
#define pir1 2
#define pir2 3
#define eth1 4//eth?
#define pir3 5
#define pir4 6
#define pir5 7
#define btn1 8
#define btn2 9
#define eth2 10//eth?
#define eth3 11//eth?
#define eth4 12//eth?
#define eth5 13//eth?
#define btn3 14
#define btn4 15
#define btn5 16
#define btn6 17
#define btn7 18
#define btn8 19





//state variables
bool btn1b = false;
bool btn2b = false;
bool btn3b = false;
bool btn4b = false;
bool btn5b = false;
bool btn6b = false;
bool btn7b = false;
bool btn8b = false;
bool pir1b = false;
bool pir2b = false;
bool pir3b = false;
bool pir4b = false;
bool pir5b = false;



bool checkResistance(int pin){
    
}



//go through pins, check levels and apply state accordingly
void checkButtons() {

  if (checkResistance(btn1) != btn1b) {
    btn1b = checkResistance(btn1);
    if (btn1b) {
    }
  }
  if (checkResistance(btn2) != btn2b) {
    btn2b = checkResistance(btn2);
    if (btn2b) {
    }
  }
  if (checkResistance(btn3) != btn3b) {
    btn3b = checkResistance(btn3);
    if (btn3b) {
    }
  }
  if (checkResistance(btn4) != btn4b) {
    btn4b = checkResistance(btn4);
    if (btn4b) {
    }
  }
  if (checkResistance(btn5) != btn5b) {
    btn5b = checkResistance(btn5);
    if (btn5b) {
    }
  }
  if (checkResistance(btn6) != btn6b) {
    btn6b = checkResistance(btn6);
    if (btn6b) {
    }
  }
  if (checkResistance(btn7) != btn7b) {
    btn7b = checkResistance(btn7);
    if (btn7b) {
    }
  }
  if (checkResistance(btn8) != btn8b) {
    btn8b = checkResistance(btn8);
    if (btn8b) {
    }
  }
}

void setup() {
  Serial.begin(9600);

  //set correct pinmodes. propably one analog for each pin.
  
}

void loop() {
  checkButtons();
}

