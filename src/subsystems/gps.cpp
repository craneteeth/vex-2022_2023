#include "main.h"
void set()
{
    gps.set_offset(-1,-1.7);
    gps.set_data_rate(5);
}
std::vector<int> getStatus()
{
    //get current cordinates with the angle
    return {0,0,0};//x,y,angle
}
int getDistance()
{
    //find the distance from the shooter to the goal
    return 0;
}
int speedShooting(int d)
{
    //find the speed base on the distance
    return 0;
}
void rotate(double angle,double speed)
{
    //+ for turn right, - for turn left
    double start = gps.get_heading();
    double end;
    double target = start;
    if(angle <= 0)
    {    
        speed = -speed;
        end = start + angle;
        if(end<0)
            end += 360;
    }
    else 
    {
        end = start + angle;
        if(end >= 360)
            end -= 360;
    }
    while(target != end)//error bound = 10 degrees
    {
        runLeftBase(speed);
        runRightBase(-speed);
        target = gps.get_heading();
    }
}