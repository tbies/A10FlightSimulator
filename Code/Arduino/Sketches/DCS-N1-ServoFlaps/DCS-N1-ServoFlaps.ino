#define DCSBIOS_IRQ_SERIAL
#include <Servo.h>
#include "DcsBios.h"

DcsBios::ServoOutput flapPos(0x10a0, 9, 1060, 150);
void setup() {
DcsBios::setup();
}

void loop() {
DcsBios::loop();
}
