#define DCSBIOS_IRQ_SERIAL
#include "DcsBios.h"

void setup()   {        
  DcsBios::setup();
 }

DcsBios::Switch2Pos cmscJmr("CMSC_JMR", 2);
DcsBios::Switch2Pos cmscMws("CMSC_MWS", 3);
DcsBios::Switch2Pos cmscPri("CMSC_PRI", 4);
DcsBios::Switch2Pos cmscSep("CMSC_SEP", 5);
DcsBios::LED cmscPrio(0x1012, 0x0200, 6);
DcsBios::LED cmscLaunch(0x1012, 0x0100, 7);
DcsBios::LED cmscUnkn(0x1012, 0x0400, 8);

void loop() {
  DcsBios::loop(); 
    delay(50);
   }



