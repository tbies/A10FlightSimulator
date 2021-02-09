#define numberOfLEDs 18
long nextFlash[18];
int ledPin[] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}; // LED pins to use.
int ledState[18];

void setup(){
for(int i = 0; i<numberOfLEDs; i++){
  pinMode(ledPin[i],OUTPUT);
  ledState[i] = LOW;
  digitalWrite(ledPin[i], LOW); // all LEDs off
    nextFlash[i] = millis() +random(100, 1000);
}
}

void loop(){
for(int i = 0; i<numberOfLEDs; i++){
if(millis() > nextFlash[i]){
 if(ledState[i] == LOW) ledState[i] = HIGH; else ledState[i] = LOW;
 digitalWrite(ledPin[i],ledState[i]);
 nextFlash[i] = millis()+random(100, 1000) ; // next toggle random time
} }
}
