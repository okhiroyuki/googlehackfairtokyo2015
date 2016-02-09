#include <IRSendRev.h>

#include <Shieldbot.h>

int method;

unsigned char dta[20];

Shieldbot shieldbot = Shieldbot();

void control_bot() {
  if (method == 1) {
    shieldbot.forward();

  } else if (method == 2) {
    shieldbot.drive(127,0);
  } else if (method == 3) {
    shieldbot.drive(0,127);
  } else if (method == 4) {
    shieldbot.backward();
  }
  delay(500);
  shieldbot.stop();
  method = 0;
}

void setup()
{
  IR.Init(2);

  Serial.begin(9600);

  pinMode(5, OUTPUT);
}


void loop()
{
  if (IR.IsDta()) {
    IR.Recv(dta);
    method = dta[6];
    Serial.println(method);
    digitalWrite(5,HIGH);

  }
  control_bot();
  digitalWrite(5,LOW);

}