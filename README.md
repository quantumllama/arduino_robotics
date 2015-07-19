# Arduino Cartesian Robot
Code to drive robots in cardinal directions with Arduiono, XBee Shield, and Adafruit Mobile Shield!

## Overview 
This project requires the following components

For one robot:
- Two Arduino Unos
- Two Arduino SD Wireless Shields ( 802.15.4 )
- One Adafruit Motor Shiled v2
- A potentiometer based motor controller which allows for x-axis output and y-axis output

In order to build more than one robot, the channel on the xBee radio will have to be changed. A link to a project discussing how to do robot specific communication with the xBee module can be found [here](http://www.instructables.com/id/Processing-Controls-RC-Car-with-XBee-modules/step9/Install-CoolTerm-for-MacOS/) 

NOTE: All of the code written here is specific to the hardware of the project. In all likelihood the following will have to be edited:
- Amount of voltage subtracted from input
- Ports for which input is recieved
- Speed of the robot


