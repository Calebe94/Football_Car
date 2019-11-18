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
void motor_1_init();

/*
    Initialize motor2
*/
void motor_2_init();

/*
    Set motor 1 Speed.
*/
void motor_1_set_speed(uint8_t);

/*
    Set motor 2 Speed.
*/
void motor_2_set_speed(uint8_t);

/*
    Makes motor 1 fowards
*/
void motor_1_move_foward();

/*
    Makes motor 2 fowards
*/
void motor_2_move_foward();

/*
    Makes motor 1 backwards
*/
void motor_1_move_backward();

/*
    Makes motor 2 backwards
*/
void motor_2_move_backward();

/*
    Makes motor 1 stop
*/
void motor_1_stop();

/*
    Makes motor 2 stop
*/
void motor_2_stop();