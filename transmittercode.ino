// FOR Transmitter 

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(22, 17);        // Set CE and CSN pins
int potValue = 0;         // Initialize potentiometer value

const byte address[6] = "00001"; // Address for the communication channel

void setup() {
  Serial.begin();
  radio.begin();                  // Initialize the NRF24L
  radio.openWritingPipe(address);  // Open the communication pipe
}

void loop() {
  potValue = analogRead(A0);  // Read potentiometer value
  radio.write(&potValue, sizeof(potValue)); // Send the potentiometer value
  delay(100);                // Delay for 
  Serial.println(potValue);
  delay(1000);                // Delay for 

}
