//Transmitter

int flex_val = 0; //flex enable pin
int x_ax = 0; //X-axis value
int y_ax = 0; //Y-axis value

void setup() {
  pinMode(A1,INPUT); //Flex Sensor
  pinMode(A2,INPUT); //Accelerometer X-Axis
  pinMode(A3,INPUT); //Accelerometer Y-Axis

}

void loop() {
  flex_val = analogRead(A1);
  

  if (flex_val > [Threshhold]) {
    x_ax = analogRead(A2);
    y_ax = analogRead(A3);

    if (x_ax > [+ve Threshhold]) {
      //Forward
      //Your code here
      
      //Transmit value 'W'
    }

    if (x_ax < [-ve Threshhold]) {
      //Backward
      //Your code here
      
      //Transmit value 'S'
    }

    if (y_ax > [+ve Threshhold]) {
      //Left
      //Your code here
      
      //Transmit value 'A'
    }

    if (y_ax < [-ve Threshhold]) {
      //Right
      //Your code here
      
      //Transmit value 'D'
    }

    if ((y_ax > [+ve Threshhold])&&(x_ax > [+ve Threshhold])) {
      //Left
      //Your code here
      
      //Transmit value 'A'
    }

    if ((y_ax < [-ve Threshhold])&&(x_ax > [+ve Threshhold])) {
      //Right
      //Your code here
      
      //Transmit value 'D'
    }
  }

}
