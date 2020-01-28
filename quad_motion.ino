#include <ros.h>
#include "quad_opencr/quad_stat.h"
#include "motion.h"

void motionCallback(const quad_opencr::quad_stat& msg);

ros::NodeHandle _nh;
ros::Subscriber<quad_opencr::quad_stat> sub("quad_motion", &motionCallback);

void setup()
{
    
}

void loop()
{

}

void motionCallback(const quad_opencr::quad_stat& msg)
{

}