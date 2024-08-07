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
  Serial1.begin(115200);
  Serial1.println("holi");
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
   pinMode(LED_BUILTIN, OUTPUT);
}


unsigned int counter = 0;

void loop() {

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  const int duration = pulseIn(echo, HIGH);
  const int durationfr = duration / 58;

  Serial1.print("Distance in CM: ");
  Serial1.println(durationfr);
  
  tm.display(0, (durationfr / 1000) % 10);
  tm.display(1, (durationfr / 100) % 10);
  tm.display(2, (durationfr / 10) % 10);
  tm.display(3, durationfr % 10);
  
  if durationfr < 15 (
    digitalWrite(LED_BUILTIN, HIGH);  
  ) else (
    digitalWrite(LED_BUILTIN, LOW);
  )

  /*
  if durationfr > 9 (
     tm.display(0, (durationfr));
  ) else (
     tm.display(0, (counter / 1000) % 10);
     tm.display(1, (counter / 100) % 10);
  )

  tm.display(0, (counter / 1000) % 10);
  tm.display(1, (counter / 100) % 10);
  tm.display(2, (counter / 10) % 10);
  tm.display(3, counter % 10);

  counter++;
  if (counter == 10000) {
    counter = 0;
  }
  */
  delay(1);
}
