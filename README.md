# Arduino Cartesian Robot
Code to drive robots in cardinal directions with Arduiono, XBee shields, and a motor shield!

## Overview 
This project requires the following components (per robot-controller pair):
- Two Arduino Unos
- Two Arduino SD Wireless Shields ( 802.15.4 )
- One Pololu Dual MAX14870 Motor Driver Shield (Find relevant library [here](https://github.com/pololu/dual-max14870-motor-shield))
- A potentiometer based joystick providing separate x- and y-axis output

In order to build more than one robot, the channel on the XBee radio will have to be changed. A project discussing how to do robot specific communication with the xBee module can be found [here](http://www.instructables.com/id/Processing-Controls-RC-Car-with-XBee-modules/step9/Install-CoolTerm-for-MacOS/) or in the pdf above.


## Further work
Code is not generalized. If expansion to other hardware or more complex control schemes is desired, significant work may be needed. The following are several points to keep in mind.
- Amount of voltage subtracted from input
- Ports for which input is recieved
- Speed of the robot

If there are issues with controller burn out, consider a higher power motor shield such as the Dual TB9051FTG Motor Driver Shield. Small code reworks may be needed for library differences.
