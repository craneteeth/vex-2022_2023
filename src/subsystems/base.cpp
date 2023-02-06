#include "main.h"
int left1Direction = -1;
int left2Direction = -1;
int right1Direction = 1;
int right2Direction = 1;
void runLeftBase(double percVolt)
{
    leftBase1.move_voltage(percVolt * 12000/127);
    leftBase2.move_voltage(percVolt * 12000/127);
}

void runRightBase(double percVolt)
{
    rightBase1.move_voltage(percVolt * 12000/127);
    rightBase2.move_voltage(percVolt * 12000/127);
}

double getLeftBase()
{
    return (leftBase1.get_position() + leftBase2.get_position()) / 2.0;
}

double getRightBase()
{
    return (rightBase1.get_position() + rightBase2.get_position()) / 2.0;
}

void resetLeftBase()
{
    leftBase1.tare_position();
    leftBase2.tare_position();
}

void resetRightBase()
{
    rightBase1.tare_position();
    rightBase2.tare_position();
}

void moveBase(double input, double speed)
{
    leftBase1.move_relative(input, speed); 
    leftBase2.move_relative(input, speed); 
    rightBase1.move_relative(input, speed); 
    rightBase2.move_relative(input, speed); 
}

void turnBase(double input, double speed)
{
    std::cout << "works" << std::endl;
    leftBase1.tare_position(); leftBase2.tare_position();
    rightBase1.tare_position(); rightBase2.tare_position();
    leftBase1.move_relative(input, speed); 
    leftBase2.move_relative(input, speed); 
    rightBase1.move_relative(-input, speed); 
    rightBase2.move_relative(-input, speed); 
}
void moveBasePID(double deltaTicks, double time, double maxOutput)
{
    double leftBaseTarget = getLeftBase() + deltaTicks;
    double rightBaseTarget = getRightBase() + deltaTicks;
    PID leftBase (0.35, 0.3, 0.5);
    PID rightBase (0.35, 0.3, 0.5);
    std::uint_least32_t now = millis();
    for (int i = 0; i < time; i++) {
        leftBase.setError(leftBaseTarget - getLeftBase());
        rightBase.setError(rightBaseTarget - getRightBase());
        
        runLeftBase(leftBase.runPID());
        runRightBase(rightBase.runPID());
        Task::delay_until(&now, 1);
    }
    runLeftBase(0);
    runRightBase(0);
}
void hexa_move(double percVolt)
{
    leftBase1.move_voltage(percVolt * 12000/127 * left1Direction);
    leftBase2.move_voltage(percVolt * 12000/127 * left2Direction);
    rightBase1.move_voltage(percVolt * 12000/127 * right1Direction);
    rightBase2.move_voltage(percVolt * 12000/127 * right2Direction);
}
void move_side(double percVolt)//+ = right, - = left
{
    leftBase1.move_voltage(percVolt * -12000/127 * left1Direction);
    leftBase2.move_voltage(percVolt * 12000/127 * left2Direction);
    rightBase1.move_voltage(percVolt * -12000/127 * right1Direction);
    rightBase2.move_voltage(percVolt * 12000/127 * right2Direction);
}
void move_diagonal_right(double percVolt)
{
    leftBase1.move_voltage(percVolt * 12000/127 * left1Direction);
    rightBase2.move_voltage(percVolt * 12000/127 * right2Direction);
}
void move_diagonal_left(double percVolt)
{
    leftBase2.move_voltage(percVolt * 12000/127 * left2Direction);
    rightBase1.move_voltage(percVolt * 12000/127 * right1Direction);
}