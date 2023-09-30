/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       cameronvakili                                             */
/*    Created:      9/22/2023, 4:27:45 PM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"

using namespace vex;
competition Competition;

vex::motor FrontLeft (vex::PORT7, vex::gearSetting::ratio18_1, true);
vex::motor FrontRight (vex::PORT8, vex::gearSetting::ratio18_1, false);
vex::motor BackLeft (vex::PORT9, vex::gearSetting::ratio18_1, true);
vex::motor BackRight (vex::PORT10, vex::gearSetting::ratio18_1, false);
vex::motor MiddleLeft (vex::PORT1, vex::gearSetting::ratio18_1, true);
vex::motor MiddleRight (vex::PORT2, vex::gearSetting::ratio18_1, true);
vex::motor Intake (vex::PORT4, vex::gearSetting::ratio18_1, true);
vex::controller Controller1 (vex::controllerType::primary);


// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}
void resetDrive(){
  FrontLeft.resetPosition();
  BackLeft.resetPosition();
  MiddleLeft.resetPosition();
  BackRight.resetPosition();
  MiddleRight.resetPosition();
  FrontRight.resetPosition();
}

void MoveBackward (double dist, double spd){
  FrontLeft.spinTo(dist * -1,vex::rotationUnits::deg, spd * -1, vex::velocityUnits::pct);
  BackLeft.spinTo(dist * -1,vex::rotationUnits::deg, spd * -1, vex::velocityUnits::pct);
  MiddleLeft.spinTo(dist * -1,vex::rotationUnits::deg, spd * -1, vex::velocityUnits::pct);
  BackRight.spinTo(dist,vex::rotationUnits::deg, spd, vex::velocityUnits::pct);
  MiddleRight.spinTo(dist , vex::rotationUnits::deg, spd, vex::velocityUnits::pct);
  FrontRight.spinTo(dist * 1, vex::rotationUnits::deg, spd, vex::velocityUnits::pct);
}

void MoveForward (double dist, double spd){
  FrontLeft.spinTo(dist, vex::rotationUnits::deg, spd, vex::velocityUnits::pct);
  BackLeft.spinTo(dist, vex::rotationUnits::deg, spd, vex::velocityUnits::pct);
  MiddleLeft.spinTo(dist * 1 ,vex::rotationUnits::deg, spd, vex::velocityUnits::pct);
  FrontRight.spinTo(dist * -1, vex::rotationUnits::deg, spd * 1, vex::velocityUnits::pct);
  BackRight.spinTo(dist * -1, vex::rotationUnits::deg, spd * 1, vex::velocityUnits::pct);
  MiddleRight.spinTo(dist * -1, vex::rotationUnits::deg, spd * 1, vex::velocityUnits::pct);
}

void MoveLeft (double dist, double spd){
  FrontLeft.spinTo(dist * -1,vex::rotationUnits::deg, spd * 1, vex::velocityUnits::pct);
  BackLeft.spinTo(dist *-1,vex::rotationUnits::deg, spd * 1, vex::velocityUnits::pct);
  MiddleLeft.spinTo(dist *-1,vex::rotationUnits::deg, spd * 1, vex::velocityUnits::pct);
  FrontRight.spinTo(dist * -1,vex::rotationUnits::deg, spd, vex::velocityUnits::pct);
  BackRight.spinTo(dist * -1, vex::rotationUnits::deg, spd, vex::velocityUnits::pct);  
  MiddleRight.spinTo(dist * -1, vex::rotationUnits::deg, spd, vex::velocityUnits::pct);

}

void MoveRight (double dist, double spd){
  FrontLeft.spinTo(dist,vex::rotationUnits::deg, spd * 1, vex::velocityUnits::pct);
  BackLeft.spinTo(dist,vex::rotationUnits::deg, spd * 1, vex::velocityUnits::pct);
  MiddleRight.spinTo(dist,vex::rotationUnits::deg, spd * 1, vex::velocityUnits::pct);
  FrontRight.spinTo(dist * 1,vex::rotationUnits::deg, spd, vex::velocityUnits::pct);
  MiddleLeft.spinTo(dist * 1, vex::rotationUnits::deg, spd, vex::velocityUnits::pct);  
  BackRight.spinTo(dist * 1, vex::rotationUnits::deg, spd, vex::velocityUnits::pct);
}


void LeftOnly (double dist, double spd){
  FrontLeft.spinTo(dist,vex::rotationUnits::deg, spd, vex::velocityUnits::pct);
  BackLeft.spinTo(dist,vex::rotationUnits::deg, spd, vex::velocityUnits::pct);
  MiddleLeft.spinTo(dist,vex::rotationUnits::deg, spd, vex::velocityUnits::pct);
}

void RightOnly(double dist, double spd){
  FrontRight.spinTo(dist, vex::rotationUnits::deg, spd, vex::velocityUnits::pct);
  BackRight.spinTo(dist, vex::rotationUnits::deg, spd, vex::velocityUnits::pct);
  MiddleRight.spinTo(dist * 1, vex::rotationUnits::deg, spd, vex::velocityUnits::pct);
}

void ChassisStop(){
  FrontLeft.stop(vex::brakeType::brake);
  BackLeft.stop(vex::brakeType::brake);
  MiddleLeft.stop(vex::brakeType::brake);
  BackRight.stop(vex::brakeType::brake);
  FrontRight.stop(vex::brakeType::brake);
  MiddleRight.stop(vex::brakeType::brake);
}
void ChassisStopCoast(){
  FrontLeft.stop(vex::brakeType::coast);
  BackLeft.stop(vex::brakeType::coast);
  MiddleLeft.stop(vex::brakeType::coast);
  BackRight.stop(vex::brakeType::coast);
  FrontRight.stop(vex::brakeType::coast);
  MiddleRight.stop(vex::brakeType::coast);

}
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    BackLeft.spin(vex::directionType::fwd,((1*Controller1.Axis3.value()) + (.75*Controller1.Axis1.value())), vex::velocityUnits::pct);
    BackRight.spin(vex::directionType::fwd, ((1* Controller1.Axis3.value()) + (-.75* Controller1.Axis1.value())), vex::velocityUnits::pct);
    FrontLeft.spin(vex::directionType::fwd, ((1* Controller1.Axis3.value()) + (.75* Controller1.Axis1.value())), vex::velocityUnits::pct);
    FrontRight.spin(vex::directionType::fwd,  ((1* Controller1.Axis3.value()) + (-.75* Controller1.Axis1.value())), vex::velocityUnits::pct);
    MiddleLeft.spin(vex::directionType::fwd, ((1* Controller1.Axis3.value()) + (.75* Controller1.Axis1.value())), vex::velocityUnits::pct);
    MiddleRight.spin(vex::directionType::fwd,  ((1* Controller1.Axis3.value()) + (-.75* Controller1.Axis1.value())), vex::velocityUnits::pct);

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
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
