/* use '#define DCSBIOS_DEFAULT_SERIAL' instead if your Arduino board
 *  does not feature an ATMega328 or ATMega2650 controller.
 */
#define DCSBIOS_IRQ_SERIAL
#include "DcsBios.h"

DcsBios::LED nmspHarsLed(0x1110, 0x0200, 13);
DcsBios::Switch2Pos nmspHarsBtn("NMSP_HARS_BTN", 12);
void setup() {
  DcsBios::setup();
}

void loop() {
  DcsBios::loop();
}

