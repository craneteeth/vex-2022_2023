#include "main.h"
#include "pros/vision.h"
using namespace pros;
void set_vision_sensor()
{

}
bool colorCheck(int check)//1 for red 2 for blue
{
    while(vision.get_object_count()>0)
    {
        
    }
    return true;
}
vision_object_s_t get_goal(int check)//1 for red 2 for blue
{
    vision_signature_s_t blueGoal = 
    Vision::signature_from_utility (2, -2731, 1, -1365, 6371, 9741, 8056, 3.000, 0);
    vision.set_signature(1, &blueGoal);
    vision_object_s_t blue_goal = vision.get_by_sig(0,1);

    vision_signature_s_t redGoal =
    Vision::signature_from_utility (4, 4599, 8107, 6353, -1, 1003, 501, 3.000, 0);
    vision.set_signature(2, &redGoal);
    vision_object_s_t red_goal = vision.get_by_sig(0,2);

    if(check == 1)
        return red_goal;
    else
        return blue_goal;
}
int get_mid_x(vision_object_s_t goal)
{
    return goal.x_middle_coord;
}
int get_width(vision_object_s_t goal)
{
    return goal.width;
}
int get_height(vision_object_s_t goal)
{
    return goal.height;
}
double get_distance(int width, int height, double heightDiff)
{
    double distance = 0; //ratio using width, height, distance formula
    return distance;
}