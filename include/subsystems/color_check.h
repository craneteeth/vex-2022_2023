#include "api.h"
using namespace pros;
#ifndef COLOR_CHECK_H
#define COLOR_CHECK_H
void set_vision_sensor();
bool colorCheck(int check);
vision_object_s_t get_goal(int check);
int get_mid_x(vision_object_s_t goal);
int get_width(vision_object_s_t goal);
int get_height(vision_object_s_t goal);
double get_distance(int width, int height, double heightDiff);
#endif