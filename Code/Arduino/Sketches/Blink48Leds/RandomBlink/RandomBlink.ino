#define numberOfLEDs 48
long nextFlash[18];
int ledPin[] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49}; // LED pins to use.
int ledState[48];

void setup(){

  
for(int i = 0; i<numberOfLEDs; i++){
  pinMode(ledPin[i],OUTPUT);
  ledState[i] = LOW;
  digitalWrite(ledPin[i], LOW); // all LEDs off
    nextFlash[i] = millis() +random(3000, 5000);
}
}

void loop(){
for(int i = 0; i<numberOfLEDs; i++){
if(millis() > nextFlash[i]){
 if(ledState[i] == LOW) ledState[i] = HIGH; else ledState[i] = LOW;
 digitalWrite(ledPin[i],ledState[i]);
 nextFlash[i] = millis()+random(3000, 5000) ; // next toggle random time
} }
}
