#include <stdint.h>
#include "driver/ledc.h"

struct motor 
{
    uint8_t gpio_a;
    uint8_t gpio_b;
    ledc_channel_config_t pwm;
};

typedef struct motor motor_t;

/*
    Convert percentage to duty cycle
*/
uint16_t percentage_to_duty(uint8_t percentage);

/*
    Initialize both motors
*/
void motor_init();

/*
    Initialize motor1
*/
void motor_left_init();

/*
    Initialize motor2
*/
void motor_right_init();

/*
    Set motor 1 Speed.
*/
void motor_left_set_speed(uint8_t);

/*
    Set motor 2 Speed.
*/
void motor_right_set_speed(uint8_t);

/*
    Makes motor 1 fowards
*/
void motor_left_move_foward();

/*
    Makes motor 2 fowards
*/
void motor_right_move_foward();

/*
    Makes motor 1 backwards
*/
void motor_left_move_backward();

/*
    Makes motor 2 backwards
*/
void motor_right_move_backward();

/*
    Makes motor 1 stop
*/
void motor_left_stop();

/*
    Makes motor 2 stop
*/
void motor_right_stop();