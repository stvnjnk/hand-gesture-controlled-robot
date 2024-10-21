#include "Wire.h"                         // Wire library for I2C communication (SDA,SCL)
#include <MPU6050_light.h>                // MPU6050 Library
#include <RH_ASK.h>                       // RadioHead library for 443MHz transmitter

RH_ASK transmitter;                       // Creates an object for the transmitter
MPU6050 mpu(Wire);                        // Creates an object for the MPU6050 using Wire (I2C)

void setup() {
  transmitter.init();                     // Initializes the transmitter
  Wire.begin();                           // Initializes I2C
  mpu.begin();                            // Initializes MPU6050  
  delay(1000);                            // Delay of 1 second
  mpu.calcOffsets();                      // Calibrates MPU6050   
}

void loop() {
  mpu.update();                           // Updates the values of MPU6050
  float X = mpu.getAngleX();              // Gets the X angle (forwards/backwards)
  float Y = mpu.getAngleY();              // Gets the Y angle (left/right)

  byte Action = determineAction(X, Y);    // Runs the function that finds the action that needs to be sent via the transmitter
  transmit(Action);                       // Runs the function of transmitting the message
}

byte determineAction(float X, float Y) {  // The function that finds out the action
  if (abs(X) > abs(Y)) {                  // If there is more pitch than roll
    if (X > 20) return 1;                 // Forwards (action 1)
    else if (X < -20) return 2;           // Backwards (action 2)
  } 
  else {                                   
    if (Y > 30 && Y < 60) return 3;       // Slow Right Turn (action 3)
    else if (Y >= 60) return 4;           // Fast Right Turn (action 4)
    else if (Y < -30 && Y > -60) return 5;// Slow Left Turn (action 5)
    else if (Y <= -60) return 6;          // Fast Left Turn (action 6)
  }
  return 0;                               // Stop (if none of the above are true)
}

void transmit(byte Action) {              // Function that transmitts the action and "encryption" number
  uint8_t msg[2] = {0, Action};           // MSG array of a size of 2, with 0 as the "encryption" and the action
  transmitter.send(msg, sizeof(msg));     // Sends the message
  transmitter.waitPacketSent();           // Waits until the message is sent
}