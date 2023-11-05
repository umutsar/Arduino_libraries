#include <mcp_can.h>
#include <SPI.h>

const int potansiyometer = A0;
int current_data = 0;

MCP_CAN CAN0(10);     // Set CS to pin 10

void setup() {

  Serial.begin(115200);

  // Initialize MCP2515 running at 16MHz with a baudrate of 500kb/s and the masks and filters disabled.
  if (CAN0.begin(MCP_ANY, CAN_500KBPS, MCP_16MHZ) == CAN_OK)
    Serial.println("MCP2515 Initialized Successfully!");
  else
    Serial.println("Error Initializing MCP2515...");

  CAN0.setMode(MCP_NORMAL);   // Change to normal mode to allow messages to be transmitted
}

void loop() {
  current_data = analogRead(potansiyometer);
  String send_data = String(current_data);
  String last_value = "starting";
  
  if (send_data.length() == 1) {
    last_value = send_data + "       ";
  } else if (send_data.length() == 2) {
    last_value = send_data + "      ";
  } else if (send_data.length() == 3) {
    last_value = send_data + "     ";
  } else if (send_data.length() == 4) {
    last_value = send_data + "    ";
  } else {
    last_value = "starting";
  }

  byte data[8];
  last_value.getBytes(data, 8);

  byte sndStat = CAN0.sendMsgBuf(0x100, 0, 8, data);
  // send data:  ID = 0x100, Standard CAN Frame, Data length = 8 bytes, 'data' = array of data bytes to send

  if (sndStat == CAN_OK) {
    Serial.println("Message Sent Successfully!");
  } else {
    Serial.println("Error Sending Message...");
  }
  delay(50);   // send data per 100ms
}
