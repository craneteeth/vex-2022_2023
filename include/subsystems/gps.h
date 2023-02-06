#include "api.h"
using namespace pros;
#ifndef GPS_H
#define GPS_H
void set();
std::vector<int> getStatus();
int getDistance();
int speedShooting(int d);
void rotate(double angle, double speed);
#endif