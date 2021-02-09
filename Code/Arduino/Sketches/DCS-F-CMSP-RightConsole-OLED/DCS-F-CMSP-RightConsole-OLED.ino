#define DCSBIOS_IRQ_SERIAL

#include <Adafruit_CharacterOLED.h>
#include "DcsBios.h"

Adafruit_CharacterOLED lcd(OLED_V2, 6, 7, 8, 9, 10, 11, 12);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Tom's A-10 Sim v1.0");
   lcd.setCursor(0, 1);
    lcd.print("AWAITING CONNECTION");
    DcsBios::setup();
}


void onCmsp1Change(char* newValue) {
    lcd.setCursor(0, 0);
    lcd.print(newValue);
}
DcsBios::StringBuffer<19> cmsp1Buffer(0x1000, onCmsp1Change);



void onCmsp2Change(char* newValue) {
    lcd.setCursor(0, 1);
    lcd.print(newValue);
}
DcsBios::StringBuffer<19> cmsp2Buffer(0x1014, onCmsp2Change);


void loop() {
  DcsBios::loop();
}

