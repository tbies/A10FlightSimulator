/*
* Opto Slotted Switch Test Sketch
*
* Pins
* Vcc to A0
* DO to A1
* AO to Arduino pin A2
* Gnd to A3
*/

int analog = 16; // Arduino A2
int digital = 2; // Arduino A1
int gnd = 3;  // supplies 0 volts
int power = 4;  // supplies 5 volts

void setup() {
 Serial.begin(9600); // start Serial Monitor
 pinMode(13, OUTPUT);
 digitalWrite(13,LOW);  // turn OFF the LED on Arduino pin 13
 pinMode(digital, INPUT);  // this pin reads the digital output, either HIGH or LOW
 pinMode(power, OUTPUT);
 digitalWrite(power,HIGH);// this pin will supply 5 volts
 pinMode(gnd, OUTPUT);
 digitalWrite(gnd,LOW); // this pin will supply the GND to the board
}

void loop() {
 // print the analog output in milli volts
 //Serial.print("Analog level = ");
 //Serial.print(analogRead(analog));
 //Serial.println(" mv");  // milli volts
 // print the digital Output LOW = alarm tripped
 Serial.print("Digital level =");
 if (digitalRead(digital) == HIGH){
   Serial.println(" HIGH");
 }
 else{
   Serial.println(" LOW");
 }
 delay (0);  // this just makes it easier to read the serial output
}
