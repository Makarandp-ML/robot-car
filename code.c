#include <AFMotor.h>
#include <Servo.h>
#include <NewPing.h>

// L293D motor shield setup
AF_DCMotor motor1(1, MOTOR12_64KHZ); // Motor 1 connected to M1
AF_DCMotor motor2(1, MOTOR12_64KHZ); // Motor 2 connected to M2

// Ultrasonic sensor pins
#define TRIGGER_PIN A1
#define ECHO_PIN A0
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters)

// Servo motor pin
#define SERVO_PIN 10 // Servo connected to pin 10 on the shield

// Constants
#define FORWARD_SPEED 80 // Motor speed when moving forward (0-255)
#define BACKWARD_SPEED 1 // Motor speed when moving backward (0-255)
#define OBSTACLE_DISTANCE 25 // Distance threshold to detect obstacles (in cm)

Servo myServo; // Create servo object
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance

int distance = 0;

void setup() {
  // Initialize motor speeds to 0
  motor1.setSpeed(0);
  motor2.setSpeed(0);

  // Attach servo to pin
  myServo.attach(SERVO_PIN);

  // Center the servo
  myServo.write(90);

  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // Get distance reading from ultrasonic sensor
  distance = sonar.ping_cm();

  // Print distance for debugging
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // If obstacle is detected
  if (distance > 0 && distance < OBSTACLE_DISTANCE) {
    stopMotors();
    delay(500);

    // Reverse slightly
    moveBackward();
    delay(500);

    stopMotors();
    delay(500);

    // Resume moving forward
    moveForward();
  } else {
    // No obstacle, move forward
    moveForward();
  }
}

void moveForward() {
  motor1.setSpeed(FORWARD_SPEED);
  motor2.setSpeed(FORWARD_SPEED);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
}

void moveBackward() {
  motor1.setSpeed(BACKWARD_SPEED);
  motor2.setSpeed(BACKWARD_SPEED);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
}

void stopMotors() {
  motor1.setSpeed(0);
  motor2.setSpeed(0);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}