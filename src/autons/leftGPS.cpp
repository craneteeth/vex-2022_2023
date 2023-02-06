#include "main.h"
#include "subsystems/base.h"
void leftGPS()
{
    leftBase1.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	leftBase2.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	rightBase1.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	rightBase2.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    setBool(piston2,false);
    setBool(piston,false);
    setBool(piston3, false);
    set();
    runIntake(-127);
    delay(200);
    moveBase(-50,100);
    delay(600);
    runIntake(0);

    moveBase(80,100);
    delay(300);

    rotate(-20, 100);
    delay(500);

    delay(2400);

    setBool(piston,true);
    delay(200);
    setBool(piston,false);
    delay(600);
    turnBase(-1,80);
    delay(1800);

    setBool(piston,true);
    delay(200);
    setBool(piston,false);
    delay(1200);
    shoot(0);
       

/*
    //turn right
    turnBase(230,100);
    delay(700);
    //move forward and collect 3 discs
    moveBase(800,100);
    runIntake(127);
    delay(1200);
    runIntake(0);
    //turn left
    turnBase(-230, 100);
    delay(700);
    //shoot three times
    shoot(74);
    delay(500);

    setBool(piston,true);
    delay(200);
    setBool(piston,false);
    delay(100);

    setBool(piston,true);
    delay(200);
    setBool(piston,false);
    delay(100);

    setBool(piston,true);
    delay(200);
    setBool(piston,false);
    delay(100);
    shoot(0);
    //turn left
    turnBase(-100,127);
    delay(200);
    //move back towards the other roller
    moveBase(1500,-127);
    delay(1500);
    //roll the roller
    moveBase(500,-127);
    runIntake(-127);
    delay(300);
    runIntake(0);
    //move forward
    moveBase(100,127);
    delay(200);*/
}