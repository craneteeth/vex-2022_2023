#include "main.h"
void leftNew()
{
    leftBase1.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	leftBase2.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	rightBase1.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	rightBase2.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    intake.set_brake_mode(E_MOTOR_BRAKE_COAST);
    feeder.set_brake_mode(E_MOTOR_BRAKE_COAST);
    setBool(piston2,false);
    setBool(piston,false);
    setBool(piston3, false);

    shoot(79);

    /*moveBase(50,100);
    delay(600);
    moveBase(-150, 100);
    delay(1000);*/

    turnBase(47,80);
    delay(800);

    setBool(piston,true);
    delay(600);
    feeder.move(127);
    delay(1200);
    runIntake(127);
    delay(2800);
    feeder.move(0);
    setBool(piston, false);
    runIntake(0);
    delay(200);

    turnBase(453,80);
    delay(1000);
    runIntake(127);
    moveBase(-200,100);
    delay(1200);

    turnBase(-160,80);
    delay(800);
    runIntake(127);
    moveBase(-700,100);
    delay(1300);

    turnBase(-272,80);
    delay(800);

    setBool(piston,true);
    delay(600);
     runIntake(0);
    feeder.move(127);
    delay(1200);
    runIntake(127);
    delay(2800);
    feeder.move(0);
    setBool(piston, false);
    runIntake(0);
    delay(200);
}