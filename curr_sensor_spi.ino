// SPI pin setup
// Define all the pins for each line


// ADS117 dictionary
// Define the register addresses and  (p. 48) 


void setup() {

  // SPI communication setup
  // SPI configuration and SPI.begin stuff

  
  // start Serial over usb to computer
  Serial.begin(115200);
  while (!Serial)
  {
    // wait until the serial port is opened
  }
}

void loop() {

  // Check for any available commands
  if(Serial.available()) {
    char in = Serial.read(); // Serial.read removes from the buffer

    // Make a bunch of cases that you want to test
    switch(in) {
      case 'S':
        runFunc();
        break;
      case 'N':
        runFunc2();
        break;
      default:
        Serial.println("Unknown command");
    }

  }

}

void runFunc() {
  // Function to run for testing
  Serial.println("start");
}

void runFunc2() {
  // Function to run for testing
  Serial.println("stop");
}

void readReg() {

  // create buffer of bytes to store the packet you will write
  uint8_t buf[32];

  // Fill buf with the packet you want to send
  buf[0] = ...
  buf[1] = ...

  numBytes = ... // number of bytes in the packet

  // SPI.transfer using a buffer and number of bytes overwrites the data in buf with the received values
  //  the variable 'buf' is actually a reference to the first element of the array,
  //    so 'buf' is equivalent to '&buf[0]'. You may see me use the latter notation
  SPI.transfer(buf, numBytes);

  // Print out the elements of buf
}
