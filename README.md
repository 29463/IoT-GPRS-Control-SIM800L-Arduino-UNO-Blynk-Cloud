###  IoT-GPRS-Control-SIM800L-Arduino-UNO-Blynk-Cloud
This repository demonstrates how to establish a bi-directional communication channel between an Arduino UNO and the Blynk IoT Cloud using the SIM800L GSM/GPRS module.
## 🎯 Project Goal
To control an LED (or a relay for larger appliances) remotely via the Blynk Mobile App using mobile data (2G/GPRS).
## 🚀 Key FeaturesCellular Connectivity: 
Connects to the internet via GPRS using a SIM card.Remote Control: Toggle an LED ON/OFF from anywhere in the world using the Blynk Dashboard or App.Low Cost: Utilizes the affordable SIM800L module and the standard Arduino UNO.Blynk 2.0 Ready Compatible with the latest Blynk IoT platform.
## 🛠️ Hardware RequirementsMicrocontroller: Arduino UNO (or Nano).GSM Module: SIM800L (Red module recommended).Power Supply: External 3.7V - 4.2V Li-Ion battery or a Buck Converter (LM2596) capable of delivering 2A peak current.Note: The Arduino 5V pin is usually insufficient to power the SIM800L during network bursts.SIM Card: A working Micro-SIM with an active data plan (2G support required).Output: LED (and 220Ω resistor) or 5V Relay Module.Connection: Jumper wires and Breadboard.
## 💻 Software & Libraries 
To run this project, you need the Arduino IDE and the following libraries installed via the Library Manager:TinyGSM: For handling the SIM800L AT commands.Blynk: For connecting to the Blynk Cloud.
## 🔌 Circuit Connections
SIM800L PinArduino UNO PinNoteVCCExternal Power +Must be 3.7V - 4.2V (Max 4.4V)GNDGNDCommon Ground with ArduinoTXD2 (SoftwareSerial RX)Connects to Arduino RX defined in codeRXD3 (SoftwareSerial TX)Connects to Arduino TX defined in codeRSTNot Connected(Optional)ComponentArduino UNO PinLED (+)D13 (or D7)LED (-)GND
## ⚠️ Important: 
The SIM800L communicates at 2.8V logic. While it often works directly with Arduino (5V), it is recommended to use a voltage divider on the SIM800L RX pin to protect the module.
## ⚙️ ConfigurationBlynk Setup:
Create a new Template in the Blynk Console.Create a Datastream (Virtual Pin V1) for the LED (Integer, 0-1).Copy your BLYNK_TEMPLATE_ID and BLYNK_DEVICE_NAME.

![WhatsApp Image 2026-01-28 at 2 46 50 PM](https://github.com/user-attachments/assets/5b7ce8ae-8bb7-49e9-9ddd-f86d5634e1f7)
