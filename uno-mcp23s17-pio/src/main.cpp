#include <Arduino.h>
#include <SPI.h>
#include <gpio_MCP23S17.h>   // import library

//define CS pin and using HAEN or not
//to use HAEN, address should be 0x20 to 0x27
gpio_MCP23S17 mcp(10,0x20);//instance

void setup() {
    //pinMode(LED_BUILTIN, OUTPUT);
    //Serial.begin(9600);
    Serial.begin(57600);
    mcp.begin();//x.begin(1) will override automatic SPI initialization
    // Set all pins to be outputs (by default they are all inputs)
    mcp.gpioPinMode(OUTPUT);
    // Change all pins at once, 16-bit value
    mcp.gpioPort(0xFFFF);
}
 
void loop() {
    //digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("LED On!!"); 
    for (int i=0; i<16; i++){
      mcp.gpioDigitalWrite(i, HIGH);
    }
    delay(1000);

    //digitalWrite(LED_BUILTIN, LOW); 
    Serial.println("LED Off!!");
    for (int i=0; i<16; i++){
      mcp.gpioDigitalWrite(i, LOW);
    }
    delay(1000); 
}
