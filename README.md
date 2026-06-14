# 3D-Robot-Arm-
ZOTBotics Level 2 Robot Arm 

🛠️ MECHANICAL PRODUCTION

The robot arm structure is fully 3D printed using PLA, allowing for rapid prototyping and customization of each component.

The mechanical design includes:

Multi-joint articulated arm segments designed for rotational motion
A string or linkage-based transmission system (if applicable) to transfer motion between components
A servo-driven gripper (claw) for object manipulation
Mounting structures for stepper motors and sensors to ensure alignment and stability

Assembly Instructions: https://arctosrobotics.com/assembly-manual-0-2-9-beta/


⚡ ELECTRICAL SYSTEMS

This project implements a multi-axis 3D robot arm using stepper motors, sensors, and a servo-controlled gripper. The system is designed to achieve precise and repeatable motion across multiple joints through coordinated control.

Microcontroller: Arduino Mega 2560
Components: Buck converter, Driver, Brushless fans, Servo motor, Stepper motors, Hall sensors, switch, connector
Connection: Breadboard prototype

The system includes:

An Arduino Mega to coordinate signals between drivers, sensors, and actuators
Multiple NEMA stepper motors to control each joint of the robot arm (X, Y, Z, and rotational axes)
CNC driver modules (CNC Shield V3) to control stepper motor movement and direction
Hall effect sensors to detect magnetic fields and provide positional feedback or limit detection
A DS3230 servo motor to control the gripper (claw) at the end of the arm
An XL4016 buck converter to step down the main supply voltage to a safe operating range (6–8V) for the servo
A 20V-15A power supply to provide sufficient current for all motors and control electronics
24V bruhsless fans to cool the internal systems

The design separates high-power motor control from low-power logic, ensuring stable operation while handling the higher current demands of stepper motors and the servo.

💻 SOFTWARE

The system is programmed in C++ using the Arduino IDE to control motion, interpret sensor input, and coordinate the robot arm’s behavior. 
