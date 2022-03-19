#include <Servo.h>

Servo servos[5];
int pins[5] = {3,5,6,9,10};
int bounds[5][2] = {
  {30,100}, // short 1
  {30,130}, // short 2
  {30,120}, // long 1
  {20,120}, // long 2
  {30,110}  // long 3
};
bool alternate = true;

void doPosition(String code)
{
  for (int i = 0; i < 2; i++) // short side
  {
    if (code[i] == '0')
    {
      servos[i].write(bounds[i][0]);
    }
    else if (code[i] == '1')
    {
      servos[i].write(bounds[i][1]);
    }
  }
  for (int i = 2; i < 5; i++) // long side
  {
    if (code[i] == '0')
    {
      servos[i].write(180-bounds[i][0]);
    }
    else if (code[i] == '1')
    {
      servos[i].write(180-bounds[i][1]);
    }
  }
}

void setup() {
  for (int i = 0; i < 5; i++)
  {
    servos[i].attach(pins[i]);
  }
}

void loop() {
  if (alternate)
  {
    delay(1000);
    doPosition("00000");
    delay(1000);
    doPosition("11111");
  }
  else
  {
    doPosition("00000");
  }
}
