#include "main.h"
void shoot(double percVolt)
{
    shooter1.move_voltage(percVolt * 12000/100);
    shooter2.move_voltage(percVolt * 12000/100);
    shooter3.move_voltage(percVolt * 12000/100);
}
void shooterTest()
{
    shooter1.move_voltage(12000*127);
    delay(1200);
    shooter1.move_voltage(0);
    shooter2.move_voltage(12000*127);
    delay(1200);
    shooter2.move_voltage(0);
    shooter3.move_voltage(12000*127);
    delay(1200);
    shooter3.move_voltage(0);
}
void FlywheelPID(float target, float speed){;
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
    float currentVelocity = shooter1.get_actual_velocity();
    pros::screen::print(pros::E_TEXT_LARGE, 9, "Power: %3f", power);
    if(currentVelocity < 270){
        errorLast = error;
        error = target - (currentVelocity);
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