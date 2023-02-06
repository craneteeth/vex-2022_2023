#ifndef BASE_H
#define BASE_H
void runLeftBase(double input);
void runRightBase(double input);
double getLeftBase();
double getRightBase();
void resetLeftBase();
void resetRightBase();
void moveBase(double input, double speed);
void turnBase(double input, double speed);
void moveBasePID(double deltaTicks, double time, double maxOutput);
void hexa_move(double speed);
void move_diagonal_right(double speed);
void move_diagonal_left(double speed);
void move_side(double speed);
#endif