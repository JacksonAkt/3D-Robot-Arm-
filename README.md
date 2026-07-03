🤖 3D Robot Arm (Arduino-Based)
Project Overview
This project implements a 6-axis 3D printed robotic arm capable of performing precise multi-axis motion and object manipulation. The system integrates mechanical design, electrical hardware, embedded programming, and custom PCB development into a complete robotic platform.

The robot arm is controlled by an Arduino Mega through CNC driver shields that operate multiple NEMA stepper motors. Hall effect sensors provide positional feedback, while a high-torque servo motor actuates the gripper for object manipulation. To improve system reliability and reduce wiring complexity, a custom PCB was designed, simulated, fabricated, and integrated into the final system.

⚡ Electrical Systems
The electrical system is responsible for power distribution, motion control, sensing, and communication between all hardware components.

Components
Arduino Mega 2560
CNC Shield V3
Stepper Motor Drivers
NEMA Stepper Motors
Hall Effect Sensors
DS3225 Servo Motor (Gripper)
XL4016 Buck Converter
20V 15A Power Supply
System Description

The Arduino Mega coordinates the operation of all six axes by generating STEP and DIR signals for the CNC drivers, which control the NEMA stepper motors responsible for joint motion. Hall effect sensors detect magnetic fields at designated positions to provide homing and positional reference. A DS3225 high-torque servo motor controls the gripper, while an XL4016 buck converter regulates the main supply voltage to a safe operating voltage for the servo.
The system separates high-current motor power from low-voltage logic circuitry to improve electrical stability and reduce interference.

Original Wiring Diagram
The robot arm was originally assembled following the wiring diagram provided by ARCTOS Robotics: https://app.cirkitdesigner.com/project/ac6f1dd5-f837-4f83-979b-ccfcafe8fc56

Final Wiring Configuration
The final wiring configuration was modified to accommodate additional hardware, improve cable management, and integrate the custom PCB developed for this project.
<img width="1781" height="848" alt="Cooked Schematics" src="https://github.com/user-attachments/assets/2152204e-0dca-4a3b-961a-428aa5aba010" />

🔌 Custom PCB Design
Objective: A custom PCB was developed to simplify wiring, improve electrical reliability, and provide a cleaner integration between the Arduino Mega and peripheral devices.

The PCB was designed to:
Regulate system power distribution
Extend 5V and GND connections from the microcontroller
Reduce wiring complexity
Improve electrical stability
Create a modular interface for future expansion
Reduce the weight of the power circuit by 50 grams. 

Schematic Design
The circuit schematic was designed to organize power routing and signal connections prior to PCB layout.
<img width="1044" height="766" alt="Raw-Schematics" src="https://github.com/user-attachments/assets/cca2e4b3-45fd-43ce-8bb9-648207f6e0e6" />
The schematic defines the electrical connections between voltage regulation, power distribution, and the external peripherals connected to the robot arm.

[BOM](./PCB/BOM.xlsx)

Circuit Simulation (LTspice)
Before fabrication, the circuit was simulated in LTspice to verify the expected electrical behavior and validate component selection.

The simulation was used to evaluate:
Voltage regulation
Current flow
Component behavior (the voltage drop of LED and Schottky diode)
Power stability
<img width="1920" height="1030" alt="Schematics" src="https://github.com/user-attachments/assets/b6780fc8-443b-4dfe-8bb1-db4b4f140e6f" /> <img width="1920" height="1030" alt="Stimulation" src="https://github.com/user-attachments/assets/28f7dfea-d4a6-441a-90f6-530c9569d8eb" />
Simulation results confirmed that the circuit operated within the desired electrical specifications before hardware fabrication.

Breadboard Testing
The circuit was first assembled on a breadboard to validate functionality prior to manufacturing the PCB.

Testing verified:
Correct voltage outputs
Stable power delivery
Proper component operation
Expected circuit behavior
<img width="5712" height="4284" alt="CircuitTest" src="https://github.com/user-attachments/assets/8ec4c8f0-d2ab-4593-b32f-c83771d57049" />
Prototype testing reduced design risk by identifying potential issues before fabrication.

PCB Layout Design
After successful verification, the schematic was converted into a PCB layout.

Design considerations included:
Efficient trace routing
Power integrity
Component spacing
Manufacturability
Ease of assembly
<img width="1920" height="1030" alt="Layout1" src="https://github.com/user-attachments/assets/21e0fa9e-3e6a-4c3e-8b7e-b5fb0f1ab376" /><img width="1054" height="865" alt="Layout2" src="https://github.com/user-attachments/assets/7f5251b5-67fb-47a5-b6f6-6b8c76d59eb8" />

PCB Fabrication
The final PCB was manufactured and assembled by soldering all electronic components onto the fabricated board.

The completed PCB provides a compact, reliable, and organized solution for integrating the robot arm's electrical system.



🛠 Mechanical Systems
The robot arm structure is fully 3D printed using PLA, providing a lightweight and modular platform for rapid prototyping and iterative design.

Features
Multi-joint articulated arm
Modular printed components
Servo-actuated gripper
Stepper motor mounting brackets
Hall sensor mounting locations

PLA was selected due to its ease of manufacturing, dimensional accuracy, and sufficient strength for the intended payload. The modular construction allows damaged components to be replaced individually without reprinting the entire assembly.



💻 Software
The robot arm is programmed in C++ using the Arduino IDE.

Features
Multi-axis stepper motor control
Servo control for gripper operation
Hall sensor homing routine
Motion sequencing
Modular code architecture for future expansion

The software coordinates all hardware components to produce smooth and repeatable robotic motion while maintaining a scalable architecture for future upgrades.
