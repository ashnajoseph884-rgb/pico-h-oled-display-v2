# Raspberry Pi Pico H to I2C OLED Screen Wiring Guide

Use this reference guide to connect your 4-pin SSD1306 OLED display to your Raspberry Pi Pico H microcontroller.

## Pin Connections Table

| OLED Display Pin | Raspberry Pi Pico H Pin | Pin Function / Description |
| :--- | :--- | :--- |
| **VCC** | **3V3 (OUT)** (Physical Pin 36) | 3.3V Power Supply |
| **GND** | **GND** (Physical Pin 38 or any Ground) | Ground Connection |
| **SDA** | **GP4** (Physical Pin 6 / I2C0 SDA) | Data Signal Line |
| **SCL** | **GP5** (Physical Pin 7 / I2C0 SCL) | Clock Signal Line |

## Crucial Reminders
* **Do not use the 5V VBUS pin:** The SSD1306 screen logic works safely on 3.3V. Connecting it to 5V might permanently damage the Pico's GPIO pins.
* **Code Match:** If you change the `GP4` and `GP5` pins in your physical hardware setup, you must update the `Wire.setSDA()` and `Wire.setSCL()` numbers inside your `display_test.ino` code file to match.
*
