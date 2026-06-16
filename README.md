# Obstacle Avoiding Robot using Arduino, Ultrasonic Sensor, Servo Motor and L293D Motor Shield

## Project Overview

This project implements an autonomous obstacle-avoiding robot using Arduino. The robot continuously moves forward and detects nearby objects using an ultrasonic sensor. When an obstacle is detected within a predefined distance threshold, the robot stops, moves backward briefly, and then resumes forward movement.

The system uses:

* Arduino Uno
* L293D Motor Shield
* Ultrasonic Sensor (HC-SR04)
* Servo Motor
* DC Motors
* Arduino IDE

---

## Features

* Autonomous movement
* Obstacle detection using ultrasonic sensor
* Automatic stop and reverse behavior
* Motor control using L293D Motor Shield
* Distance monitoring through Serial Monitor

---

## Hardware Components

| Component                 | Quantity |
| ------------------------- | -------- |
| Arduino UNO               | 1        |
| L293D Motor Shield        | 1        |
| DC Motors                 | 2        |
| Ultrasonic Sensor HC-SR04 | 1        |
| Servo Motor               | 1        |
| Robot Chassis             | 1        |
| Battery Pack              | 1        |

---

## Libraries Required

Install these libraries using Arduino IDE:

```text
AFMotor
Servo
NewPing
```

Installation:

Arduino IDE → Sketch → Include Library → Manage Libraries

Search and install:

* AFMotor
* NewPing

Servo library comes pre-installed.

---

## Pin Configuration

### Ultrasonic Sensor

| Sensor  | Arduino |
| ------- | ------- |
| Trigger | A1      |
| Echo    | A0      |

### Servo Motor

| Device | Pin |
| ------ | --- |
| Servo  | D10 |

### Motor Connections

| Motor   | Shield Port |
| ------- | ----------- |
| Motor 1 | M1          |
| Motor 2 | M2          |


## System Workflow

1. Robot starts moving forward.
2. Ultrasonic sensor continuously measures distance.
3. If distance becomes less than 25 cm:

   * Stop motors
   * Reverse briefly
   * Stop
   * Continue moving forward
4. Repeat continuously.



## Parameters Used

```cpp
FORWARD_SPEED = 80
BACKWARD_SPEED = 1
OBSTACLE_DISTANCE = 25
MAX_DISTANCE = 200
```

## Project Structure

```text
Obstacle_Avoiding_Robot/
│
├── obstacle_robot.ino
├── README.md

## How to Run

### Step 1

Install Arduino IDE.

### Step 2

Install required libraries.

### Step 3

Connect hardware.

### Step 4

Upload the code to Arduino.

### Step 5

Open Serial Monitor.

### Step 6

Power the robot and observe movement.

## Expected Output

* Robot moves forward automatically.
* Detects obstacles.
* Stops and reverses.
* Continues navigation.
## Future Improvements

* Add left/right scanning using servo rotation
* Improve obstacle decision logic
* Add Bluetooth control
* Add live monitoring dashboard

---

## Author

Makarand Patil

Arduino | Embedded Systems | Robotics
