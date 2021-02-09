#include <Keypad.h>

const byte ROWS = 8; //four rows
const byte COLS = 10; //three columns
char keys[ROWS][COLS] = {
  {'!','"','#','c','%','m','F','L','R','X'},
  {'&','E','K','Q','Q','W','Z'},
  {'|','D','J','P','P','V','Y','m'},
  {')','C','I','O','O','U','@','s','p','d'},
  {'{','A','B','G','G','H','M','N','S','T'},
  {':','3','6','9','9','>','`','/','*','f'},
  {';','2','5','8','8','0','-','}','c','z'},
  {'+',']','^','a','b','1','1','4','7','.'},

};
byte rowPins[ROWS] = {31, 33, 35, 37, 39, 41, 43, 45}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {30, 32, 34, 36, 38, 40, 42, 44, 46, 48}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);
}

void loop(){
  char key = keypad.getKey();

  if (key != NO_KEY){
    Serial.println(key);
  }
}
