#include <VirtualWire.h>
#include <VirtualWire_Config.h>

int m1pin1 = 5;
int m1pin2 = 6;
int m2pin1 = 7;
int m2pin2 = 8;

void setup() {
Serial.begin(9600);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(12,INPUT);
vw_set_ptt_inverted(true);
vw_set_rx_pin(12);
vw_setup(4000);
vw_rx_start();
}

void loop() {
uint8_t buf[VW_MAX_MESSAGE_LEN];
uint8_t buflen = VW_MAX_MESSAGE_LEN;

if(vw_get_message(buf,&buflen))
{
  if (buf[0]=='61')
  {
    digitalWrite(m1pin1,1);
    digitalWrite(m1pin2,0);
    digitalWrite(m2pin1,1);
    digitalWrite(m2pin2,0);
  }
  else if (buf[0]=='64')
  {
    digitalWrite(m1pin1,0);
    digitalWrite(m1pin2,0);
    digitalWrite(m2pin1,1);
    digitalWrite(m2pin2,0); 
  }
  else if (buf[0]=='63')
  {
    digitalWrite(m1pin1,1);
    digitalWrite(m1pin2,0);
    digitalWrite(m2pin1,0);
    digitalWrite(m2pin2,0);
  }
  else if (buf[0]=='62')
  {
    digitalWrite(m1pin1,0);
    digitalWrite(m1pin2,1);
    digitalWrite(m2pin1,0);
    digitalWrite(m2pin2,1);
  }
  else if (buf[0]=='65')
  {
    digitalWrite(m1pin1,0);
    digitalWrite(m1pin2,1);
    digitalWrite(m2pin1,0);
    digitalWrite(m2pin2,0);
  }
  else if (buf[0]=='66')
  {
    digitalWrite(m1pin1,0);
    digitalWrite(m1pin2,0);
    digitalWrite(m2pin1,0);
    digitalWrite(m2pin2,1);
  }
  else  if (buf[0]=='67')
  {
    digitalWrite(m1pin1,0);
    digitalWrite(m1pin2,0);
    digitalWrite(m2pin1,0);
    digitalWrite(m2pin2,0);    
  }
}
}
