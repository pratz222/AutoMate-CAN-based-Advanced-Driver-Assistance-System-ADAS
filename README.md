# CAN-Based Advanced Driver Assistance System (ADAS)

## Project Overview
The CAN-based Advanced Driver Assistance System (ADAS) is an innovative hardware solution designed to enhance vehicle safety and performance. By integrating multiple sensors and actuators with a Controller Area Network (CAN) bus, this project facilitates real-time communication between components, leading to a more intelligent driving experience. Currently, the system operates with two CAN nodes, with plans for expansion to accommodate more nodes in the future.

## Motivation Behind the Project
This project arose from the need for improved vehicle safety and automation. By utilizing advanced sensors and actuators, I aimed to create a system that can react to environmental conditions and enhance the driver's experience, contributing to safer roads and smarter vehicles.

## Key Features
- **CAN Communication:** Utilizes MCP2515 CAN modules for efficient data transmission at 500kbps between multiple microcontrollers.
- **Sensor Integration:** Incorporates various sensors, including LDR (Light Dependent Resistor), temperature sensor, ultrasonic sensor, and raindrop sensor, to monitor environmental conditions.
- **Actuator Control:** Activates several actuators based on sensor inputs, including:
  - **DC Fan:** Engages when temperature thresholds are exceeded.
  - **Servo Motor:** Operates windshield wipers automatically upon detecting rain.
  - **LED Headlights:** Illuminates in response to low light conditions.
  - **OLED Display:** Provides real-time feedback on sensor readings and actuator statuses.

## How It Works
1. **Data Collection:** Sensors gather critical environmental data continuously.
2. **CAN Communication:** The data is framed with unique CAN IDs and transmitted through CAN High and CAN Low twisted pair wires.
3. **Actuator Activation:** At the receiving end, the microcontroller interprets the data and activates the appropriate actuators:
   - The **DC fan** turns on to maintain a comfortable cabin temperature.
   - The **servo motor** drives the wipers automatically when rain is detected.
   - The **LED headlights** activate as darkness falls.
   - The **OLED display** presents real-time sensor readings and actuator status.

## Hardware Highlights
- **Microcontrollers:** Two microcontrollers serve as the central units for processing sensor data and controlling actuators.
- **MCP2515 CAN Modules:** Each module comes equipped with a CAN controller and transceiver for reliable communication.
- **Sensors:** LDR, temperature sensor, ultrasonic sensor, and raindrop sensor for comprehensive environmental monitoring.
- **Actuators:** DC fan, servo motor, LED headlights, and OLED display for interactive feedback.

## Future Plans
This project is just the beginning. Future enhancements will include additional CAN nodes for simultaneous communication, expanding the system's capabilities and further improving vehicle automation.

## Contribution
I welcome contributions to the CAN-based ADAS project! Feel free to share your ideas, report issues, or propose enhancements to improve the system's functionality.

## Conclusion
This project represents a significant step toward the future of autonomous driving, combining advanced sensing and actuator technologies within a CAN framework. Stay tuned for further developments and updates as this project evolves into a more sophisticated driver assistance system!

![image](https://github.com/pratz222/AutoMate-CAN-based-Advanced-Driver-Assistance-System-ADAS/assets/53640877/75558c65-f6fc-4b90-a875-9705941fbe85)

