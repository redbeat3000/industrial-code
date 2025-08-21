# Industrial IoT Predictive Maintenance System

## Table of Contents
- [Description](#description)
- [Tech Stack](#tech-stack)
- [Key Features](#key-features)
- [Project Structure](#project-structure)
- [Setup Instructions](#setup-instructions)
- [Dashboard](#dashboard)
- [Contribution Guidelines](#contribution-guidelines)
- [License](#license)
# Stats

![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)
![Issues](https://img.shields.io/github/issues/redbeat3000/industrial-code)
![Pull Requests](https://img.shields.io/github/issues-pr/redbeat3000/industrial-code)
![Last Commit](https://img.shields.io/github/last-commit/redbeat3000/industrial-code)
![Contributors](https://img.shields.io/github/contributors/redbeat3000/industrial-code)
![Repo Size](https://img.shields.io/github/repo-size/redbeat3000/industrial-code)

## Description
A system to monitor industrial machines’ vibration, temperature, and pressure, predicting failures before they happen. This helps reduce downtime and maintenance costs by proactively identifying potential issues.

## Tech Stack
- **Hardware:** ESP32, Vibration Sensor, Temperature Sensor  
- **IoT Platform:** [Azure IoT Hub](https://azure.microsoft.com/en-us/services/iot-hub/) / [AWS IoT Analytics](https://aws.amazon.com/iot-analytics/)  
- **Programming Languages:** Python, C++  
- **Libraries:** Scikit-learn, MQTT, Pandas  
- **Frontend:** HTML, CSS, JavaScript
- **Database:** InfluxDB / PostgreSQL
- **Visualization:** Grafana / Custom Dashboard

## Key Features
- Predictive maintenance alerts  
- Machine health monitoring dashboard  
- Historical analysis and trend prediction  

## Project Structure
PredictiveMaintenance/
├── firmware/
│ └── sensors.cpp
├── analytics/
│ ├── data_processing.py
│ └── predictive_model.py
├── dashboard/
│ ├── index.html
│ ├── style.css
│ └── dashboard.js
└── README.md

## Bonus Enhancements
- AI-powered failure prediction model  
- Edge computing for real-time local decisions  

## Setup Instructions
# How to Run the Industrial IoT Predictive Maintenance System

## 1. Set up the ESP32 Firmware
1. Install **Arduino IDE** or **PlatformIO**.  
2. Connect your ESP32 to your computer via USB.  
3. Open `sensors.cpp` in the IDE.  
4. Replace placeholders for WiFi SSID, password, and MQTT broker with your info.  
5. Select the ESP32 board and the correct COM port.  
6. Click **Upload** to flash the firmware.  

*The ESP32 will now start sending sensor data to your MQTT broker every 2 seconds.*

---

## 2. Run the Data Processing Script
1. Make sure **Python 3** is installed.  
2. Install dependencies:  
```bash
pip install pandas paho-mqtt
Run the script to collect and store incoming MQTT data:
```
python3 analytics/data_processing.py
Incoming sensor readings will be saved to machine_data.csv.

3. Train the Predictive Model
Install additional libraries:


```pip install scikit-learn joblib```
Run the predictive model script:

python3 analytics/predictive_model.py
This trains a Random Forest model and saves it as predictive_model.pkl.

4. Launch the Dashboard
Option A: Open Locally

Open dashboard/index.html in your browser.

The page will show static data unless connected to live MQTT via WebSockets.

Option B: Run Live Dashboard with Node.js

Install Node.js and npm.

Install the MQTT library:

```npm install mqtt```

Serve the dashboard using a simple server like live-server or http-server.

Ensure dashboard.js connects to your MQTT broker via WebSockets (wss://broker.hivemq.com:8000/mqtt or your broker).

Open the dashboard in your browser to see real-time sensor data.

5. Verify Everything Works
ESP32 is publishing data to MQTT.

data_processing.py is storing readings.

predictive_model.py trains the AI model.

Dashboard displays live metrics from your machines.

## Dashboard
The dashboard displays real-time machine vibration and temperature data via MQTT.  
- Open `index.html` in a browser to view metrics.  
- For live updates, `dashboard.js` connects to the MQTT broker and updates the UI.

## Lisence
MIT License

Copyright (c) 2025 Blessing Nyaberi Hamisi

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

[full MIT text continues...]


