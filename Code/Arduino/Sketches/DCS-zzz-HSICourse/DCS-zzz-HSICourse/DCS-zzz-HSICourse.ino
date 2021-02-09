#define DCSBIOS_IRQ_SERIAL

#include "DcsBios.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/dl/digital_counter_717pt7b.h>

//Good fonts - FreeMono12pt7b  FreeMonoBold12pt7b FreeSerif12pt7b

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

DcsBios::RotaryEncoder hsiCrsKnob("HSI_CRS_KNOB", "-1000", "+7000", 7, 8);

void setup()   {                
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  // init done
  
  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.clearDisplay();
  display.display();
  display.setFont(&digital_counter_717pt7b);
  display.setTextColor(WHITE);
 // display.setTextSize(2);
  display.setCursor(52,28);
  display.print("123");
    display.display();
  delay(0);
  DcsBios::setup();


 }

void onHsiCrsKnobChange(unsigned int newValue) {
  display.clearDisplay();
  display.setFont(&digital_counter_717pt7b);
  display.setTextColor(WHITE);
  display.setCursor(52,28);
  display.print(newValue / 182);
  display.display();
}
DcsBios::IntegerBuffer hsiCrsKnobBuffer(0x115a, 0xffff, 0, onHsiCrsKnobChange);



void loop() {
  DcsBios::loop();
}



