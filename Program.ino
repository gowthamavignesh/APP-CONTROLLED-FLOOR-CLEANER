#include <Servo.h>
#include <BluetoothSerial.h>

Servo motor;
BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("FloorCleaner"); // Bluetooth device name

  motor.attach(D3); // Connect motor to pin D3
}

void loop() {
  if (SerialBT.available()) {
    char command = SerialBT.read();
    processCommand(command);
  }
}

void processCommand(char command) {
  switch (command) {
    case 'F':
      moveForward();
      break;
    case 'B':
      moveBackward();
      break;
    case 'L':
      turnLeft();
      break;
    case 'R':
      turnRight();
      break;
    case 'S':
      stopMoving();
      break;
    default:
      break;
  }
}

void moveForward() {
  // Implement forward movement logic here
  Serial.println("Moving Forward");
}

void moveBackward() {
  // Implement backward movement logic here
  Serial.println("Moving Backward");
}

void turnLeft() {
  // Implement left turn logic here
  Serial.println("Turning Left");
}

void turnRight() {
  // Implement right turn logic here
  Serial.println("Turning Right");
}

void stopMoving() {
  // Implement stop movement logic here
  Serial.println("Stopping");
}
