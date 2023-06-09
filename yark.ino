#include <QTRSensors.h>

QTRSensors qtr;

const uint8_t SensorCount = 6;
uint16_t sensorValues[SensorCount];

const int Enable_A = 3;
const int Enable_B = 2;
const int inputA1 = 9;
const int inputA2 = 8;
const int inputB1 = 7;
const int inputB2 = 6;

void setup() {
  pinMode(Enable_A, OUTPUT);
  pinMode(Enable_B, OUTPUT);
  pinMode(inputA1, OUTPUT);
  pinMode(inputA2, OUTPUT);
  pinMode(inputB1, OUTPUT);
  pinMode(inputB2, OUTPUT);
  digitalWrite(Enable_A, HIGH);
  digitalWrite(Enable_B, HIGH);

  qtr.setTypeAnalog();
  qtr.setSensorPins((const uint8_t[]){A0, A1, A2, A3, A4, A5}, SensorCount);
  qtr.setEmitterPin(2);

  delay(500);
  pinMode(LED_BUILTIN, OUTPUT);

  for (uint16_t i = 0; i < 400; i++)
  {
    qtr.calibrate();
  }
}

void forward(){
  digitalWrite(inputA1, HIGH);
  digitalWrite(inputA2, LOW);
  digitalWrite(inputB1 , HIGH);
  digitalWrite(inputB2, LOW);
}


void stop_(){
  digitalWrite(inputA1, LOW);
  digitalWrite(inputA2, LOW);
  digitalWrite(inputB1 , LOW);
  digitalWrite(inputB2, LOW);
}
void left(){
  digitalWrite(inputA1, HIGH);
  digitalWrite(inputA2, LOW);
  digitalWrite(inputB1 , LOW);
  digitalWrite(inputB2, LOW);
}

void right(){
  digitalWrite(inputA1, LOW);
  digitalWrite(inputA2, LOW);
  digitalWrite(inputB1 , HIGH);
  digitalWrite(inputB2, LOW);; 
}

void decide() {
  uint16_t position = qtr.readLineBlack(sensorValues);

  while(!(position[2] == 1 && position[3] == 1)) {
    pos = -1

    for (i=0; arr[i]; ++i)
        if (arr[i] == 1) pos = i

    if(pos < 3) left()
    if(pos > 3) right()
  }
}

void loop(){
  digitalWrite(Enable_A, HIGH);
  digitalWrite(Enable_B, HIGH);
  //----------Motor çalıştır-----------//
  digitalWrite(inputA1, HIGH);
  digitalWrite(inputA2, LOW);
  digitalWrite(inputB1 , HIGH);
  digitalWrite(inputB2, LOW);
  delay(3000);
  //-------Motoru devre disi birak----------//
  digitalWrite(Enable_A, LOW);
  digitalWrite(Enable_B, LOW);
  delay(3000);
  //-------Ters Bağlama----------//
  digitalWrite(Enable_A, HIGH);
  digitalWrite(Enable_B, HIGH);
  digitalWrite(inputA1, LOW);
  digitalWrite(inputA2, HIGH);
  digitalWrite(inputB1 , LOW);
  digitalWrite(inputB2, HIGH);
  delay(3000);
  //-------Motor devre disi----------//
  digitalWrite(Enable_A, LOW);
  digitalWrite(Enable_B, LOW);
  delay(3000);
 }
