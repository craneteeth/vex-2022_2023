#include "main.h"
void set_gyro()
{
    gyro_turret.reset();
    gyro_base.reset();
}
double getAngleTurret()
{
    return gyro_turret.get_yaw();
}
double getAngleBase()
{
    return gyro_base.get_yaw();
}
void rotateTurret(double angle, double speed)
{
    
}
void rotateBase(double angle, double speed)
{

}
void rotatePID(float target, float speed){;
    float kp = 4;
    float ki = 0;
    float kd = 0;
    float error = 0;
    float errorTotal = 0;
    float errorLast = 0;
    float pTerm = 0;
    float iTerm = 0;
    float dTerm = 0;
    float power = speed;
    float currentAngle = gyro_turret.get_yaw();
    pros::screen::print(pros::E_TEXT_LARGE, 9, "Power: %3f", power);
    if(currentAngle < 270){
        errorLast = error;
        error = target - (currentAngle);
        errorTotal += error;
        pTerm = error * kp;
        iTerm = ki * errorTotal;
        dTerm = kd * (error - errorLast);
        power = pTerm + iTerm + dTerm;
        shoot(power);
        pros::screen::print(pros::E_TEXT_LARGE, 9, "Power: %3f", power);
        pros::delay(40);
    }
    else{
        shoot(speed);
    }
}