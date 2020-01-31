
#include <ros.h>
#include "include/motion.h"

#include "include/turtlebot3_sensor.h"
#include "sensor_msgs/Imu.h"

/**
 * IMU test
**/
    sensor_msgs::Imu msg_imu;
    ros::Publisher imu_pub("test_imu_msg", &msg_imu);
    Turtlebot3Sensor sensors;
//

void motionCallback(const quad_opencr::quad_stat& msg);

ros::NodeHandle _nh;
ros::Subscriber<quad_opencr::quad_stat> sub("quad_motion", &motionCallback);

unsigned long boot_t;
void setup()
{
    boot_t = millis();    
    led_test = false;
    led_status = false;
    pinMode(OPENCR_PIN_USER_LED_1,OUTPUT);
    pinMode(OPENCR_PIN_USER_LED_4,OUTPUT);
    _nh.initNode();
    _nh.subscribe(sub);
    sensors.init();
}

void loop()
{
    unsigned long loop_t = millis();

    if((loop_t - boot_t) > 500)
    {
        led_status = !led_status;
        ledSwith(OPENCR_PIN_USER_LED_4,led_status);

        msg_imu = sensors.getIMU();
        _nh.advertise(imu_pub);
    }

    _nh.spinOnce();
    delay(10);
}

void motionCallback(const quad_opencr::quad_stat& msg)
{
    if(msg.throttle > 60)
    {
        led_test = true;
    }
    else
    {
        led_test = false;
    }
    
}

void ledSwith(int pin, bool onoff)
{
    if(onoff)
    {
        digitalWrite(pin,HIGH);
    }
    else
    {
        digitalWrite(pin,LOW);
    }
    
}
