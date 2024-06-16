#include <Wire.h>
#include <SPI.h>
#include <Servo.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "mcp2515_can.h"
#define CAN_2515

Servo servo;

const int SPI_CS_PIN = 10;
const int CAN_INT_PIN = 2;
mcp2515_can CAN(SPI_CS_PIN);

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int ledPin =  8;
const int ACPin =  7;

void setup() {
  
    SERIAL_PORT_MONITOR.begin(115200);

    pinMode(ACPin, OUTPUT);
    pinMode(ledPin, OUTPUT);
    pinMode(4, OUTPUT);
    servo.attach(9);

    while (CAN_OK != CAN.begin(CAN_500KBPS)) {             // init can bus : baudrate = 500k
        SERIAL_PORT_MONITOR.println("CAN init fail, retry...");
        delay(100);
    }
    SERIAL_PORT_MONITOR.println("CAN init ok!");

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  
  display.clearDisplay();
}


void loop() {

   display.clearDisplay();  
   display.setTextSize(1);  
   display.setTextColor(SSD1306_WHITE);
   digitalWrite(4, HIGH);
   
    unsigned char len = 0;
    unsigned char rxBuf[8];

    if (CAN_MSGAVAIL == CAN.checkReceive()) {         // check if data coming
        CAN.readMsgBuf(&len, rxBuf);                  // read data,  len: data length, buf: data buf

        unsigned long canId = CAN.getCanId();
        
        SERIAL_PORT_MONITOR.print("get data from ID: 0x");
        SERIAL_PORT_MONITOR.println(canId, HEX);

        SERIAL_PORT_MONITOR.println(rxBuf[0]);
        SERIAL_PORT_MONITOR.println(rxBuf[1]);
        SERIAL_PORT_MONITOR.println(rxBuf[2]);
        SERIAL_PORT_MONITOR.println(rxBuf[3]);

        display.setCursor(15, 0); 
        display.print("FORD GT DASHBOARD");  

        if(rxBuf[0] > 5){
          digitalWrite(ledPin, HIGH);
          display.setCursor(0, 50);  
          display.print(" HEADLIGHTS:  ON");
          
        }
        else{
          digitalWrite(ledPin, LOW);
          display.setCursor(0, 50);  
          display.print(" HEADLIGHTS:  OFF");
        }

        display.setCursor(0, 36);  
        display.print(" WIPERS : ");
        
        if(rxBuf[1] < 165){   
        display.setCursor(82, 36);  
        display.print("ON"); 
        
          servo.write(180);
          delay(500);
          servo.write(0);
          delay(500);
        }
        else{
          display.setCursor(82, 36);  
          display.print("OFF"); 
        }

        float temperature = rxBuf[2];
        
        if(temperature >= 30){
          digitalWrite(ACPin, HIGH);
          delay(1000);
        }
        else{
          digitalWrite(ACPin, LOW);
        }
        display.setCursor(0, 24);  
        display.print(" TEMP : "); 
        display.setCursor(82, 24); 
        display.print(temperature); 

        float distance = rxBuf[3];
        
         display.setCursor(0, 12);  
         display.print(" SAFE DIST : ");  
         display.setCursor(82, 12); 
         display.print(distance); 


   display.display();  
   
        
    }
 
}
