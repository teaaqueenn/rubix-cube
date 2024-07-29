// Motor control pins
const int motor1Pin = 9;  // Example pin for Motor 1
const int motor2Pin = 10; // Example pin for Motor 2

void setup() {
  // Initialize serial communication at 9600 baud rate
  Serial.begin(9600);
  
  // Set motor pins as output
  pinMode(motor1Pin, OUTPUT);
  pinMode(motor2Pin, OUTPUT);
}

void loop() {
  // Check if data is available to read
  if (Serial.available() > 0) {
    // Read the incoming byte
    char command = Serial.read();
    
    // Execute commands based on the received byte
    switch (command) {
      case 'A':
        turnMotor1();
        break;
      case 'B':
        turnMotor1Alternative();
        break;
      case 'C':
        turnMotor2();
        break;
      case 'D':
        turnMotor2Alternative();
        break;
      case 'E':
        turnMotor1();
        turnMotor2();
        break;
      case 'F':
        turnMotor1Alternative();
        turnMotor2();
        break;
      // Add more cases as needed for additional commands
      default:
        // Handle unknown commands
        Serial.print("Unknown command: ");
        Serial.println(command);
        break;
    }
  }
}

// Function to turn Motor 1
void turnMotor1() {
  digitalWrite(motor1Pin, HIGH); // Turn motor 1 on
  delay(500);                    // Run for 500 ms
  digitalWrite(motor1Pin, LOW);  // Turn motor 1 off
}

// Alternative function to turn Motor 1
void turnMotor1Alternative() {
  digitalWrite(motor1Pin, HIGH);
  delay(1000);                   // Run for 1000 ms
  digitalWrite(motor1Pin, LOW);
}

// Function to turn Motor 2
void turnMotor2() {
  digitalWrite(motor2Pin, HIGH);
  delay(500);
  digitalWrite(motor2Pin, LOW);
}

// Alternative function to turn Motor 2
void turnMotor2Alternative() {
  digitalWrite(motor2Pin, HIGH);
  delay(1000);
  digitalWrite(motor2Pin, LOW);
}
