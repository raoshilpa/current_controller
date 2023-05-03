// SPI pin setup
#include <SPI.h>

// NOT USING FOR NOW.
// Initialize pins - might want to do our own cs because spi.transfer might not give us the cs signal we want
const int cs = 7;

// ADS117 dictionary
// Define the register addresses (p. 48) 
// FIRST TASK: READ DEV_ID
const int DEV_ID = 0x0;
const int REV_ID = 0x1;
const int STATUS = 0x2;
const int CONTROL = 0x3;
const int MUX = 0x4;
const int CONFIG1 = 0x5;
const int CONFIG2 = 0x6;
const int CONFIG3 = 0x7;
const int CONFIG4 = 0x8;
const int OFFSET2 = 0x9;
const int OFFSET1 = 0xA;
const int  OFFSET0 = 0xB; 
const int GAIN2 = 0xC;
const int GAIN1 = 0xD;
const int GAIN0 = 0xE;
const int CRC = 0xF;

void setup() {

  // SPI communication setup
  // SPI configuration and SPI.begin stuff
  SPI.beginTransaction(SPISettings(400000, MSBFIRST, SPI_MODE1)); // MSB or LSB first? 

  // start Serial over usb to computer
  Serial.begin(115200);
  while (!Serial)
  {
    // wait until the serial port is opened
  }

  delay(100); // give the sensor time to set up:

}

void loop() {

  // Check for any available commands
  if(Serial.available()) {
    char in = Serial.read(); // Serial.read removes from the buffer

    // Make a bunch of cases that you want to test
    switch(in) {
      case 'Start':
        start();
        break;
      case 'Stop':
        stop();
        break;
      default:
        Serial.println("Unknown command");
    }

  }

}

void start() {
  // Function to run for testing
  Serial.println("start");
}

void stop() {
  // Function to run for testing
  Serial.println("stop");
}

void readReg() {

  // create buffer of bytes to store the packet you will write
  uint8_t buf[32];

  // Fill buf with the packet you want to send
  buf[0] = 0x00;
  buf[1] = 0x40 + DEV_ID;
  buf[2] = 0x00;
  // buf[1] = 0x40 + DEV_ID + 0x40

  int numBytes = 3; // number of bytes in the packet

  // SPI.transfer using a buffer and number of bytes overwrites the data in buf with the received values
  //  the variable 'buf' is actually a reference to the first element of the array,
  //   so 'buf' is equivalent to '&buf[0]'. You may see me use the latter notation in later code.
  SPI.transfer(buf, numBytes);

  // Print out the elements of buf
  Serial.println(buf[0]);
  Serial.println(buf[1]);
  Serial.println(buf[2]);
  Serial.println();

}
