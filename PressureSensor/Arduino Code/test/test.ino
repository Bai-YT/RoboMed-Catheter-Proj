
#include "SparkFun_LPS33HW_Arduino_Library.h"  // Click here to get the library: http://librarymanager/All#SparkFun_LPS33HW
#include <Wire.h>

LPS33HW pressureSensor; // Create an object of the LPS33HW class

void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.println("LPS33HW Pressure Sensor");
  Serial.println();
  delay(1000);

  pressureSensor.begin();    // Begin links an I2C port and I2C address to the sensor, sets an I2C speed, begins I2C on the main board, and then sets default settings

  if(pressureSensor.isConnected() == false)  // The library supports some different error codes such as "DISCONNECTED"
  {
    Serial.println("LPS33HW disconnected. Reset the board to try again.");        // Alert the user that the device cannot be reached
    Serial.println("Are you using the right Wire port and I2C address?");         // Suggest possible fixes
    Serial.println("See Example2_I2C_Configuration for how to change these.");    // Suggest possible fixes
    Serial.println("");
    while(1);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(5000);
  Serial.println("LPS33HW Pressure Sensor");
}
