# Smart Water Tank Level Monitoring System

## 1. Project Overview

The Smart Water Tank Level Monitoring System is an Arduino UNO-based project designed to monitor the water level in a tank automatically.

It uses an HC-SR04 ultrasonic sensor to measure the distance between the sensor and the water surface. The Arduino calculates the water level percentage and displays the result on a 16×2 I2C LCD.

Red and green LEDs, along with a buzzer, provide alerts based on the water level.

## 2. Objectives

- Automatically monitor the water level.
- Display the water level percentage on an LCD.
- Identify LOW, NORMAL and FULL water conditions.
- Provide alerts using LEDs and a buzzer.
- Reduce manual monitoring and water wastage.

## 3. Components Required

- Arduino UNO
- HC-SR04 Ultrasonic Sensor
- 16×2 I2C LCD Display
- Red LED
- Green LED
- Buzzer
- 220Ω Resistors
- Breadboard
- Jumper Wires
- USB Cable

## 4. Pin Connections

| Component | Arduino UNO Pin |
|---|---|
| HC-SR04 TRIG | D9 |
| HC-SR04 ECHO | D10 |
| Red LED | D11 |
| Green LED | D12 |
| Buzzer | D8 |
| LCD SDA | A4 |
| LCD SCL | A5 |
| VCC | 5V |
| GND | GND |

## 5. Working Principle

1. The ultrasonic sensor sends ultrasonic waves towards the water surface.
2. The waves reflect from the water surface and return to the sensor.
3. The sensor measures the echo time.
4. Arduino calculates the distance and water level percentage.
5. The LCD displays the water level and status.
6. LEDs and the buzzer indicate the water level condition.

## 6. Calculation

Distance = (Echo Time × 0.0343) / 2

Water Level = Tank Height − Distance

Water Level Percentage = (Water Level / Tank Height) × 100

Example:

Tank Height = 30 cm  
Measured Distance = 9 cm  
Water Level = 30 − 9 = 21 cm  
Water Level Percentage = (21 / 30) × 100 = 70%

## 7. Output Conditions

- LOW (Below 20%): Red LED ON and Buzzer ON.
- NORMAL (20%–79%): Green LED ON and Buzzer OFF.
- FULL (80%–100%): Green LED ON and Buzzer ON.

## 8. Applications

- Domestic water tanks
- Apartments and buildings
- Industrial water storage tanks
- Agricultural water tanks

## 9. Future Enhancements

- IoT-based remote water level monitoring.
- Mobile application notifications.
- Automatic water pump control.
- Cloud-based water level data storage.

## 10. Technologies Used

- Embedded Systems
- Arduino Programming
- Ultrasonic Sensing
- LCD Interfacing
- Hardware Prototype

## 11. Conclusion

- This project provides a simple and cost-effective solution for automatic water level monitoring. It helps users identify water levels and receive alerts, reducing the need for manual monitoring.

This project provides a simple and cost-effective solution for automatic water level monitoring. It helps users identify water levels and receive alerts, reducing the need for manual monitoring.
