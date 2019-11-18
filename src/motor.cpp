#include <Arduino.h>
#include <math.h>
#include "motor.h"
#include "config.h"

/*
    Convert percentage to duty cycle
*/
uint16_t percentage_to_duty(uint8_t percentage)
{
    if (percentage > 99)
    {
        percentage = 100;
    }
    return (uint16_t) percentage*pow(2, MOTOR_DUTY_RES)/100;
}

/*
    Initialize both motors
*/
void motor_init()
{
    ledcSetup(MOTOR_LEFT_CHANNEL, MOTOR_PWM_FREQ_HZ, MOTOR_DUTY_RES);
    ledcSetup(MOTOR_RIGHT_CHANNEL, MOTOR_PWM_FREQ_HZ, MOTOR_DUTY_RES);
    motor_left_init();
    motor_right_init();
}

/*
    Initialize motor1
*/
void motor_left_init()
{
    ledcAttachPin(MOTOR_LEFT_GPIO, MOTOR_LEFT_CHANNEL);
    pinMode(MOTOR_LEFT_A, OUTPUT);
    pinMode(MOTOR_LEFT_B, OUTPUT);
}

/*
    Initialize motor2
*/
void motor_right_init()
{
    ledcAttachPin(MOTOR_RIGHT_GPIO, MOTOR_RIGHT_CHANNEL);
    pinMode(MOTOR_RIGHT_A, OUTPUT);
    pinMode(MOTOR_RIGHT_B, OUTPUT);
}

/*
    Set motor 1 Speed.
*/
void motor_left_set_speed(uint8_t porcentage)
{
    ledcWrite(MOTOR_LEFT_CHANNEL, percentage_to_duty(porcentage));
}

/*
    Set motor 2 Speed.
*/
void motor_right_set_speed(uint8_t porcentage)
{
    ledcWrite(MOTOR_RIGHT_CHANNEL, percentage_to_duty(porcentage));
}

/*
    Makes motor 1 fowards
*/
void motor_left_move_foward()
{
    digitalWrite(MOTOR_LEFT_A, HIGH);
    digitalWrite(MOTOR_LEFT_B, LOW);
}

/*
    Makes motor 2 fowards
*/
void motor_right_move_foward()
{
    digitalWrite(MOTOR_RIGHT_A, HIGH);
    digitalWrite(MOTOR_RIGHT_B, LOW);
}

/*
    Makes motor 1 backwards
*/
void motor_left_move_backward()
{
    digitalWrite(MOTOR_LEFT_A, LOW);
    digitalWrite(MOTOR_LEFT_B, HIGH);
}

/*
    Makes motor 2 backwards
*/
void motor_right_move_backward()
{
    digitalWrite(MOTOR_RIGHT_A, LOW);
    digitalWrite(MOTOR_RIGHT_B, HIGH);
}

/*
    Makes motor 1 stop
*/
void motor_left_stop()
{
    digitalWrite(MOTOR_LEFT_A, LOW);
    digitalWrite(MOTOR_LEFT_B, LOW);
}

/*
    Makes motor 2 stop
*/
void motor_right_stop()
{
    digitalWrite(MOTOR_RIGHT_A, LOW);
    digitalWrite(MOTOR_RIGHT_B, LOW);
}
