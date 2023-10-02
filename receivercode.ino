// For Receiver 

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

RF24 radio(22, 17);        // Set CE and CSN pins
Servo myServo;             // Create a servo object

const byte address[6] = "00001"; // Address for the communication channel

void setup() {
    Serial.begin();

  radio.begin();                  // Initialize the NRF24L
  radio.openReadingPipe(1, address); // Open the communication pipe
  radio.startListening();           // Start listening for incoming messages
  myServo.attach(0);                // Attach the servo to pin 6
}

void loop() {
  if (radio.available()) {          // Check if data is available
    int potValue;                   // Variable to store potentiometer value
    radio.read(&potValue, sizeof(potValue)); // Read the potentiometer value
    int servoPos = map(potValue, 0, 1023, 0, 180); // Map the pot value to servo position
    myServo.write(servoPos);        // Move the servo to the desired position
     Serial.println(servoPos);
    delay(1000);  
  }
}
