#include <SPI.h>
#include <DHT.h>

const int SPI_CS_PIN = 10;
const int CAN_INT_PIN = 2;

#include "mcp2515_can.h"
mcp2515_can CAN(SPI_CS_PIN); // Set CS pin

//**************************** DEFINING PINS FOR PROJECT **************************//

#define ldrPin A0           
const int echoPin = 6;
const int trigPin = 5;
#define rainPin A1

#define DHTPIN 8                 // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11            // DHT 11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
    SERIAL_PORT_MONITOR.begin(115200);
    dht.begin();
    
//**************************** CONFIGURE PIN_MODE FOR SENSORS *************************//

   pinMode(ldrPin, INPUT);   
   pinMode(echoPin, INPUT); 
   pinMode(trigPin, OUTPUT);
   pinMode(rainPin, INPUT); 

    while (CAN_OK != CAN.begin(CAN_500KBPS)) {          
        SERIAL_PORT_MONITOR.println("CAN init fail, retry...");
        delay(100);
    }
    SERIAL_PORT_MONITOR.println("CAN init ok!");
}

void loop() {

     unsigned char ldrStatus = analogRead(ldrPin);  
    
     SERIAL_PORT_MONITOR.print("LDR STATUS ");
     SERIAL_PORT_MONITOR.println(ldrStatus);
     
     unsigned char rainStatus = analogRead(rainPin); 
     SERIAL_PORT_MONITOR.print("RAIN STATUS ");
     SERIAL_PORT_MONITOR.println(rainStatus);
     
     int t = dht.readTemperature();
     SERIAL_PORT_MONITOR.print("TEMP ");
     SERIAL_PORT_MONITOR.println(t);

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    float duration = pulseIn(echoPin, HIGH);
    int distance = (duration*.0343)/2;
    SERIAL_PORT_MONITOR.print("Safe Distance ");
     SERIAL_PORT_MONITOR.println(distance);
  
   
    uint8_t sensor_data[] = { ldrStatus,rainStatus,t,distance };
    
    
    // send data:  id = 0x70, standard frame, data len = 8, stmp: data buf
    CAN.sendMsgBuf(0x70, 0, 4, sensor_data);
    delay(2000);                      
}
