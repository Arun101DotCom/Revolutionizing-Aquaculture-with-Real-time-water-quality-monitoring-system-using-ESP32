# Revolutionizing-Aquaculture-with-Real-time-water-quality-monitoring-system-using-ESP32
An IoT-based aquaculture monitoring system using ESP32S3 and ThingsBoard. Features real-time tracking of pH (Nernst Equation), turbidity, water level, and air quality. Utilizes ESP-NOW for peer-to-peer sensor communication and WiFi for cloud data analytics, providing a scalable solution for smart aquatic farming management.

# Revolutionizing Aquaculture: Real-time Water Quality Monitoring

This project implements an automated monitoring system designed to optimize aquatic farming environments. Using an array of specialized sensors and the ESP32S3 microcontroller, it tracks critical water and environmental parameters to prevent livestock loss and improve profitability.

## 🚀 System Architecture
The system follows a decentralized architecture where sensor nodes collect data and relay it via **ESP-NOW** to a central gateway, which then pushes the data to the **ThingsBoard IoT Platform** via Wi-Fi.



## 📊 Sensor Implementation & Physics
- **pH Level:** Measured using a glass-bulb electrode and calculated via the **Nernst Equation**: $E_m = E_o + \frac{2.3RT}{nF} \log[H^+]$.
- **Turbidity:** Detected using the **TSL2561 Luminosity sensor** to measure light scattering through water.
- **Water Level:** Calculated via Ultrasonic sound waves ($D = \frac{v \times t}{2}$).
- **Air Quality:** Monitoring for toxic gases (CO, Formaldehyde) above the water surface to ensure environmental safety.



## 📡 Communication Protocols
- **ESP-NOW:** Peer-to-peer communication between nodes (no router required).
- **UART:** Serial communication for RFID data acquisition.
- **MQTT/WiFi:** Secure data transmission to the ThingsBoard cloud dashboard.

## 🛠 Tech Stack
- **Hardware:** ESP32S3, TSL2561, HC-SR04, pH Probe, Grove 125KHz RFID.
- **Software:** Arduino IDE (C++).
- **Cloud:** ThingsBoard (Data Visualization & Analytics).

## 📂 Project Structure
- `/src`: Arduino `.ino` sketches for Master and Slave nodes.
- `/docs`: Technical datasheets and circuit diagrams.
- `/dashboard`: JSON exports of the ThingsBoard dashboard layout.
