/* use '#define DCSBIOS_DEFAULT_SERIAL' instead if your Arduino board
 *  does not feature an ATMega328 or ATMega2650 controller.
 */
#define DCSBIOS_IRQ_SERIAL
#include "DcsBios.h"

DcsBios::LED canopyUnlocked(0x10da, 0x0004, 2);
DcsBios::LED gunReady(0x1026, 0x8000, 3);
DcsBios::LED markerBeacon(0x10da, 0x0002, 4);
DcsBios::LED nosewheelSteering(0x10da, 0x0001, 5);

void setup() {
  DcsBios::setup();
  digitalWrite(2, HIGH);   
  delay(1000);                     
  digitalWrite(2, LOW);    
  delay(1000);
    digitalWrite(3, HIGH);   
  delay(1000);                     
  digitalWrite(3, LOW);    
  delay(1000); 
    digitalWrite(4, HIGH);   
  delay(1000);                     
  digitalWrite(4, LOW);    
  delay(1000); 
    digitalWrite(5, HIGH);   
  delay(1000);                     
  digitalWrite(5, LOW);    
  delay(1000); 
  digitalWrite(2, HIGH);   
  digitalWrite(3, HIGH);   
  digitalWrite(4, HIGH);   
  digitalWrite(5, HIGH);
  delay(3000);          
  digitalWrite(2, LOW);   
  digitalWrite(3, LOW);   
  digitalWrite(4, LOW);   
  digitalWrite(5, LOW);                 
}

void loop() {
  DcsBios::loop();
}

