#include <Servo.h>

// Define the pins for 6 servos
const int servoPins[6] = {2, 3, 4, 5, 6, 7}; // Example pins for 6 servos

// Create an array of Servo objects
Servo servos[6];

// Define current angles for each servo
int currentAngles[6] = {0, 0, 0, 0, 0, 0};

// Define the min and max angle for servo wrapping
const int minAngle = 0;
const int maxAngle = 270;

void setup() {
  // Initialize serial communication at 9600 baud rate
  Serial.begin(9600);
  
  // Attach each servo to its pin
  for (int i = 0; i < 6; i++) {
    servos[i].attach(servoPins[i]);
    servos[i].write(currentAngles[i]); // Initialize the servo to the starting angle
  }
}

void loop() {
  // Check if data is available to read
  if (Serial.available() > 0) {
    // Read the incoming byte
    String command = Serial.readStringUntil('\n'); // Read until newline

    // Execute commands based on the received byte
    char cmd = command.charAt(0); // First character for the main command
    String parameters = command.substring(1); // Remaining part of the command

    switch (cmd) {
      case 'U':
        handleServoMovement(0, 90); // Turn servo 0 (1st) 90 degrees clockwise
        break;
      case 'U2':
        handleServoMovement(0, 180); // Turn servo 0 (1st) 180 degrees
        break;
      case 'U\'':
        handleServoMovement(0, -90); // Turn servo 0 (1st) 90 degrees counter-clockwise
        break;
      case 'D':
        handleServoMovement(1, 90); // Turn servo 1 (2nd) 90 degrees clockwise
        break;
      case 'D2':
        handleServoMovement(1, 180); // Turn servo 1 (2nd) 180 degrees
        break;
      case 'D\'':
        handleServoMovement(1, -90); // Turn servo 1 (2nd) 90 degrees counter-clockwise
        break;
      case 'L':
        handleServoMovement(2, 90); // Turn servo 2 (3rd) 90 degrees clockwise
        break;
      case 'L2':
        handleServoMovement(2, 180); // Turn servo 2 (3rd) 180 degrees
        break;
      case 'L\'':
        handleServoMovement(2, -90); // Turn servo 2 (3rd) 90 degrees counter-clockwise
        break;
      case 'R':
        handleServoMovement(3, 90); // Turn servo 3 (4th) 90 degrees clockwise
        break;
      case 'R2':
        handleServoMovement(3, 180); // Turn servo 3 (4th) 180 degrees
        break;
      case 'R\'':
        handleServoMovement(3, -90); // Turn servo 3 (4th) 90 degrees counter-clockwise
        break;
      case 'F':
        handleServoMovement(4, 90); // Turn servo 4 (5th) 90 degrees clockwise
        break;
      case 'F2':
        handleServoMovement(4, 180); // Turn servo 4 (5th) 180 degrees
        break;
      case 'F\'':
        handleServoMovement(4, -90); // Turn servo 4 (5th) 90 degrees counter-clockwise
        break;
      case 'B':
        handleServoMovement(5, 90); // Turn servo 5 (6th) 90 degrees clockwise
        break;
      case 'B2':
        handleServoMovement(5, 180); // Turn servo 5 (6th) 180 degrees
        break;
      case 'B\'':
        handleServoMovement(5, -90); // Turn servo 5 (6th) 90 degrees counter-clockwise
        break;
      default:
        Serial.print("Unknown command: ");
        Serial.println(command);
        break;
    }
  }
}

// Function to handle servo movement
void handleServoMovement(int servoIndex, int degrees) {
  if (servoIndex >= 0 && servoIndex < 6) {
    int targetAngle = currentAngles[servoIndex] + degrees;
    targetAngle = wrapAngle(targetAngle); // Wrap the angle if necessary

    // Move the servo to the target angle
    servos[servoIndex].write(targetAngle);

    // Update the current angle
    currentAngles[servoIndex] = targetAngle;
  }
}

// Function to wrap the angle around 270 degrees
int wrapAngle(int angle) {
  // Adjust the angle within the 0 to 270 degree range
  if (angle < minAngle) {
    angle = maxAngle + (angle - minAngle);
  } else if (angle > maxAngle) {
    angle = minAngle + (angle - maxAngle);
  }
  return angle;
}