#include <RH_ASK.h>                                           // RadioHead library for 443MHz transmitter
#include <SPI.h>                                              // SPI library (Serial Peripheral Interface)

#define ENB 5                                                 // Speed of Left Motors
#define ENA 6                                                 // Speed of Right Motors
#define IN1 7                                                 // Right Rear Motor
#define IN2 8                                                 // Right Front Motor
#define IN3 9                                                 // Left Front Motor
#define IN4 11                                                // Left Rear Motor
#define carSpeed 200                                          // Predefined speed of the motors
#define RADIOHEAD_BAUD 2000                                   // Rate at which info is transfrered to the receiver 2000bits/s
#define RADIOHEAD_TX_PIN 11                                   // Pin of transmitter (not needed)     
#define RADIOHEAD_RX_PIN 13                                   // Pin of receiver

RH_ASK receiver(RADIOHEAD_BAUD, RADIOHEAD_RX_PIN, RADIOHEAD_TX_PIN);

unsigned long MessageLoss = 0;                                // Non negative large number variable
const unsigned long MessageLossThreshold = 10000;             // Threshold for number of messages not received
byte Action = 0;                                              // Declaring the action variable

void MotorControl(bool IN1State, bool IN2State, bool IN3State, bool IN4State, byte ENASpeed, byte ENBSpeed) {
  digitalWrite(IN1, IN1State);                                // Function that you can call later to set the 
  digitalWrite(IN2, IN2State);                                // states and speeds of the motors
  digitalWrite(IN3, IN3State);
  digitalWrite(IN4, IN4State);
  analogWrite(ENA, ENASpeed);
  analogWrite(ENB, ENBSpeed);
}

void setup() {
  receiver.init();                                            // Initializes the receiver
  Serial.begin(9600);                                         // Initializes serial communication 9600bits/s
  pinMode(IN1, OUTPUT);                                       // Sets motor pins as outputs
  pinMode(IN2, OUTPUT);                                       // Sets motor pins as outputs
  pinMode(IN3, OUTPUT);                                       // Sets motor pins as outputs
  pinMode(IN4, OUTPUT);                                       // Sets motor pins as outputs
  pinMode(ENA, OUTPUT);                                       // Sets motor pins as outputs
  pinMode(ENB, OUTPUT);                                       // Sets motor pins as outputs
}

void loop() {
  receive();                                                  // Runs the receive function to check for new msg
  if (MessageLoss > MessageLossThreshold) {                  // Self explanatory (no message received)
    Action = 7;                                               // Stops
    MessageLoss = 0;                                         // Resets count to zero so the car works again
  }
  switch (Action) {                                           // Simplified if statement
    case 1:
      MotorControl(LOW, HIGH, HIGH, LOW, carSpeed, carSpeed); // Forwards (action 1)
      break;
    case 2:
      MotorControl(HIGH, LOW, LOW, HIGH, carSpeed, carSpeed); // Backwards (action 2)
      break;
   case 3:
      MotorControl(HIGH, LOW, LOW, LOW, carSpeed, carSpeed);  // Slow Right Turn (action 3)
      break;
    case 4:
      MotorControl(HIGH, LOW, HIGH, LOW, carSpeed, carSpeed); // Fast Right Turn (action 4)
      break;
    case 5:
      MotorControl(LOW, LOW, LOW, HIGH, carSpeed, carSpeed);  // Slow Left Turn (action 5)
      break;
    case 6:
      MotorControl(LOW, HIGH, LOW, HIGH, carSpeed, carSpeed); // Fast Left Turn (action 6)
      break;
    case 7:
      MotorControl(LOW, LOW, LOW, LOW, 0, 0);                 // Stop
      break;
    default:
      MotorControl(LOW, LOW, LOW, LOW, 0, 0);                 // Stop (if none of the above are true)
      break;
  }
}

void receive() {                                              // Function that receives the action number and "encryption" number                                
  uint8_t msg[2];                                             // Size of the msg
  if (receiver.recv(msg, 2) && (msg[0] == 0)) {               // If it receives a msg and the "encyption" number matches
    Action = msg[1];                                          // Sets the action to be equal to the second byte of the msg
    MessageLoss = 0;                                          // Resets the count
  }
  else {
    MessageLoss++;                                            // Increases the count by one
  }
}