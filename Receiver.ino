#include <VirtualWire.h>
const int receive_pin = 11;
const int m1pin1 = 5;
const int m1pin2 = 6;
const int m2pin1 = 7;
const int m2pin2 = 8;
void setup()
{
    Serial.begin(9600);
    Serial.println("setup");
    pinMode(5,OUTPUT);
    pinMode(6,OUTPUT);
    pinMode(7,OUTPUT);
    pinMode(8,OUTPUT);
    vw_set_rx_pin(receive_pin);
    vw_set_ptt_inverted(true);
    vw_setup(2000);
    vw_rx_start();
}
void loop()
{
 uint8_t buf[VW_MAX_MESSAGE_LEN];
 uint8_t buflen = VW_MAX_MESSAGE_LEN;
 if (vw_get_message(buf, &buflen))
  {
   int i;       
   for (i = 0; i < buflen; i++)
   {
     int j;
     j = buf[i];
     Serial.println(j);
     if (j == 97)
     {
      digitalWrite(m1pin1,1);
      digitalWrite(m1pin2,0);
      digitalWrite(m2pin1,1);
      digitalWrite(m2pin2,0);
     } 
     else if (j == 100)
     {
      digitalWrite(m1pin1,0);
      digitalWrite(m1pin2,0);
      digitalWrite(m2pin1,1);
      digitalWrite(m2pin2,0); 
     }
     else if (j == 99)
     {
      digitalWrite(m1pin1,1);
      digitalWrite(m1pin2,0);
      digitalWrite(m2pin1,0);
      digitalWrite(m2pin2,0);
     }
     else if (j == 98)
     {
      digitalWrite(m1pin1,0);
      digitalWrite(m1pin2,1);
      digitalWrite(m2pin1,0);
      digitalWrite(m2pin2,1);
     }
     else if (j == 101)
     {
      digitalWrite(m1pin1,0);
      digitalWrite(m1pin2,1);
      digitalWrite(m2pin1,0);
      digitalWrite(m2pin2,0);
     }
     else if (j == 102)
     {
      digitalWrite(m1pin1,0);
      digitalWrite(m1pin2,0);
      digitalWrite(m2pin1,0);
      digitalWrite(m2pin2,1);
     }
     else 
     {
      digitalWrite(m1pin1,0);
      digitalWrite(m1pin2,0);
      digitalWrite(m2pin1,0);
      digitalWrite(m2pin2,0);
     }     
   }
 }
} 

