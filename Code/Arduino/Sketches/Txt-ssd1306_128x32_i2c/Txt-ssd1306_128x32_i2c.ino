/*********************************************************************
This is an example for our Monochrome OLEDs based on SSD1306 drivers

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/category/63_98

This example is for a 128x32 size display using I2C to communicate
3 pins are required to interface (2 I2C and one reset)

Adafruit invests time and resources providing this open source code, 
please support Adafruit and open-source hardware by purchasing 
products from Adafruit!

Written by Limor Fried/Ladyada  for Adafruit Industries.  
BSD license, check license.txt for more information
All text above, and the splash screen must be included in any redistribution
*********************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/dl/BEBAS___16pt7b.h>

//Good fonts - FreeMono12pt7b  FreeMonoBold12pt7b FreeSerif12pt7b


#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

//To use a font in your Arduino sketch, #include the corresponding .h file and pass address of GFXfont struct to setFont(). Pass NULL to revert to 'classic' fixed-space bitmap font.



#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

void setup()   {                
  //Serial.begin(9600);

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  // init done
  
  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.display();
  delay(0);


 }

 void loop() {

    // Clear the buffer.
  display.clearDisplay();
  
  // text display tests
  display.setFont(&BEBAS___16pt7b);
  display.setTextColor(WHITE);
 // display.setTextSize(2);
  display.setCursor(0,28);
  display.print("123456789");
  display.display();
  delay(1000);

    // Clear the buffer.
  display.clearDisplay();

   // text display tests
  display.setFont(&BEBAS___16pt7b);
  display.setCursor(0,28);
  display.print("ABCDEFGHI");
  display.display();
  delay(1000);


}

// void loop() {
  // text display tests
  //display.setTextSize(1);
  //display.setTextColor(WHITE);
  //display.setCursor(0,0);
  //display.println("Hello, world!");
  //display.setTextColor(BLACK, WHITE); // 'inverted' text
 // display.println(3.141592);
 // display.setTextSize(2);
  //display.setTextColor(WHITE);
  //display.print("0x"); display.println(0xDEADBEEF, HEX);
 // display.display();
 // delay(2000);
 // display.clearDisplay();


