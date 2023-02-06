#include "main.h"
void setBool(ADIDigitalOut &p,bool input)
{
    p.set_value(input);
}