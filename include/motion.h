#include "quad_opencr/quad_stat.h"      //quad_stat msg defined in this header.

//Define mode here
#define MODE_1 1        //motion called inch worm motion.
#define MODE_2 2        //motion called vertical wave motion.

//Define motion info here
#define MOTION_SAMPLING 100         //motion sampling rate.

//OpenCR pin map here
#define OPENCR_PIN_USER_LED_1 22
#define OPENCR_PIN_USER_LED_2 23
#define OPENCR_PIN_USER_LED_3 24
#define OPENCR_PIN_USER_LED_4 25
#define OPENCR_PIN_ARDUINO_LED_1 13

//Global variable for code here.
bool led_test = false;
bool led_status = false;

int loop_time = 500;        //500ms


//ROS msg structure