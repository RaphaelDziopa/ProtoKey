/*
 * Protokey Device test
 * 
 * This code checks the main functionalities of the Protokey.
 * It should be run to verify that every function is working properly.
 * It is a debug of the device in itself.
 * 
 * 
 * The program works in 2 stages:
 * 
 * First, it will display common info on the ESP32 chip used, including:
 *  - Cores & revision
 *  - CPU freq
 *  - Flash size
 *  - RAM free and used spaces
 *  - The MAC address of the ESP32
 * 
 * Afterwards, it will check the functionalities of each componenent embedded in the system:
 *  - Checks every GPIO pin for a connection.
 *  - Checks the functioning of the OLED screen.
 *  - Checks the encoder.
 * 
 * !!! Make sure before flashing the code [Tools → USB CDC On Boot → Enabled]
 * 
 */

// 
#include <esp_system.h>
#include <esp_chip_info.h>
#include <esp_flash.h>
#include <esp_mac.h>
#include <WiFi.h>

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

// OLED config
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 128
#define OLED_RESET -1
Adafruit_SH1107 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Rotary encoder pins
#define ENC_BTN   13
#define ENC_PIN_A 14
#define ENC_PIN_B 15

// Return button pin
#define BTN_return   16   // GP16

// Encoder
int selectedIndex = 0;
int lastA = HIGH;
int lastB = HIGH;

// Button_debounce
unsigned long lastButtonPress = 0;
const unsigned long debounceMs = 200;

// Menus
const int optionHeight = 10;
const int menuX = 2;
const int menuY = 12;
const int textX = menuX + 3;

const char* menuMAINItems[] = {"Flipper Menu", "Option ONE", "Option TWO"};
const int menuMAINCount = sizeof(menuMAINItems) / sizeof(menuMAINItems[0]);

const char* menuKMItems[] = {"KeyMouse Menu", "Logout OSX/MAC", "Logout Windows", "Logout Ubuntu", "Program 1"};
const int menuKMCount = sizeof(menuKMItems) / sizeof(menuKMItems[0]);

// Active menu
const char** currentMenu = menuMAINItems;
int currentMenuCount = menuMAINCount;

// MODES
int debug_mode = 0;



/* ############################################################################################################## */
void setup() {

  Serial.begin(9600);
  
  pinMode(ENC_PIN_A, INPUT_PULLUP);
  pinMode(ENC_PIN_B, INPUT_PULLUP);
  pinMode(ENC_BTN, INPUT_PULLUP);
  pinMode(BTN_return, INPUT_PULLUP);

  if (!display.begin(0x3C, true)) {
    for (;;); // hang if display not found
  }

  chip_test();
  self_test();
}

void loop(){
  delay(10000);
}

int chip_test(){
  
  delay(500);
  Serial.println("=== SYSTEM INFO ===");
  
  // Chip info
  esp_chip_info_t chip_info;
  esp_chip_info(&chip_info);
  Serial.printf("Cores: %d\n", chip_info.cores);
  Serial.printf("Revision: %d\n", chip_info.revision);

  // CPU speed
  Serial.printf("CPU Frequency: %d MHz\n", getCpuFrequencyMhz());

  // Flash size
  uint32_t flash_size = 0;
  esp_flash_get_size(NULL, &flash_size);
  Serial.printf("Flash Size: %d MB\n", flash_size / (1024 * 1024));

  // RAM info
  Serial.printf("Heap Size: %d bytes\n", ESP.getHeapSize());
  Serial.printf("Free Heap: %d bytes\n", ESP.getFreeHeap());

  // MAC address
  uint8_t mac[6];
  esp_read_mac(mac, ESP_MAC_WIFI_STA);
  Serial.printf("MAC Address: %02X:%02X:%02X:%02X:%02X:%02X\n",
                mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
                
  Serial.println("=========================");
}
 
int self_test(){
  
  delay(500);
  Serial.print("=== SELF_TEST ===");
  int critfail = 0;
  int fail = 0;

  Serial.print("=1 GPIO_VAL_CHECK"); // Check if theres an input on each GPIO pin
  for (int i = 0; i<= 10; i++){
    int pin = A0+i;
    int pinVal = analogRead(pin);
    if (pinVal != 0){
      Serial.print("Pin ");
      Serial.print(pin);
      Serial.print(" Value: ");
      Serial.println(pinVal);  
    }
    else{
      Serial.println(pin);
      Serial.print(" Not Connected");
    }
  delay(10); 
  }
  Serial.print("=2 OLED_CHECK"); // Checks if the oled is correctly plugged in.
  if (!display.begin(0x3C, true)) { 
    Serial.println("OLED not found (check pinout + I²C address)"); // check if the if 
    critfail++;
    fail++;
  }
  else{
    Serial.println("OLED PASS");
  }
  delay(10);
  Serial.print("=3 ENCODER_CHECK"); // Checks if the encoder is correctly plugged in.
  if (digitalRead(ENC_PIN_A) == LOW && digitalRead(ENC_PIN_B) == LOW) {
    Serial.println("Encoder not found (check pinout)");
    critfail++;
    fail++;
  }
  else{
    Serial.println("Encoder button not checked");
    Serial.println("ENCODER PASS");
  }
  delay(10); 


  Serial.println("=== DONE ===");
  Serial.print("Critical fails: ");
  Serial.println(critfail);
  Serial.print("Fails: ");
  Serial.println(fail);
  Serial.println("=========================");
  return 0;
}
