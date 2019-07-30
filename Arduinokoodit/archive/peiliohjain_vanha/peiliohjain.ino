//int analogPin = 0;
int raw = 0;
int Vin = 5;
float Vout = 0;
float R1 = 1000;
float R2 = 0;
float buffer = 0;




void checkSide(int analogPin) {
  raw = analogRead(analogPin);
  if (raw) {
    buffer = raw * Vin;
    Vout = (buffer) / 1024.0;
    buffer = (Vin / Vout) - 1;
    R2 = R1 * buffer;
    Serial.print("Pin: ");
    Serial.print(analogPin);
    Serial.print("\t\t\t\t\t");
    Serial.print("Vout: ");
    Serial.print(Vout);
    Serial.print("\t\t\t\t\t");
    Serial.print("R2: ");
    Serial.println(R2);
  }
  else {
    Serial.println("--------------------------------------------------------------------");
  }
}

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.println(analogRead(1));
  delay(500);
}
