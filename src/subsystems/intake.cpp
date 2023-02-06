#include "main.h"
void runIntake(double input)
{
    intake.move_voltage(input * 12000/100);
    intake2.move_voltage(input * 12000/100);
}