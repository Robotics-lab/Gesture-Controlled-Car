#include <VirtualWire.h>
#include <VirtualWire_Config.h>
char *send;
const int flex_pin1 = A0;
const int flex_pin2 = A1;
const int flex_pin3 = A2;
const int flex_pin4 = A3;
const float vcc = 4.98; 
const float ext_resist = 100000.0;
const float straight_flex_resist = 37300.0; 
const float bend_flex_resist = 90000.0;
void setup() {
  pinMode(flex_pin1,INPUT);
  pinMode(flex_pin2,INPUT);
  pinMode(flex_pin3,INPUT);
  pinMode(flex_pin4,INPUT);
  pinMode(12,OUTPUT);
  vw_set_ptt_inverted(true);
  vw_set_tx_pin(12);
  vw_setup(4000);
}

void loop() {
 int flexADC1 = analogRead(flex_pin1);
 int flexADC2 = analogRead(flex_pin2);
 int flexADC3 = analogRead(flex_pin3);
 int flexADC4 = analogRead(flex_pin4);
 float flexV1 = flexADC1 * vcc / 1023.0;
 float flexR1 = ext_resist * (vcc / flexV1 - 1.0);
 float flexV2 = flexADC2 * vcc / 1023.0;
 float flexR2 = ext_resist * (vcc / flexV2 - 1.0);
 float flexV3 = flexADC3 * vcc / 1023.0;
 float flexR3 = ext_resist * (vcc / flexV3 - 1.0);
 float flexV4 = flexADC4 * vcc / 1023.0;
 float flexR4 = ext_resist * (vcc / flexV4 - 1.0);
 float angle1 = map(flexR1, straight_flex_resist, bend_flex_resist, 0, 90.0);
 float angle2 = map(flexR2, straight_flex_resist, bend_flex_resist, 0, 90.0);
 float angle3 = map(flexR3, straight_flex_resist, bend_flex_resist, 0, 90.0);
 float angle4 = map(flexR4, straight_flex_resist, bend_flex_resist, 0, 90.0);
 if (angle1 > 20 && angle2 > 20)
 {
  send="a";
  vw_send((uint8_t *)send, strlen(send));
  vw_wait_tx();
 }
 else if (angle3 > 20 && angle4 > 20)
 {
  send="b";
  vw_send((uint8_t *)send, strlen(send));
  vw_wait_tx();
 }
 else if (angle1 > 20)
 {
  send="c";
  vw_send((uint8_t *)send, strlen(send));
  vw_wait_tx();
 }
 else if (angle2 > 20)
 {
  send="d";
  vw_send((uint8_t *)send, strlen(send));
  vw_wait_tx();
 }
 else if (angle3 > 20)
 {
  send="e";
  vw_send((uint8_t *)send, strlen(send));
  vw_wait_tx();
 }
 else if (angle4 > 20)
 {
  send="f";
  vw_send((uint8_t *)send, strlen(send));
  vw_wait_tx();
 }
 else
 {
  send="g";
  vw_send((uint8_t *)send, strlen(send));
  vw_wait_tx();
 }
delay(500);
}
