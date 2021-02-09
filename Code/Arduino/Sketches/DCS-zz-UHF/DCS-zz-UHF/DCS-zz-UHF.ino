#define DCSBIOS_IRQ_SERIAL

#include <Adafruit_CharacterOLED.h>
#include "DcsBios.h"

Adafruit_CharacterOLED lcd(OLED_V2, 6, 7, 8, 9, 10, 11, 12);
//Adafruit_CharacterOLED lcd(OLED_V2, 22, 23, 24, 25, 26, 27, 28);

void setup() {
  lcd.begin(16, 1);
  lcd.print("     123.456");
    DcsBios::setup();
}

//1st
void onUhfFrequencyChange(char* newValue) {
    lcd.setCursor(5, 5);
    lcd.print(newValue);
}
DcsBios::StringBuffer<7> uhfFrequencyBuffer(0x1180, onUhfFrequencyChange);


void loop() {
  DcsBios::loop();
}

