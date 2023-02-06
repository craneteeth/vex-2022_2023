#include "main.h"
#include "subsystems/base.h"
void left()
{
    leftBase1.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	leftBase2.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	rightBase1.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	rightBase2.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    setBool(piston2,false);
    setBool(piston,false);
    setBool(piston3, false);
    //get the discs in the intake, don't need
    /*runIntake(127);
    delay(1600);
    runIntake(0);*/
    //move back and roll the roller 
    shoot(100);
    /*runIntake(-127);
    delay(200);
    moveBase(-50,127);
    delay(400);
    moveBase(50,127);
    delay(100);
    moveBase(-100,127);
    delay(400);
    moveBase(70,127);
    delay(150);
    moveBase(-100,127);
    delay(450);
    runIntake(0);
    delay(100);*/
    //move forward and turnright
    moveBase(140,100);
    delay(600);

//additoinal
    moveBase(-200, 100);
    delay(1000);

    moveBase(300,100);
    delay(600);

/////

    //toward our zone
    /*turnBase(240, 100);
    delay(500);*/
    //high goal
    turnBase(-110,127); ////////////////
    delay(800);
    //move forward and collect disc
    /*runIntake(127);
    moveBase(1000,100);
    delay(2400);
    runIntake(0);
    //turnleft
    turnBase(-200,100);
    delay(700);*/
    //shoot three times, our zone 
    //shoot(67);
    //shoot high goal
    //shoot(79);//////////////

    
    //shoot(89);
    shoot(73.5);

    delay(3000);

    setBool(piston,true);
    delay(200);
    setBool(piston,false);
    delay(600);
    turnBase(-1,100);
    shoot(100);
    delay(600);
    shoot(89);
    delay(1800);

    setBool(piston,true);
    delay(200);
    setBool(piston,false);
    delay(1200);
    shoot(0);

    /*setBool(piston,true);
    delay(200);
    setBool(piston,false);
    delay(300);
    shoot(0);*/
       
    turnBase(340,127);
    /*delay(1000);
    runIntake(127);
    moveBase(1500,127);
    delay(2800);
    moveBase(-50,127);
    delay(100);
    moveBase(50,127);
    delay(100);
    moveBase(-50,127);
    delay(100);
    moveBase(50,127);
    delay(100);
    moveBase(-50,127);
    delay(100);
    moveBase(50,127);
    delay(100);*/
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