
//for this test the x value of acceleration will be treated
//as channel 0 of the ads1115 and the y value will be
//treated as channel 1
#include <Wire.h>
#define SLAVE_ADDRESS 0x48
//define pin numbers
int x_pin = A0;
int y_pin = A1;
//initialize variables
int read_val;
byte pointer_reg;
byte config_reg[2];
uint8_t conversion_reg[2];
uint16_t val_16_bit;

void setup() {
  Serial.begin(9600);
  Wire.begin(SLAVE_ADDRESS);
  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);
  pinMode(x_pin, INPUT);
  pinMode(y_pin, INPUT);
}
void loop() {}

void receiveData(int bytecount) {
  for (int i = 0; i < bytecount; i++) {
    switch (i) {
      case 0: pointer_reg = Wire.read(); break;
      case 1: config_reg[0] = Wire.read(); break;
      case 2: config_reg[1] = Wire.read(); break;
      default: Serial.println("default case");
    }
  }
  //begin a conversion if configured to do so
  int os_bit = (config_reg[0] & 0b10000000);
  if (os_bit > 0 & pointer_reg > 0) {
    if ((config_reg[0] & 0b00010000) > 0) {
      //if channel 1 is requested
      read_val = analogRead(y_pin);
    }
    else { //channel 0 is requested
      read_val = analogRead(x_pin);
    }
    val_16_bit = map(read_val, 0, 1023, 0, 65535);
    conversion_reg[0] = val_16_bit >> 8;
    conversion_reg[1] = val_16_bit & 0x00FF;
  }
}

void sendData() {
  Serial.println(val_16_bit);
  Wire.write(conversion_reg[0]);
  Wire.write(conversion_reg[1]);
}
