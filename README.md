# CAN-based Advanced Driver Assistance System (ADAS)
I’m excited to share my latest project, a CAN-based Advanced Driver Assistance System (ADAS), designed to enhance vehicle safety and performance. This innovative hardware solution integrates two microcontrollers and two MCP2515 CAN modules, each equipped with onboard CAN Controller and CAN Transceiver capabilities set at 500kbps. 

As of now, the project has only two CAN Nodes. The next part will have more number of CAN Nodes communicating simultaneously over the CAN Bus.

🛠 𝐇𝐚𝐫𝐝𝐰𝐚𝐫𝐞 𝐇𝐢𝐠𝐡𝐥𝐢𝐠𝐡𝐭𝐬 :
Sensors Galore: LDR, Temperature Sensor, Ultrasonic Sensor, and Raindrop Sensor.

Actuator Heaven: DC Fan, Servo Motor, LED Headlights, and an OLED Display for real-time feedback.

🔧 𝐇𝐨𝐰 𝐢𝐭 𝐖𝐨𝐫𝐤𝐬 :
Data Collection: Sensors gather critical environmental data.
CAN Communication: Unique CAN IDs frame the data and transmit it via CAN High and CAN Low twisted pair wires.

𝐀𝐜𝐭𝐢𝐨𝐧 𝐓𝐢𝐦𝐞 : 
On the receiving end, the microcontroller activates the appropriate actuators:

🌡 DC Fan kicks in when the temperature rises.
☔️ Servo Motor drives the wipers automatically on detecting rain.
💡 LED headlights illuminate as soon as darkness falls.
📊 OLED Display shows real-time sensor readings and actuator status, bringing the dashboard to life!

The magic happens as the data is transmitted via CAN High and CAN Low twisted pair wires to a second CAN module. Here, a microcontroller interprets the sensor readings and activates multiple actuators accordingly. Imagine a DC fan that kicks in to cool down the cabin when temperatures soar, a servo motor that mimics automatic wiper action during rainfall, and an LED that illuminates the headlights in response to darkness detected by the LDR.

But that’s not all! An OLED display serves as the main dashboard, providing a real-time overview of which actuators are active and displaying sensor readings for an intuitive user experience.
This project is a step towards safer roads and smarter vehicles. Stay tuned for more updates on this exciting journey into the world of autonomous driving!
