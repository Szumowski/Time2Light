#ESP32 Automatic Light Controller

This project uses ESP32 to automatically control decorative lights (or other devices) based on the current time.
Lights turn on daily from 17:00 to 23:59 and off otherwise.
Time synchronization is handled via NTP (Network Time Protocol).

#✨ Features

Connects ESP32 to Wi-Fi

Retrieves current time from an NTP server

Controls decorative lights through a MOSFET connected to ESP32 GPIO

Automatically turns lights on from 17:00 to 24:00

Displays current time in Serial Monitor

#🛠️ Hardware Requirements

ESP32

MOSFET (e.g., IRF520)

Decorative lights

Battery or power supply for lights

Resistors: 200 Ω and 100 kΩ

#🔌 Wiring Diagram

Light negative → D MOSFET

Battery negative → S MOSFET and ESP32 GND

ESP32 GPIO 26 → G MOSFET through 200 Ω resistor

G MOSFET → ESP32 GND through 100 kΩ resistor

Decorative lights (-) ---> D MOSFET
Battery (-) -------------> S MOSFET ---> ESP32 GND
ESP32 GPIO 26 ---> 200Ω ---> G MOSFET
G MOSFET ---> 100kΩ ---> ESP32 GND

#📂 Code Overview

WiFi.begin(ssid, password) → connects to Wi-Fi

configTime(gmtOffset_sec, daylightOffset_sec, ntpServer) → sets time from NTP server

In loop():

retrieves current time

if the hour is between 17 and 23, sets gatePin HIGH (lights ON)

otherwise, sets gatePin LOW (lights OFF)

#⚙️ Setup

Replace placeholders in the code with your credentials:

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";


Upload the code to your ESP32 using Arduino IDE or PlatformIO.

Connect decorative lights through the MOSFET according to the wiring diagram above.

Open the Serial Monitor (9600 baud) to see the current time and light status.

#🚀 Example Output (Serial Monitor)
Wifi connected.
Time: 17:05
Light ON

Time: 00:01
Light OFF

#📌 Notes

You can change gatePin if you want to use a different GPIO.

On/off hours can be easily modified in the if statement.

Time zone and daylight saving are set via gmtOffset_sec and daylightOffset_sec.

Make sure the MOSFET is rated for the current drawn by your lights.
