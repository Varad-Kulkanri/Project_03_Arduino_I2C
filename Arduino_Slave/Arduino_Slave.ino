// Arduino as Slave Code
// by Varad Kulkarni <http://www.microcontrollershub.com>
// Created 08 March 2018

#include <Wire.h>

void setup() 
{
  Wire.begin(0x40);                 // Initialize Arduino as slave with addres 0x40
  Wire.onReceive(receiveEvent);     // Register event
  Serial.begin(9600);               // Start serial for debug
  pinMode(13,OUTPUT);               // Use LED connected tompin 13 as indicator
  digitalWrite(13,LOW);             // Initialize LED in OFF state
}

void loop() 
{
}

// function that executes whenever data is received from master

void receiveEvent(int howMany) 
{
  while (0 < Wire.available())              // loop through all but the last
  {  
    Serial.println("data received"); 
    char cReceivedData = Wire.read();       // receive byte as an char
    Serial.println(cReceivedData);          // print the character
    if('0' == cReceivedData)                // If '0' is received, turn LED OFF
    {
      digitalWrite(13,LOW);
    }
    else if('1' == cReceivedData)           // If '1' is received, turn LED ON
    {
      digitalWrite(13,HIGH);
    }
  }

}
