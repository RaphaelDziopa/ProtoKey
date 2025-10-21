# ProtoKey

A project to create a swiss army knife but for electronics. The whole system is to be compact and lightweight with ease of repairability and modifications. 

📁 ProtoKey/
├── 📂 /
│   ├── 📂 html
│   ├── 📂 images
│   ├── 📂 style
│   └── 📂 scripts
├── 📂 .github/
│   └── 📂 workflow
├── 📂 README/
│   └── 📂 images
├── LICENCE
└── README.md 




## 1. Requirements
Based on an ESP32 dev board it must fulfil multiple requirements.

Internal battery to the system
Handle RFID
Handle 2.4GHz and bluetooth
Handle ESPnow
A small screen for battery percentage and connection info
Send all data to a selfhosted webserver (thus accessible by phone)
Data writes and modifications to be sent by phones from the webserver.
Uses infrared light as a universal remote

The addition of new modules such as sim readers or gps have to be possible and reasonably easy physically in the system but also in the code.



## 2. Components

### 2.1 Mainboard - ESP32 Devkit

The ESP32 dev board formally named the ESP32 VROOM 32 has an USB-C connector with 34 GPIO pins. With included Wifi and bluetooth capabilities powered with the ESP32-D0WDQ6 chip.

For specifications it has:

USB-C Input voltage		5V
GPIO Input/Output		3.3V
Minimal functioning Current	min. 500mA
Clock speed margins			80MHz / 240MHz
RAM					512kB
External Flash				4MB
Pins I/O				34
Supported Interfaces		SPI, I2C, I2S, CAN, UART
Wi-Fi protocols			802.11 b/g/n (802.11n up to 150 Mbps)
Wi-Fi frequencies			2.4 GHz - 2.5 GHz
Bluetooth				V4.2 - BLE & Classic Bluetooth
Antenna				PCB
Dimensions				56x28x13mm

The pinout of the GPIO pins is as follows :

For more information see: (https://www.espressif.com/sites/default/files/documentation/esp32-wroom-32_datasheet_en.pdf)

### 2.2 Display - 0.86" I²C OLED
The display uses a 0.96” OLED Module with the I2C protocol. This will display battery and connection information

No backlight
Voltage: 3.3V-5V DC.
Viewing angle: >160°
Resolution: 128 x 64
Working temperature: -30°C ~ 70°C 


### 2.3 User input - ???
Not yet decided.

### 2.4 RFID module - ???
Not yet decided

### 2.5 RF module - ???
Not yet decided.

### 2.6 Case
Not yet decided.
