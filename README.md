# Tom's A10 Flight Simulator Cockpit project


| Author | [Tom Bies](https://github.com/tbies) |
|:---|:---|
| Target platforms   | <ul><li>Windows 10 x64</li><li>Arduino Nano, Uno and Mega 2560 platforms</li></ul> |
| Core Hardware required | <ul><li>A very high-end gaming PC running Windows 10 x64 with at least a Geforce GTX 2080TI graphics card</li><li>Several Arduino Nano, Uno and Mega 2560 boards</li><li>Dupont wires and breadboards</li><li>MAX RS487 Transceivers</li></ul> |
| Software required | <ul><li>[DCS A-10 Flight Simulator platform](https://www.digitalcombatsimulator.com/en/products/planes/tank_killer/)</li><li>[Arduino IDE](https://www.arduino.cc/en/software)</li><li>[Vectric Aspire](https://www.vectric.com/products/aspire)</li></ul>|
| Programming Languages | <ul><li>C</li><li>LUA</li><li>G-Code</li></ul> |
| Prerequisites | <ul><li>Basic proficiency in using Ardunio Micro Controllers to interface with LEDs, Switches, Potentiometers, H-Bridges, Stepper and Servo motors, Sensors, Transceivers, OLED displays, rotary encoders</li><li>CNC and woodworking skills if you wish to build a full cockpit.</li><li>Wife permission</li></ul> |
| Published on github | February 2021 |

<img src = "https://github.com/tbies/A10FlightSimulator/blob/main/Cover.jpg" >
Tom's Home Flight Simulator Cockpit project based on the A-10 Thunderbolt II Warthog aircraft flown by the United States Air Force.  

This repo contains the following:
* Patched LUA Code for the use in the A-10 Thunderbolt II Warthog aircraft inside the DCS Flight Simulator platform. 
* C Code for the Arduino Platform of micro controllers which drives all the panels including Switches / LEDs / POTs / OLED displays / Stepper motors / Rotary encoders /  
* CNC Design Files for cockpit parts in Vectric Aspire CAD format

/\/\/\/\/\ WARNING /\/\/\/\/\/\/\/\/\/\ WARNING /\/\/\/\/\/\/\/\/\/\ WARNING /\/\/\/\/\/\/\/\/\/\ WARNING /\/\/\/\/\/\/\/\/\/\ WARNING /\/\/\/\/\

The supplied GCODE and Toolpaths contained in the CNC design files are for *MY* CNC mills and tooling.  Using these directly on your CNC machine will most certainly cause it to bottom out / break tools or go out of limits.  You could even injure yourself.  You WILL need to re-compute all Toolpaths and GCODE for use on your machine before any cutting, engraving or milling begins.  

/\/\/\/\/\ WARNING /\/\/\/\/\/\/\/\/\/\ WARNING /\/\/\/\/\/\/\/\/\/\ WARNING /\/\/\/\/\/\/\/\/\/\ WARNING /\/\/\/\/\/\/\/\/\/\ WARNING /\/\/\/\/\
[![](http://img.youtube.com/vi/PuVNLaH2i5Q/0.jpg)](http://www.youtube.com/watch?v=PuVNLaH2i5Q "DCS A-10C II Tank Killer trailer")<br>
(Awesome YouTube video trailer of the DCS A10 Flight Simulator Platform)
