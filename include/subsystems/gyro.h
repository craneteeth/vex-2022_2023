#include "api.h"
using namespace pros;
#ifndef GYRO_H
#define GYRO_H
void set_gyro();
double getAngleTurret();
double getAngleBase();
void rotateTurret(double angle, double speed);
void rotateBase(double angle, double speed);
#endif