#include <VirtualWire.h>
const int transmit_pin = 12;
const int transmit_en_pin = 3;
void setup()
{
  vw_set_tx_pin(transmit_pin);
  vw_set_ptt_pin(transmit_en_pin);
  vw_set_ptt_inverted(true);
  vw_setup(2000);
}
byte count = 1;
void loop()
{
  char msg[7] = {'h','e','l','l','o',' ','#'};
  msg[6] = count;
  vw_send((uint8_t *)msg, 7);
  vw_wait_tx();
  delay(1000);
  count = count + 1;
}
