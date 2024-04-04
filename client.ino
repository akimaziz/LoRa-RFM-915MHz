#include <SPI.h>
#include <RH_RF95.h>

#define RFM95_CS 10
#define RFM95_RST 7
#define RFM95_INT 2

#define RF95_FREQ 915.0

// Singleton instance of the radio driver
RH_RF95 rf95(RFM95_CS, RFM95_INT);

void setup() {
  pinMode(RFM95_RST, OUTPUT);
  digitalWrite(RFM95_RST, HIGH);

  while (!Serial);
  Serial.begin(9600);
  delay(100);

  Serial.println("Arduino LoRa RX Test!");

  // Manual reset
  digitalWrite(RFM95_RST, LOW);
  delay(10);
  digitalWrite(RFM95_RST, HIGH);
  delay(10);

  while (!rf95.init()) {
    Serial.println("LoRa radio init failed");
    while (1);
  }
  Serial.println("LoRa radio init OK!");

  // Set the LoRa frequency
  if (!rf95.setFrequency(RF95_FREQ)) {
    Serial.println("setFrequency failed");
    while (1);
  }
  Serial.print("Set Freq to: "); Serial.println(RF95_FREQ);

  // Set the LoRa transmitter power
  rf95.setTxPower(23, false);
}

void loop() {
  if (rf95.available()) {
    // Should be a message for us now   
    uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
    uint8_t len = sizeof(buf);

    if (rf95.recv(buf, &len)) {
      // Extract the received message
      String receivedMessage = (char*)buf;
      
      Serial.println(receivedMessage);

      // Now you can add your own logic to process the received message
      // For example, if you expect a specific format like "Temperature: XX.XX C, Humidity: XX.XX%", you can extract the temperature and humidity values.

      // Send an acknowledgment if needed
      uint8_t ack[] = "Message received!";
      rf95.send(ack, sizeof(ack));
      rf95.waitPacketSent();
    } else {
      Serial.println("Receive failed");
    }
  }
}
