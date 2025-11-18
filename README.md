# ProtoKey
A student project to design a multitool for electronic hobbyist.

# ProtoKey

A project to create a swiss army knife but for electronics. The whole system is to be compact and lightweight with ease of repairability and modifications. 

📁 ProtoKey/  
├── 📂 /  
│   ├── 📂 html  
│   └── 📂 scripts  
├── 📂 .github/  
├── 📂 README/  
├── LICENCE  
└── README.md   




## 1. Requirements

The idea being based on the Flipper Zero, this project doesn't intend to copy the Flipper. It is a student's project to create a usable multitool, to help in small hobbyist electronics, in a small and portable package. Thus, it has to be able to anwser to multiple demands to debug projects. The ProtoKey is based on an ESP32 dev board with the addition of multiple open source modules.

The system must:

Have an onboard user interface, with an OLED b&w, with an encoder and 2 buttons for the input.  
Have a 1 channel Occiloscope for AC/DC in range [-15;15]V and [0;30]V.  
Be able to run with an intergrated Li-Po battery.  
Handle RFID with copy and paste functionalities.  
Be able to act as a universal IR emiter and receiver, such as a universal remote.


For future versions:  
Handle 2.4GHz and Bluetooth  
Handle ESPnow  

The addition of new modules such as SIM or GPS must be possible and reasonably easy physically and through the code.


## 2. Components

### 2.1 Mainboard - ESP32 Devkit

The ESP32 dev board formally named the ESP32 VROOM 32 has an USB-C connector with 34 GPIO pins. With included Wifi and bluetooth Capabilities powered with the ESP32-D0WDQ6 chip.

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
