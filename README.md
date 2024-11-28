# Door-Lock
Smart Door Lock system using an esp32 Microcontroller
OBJECTIVE:

To develop a smart iot door lock system using a esp32 microcontroller.

Problem Statement: Smart IoT Door Lock System Using ESP32 microcontroller
•	Current Issues:
o	Traditional locks are vulnerable to key loss, duplication, and theft.
o	Existing smart locks are expensive and often lack integration flexibility.
•	Project Goal:
o	Develop a cost-effective and secure IoT door lock system using the ESP32 microcontroller.
•	Key Features:
o	Remote access and control via a web or mobile interface.
o	Secure authentication (PIN codes, mobile approval, or other methods).
o	Real-time monitoring and notifications for access attempts or suspicious activity.
o	Presence detection using sensors like ultrasonic or PIR.
o	Integration with smart home ecosystems (e.g., Alexa, Google Home).
•	Focus Areas:
o	Cost-efficiency with affordable components.
o	Reliability in hardware and network communication.
o	Enhanced security with encrypted communication protocols.
•	Outcome:
o	A user-friendly, scalable, and robust smart lock system that improves convenience and home security.


MICROCONTROLLER STRUCTURE

The ESP32 acts as the central controller of the system. Key features include:
•	Dual-Core Processor: Handles multitasking (web server, sensor processing, and device control).
•	Wi-Fi Capability: Hosts the HTTP web server for remote access via smartphones, laptops, or other devices.
•	GPIO Pins: Used to interface with LEDs, servo motors, and sensors.
•	Analog and Digital Inputs: Read sensor data and control actuators



Sensors and Components used


1   (HC SR-04) Ultrasonic Sensor:
The ultrasonic sensor was used to detect the presence of a person near the door. Although removed in later versions, it initially helped automate the detection mechanism by measuring distance.
2 Servo Motor:
The servo motor controls the physical locking and unlocking of the door. It rotates based on commands from the web server, securing or releasing the lock.
3  LEDs:
The green and red LEDs provide visual feedback about the door's status. The green LED lights up when entry is approved, and the red LED indicates denied access or that the door is locked.
4  Arduino Uno:
The Arduino Uno is used to supply an external power source to the servo motor, ensuring stable operation of the lock mechanism, independent of the ESP32.
5  Web Camera:
The web camera streams live video to the web interface hosted on the ESP32, allowing users to monitor the entrance and visually verify visitors before granting or denying access.

Software Used 

1.	Arduino IDE:
The Arduino IDE was used to program the ESP32 microcontroller and configure the web server, enabling communication between the ESP32 and the user interface for controlling the door lock system.
2.	Python (Flask):
A Python Flask server was used to host the live video feed from the web camera. Since the ESP32 does not support video streaming, Flask provided a solution to stream real-time video to the web interface, allowing users to visually monitor the door area.
