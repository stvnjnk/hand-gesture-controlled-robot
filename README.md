# Hand Gesture Controlled Robot using RF Modules

## Project Description

This project involves the design and implementation of a hand gesture-controlled robot car using RF (Radio Frequency) communication technology. Utilizing 433MHz RF transmitter/receiver modules and the MPU6050 sensor, motion data from hand gestures is captured and transmitted to control the movement of a robot car. The system responds to various gestures to command the car to move forward, backward, turn, or stop.

## Components Used
- **Arduino UNO & Arduino Nano**: Microcontroller boards for transmitter and receiver.
- **RF 433MHz Transmitter Module**: Sends commands from hand gestures to the robot.
- **RF 433MHz Receiver Module**: Receives commands and controls the robot’s movements.
- **MPU6050 Accelerometer and Gyroscope**: Tracks hand gestures and relays data to the Arduino.
- **L298N Motor Driver**: Controls the speed and direction of the robot’s motors.
- **DC Motors**: Drives the robot's wheels.

## Setup Instructions

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/your-repo/Hand-Gesture-Controlled-Robot.git
   ```

2. **Upload Arduino Sketches**:
   - Use the Arduino IDE to upload `GROUP4_TRANSMITTER_CODE.ino` to the transmitter (hand controller).
   - Upload `GROUP4_RECEIVER_CODE.ino` to the receiver (robot car).

3. **Circuit Setup**:
   - Assemble the circuit as per the schematic provided (connect the Arduino, MPU6050 sensor, RF modules, and motor driver as needed).

4. **Power Supply**:
   - Use a power bank for the transmitter module and ensure proper power connections for the robot’s motors.

## Usage Guide

Once the sketches are uploaded and the circuit is complete, the robot can be controlled using hand gestures:

- **Move Forward**: Tilt hand forward
- **Move Backward**: Tilt hand backward
- **Turn Left**: Tilt hand to the left
- **Turn Right**: Tilt hand to the right
- **Stop**: Hold hand level

The robot responds to these gestures via the MPU6050 sensor and the RF communication between the transmitter and receiver.

## Troubleshooting

- **Weak RF Signal**: The RF signal range may be limited. Consider increasing the input voltage or adding a longer antenna for better signal transmission.
- **Interference from Other RF Devices**: If other RF devices interfere with your control signals, consider changing the frequency or implementing signal encoding to avoid conflicts.

## Future Improvements

- **Increase Signal Range**: Testing with a higher voltage on the transmitter may improve the RF signal range.
- **Enhanced Antenna**: Soldering a 22- or 24-gauge wire as an antenna could improve the signal strength.
- **Signal Encoding**: Adding signal encoding to avoid interference and ensure reliable communication.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
