# nRF24L01 Temp & Humidity Receiver

This Arduino code is designed to receive temperature, humidity, and pressure data from a sensor node via an nRF24L01 transceiver module. It utilizes the U8x8lib library for displaying sensor data on an SSD1306 128x64 OLED display.

**Hardware Requirements**
- Arduino board
- nRF24L01 transceiver module
- SSD1306 128x64 OLED display
- DHT sensor (or any other sensor providing temperature, humidity, and pressure data)
- Connecting wires

**Libraries Used**

- U8x8lib: A lightweight graphics library for monochrome displays, used for OLED display management.
- SPI: Arduino SPI library for communication with SPI devices.
- nRF24L01: Library for controlling the nRF24L01 transceiver module.
- Wire: Arduino Wire library for I2C communication.

**Installation**

- Install the necessary libraries mentioned above.
- Connect the nRF24L01 module, OLED display, and sensor node to the Arduino board as per the wiring described in the code.

**Setup**

- Upload the code to the Arduino board.
- Ensure that the correct pins for the nRF24L01 module, OLED display, and sensor node are configured in the code (pipe1, SCL, SDA, etc.).
- Power up the setup.

**Operation**

- The Arduino continuously listens for data from the sensor node via the nRF24L01 module.
- Once data is received, it is displayed on the OLED display and printed to the serial monitor.
- The OLED display shows the temperature, humidity, and pressure values received from the sensor node.

**Additional Notes**
- This code assumes that the sensor node is transmitting data in a specific format, including temperature, humidity, pressure, and a sensor number.
- Make sure to adjust the code according to your specific sensor node's data format if necessary.
- Ensure proper power supply and wiring connections to avoid any hardware issues.
