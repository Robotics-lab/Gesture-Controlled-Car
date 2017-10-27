#include <VirtualWire.h>
const int transmit_pin = 12;
const int FLEX_PIN1 = A0; 
const int FLEX_PIN2 = A1;
const int FLEX_PIN3 = A2; 
const int FLEX_PIN4 = A3; 
const float VCC = 4.98;
const float R_DIV = 47500.0;
const float STRAIGHT_RESISTANCE1 = 35150.0; 
const float STRAIGHT_RESISTANCE2 = 34150.0; 
const float STRAIGHT_RESISTANCE3 = 37000.0; 
const float STRAIGHT_RESISTANCE4 = 48000.0; 
const float BEND_RESISTANCE1 = 74000.0; 
const float BEND_RESISTANCE2 = 74000.0; 
const float BEND_RESISTANCE3 = 74000.0; 
const float BEND_RESISTANCE4 = 100000.0; 
char i = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(FLEX_PIN1, INPUT);
  pinMode(FLEX_PIN2, INPUT);
  pinMode(FLEX_PIN3, INPUT);
  pinMode(FLEX_PIN4, INPUT);  
  vw_set_tx_pin(transmit_pin);
  vw_set_ptt_pin(transmit_en_pin);
  vw_set_ptt_inverted(true);
  vw_setup(2000);
}
void loop()
{
  int flexADC1 = analogRead(FLEX_PIN1);
  int flexADC2 = analogRead(FLEX_PIN2);
  int flexADC3 = analogRead(FLEX_PIN3);
  int flexADC4 = analogRead(FLEX_PIN4);
  float flexV1 = flexADC1 * VCC / 1023.0;
  float flexV2 = flexADC2 * VCC / 1023.0;
  float flexV3 = flexADC3 * VCC / 1023.0;
  float flexV4 = flexADC4 * VCC / 1023.0;
  float flexR1 = R_DIV * (VCC / flexV1 - 1.0);
  float flexR2 = R_DIV * (VCC / flexV2 - 1.0);
  float flexR3 = R_DIV * (VCC / flexV3 - 1.0);
  float flexR4 = R_DIV * (VCC / flexV4 - 1.0);
  Serial.println("Resistance: " + String(flexR1) + " ohms");
  Serial.println("Resistance: " + String(flexR2) + " ohms");
  Serial.println("Resistance: " + String(flexR3) + " ohms");
  Serial.println("Resistance: " + String(flexR4) + " ohms");
  float angle1 = map(flexR1, STRAIGHT_RESISTANCE1, BEND_RESISTANCE1,0, 90.0);
  float angle2 = map(flexR2, STRAIGHT_RESISTANCE2, BEND_RESISTANCE2,0, 90.0);
  float angle3 = map(flexR3, STRAIGHT_RESISTANCE3, BEND_RESISTANCE3,0, 90.0);
  float angle4 = map(flexR4, STRAIGHT_RESISTANCE4, BEND_RESISTANCE4,0, 90.0);
  Serial.println("Bend: " + String(angle1) + " degrees");
  Serial.println("Bend: " + String(angle2) + " degrees");
  Serial.println("Bend: " + String(angle3) + " degrees");
  Serial.println("Bend: " + String(angle4) + " degrees");
  if (angle1 > 40 && angle2 > 40)
  {
   char msg[1] = {'a'};
   vw_send((uint8_t *)msg,1);
   vw_wait_tx();
  }
  else if (angle3 > 40 && angle4 > 65)
  {
   char msg[1] = {'b'};
   vw_send((uint8_t *)msg,1);
   vw_wait_tx();
  }
  else if (angle1 > 40)
  {
   char msg[1] = {'c'};
   vw_send((uint8_t *)msg,1);
   vw_wait_tx();
  }
  else if (angle2 > 40)
  {
   char msg[1] = {'d'};
   vw_send((uint8_t *)msg,1);
   vw_wait_tx();  
  }
  else if (angle3 > 40)
  {
   char msg[1] = {'f'};
   vw_send((uint8_t *)msg,1);
   vw_wait_tx();  
  }
  else if (angle4 > 65)
  {
   char msg[1] = {'e'};
   vw_send((uint8_t *)msg,1);
   vw_wait_tx();
  }
  else
  {  
   char msg[1] = {'z'};
   vw_send((uint8_t *)msg,1);
   vw_wait_tx();
  }
  delay(1000);
}
