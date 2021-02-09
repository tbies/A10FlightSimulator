/*
  Tell DCS-BIOS to use a serial connection and use interrupt-driven
  communication. The main program will be interrupted to prioritize
  processing incoming data.
  
  This should work on any Arduino that has an ATMega328 controller
  (Uno, Pro Mini, many others).
 */
#define DCSBIOS_IRQ_SERIAL
#include "DcsBios.h"

//// WARNING
//// WARNING - using custom Switches.h so switch init reflects current switch positons at init
//// WARNING 


// GUN/PAC GUNARM - SAFE - ARM
DcsBios::Switch3Pos ahcpGunpac("AHCP_GUNPAC", 2, 3);
// GND = Gray, 2 = White, 3 = Blue

// Master Arm TRAIN - SAFE - ARM
DcsBios::Switch3Pos ahcpMasterArm("AHCP_MASTER_ARM", 4, 5);
// GND = Green + Purple, 4 = White, 5 = Orange

// Laser Arm TRAIN - SAFE - ARM
DcsBios::Switch3Pos ahcpLaserArm("AHCP_LASER_ARM", 6, 7);
// GND = Purple + White, 6 = Blue, 7 = Orange

// TGP OFF - ON
DcsBios::Switch2Pos ahcpTgp("AHCP_TGP", 8);
// GND = Brown, 8 = Yellow

// Altimeter Source RADAR - DELTA - BARO
DcsBios::Switch3Pos ahcpAltSce("AHCP_ALT_SCE", 9, 10);
// GND = Gray, 9 = Blue, 10 = Purple

// Hud Mode NIGHT - DAY
DcsBios::Switch2Pos ahcpHudDaynight("AHCP_HUD_DAYNIGHT", 11);
// GND = Green, 11 = Orange

// Hud Mode STBY - NORM
DcsBios::Switch2Pos ahcpHudMode("AHCP_HUD_MODE", 12);
// GND = White, 12 = Yellow

// CICU OFF - ON
DcsBios::Switch2Pos ahcpCicu("AHCP_CICU", 14);
// GND = White, 14 = Purple 

// JTRS OFF - ON
DcsBios::Switch2Pos ahcpJtrs("AHCP_JTRS", 15);
// GND = Orange, 15 = White

// IFFCC OFF - TEST - ON
DcsBios::Switch3Pos ahcpIffcc("AHCP_IFFCC", 16, 17);
// GND = Brown + Green,  16 = Yellow, 17 = Blue

unsigned int g_iCounter = 0;
void PollAllControls()
{
  ahcpGunpac.pollInputCurrent();
  ahcpMasterArm.pollInputCurrent();
  ahcpLaserArm.pollInputCurrent();
  ahcpTgp.pollInputCurrent();
  ahcpAltSce.pollInputCurrent();
  ahcpHudDaynight.pollInputCurrent();
  ahcpHudMode.pollInputCurrent();
  ahcpCicu.pollInputCurrent();
  ahcpJtrs.pollInputCurrent();
  ahcpIffcc.pollInputCurrent();
}

void setup() {
  DcsBios::setup();


}

void loop() {
  DcsBios::loop();
  if (++g_iCounter > 60000)
  {   g_iCounter = 0;
      PollAllControls();
  } 
 }

