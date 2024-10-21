
# Hand Gesture Controlled Robot using RF Modules

> A project to create a wireless hand gesture-controlled robot using RF modules and an MPU6050 sensor for gesture-based motion control.

---

## Table of Contents

- [Overview](#overview)
- [Built With](#built-with)
  - [Libraries Used](#libraries-used)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
- [Project Status](#project-status)
- [Contributing](#contributing)
- [License](#license)

---

## Overview

This project showcases a hand gesture-controlled robot that utilizes **RF communication** and an **MPU6050 accelerometer and gyroscope** sensor. By tilting your hand in different directions, the robot can move forward, backward, left, or right. The core aim of the project is to explore wireless, intuitive robot control using simple hardware components, creating an interactive and innovative control mechanism for robotics.

### Goal: 
To build a gesture-controlled robot with simple, reliable wireless communication using low-cost components.

---

![Transmitter Demo 1](docs/IMG_6290.png)
*Caption: Front view of the transmitter.*

---

## Features

- **Wireless Control**: Control the robot car wirelessly using RF communication.
- **Gesture-Based Commands**: Move the car forward, backward, and turn left or right using hand gestures.
- **Simple Setup**: Built with Arduino, MPU6050, and RF 433MHz modules for an easy-to-follow project.
- **Flexible Design**: Works with standard components and minimal hardware requirements.

---

### Built With
This project was built using:
- **Arduino UNO & NANO**
- **MPU6050 Accelerometer and Gyroscope**
- **RF 433MHz Transmitter/Receiver Modules**
- **L298N Motor Driver**
- **DC Motors**

---

### Libraries Used
This project uses the following libraries:
- [MPU6050_light](https://github.com/richardgh/mpu6050) - Lightweight MPU6050 library for working with accelerometer and gyroscope.
- [RadioHead](https://www.airspayce.com/mikem/arduino/RadioHead/) - Library for RF communication using 433MHz modules.
- [Wire](https://www.arduino.cc/en/Reference/Wire) - Arduino Wire library for I2C communication.

---

## Getting Started

To get started with this project, clone the repository and upload the provided Arduino sketches to your microcontrollers.

### Prerequisites
Before setting up the project, you will need:
- **Arduino IDE** installed.
- Basic electronics hardware: breadboards, jumper wires, and other components listed above.

### Installation

1. **Clone the repo**
   ```sh
   git clone https://github.com/your-repo/Hand-Gesture-Controlled-Robot.git
   ```

2. **Upload Arduino Sketches**:
   - Upload `src/TRANSMITTER_CODE.ino` to the Arduino NANO (transmitter).
   - Upload `src/RECEIVER_CODE.ino` to the Arduino UNO (receiver).

3. **Circuit Assembly**:
   - Assemble the circuit as per the schematic provided in the `docs/` folder.
   - Make sure all connections (MPU6050, RF modules, L298N, motors) are securely in place.

---

## Usage

Once the hardware setup is complete and sketches are uploaded, the robot can be controlled via hand gestures:

- **Move Forward**: Tilt hand forward
- **Move Backward**: Tilt hand backward
- **Turn Left**: Tilt hand to the left
- **Turn Right**: Tilt hand to the right
- **Stop**: Keep hand level

You can check the Arduino serial monitor to confirm signal transmission.

---

## Project Status

- **Current Version**: v1.0
- **Next Steps**:
  - Improve signal range and transmission stability.
  - Add gesture-based speed control.
  - Expand functionality with obstacle detection.

---

## Contributing

Contributions are welcome! Please feel free to submit pull requests or open issues for improvements or bug fixes.

---

## License

Distributed under the MIT License. See `LICENSE` for more information.

---
