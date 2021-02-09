#define DCSBIOS_IRQ_SERIAL

#include <Adafruit_CharacterOLED.h>
#include "DcsBios.h"

Adafruit_CharacterOLED lcd(OLED_V2, 6, 7, 8, 9, 10, 11, 12);
//Adafruit_CharacterOLED lcd(OLED_V2, 22, 23, 24, 25, 26, 27, 28);

void setup() {
  lcd.begin(16, 1);
  lcd.print("  12  3  4  56");
    DcsBios::setup();
}

//1st
void onVhffmFreq1Change(char* newValue) {
    lcd.setCursor(2, 2);
    lcd.print(newValue);
}
DcsBios::StringBuffer<2> vhffmFreq1StrBuffer(0x119a, onVhffmFreq1Change);



//2nd
void onVhffmFreq2Change(unsigned int newValue) {
    lcd.setCursor(6, 6);
    lcd.print(newValue);
}
DcsBios::IntegerBuffer vhffmFreq2Buffer(0x119c, 0x000f, 0, onVhffmFreq2Change);


//3rd
void onVhffmFreq3Change(unsigned int newValue) {
    lcd.setCursor(9, 9);
    lcd.print(newValue);
}
DcsBios::IntegerBuffer vhffmFreq3Buffer(0x119c, 0x00f0, 4, onVhffmFreq3Change);

//4th
void onVhffmFreq4Change(char* newValue) {
    lcd.setCursor(12, 12);
    lcd.print(newValue);
}
DcsBios::StringBuffer<2> vhffmFreq4StrBuffer(0x119e, onVhffmFreq4Change);




void loop() {
  DcsBios::loop();
}

