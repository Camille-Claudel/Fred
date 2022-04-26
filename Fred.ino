#include <Servo.h>

Servo servos[5];

// be careful, the first 2 must be on the short side of the motor block
// and the last 3 on the long side
int pins[5] = {3,5,6,9,10};

int bounds[5][2] = { // closed and open position of each finger
  {30,100}, // short 1
  {30,130}, // short 2
  {30,120}, // long 1
  {20,120}, // long 2
  {30,110}  // long 3
};

void doPosition(String code)
{
  /*
  interprets a sequence of 0s and 1s as positions for each finger
  for example "11011" is:
    pinky closed
    ring finger closed
    middle finger open
    index finger closed
    thumb closed
  */
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
    // angles reversed because the motors of the long side are facing the opposite direction
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
  // by default, open and closes the hand with a delay of 1 second
  delay(1000);
  doPosition("00000");
  delay(1000);
  doPosition("11111");
}
