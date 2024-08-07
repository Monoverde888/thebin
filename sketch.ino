// Now turn this trash into treasure!

#include <TM1637.h>

const int CLK = 2;
const int DIO = 3;
const int trig = 27;
const int echo = 26;

TM1637 tm(CLK, DIO);

void setup() {
  tm.init();
  tm.set(BRIGHT_TYPICAL);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

unsigned int counter = 0;

void loop() {

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  int duration = pulseIn(echo, HIGH);
  Serial.print("Distance in CM: ");
  Serial.println(duration / 58);
  Serial.print("Distance in inches: ");
  Serial.println(duration / 148);
  /*
  tm.display(0, (counter / 1000) % 10);
  tm.display(1, (counter / 100) % 10);
  tm.display(2, (counter / 10) % 10);
  tm.display(3, counter % 10);

  counter++;
  if (counter == 10000) {
    counter = 0;
  }
*/
  delay(100);
}
