#define DCSBIOS_IRQ_SERIAL

#include <AccelStepper.h>
#include "DcsBios.h"

struct StepperConfig {
  unsigned int maxSteps;
  unsigned int acceleration;
  unsigned int maxSpeed;
};


class Vid29Stepper : public DcsBios::Int16Buffer {
  private:
    AccelStepper& stepper;
    StepperConfig& stepperConfig;
    unsigned int (*map_function)(unsigned int);
    unsigned char initState;
  public:
    Vid29Stepper(unsigned int address, AccelStepper& stepper, StepperConfig& stepperConfig, unsigned int (*map_function)(unsigned int))
    : Int16Buffer(address), stepper(stepper), stepperConfig(stepperConfig), map_function(map_function), initState(0) {
    }

    virtual void loop() {
      if (initState == 0) { // not initialized yet
        stepper.setMaxSpeed(stepperConfig.maxSpeed);
        stepper.setAcceleration(stepperConfig.acceleration);
        stepper.moveTo(-((long)stepperConfig.maxSteps));
        initState = 1;
      }
      if (initState == 1) { // zeroing
        stepper.run();
        if (stepper.currentPosition() <= -((long)stepperConfig.maxSteps)) {
          stepper.setCurrentPosition(0);
          initState = 2;
          stepper.moveTo(stepperConfig.maxSteps/2);
        }
      }
      if (initState == 2) { // running normally
        if (hasUpdatedData()) {
          unsigned int newPosition = map_function(getData());
          newPosition = constrain(newPosition, 0, stepperConfig.maxSteps);
          stepper.moveTo(newPosition);
        }
        stepper.run();
      }
    }
};

/* modify below this line */

/* define stepper parameters
   multiple Vid29Stepper instances can share the same StepperConfig object */
struct StepperConfig stepperConfig = {
  130,  // maxSteps
  100, // maxSpeed
  100 // acceleration
  };


// define AccelStepper instance
AccelStepper stepper;
// define Vid29Stepper class that uses the AccelStepper instance defined in the line above
//           +-- arbitrary name
//           |   +-- Address of stepper data (from control reference)
//           |   |       +-- name of AccelStepper instance
//           v   v       v        v-- StepperConfig struct instance
Vid29Stepper fla(0x10a0, stepper, stepperConfig, [](unsigned int newValue) -> unsigned int {
  /* this function needs to map newValue to the correct number of steps */
  return map(newValue, 0, 65535, 0, stepperConfig.maxSteps);
}); 


DcsBios::LED gearLSafe(0x1026, 0x1000, 6);
DcsBios::LED gearNSafe(0x1026, 0x0800, 7);
DcsBios::LED gearRSafe(0x1026, 0x2000, 8);
DcsBios::LED handleGearWarning(0x1026, 0x4000, 9);
DcsBios::Switch2Pos gearLever("GEAR_LEVER", 10);
DcsBios::Switch2Pos engineTemsData("ENGINE_TEMS_DATA", 11);
DcsBios::Switch2Pos antiSkidSwitch("ANTI_SKID_SWITCH", 12);
DcsBios::Switch2Pos downlockOverride("DOWNLOCK_OVERRIDE", 14);
DcsBios::Switch3Pos landingLights("LANDING_LIGHTS", 15, 16);


unsigned int g_iCounter = 0;
void PollAllControls()
{
  gearLever.pollInputCurrent();
  landingLights.pollInputCurrent();
}

void setup() 
{
  DcsBios::setup();
}
void loop()
{
  DcsBios::loop();
   if (++g_iCounter > 60000)
  {   g_iCounter = 0;
      PollAllControls();
  }

 }
