// Arduino as Master Code
// by Varad Kulkarni <http://www.microcontrollershub.com>
// Created 08 March 2018

#include <Wire.h>

void setup() 
{
  Wire.begin();                     // Initialize Arduino as Master
}

void loop() 
{
  Wire.beginTransmission(0x40);    // Transmit to device #0x40
  Wire.write('0');                 // Sends one byte as '0'
  Wire.endTransmission();          // End transmition
  delay(2000);

  Wire.beginTransmission(0x40);    // Transmit to device #0x40
  Wire.write('1');                 // Sends one byte as '1'
  Wire.endTransmission();          // End transmition
  delay(2000);
}
