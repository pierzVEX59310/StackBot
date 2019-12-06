/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\FRC                                              */
/*    Created:      Sun Nov 10 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
    Brain.Screen.drawRectangle(1,1,150,80,color::red);
    Brain.Screen.printAt(30,50,"Red Auto");
    Brain.Screen.drawRectangle(150,1,150,80,color::blue);
    Brain.Screen.printAt(185,50,"Blue Auto");
    Brain.Screen.drawRectangle(1,80,150,80,color::red);
    Brain.Screen.printAt(30,125,"Climb On");
    Brain.Screen.drawRectangle(150,80,150,80,color::blue);
    Brain.Screen.printAt(185,125,"Climb Off");
    Brain.Screen.drawRectangle(300,1,480,240,color::blue);
    Brain.Screen.printAt(325,25,"Pre-run Stats"); 
    int Autoset = 0;
    int Climbset = 0;
    while(true){
      if (Brain.Screen.xPosition()>1 && Brain.Screen.yPosition()>1 && Brain.Screen.xPosition()<150 && Brain.Screen.yPosition()<80)
        { Autoset = 1; }
      if (Brain.Screen.xPosition()>150 && Brain.Screen.yPosition()>1 && Brain.Screen.xPosition()<300 && Brain.Screen.yPosition()<80)
        { Autoset = 2; }

      Brain.Screen.printAt(325,50,"Auto is:%d\n", Autoset);    
        
      if (Brain.Screen.xPosition()>1 && Brain.Screen.yPosition()>80 && Brain.Screen.xPosition()<150 && Brain.Screen.yPosition()<160)
        { Climbset = 1; }
      if (Brain.Screen.xPosition()>150 && Brain.Screen.yPosition()>80 && Brain.Screen.xPosition()<300 && Brain.Screen.yPosition()<160)
        { Climbset = 0; }    
        
      if (Climbset){
          //Brain.Screen.printAt(325,100,"            ");
          Brain.Screen.printAt(325,100,"Climb is On ");}
        else
          { Brain.Screen.printAt(325,100,"Climb is Off");}
}
  
}
