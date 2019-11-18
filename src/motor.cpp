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
    ledcSetup(MOTOR_1_CHANNEL, MOTOR_PWM_FREQ_HZ, MOTOR_DUTY_RES);
    ledcSetup(MOTOR_2_CHANNEL, MOTOR_PWM_FREQ_HZ, MOTOR_DUTY_RES);
    motor_1_init();
    motor_2_init();
}

/*
    Initialize motor1
*/
void motor_1_init()
{
    ledcAttachPin(MOTOR_1_GPIO, MOTOR_1_CHANNEL);
    pinMode(MOTOR_1_A, OUTPUT);
    pinMode(MOTOR_1_B, OUTPUT);
}

/*
    Initialize motor2
*/
void motor_2_init()
{
    ledcAttachPin(MOTOR_2_GPIO, MOTOR_2_CHANNEL);
    pinMode(MOTOR_2_A, OUTPUT);
    pinMode(MOTOR_2_B, OUTPUT);
}

/*
    Set motor 1 Speed.
*/
void motor_1_set_speed(uint8_t porcentage)
{
    ledcWrite(MOTOR_1_CHANNEL, percentage_to_duty(porcentage));
}

/*
    Set motor 2 Speed.
*/
void motor_2_set_speed(uint8_t porcentage)
{
    ledcWrite(MOTOR_2_CHANNEL, percentage_to_duty(porcentage));
}

/*
    Makes motor 1 fowards
*/
void motor_1_move_foward()
{
    digitalWrite(MOTOR_1_A, HIGH);
    digitalWrite(MOTOR_1_B, LOW);
}

/*
    Makes motor 2 fowards
*/
void motor_2_move_foward()
{
    digitalWrite(MOTOR_2_A, HIGH);
    digitalWrite(MOTOR_2_B, LOW);
}

/*
    Makes motor 1 backwards
*/
void motor_1_move_backward()
{
    digitalWrite(MOTOR_1_A, LOW);
    digitalWrite(MOTOR_1_B, HIGH);
}

/*
    Makes motor 2 backwards
*/
void motor_2_move_backward()
{
    digitalWrite(MOTOR_2_A, LOW);
    digitalWrite(MOTOR_2_B, HIGH);
}

/*
    Makes motor 1 stop
*/
void motor_1_stop()
{
    digitalWrite(MOTOR_1_A, LOW);
    digitalWrite(MOTOR_1_B, LOW);
}

/*
    Makes motor 2 stop
*/
void motor_2_stop()
{
    digitalWrite(MOTOR_2_A, LOW);
    digitalWrite(MOTOR_2_B, LOW);
}
