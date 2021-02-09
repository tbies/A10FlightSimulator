/*
  Tell DCS-BIOS to use a serial connection and use interrupt-driven
  communication. The main program will be interrupted to prioritize
  processing incoming data.
  
  This should work on any Arduino that has an ATMega328 controller
  (Uno, Pro Mini, many others).
 */
#define DCSBIOS_IRQ_SERIAL

#include "DcsBios.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void onUhfFrequencyChange(char* newValue) {
    lcd.setCursor(0, 0);
    lcd.print(newValue);
    
}
DcsBios::StringBuffer<7> uhfFrequencyBuffer(0x1180, onUhfFrequencyChange);

void onClockHhChange(char* newValue) {
    lcd.setCursor(0, 1);
    lcd.print(newValue);
}
DcsBios::StringBuffer<2> clockHhBuffer(0x10fe, onClockHhChange);

void onClockMmChange(char* newValue) {
    lcd.setCursor(3, 1);
    lcd.print(newValue);
}
DcsBios::StringBuffer<2> clockMmBuffer(0x1100, onClockMmChange);

void onClockSsChange(char* newValue) {
    lcd.setCursor(6, 1);
    lcd.print(newValue);
}
DcsBios::StringBuffer<2> clockSsBuffer(0x1102, onClockSsChange);

void onClockEtcChange(char* newValue) {
    lcd.setCursor(9, 1);
    lcd.print(newValue);
}
DcsBios::StringBuffer<3> clockEtcBuffer(0x1104, onClockEtcChange);

/* paste code snippets from the reference documentation here */

void setup() {
  DcsBios::setup();
    lcd.begin(16, 2);
    lcd.clear();
    
}

void loop() {
  DcsBios::loop();
}

