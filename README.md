# ESP32-S3 Robot Car

![Car Photo](IMG_8989.jpeg)

A 4WD robot car controlled over WiFi via a web server, built on the ESP32-S3 Zero microcontroller.

## Hardware

- **Microcontroller:** ESP32-S3 Zero (240MHz dual core, WiFi + BT5)
- **Chassis:** 4WD robot car chassis with TT motors
- **Motor Drivers:** 2x TB6612FNG dual DC motor driver
- **Power:** 2x ICR18650 cells (7.4V nominal) with buck converter stepping down to 5V for the ESP32
- **Control:** WiFi access point hosted on the ESP32, controllable from any browser on the network

## Wiring

Each TB6612FNG handles two motors (one per channel). Pin assignments:

| Define | GPIO | Motor |
|---|---|---|
| PWMB_FRONT_LEFT | 4 | Front Left PWM |
| BIN1_FRONT_LEFT | 5 | Front Left Direction |
| BIN2_FRONT_LEFT | 6 | Front Left Direction |
| PWMA_FRONT_RIGHT | 1 | Front Right PWM |
| AIN1_FRONT_RIGHT | 2 | Front Right Direction |
| AIN2_FRONT_RIGHT | 3 | Front Right Direction |
| PWMB_BACK_LEFT | 10 | Back Left PWM |
| BIN1_BACK_LEFT | 9 | Back Left Direction |
| BIN2_BACK_LEFT | 8 | Back Left Direction |
| PWMA_BACK_RIGHT | 13 | Back Right PWM |
| AIN1_BACK_RIGHT | 12 | Back Right Direction |
| AIN2_BACK_RIGHT | 11 | Back Right Direction |

**Motor direction key:**
- Forward: IN1 = HIGH, IN2 = LOW
- Backward: IN1 = LOW, IN2 = HIGH
- Stop: IN1 = LOW, IN2 = LOW (or PWM = 0)

**Power:**
- Battery positive → Buck converter IN+
- Buck converter OUT+ (set to 5V) → ESP32-S3 Zero 5V pin
- Battery positive → TB6612 VM
- ESP32-S3 Zero 3.3V pin → TB6612 VCC
- All grounds shared on common rail

## File Structure

```
ESP32_S3_Car/
├── ESP32_S3_Car.ino  # Entry point: WiFi AP setup, web server instantiation, main loop
├── driving.h         # Motor function declarations
├── driving.cpp       # Motor pin definitions and drive functions
├── WebControl.h      # HTTP handler declarations, extern server reference
└── WebControl.cpp    # HTTP route handlers, DNS server for captive portal
```

## Usage

1. Flash the sketch to the ESP32-S3 Zero via Arduino IDE
2. On your phone or computer, connect to the **RoboCar** WiFi network (password: `123456789`)
3. Open a browser and navigate to `192.168.4.1`
4. Control the car via the following routes:

| Route | Action |
|---|---|
| `/` | Serves the HTML control page |
| `/forward` | Drive forward |
| `/backward` | Drive backward |
| `/left` | Turn left (tank steering) |
| `/right` | Turn right (tank steering) |
| `/stop` | Stop all motors |

### Captive Portal

The firmware runs a DNS server that intercepts all domain requests and redirects them to the ESP32's IP, so connecting to the WiFi network on most devices will automatically open the control page. The following detection URLs are also handled and redirect to the control page:

- `/generate_204` (Android)
- `/hotspot-detect.html` (Apple)
- `/connecttest.txt` (Windows)
- `/ncsi.txt` (Windows)

## Motor Speeds

Forward and backward use a PWM value of **50** (out of 255). Left and right turns use a PWM value of **100** for tighter, more responsive spinning.

## Arduino IDE Setup

- **Board:** ESP32S3 Dev Module
- **USB Mode:** Hardware CDC and JTAG
- **USB CDC On Boot:** Enabled (required for Serial monitor)
- **Upload Speed:** 921600

## Turning

The car uses **tank/differential steering** — no steering wheels. Turning is achieved by spinning the left and right side wheels in opposite directions, allowing tight turns and spinning in place.
