#include <IRSendRev.h>

int x;

int y;

boolean buzzer;

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
  if (x > 700) {
    // 前進
    dtaInit();
    dtaSend[6] = 1;
    IR.Send(dtaSend,38);

  } else if (y > 700) {
    // 右
    dtaInit();
    dtaSend[6] = 2;
    IR.Send(dtaSend,38);
  } else if (y < 280) {
    // 左
    dtaInit();
    dtaSend[6] = 3;
    IR.Send(dtaSend,38);
  } else if (x < 280) {
    // 後進
    dtaInit();
    dtaSend[6] = 4;
    IR.Send(dtaSend,38);
  }
  delay(500);
}

void setup()
{
  pinMode(2, INPUT);
  Serial.begin(9600);
}


void loop()
{
  x = analogRead(A1);
  y = analogRead(A0);
  Serial.print(x);
  Serial.print(",");
  Serial.println(y);
  
  buzzer = digitalRead(2);
  send_data();

}
