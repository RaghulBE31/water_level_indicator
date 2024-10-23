# water_level_indicator


## Overview
This project utilizes a NodeMCU (ESP8266) microcontroller to create a web server that displays the water level of a tank in real-time. The water level is measured using an ultrasonic sensor (HC-SR04) or a water level sensor, and the data is presented in a visually interactive web interface.

## Components Required
- **NodeMCU (ESP8266)**
- **Ultrasonic Sensor (HC-SR04) or Water Level Sensor**
- **Breadboard and Jumper Wires**
- **Power Supply (USB or battery)**

## Wiring Instructions
1. **Ultrasonic Sensor Wiring:**
   - VCC to NodeMCU 3.3V
   - GND to NodeMCU GND
   - Trig to NodeMCU D2 (GPIO4)
   - Echo to NodeMCU D1 (GPIO5)

2. **Water Level Sensor Wiring:**
   - Connect the sensor according to its datasheet (usually involves power, ground, and signal connections).

## Software Requirements
- **Arduino IDE**
  - Install the ESP8266 board package.
  - Install necessary libraries: `ESP8266WiFi` and `ESP8266WebServer`.

## Code
The main code for the project can be found in the `water_level_indicator.ino` file. This code sets up a web server on the NodeMCU, retrieves the water level from the sensor, and serves a web page displaying the tank and current water level.

### Key Features of the Code
- **HTML/CSS/JavaScript:** A web interface that visually represents the water tank and updates the water level in real-time.
- **Water Level Measurement:** Uses an ultrasonic sensor to measure the distance to the water surface, converting it to the water level.
- **Real-time Updates:** The water level display updates every second through JavaScript.

## How to Use
1. Connect the NodeMCU and sensors according to the wiring instructions.
2. Open the Arduino IDE and upload the code to the NodeMCU.
3. Open the Serial Monitor to get the IP address assigned to the NodeMCU.
4. Enter the IP address in a web browser to view the water level indicator interface.

## Customization
- Modify the tank dimensions in the code (`tankHeight` and `tankWidth`) to match your actual tank size.
- You can enhance the CSS styles in the HTML code to improve the visual appearance of the web interface.
- Add features such as alerts for low/high water levels or historical data tracking.

## Troubleshooting
- Ensure all components are properly connected.
- Check the Serial Monitor for any error messages or connection issues.
- Make sure your NodeMCU is connected to the same Wi-Fi network as your computer or device accessing the web server.

## License
This project is open source. Feel free to modify and distribute it under your own terms.

## Acknowledgements
- [ESP8266 Community Forum](https://www.esp8266.com/)
- [Arduino Project Hub](https://create.arduino.cc/projecthub)

