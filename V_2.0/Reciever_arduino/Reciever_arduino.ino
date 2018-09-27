//Reciever
char a;

void setup() {
  pinMode(5,OUTPUT); //Motor Pin
  pinMode(6,OUTPUT); //Motor Pin
  pinMode(7,OUTPUT); //Motor Pin
  pinMode(8,OUTPUT); //Motor Pin

}

void loop() {
  //Your Code here

  //Recive value in 'a' variable

  switch(a):
  case W: forward();
  break;
  case S:backward();
  break;
  case A:left();
  break;
  case D:right();

}

void forward(){
  digitalWrite(5,1);
  digitalWrite(6,0);
  digitalWrite(7,1);
  digitalWrite(8,0);
}

void backward() {
  digitalWrite(5,0);
  digitalWrite(6,1);
  digitalWrite(7,0);
  digitalWrite(8,1);
}

void left() {
  digitalWrite(5,1);
  digitalWrite(6,0);
  digitalWrite(7,0);
  digitalWrite(8,1);
}

void right() {
  digitalWrite(5,0);
  digitalWrite(6,1);
  digitalWrite(7,1);
  digitalWrite(8,0);
}

