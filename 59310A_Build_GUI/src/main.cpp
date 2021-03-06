// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// RearRight            motor         1               
// FrontRight           motor         3               
// FrontLeft            motor         9               
// RearLeft             motor         10              
// Dump                 motor         19              
// RightIntake          motor         11              
// LeftIntake           motor         12              
// Winch                motor         8               
// Dump2                motor         20              
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// RearRight            motor         1               
// FrontRight           motor         3               
// FrontLeft            motor         9               
// RearLeft             motor         10              
// Dump                 motor         19              
// RightIntake          motor         11              
// LeftIntake           motor         12              
// Winch                motor         8               
// LeftDump             motor         20              
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// RearRight            motor         1               
// FrontRight           motor         3               
// FrontLeft            motor         9               
// RearLeft             motor         10              
// RightDump            motor         19              
// RightIntake          motor         11              
// LeftIntake           motor         12              
// Winch                motor         8               
// LeftDump             motor         20              
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// RearRight            motor         1               
// FrontRight           motor         3               
// FrontLeft            motor         9               
// RearLeft             motor         10              
// RightDump            motor         19              
// RightIntake          motor         11              
// LeftIntake           motor         12              
// Winch                motor         8               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// RearRight            motor         1               
// FrontRight           motor         3               
// FrontLeft            motor         9               
// RearLeft             motor         10              
// LeftDump             motor         20              
// RightDump            motor         19              
// RightIntake          motor         11              
// LeftIntake           motor         12              
// Winch                motor         8               
// ---- END VEXCODE CONFIGURED DEVICES ----
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Simon Kroll (Team 59310A)                                 */
/*    Coauthors:    Michael Faust                                             */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Code for tankDrive stackbot                   */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// RearRight            motor         1               
// FrontRight           motor         2               
// FrontLeft            motor         9               
// RearLeft             motor         10              
// LeftDump             motor         20              
// RightDump            motor         19              
// RightIntake          motor         11              
// LeftIntake           motor         12              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                               Functions                                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit(); //Currently does nothing
  if (Competition.isFieldControl()||Competition.isCompetitionSwitch()){
    Brain.Screen.drawRectangle(1,1,150,80,color::red);
    Brain.Screen.printAt(30,50,"Red Auto");
    Brain.Screen.drawRectangle(150,1,150,80,color::blue);
    Brain.Screen.printAt(185,50,"Blue Auto");
    Brain.Screen.drawRectangle(1,80,150,80,color::red);
    Brain.Screen.printAt(30,125,"Undeclared");
    Brain.Screen.drawRectangle(150,80,150,80,color::blue);
    Brain.Screen.printAt(185,125,"Undeclared");
    Brain.Screen.drawRectangle(300,1,480,240,color::blue);
    Brain.Screen.printAt(325,25,"Pre-run Stats"); 
    int Autoset = 0;
    int Climbset = 0;
    while(!Competition.isAutonomous() && !Competition.isDriverControl()){
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
          Brain.Screen.printAt(325,100,"Undeclared ");}
        else
          { Brain.Screen.printAt(325,100,"Undeclared");}
    }
  }  
}

void tankDrive(int leftSpeed, int rightSpeed, int duration = 0, motor FL = FrontLeft, 
motor FR= FrontRight, motor RL = RearLeft, motor RR = RearRight ){
  FL.setVelocity(leftSpeed,percent);
  FR.setVelocity(rightSpeed,percent);
  RL.setVelocity(leftSpeed,percent);
  RR.setVelocity(rightSpeed,percent);
  FL.spin(forward);
  FR.spin(forward);
  RL.spin(forward);
  RR.spin(forward);
  if(duration <= 0){
    return;
  }
  else{
    wait(duration, sec);
    FL.stop();
    FR.stop();
    RL.stop();
    RR.stop();
    return;
  }
}

void intake(int speed = 0, motor leftIn = LeftIntake, motor rightIn = RightIntake){
  leftIn.setVelocity(speed,percent);
  rightIn.setVelocity(speed,percent);
  leftIn.spin(forward);
  rightIn.spin(forward);
}

void dump(int speed = 0, motor leftDp = Dump2, motor rightDp = Dump){
  leftDp.setVelocity(speed,percent);
  rightDp.setVelocity(speed,percent);
  leftDp.spin(forward);
  rightDp.spin(forward);
}



/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Function                          */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  vex::task::sleep(500);

RightIntake.setVelocity(100, pct);
LeftIntake.setVelocity(100, pct);
FrontLeft.setVelocity(100, pct);
RearLeft.setVelocity(100, pct);
FrontRight.setVelocity(100, pct);
RearRight.setVelocity(100, pct);


  vex::task::sleep(500);

Dump.rotateFor(2, turns);

vex::task::sleep(1000);

RightIntake.spinFor(-2, turns);
LeftIntake.spinFor(-2, turns);

vex::task::sleep(1000);

Dump.spinFor(-2, turns);
{FrontLeft.spinFor(-2, turns);
RearLeft.spinFor(-2, turns);
FrontRight.spinFor(-2, turns);
RearRight.spinFor(-2, turns);}

vex::task::sleep(1000);

FrontLeft.spinFor(4, turns);
RearLeft.spinFor(4, turns);
FrontRight.spinFor(4, turns);
RearRight.spinFor(4, turns);

vex::task::sleep(1000);

  
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Function                        */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (true) {
    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
    tankDrive(Controller1.Axis3.position(percent), Controller1.Axis2.position(percent));
    // Intake Controll //
    if (!Controller1.ButtonL1.pressing() && Controller1.ButtonL2.pressing()) // polls controller
        intake(75);
      else if (Controller1.ButtonL1.pressing() && !Controller1.ButtonL2.pressing())
        intake(-75);
      else
        intake(0);
    //

    // Dump Control //
    if (!Controller1.ButtonR1.pressing() && Controller1.ButtonR2.pressing()) // polls controller
        dump(25);
      else if (Controller1.ButtonR1.pressing() && !Controller1.ButtonR2.pressing())
        dump(-25);
      else
        dump(0);
    
  
  



  

   }
  }


//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
