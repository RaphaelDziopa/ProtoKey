/*
  A simple code that is implemented in the ver1.0 of ProtoKey
  that can check that composents are correctly connected to the right pins.
  It returns through serial the number of critical fails regarding the screen, encoder and return button.
*/
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

// ----- OLED config -----
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 128
#define OLED_RESET -1
Adafruit_SH1107 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// ----- Rotary encoder pins -----
#define ENC_BTN   13
#define ENC_PIN_A 14
#define ENC_PIN_B 15

// ----- Return button pin -----
#define BTN_return   16   // GP16

// ----- Encoder -----
int selectedIndex = 0;
int lastA = HIGH;
int lastB = HIGH;

// ----- Button_debounce -----
unsigned long lastButtonPress = 0;
const unsigned long debounceMs = 200;

// ----- Menus -----
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

// ----- MODES -----
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
}

void loop(){
  self_test();
}
 
int self_test(){
  Serial.print("###_SELF_TEST_###");
  int critfail = 0;
  int fail = 0;

  Serial.print("#1#_GPIO_VAL_CHECK"); // Check if theres an input on each GPIO pin
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
  Serial.print("#2#_OLED_CHECK"); // Checks if the oled is correctly plugged in.
  if (!display.begin(0x3C, true)) { 
    Serial.println("OLED not found (check pinout + I²C address)"); // check if the if 
    critfail++;
    fail++;
  }
  else{
    Serial.println("OLED PASS");
  }
  delay(10);
  Serial.print("#3#_ENCODER_CHECK"); // Checks if the encoder is correctly plugged in.
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


  Serial.println("###_DONE_###");
  Serial.print("Critical fails: ");
  Serial.println(critfail);
  Serial.print("Fails: ");
  Serial.println(fail);
  return 0;
}
