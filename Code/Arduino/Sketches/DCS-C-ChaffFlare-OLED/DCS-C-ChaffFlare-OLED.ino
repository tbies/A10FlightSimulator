#define DCSBIOS_IRQ_SERIAL

#include "DcsBios.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/dl/enhanced_led_board_710pt7b.h>

//Good fonts - FreeMono12pt7b  FreeMonoBold12pt7b FreeSerif12pt7b

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

void setup()   {                
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  // init done
  
  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.clearDisplay();
  display.display();
  display.setFont(&enhanced_led_board_710pt7b);
  display.setTextColor(WHITE);
 // display.setTextSize(2);
  display.setCursor(0,28);
  display.print("INIT 2");
    display.display();
  delay(0);
  DcsBios::setup();


 }

void onCmscTxtChaffFlareChange(char* newValue) {
  display.clearDisplay();
  display.setFont(&enhanced_led_board_710pt7b);
  display.setTextColor(WHITE);
  display.setCursor(0,28);
  display.print(newValue);
  display.display();
}
DcsBios::StringBuffer<8> cmscTxtChaffFlareBuffer(0x108e, onCmscTxtChaffFlareChange);






void loop() {
  DcsBios::loop();
}



