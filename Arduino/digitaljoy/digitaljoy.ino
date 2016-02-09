#include <IRSendRev.h>

unsigned char dtaSend[20];

void dtaInit()
{
  dtaSend[0] = 11;
  dtaSend[1] = 180;
  dtaSend[2] = 91;
  dtaSend[3] = 11;
  dtaSend[4] = 33;
  dtaSend[5] = 1;
}

void send_data() {
  if (digitalRead(10) == LOW) {
    // 前進
    dtaInit();
    dtaSend[6] = 1;
    IR.Send(dtaSend,38);

  } else if (digitalRead(11) == LOW) {
    // 右
    dtaInit();
    dtaSend[6] = 2;
    IR.Send(dtaSend,38);
  } else if (digitalRead(12) == LOW) {
    // 左
    dtaInit();
    dtaSend[6] = 3;
    IR.Send(dtaSend,38);
  } else if (digitalRead(13) == LOW) {
    // 後進
    dtaInit();
    dtaSend[6] = 4;
    IR.Send(dtaSend,38);
  }
  delay(500);
}

void setup()
{
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
}


void loop()
{
  send_data();

}