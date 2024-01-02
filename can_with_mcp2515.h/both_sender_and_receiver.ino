#include <SPI.h>
#include <mcp2515.h>

struct can_frame Received_Data;
struct can_frame Transmitted_Data;

MCP2515 mcp2515(10);

uint8_t counter = 0;


void setup() {
  Serial.begin(115200);
  
  mcp2515.reset();
  mcp2515.setBitrate(CAN_500KBPS, MCP_8MHZ);
  mcp2515.setNormalMode();
  
  Serial.println("------- CAN Read ----------");
}

void loop() {
  if (mcp2515.readMessage(&Received_Data) != MCP2515::ERROR_OK) {
    mcp2515.readMessage(&Received_Data);
    Serial.println("ID: ");
    Serial.print(Received_Data.can_id, HEX);
    Serial.println("DLC: ");
    Serial.print(Received_Data.can_dlc, DEC);
    Serial.print(" ");
    
    for (int i = 0; i<Received_Data.can_dlc; i++)  {  // print the data
      Serial.println(Received_Data.data[i], DEC);
    }

    if(1) {
      counter = counter + 1;
      delay(400);
      if(counter == 255) {
        counter = 0;
      }
    }

    Serial.print("Message Sent ");
    Transmitted_Data.can_id = 0x379;
    Transmitted_Data.can_dlc = 8;
    Transmitted_Data.data[0] = 12;
    Transmitted_Data.data[1] = 23;
    Transmitted_Data.data[2] = 14;
    Transmitted_Data.data[3] = 53;

    Transmitted_Data.data[4] = counter;
    Transmitted_Data.data[5] = counter;
    Transmitted_Data.data[6] = counter;
    Transmitted_Data.data[7] = counter;

    mcp2515.sendMessage(&Transmitted_Data);
    
    Serial.println();      
  }
}
