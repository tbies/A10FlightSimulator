#define DCSBIOS_IRQ_SERIAL

#include "DcsBios.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/dl/digital_counter_717pt7b.h>
//Use Adafruit libs versions 
//Adafruit_GFX_Library version=1.2.3
//Adafruit SSD1306 version=1.1.2

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
//int cal_valueA;
int cal_valueB;
int cal_valueC;
int cal_valueD;
int sum_HIS_range;

void setup()   {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  DcsBios::setup();
 }


 

//RAnge counter A
//void onHsiRcAChange(unsigned int newValueA) {
//      newValueA = map(newValueA, 0, 65535, 0, 10);
//      cal_valueA =(newValueA * 1000);
// }
//DcsBios::IntegerBuffer hsiRcABuffer(0x105a, 0xffff, 0, onHsiRcAChange);

//Range counter B
void onHsiRcBChange(unsigned int newValueB) {
       newValueB = map(newValueB, 0, 65535, 0, 11);
       cal_valueB =(newValueB);
}
DcsBios::IntegerBuffer hsiRcBBuffer(0x105c, 0xffff, 0, onHsiRcBChange);

//Range counter C
void onHsiRcCChange(unsigned int newValueC) {
       newValueC = map(newValueC, 0, 65535, 0, 11);
       cal_valueC =(newValueC);
}
DcsBios::IntegerBuffer hsiRcCBuffer(0x105e, 0xffff, 0, onHsiRcCChange);

//Range counter D
void onHsiRcDChange (unsigned int newValueD) 
{
  newValueD = map(newValueD, 0, 65535, 0, 11);
  cal_valueD =(newValueD);
}
DcsBios::IntegerBuffer hsiRcDBuffer (0x1060, 0xffff, 0,  onHsiRcDChange);



void loop() {
  DcsBios::loop();
 //sum_HIS_range = cal_valueB + cal_valueC + cal_valueD;
   sum_HIS_range = cal_valueB * 100 + cal_valueC * 10 + cal_valueD;
  writeDisplay();
}

void writeDisplay()
{
display.clearDisplay();
  display.setFont(&digital_counter_717pt7b);
  display.setTextColor(WHITE);
  display.setCursor(20,28);
  display.print(sum_HIS_range);
  display.display();
}
