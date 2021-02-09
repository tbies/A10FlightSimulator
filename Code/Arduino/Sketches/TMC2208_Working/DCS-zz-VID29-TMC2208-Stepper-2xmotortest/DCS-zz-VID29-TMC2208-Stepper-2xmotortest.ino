#define DCSBIOS_IRQ_SERIAL

#include <AccelStepper.h>
#include <MultiStepper.h>
#include "DcsBios.h"

#define MS1 2
#define MS2 3
#define EN 4

// TMC2208 Working settings with VID29
// MS1   MS2 
// HIGH  LOW
// 1275,  // maxSteps
// 400, // maxSpeed 
// 400 // acceleration
//
// MS1   MS2 
// HIGH  HIGH 
// 10150,  // maxSteps
// 6000, // maxSpeed 
// 4000 // acceleration


// Multistepper vars
//  stepper1 stepper2
//  stepperConfigA stepperConfigB



struct StepperConfig {
  unsigned int maxSteps;
  unsigned int acceleration;
  unsigned int maxSpeed;
};

///// stepper1
class Vid29StepperA : public DcsBios::Int16Buffer {
  private:
    AccelStepper& stepper1;
    StepperConfig& stepperConfig;
    unsigned int (*map_function)(unsigned int);
    unsigned char initState;
  public:
    Vid29StepperA(unsigned int address, AccelStepper& stepper1, StepperConfig& stepperConfig, unsigned int (*map_function)(unsigned int))
    : Int16Buffer(address), stepper1(stepper1), stepperConfig(stepperConfig), map_function(map_function), initState(0) {
    }

    virtual void loop() {
      if (initState == 0) { // not initialized yet
        stepper1.setMaxSpeed(stepperConfig.maxSpeed);
        stepper1.setAcceleration(stepperConfig.acceleration);
        stepper1.moveTo(-((long)stepperConfig.maxSteps));
        initState = 1;
      }
      if (initState == 1) { // zeroing
        stepper1.run();
        if (stepper1.currentPosition() <= -((long)stepperConfig.maxSteps)) {
          stepper1.setCurrentPosition(0);
          initState = 2;
          stepper1.moveTo(stepperConfig.maxSteps/2);
        }
      }
      if (initState == 2) { // running normally
        if (hasUpdatedData()) {
          unsigned int newPosition = map_function(getData());
          newPosition = constrain(newPosition, 0, stepperConfig.maxSteps);
          stepper1.moveTo(newPosition);
        }
        stepper1.run();
      }
    }
};


//stepper2
class Vid29StepperB : public DcsBios::Int16Buffer {
  private:
    AccelStepper& stepper2;
    StepperConfig& stepperConfig;
    unsigned int (*map_function)(unsigned int);
    unsigned char initState;
  public:
    Vid29StepperB(unsigned int address, AccelStepper& stepper2, StepperConfig& stepperConfig, unsigned int (*map_function)(unsigned int))
    : Int16Buffer(address), stepper2(stepper2), stepperConfig(stepperConfig), map_function(map_function), initState(0) {
    }

    virtual void loop() {
      if (initState == 0) { // not initialized yet
        stepper2.setMaxSpeed(stepperConfig.maxSpeed);
        stepper2.setAcceleration(stepperConfig.acceleration);
        stepper2.moveTo(-((long)stepperConfig.maxSteps));
        initState = 1;
      }
      if (initState == 1) { // zeroing
        stepper2.run();
        if (stepper2.currentPosition() <= -((long)stepperConfig.maxSteps)) {
          stepper2.setCurrentPosition(0);
          initState = 2;
          stepper2.moveTo(stepperConfig.maxSteps/2);
        }
      }
      if (initState == 2) { // running normally
        if (hasUpdatedData()) {
          unsigned int newPosition = map_function(getData());
          newPosition = constrain(newPosition, 0, stepperConfig.maxSteps);
          stepper2.moveTo(newPosition);
        }
        stepper2.run();
      }
    }
};

//stepper3
class Vid29StepperC : public DcsBios::Int16Buffer {
  private:
    AccelStepper& stepper3;
    StepperConfig& stepperConfig;
    unsigned int (*map_function)(unsigned int);
    unsigned char initState;
  public:
    Vid29StepperC(unsigned int address, AccelStepper& stepper3, StepperConfig& stepperConfig, unsigned int (*map_function)(unsigned int))
    : Int16Buffer(address), stepper3(stepper3), stepperConfig(stepperConfig), map_function(map_function), initState(0) {
    }

    virtual void loop() {
      if (initState == 0) { // not initialized yet
        stepper3.setMaxSpeed(stepperConfig.maxSpeed);
        stepper3.setAcceleration(stepperConfig.acceleration);
        stepper3.moveTo(-((long)stepperConfig.maxSteps));
        initState = 1;
      }
      if (initState == 1) { // zeroing
        stepper3.run();
        if (stepper3.currentPosition() <= -((long)stepperConfig.maxSteps)) {
          stepper3.setCurrentPosition(0);
          initState = 2;
          stepper3.moveTo(stepperConfig.maxSteps/2);
        }
      }
      if (initState == 2) { // running normally
        if (hasUpdatedData()) {
          unsigned int newPosition = map_function(getData());
          newPosition = constrain(newPosition, 0, stepperConfig.maxSteps);
          stepper3.moveTo(newPosition);
        }
        stepper3.run();
      }
    }
};




/* modify below this line */

/* define stepper parameters
   multiple Vid29Stepper instances can share the same StepperConfig object */

// vvi
struct StepperConfig stepperConfigA = {
  2550,  // maxSteps | 1275 HIGH LOW | 2550 LOW HIGH | 5100 LOW LOW--Missing Steps | HIGH HIGH 10200
  3800, // maxSpeed |  // 3800 
  3800 // acceleration | // 3800
  };

//aoa
struct StepperConfig stepperConfigB = {
  2180,  // maxSteps | 1275 HIGH LOW | 2550 LOW HIGH | 5100 LOW LOW--Missing Steps | HIGH HIGH 10200
  3800, // maxSpeed |  // 3800 
  3800 // acceleration | // 3800
  };
  
  //asi
struct StepperConfig stepperConfigC = {
  2780,  // maxSteps | 1275 HIGH LOW | 2550 LOW HIGH | 5100 LOW LOW--Missing Steps | HIGH HIGH 10200
  3800, // maxSpeed |  // 3800 
  3800 // acceleration | // 3800
  };



// define AccelStepper instance
AccelStepper stepper1(AccelStepper::DRIVER, 6, 5);
// define Vid29Stepper class that uses the AccelStepper instance defined in the line above
//           +-- arbitrary name
//           |   +-- Address of stepper data (from control reference)
//           |   |       +-- name of AccelStepper instance
//           v   v       v        v-- StepperConfig struct instance
Vid29StepperA vvi(0x106e, stepper1, stepperConfigA, [](unsigned int newValue) -> unsigned int {
  /* this function needs to map newValue to the correct number of steps */
  return map(newValue, 0, 65535, 0, stepperConfigA.maxSteps);
}); 

AccelStepper stepper2(AccelStepper::DRIVER, 8, 7);
// define Vid29Stepper class that uses the AccelStepper instance defined in the line above
//           +-- arbitrary name
//           |   +-- Address of stepper data (from control reference)
//           |   |       +-- name of AccelStepper instance
//           v   v       v        v-- StepperConfig struct instance
Vid29StepperB aoa(0x1078, stepper2, stepperConfigB, [](unsigned int newValue) -> unsigned int {
  /* this function needs to map newValue to the correct number of steps */
  return map(newValue, 0, 65535, 0, stepperConfigB.maxSteps);
}); 

AccelStepper stepper3(AccelStepper::DRIVER, 10, 9);
// define Vid29Stepper class that uses the AccelStepper instance defined in the line above
//           +-- arbitrary name
//           |   +-- Address of stepper data (from control reference)
//           |   |       +-- name of AccelStepper instance
//           v   v       v        v-- StepperConfig struct instance
Vid29StepperC asi(0x107a, stepper3, stepperConfigC, [](unsigned int newValue) -> unsigned int {
  /* this function needs to map newValue to the correct number of steps */
  return map(newValue, 0, 65535, 0, stepperConfigC.maxSteps);
}); 

void setup() {
  DcsBios::setup();
    pinMode(MS1, OUTPUT);
    pinMode(MS2, OUTPUT);
    pinMode(EN, OUTPUT);
    digitalWrite(MS1, LOW);
    digitalWrite(MS2, HIGH);
    digitalWrite(EN, LOW);
}

void loop() {
  DcsBios::loop();
  }
