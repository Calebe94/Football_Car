#include <Arduino.h>
#include "BluetoothSerial.h" //Header File for Serial Bluetooth, will be added by default into Arduino
#include "config.h"
#include "motor.h"

BluetoothSerial ESP_BT; //Object for Bluetooth
// int incoming;
char incoming;
bool speed_button_pressed = false;

void button_released()
{
  if(speed_button_pressed)
  {
    motor_left_set_speed(MEDIUM_SPEED);
    motor_right_set_speed(MEDIUM_SPEED+5);
  }
  else
  {
    motor_left_set_speed(STOPPED);
    motor_right_set_speed(STOPPED);
  }
}

void switch_controller_actions(const char command_received)
{
  switch(command_received)
  {
    case 'a':
      // Left Button released
      Serial.println("Left Button released");
      button_released();
      break;
    case 'b':
      // Left Button pressed
      Serial.println("Left Button pressed");
      motor_left_set_speed(LOW_SPEED);
      motor_left_move_foward();
      motor_right_move_foward();
      break;
    case 'c':
      // Right Button released
      Serial.println("Right Button released");
      button_released();
      break;
    case 'd':
      // Right Button pressed
      Serial.println("Right Button pressed");
      motor_left_move_foward();
      motor_right_set_speed(LOW_SPEED);
      motor_right_move_foward();
      break;
    case 'e':
      // Up Button released
      Serial.println("Up Button released");
      button_released();
      break;
    case 'f':
      // Up Button pressed
      Serial.println("Up Button pressed");
      motor_left_move_foward();
      motor_right_move_foward();
      break;
    case 'g':
      // Down Button released
      Serial.println("Down Button released");
      button_released();
      break;
    case 'h':
      // Down Button pressed
      Serial.println("Down Button pressed");
      motor_left_move_backward();
      motor_right_move_backward();
      break;
    case 'i':
      // Square Button released
      Serial.println("Square Button released");
      break;
    case 'j':
      // Square Button pressed
      Serial.println("Square Button pressed");
      break;
    case 'k':
      // Triangle Button released
      Serial.println("Triangle Button released");
      break;
    case 'l':
      // Triangle Button pressed
      Serial.println("Triangle Button pressed");
      break;
    case 'm':
      // Cross Button released
      Serial.println("Cross Button released");
      motor_left_set_speed(STOPPED);
      motor_right_set_speed(STOPPED);
      motor_left_stop();
      motor_right_stop();
      speed_button_pressed = false;
      break;
    case 'n':
      // Cross Button pressed
      Serial.println("Cross Button pressed");
      motor_left_set_speed(MEDIUM_SPEED);
      motor_right_set_speed(MEDIUM_SPEED+5);
      speed_button_pressed = true;
      break;
    case 'o':
      // Circle Button released
      Serial.println("Circle Button released");
      break;
    case 'p':
      // Circle Button pressed 
      Serial.println("Circle Button pressed");
      break;
    case 'q':
      // Start Button released
      Serial.println("Start Button released");
      break;
    case 'r':
      // Start Button pressed
      Serial.println("Start Button pressed");
      break;
    case 's':
      // Stop Button released
      Serial.println("Stop Button released");
      break;
    case 't':
      // Stop Button pressed
      Serial.println("Stop Button pressed");
      break;
    default:
      Serial.println("Command invalid");
      break;
  }
}

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600); //Start Serial monitor in 9600
  ESP_BT.begin("Football_Car"); //Name of your Bluetooth Signal
  Serial.println("Bluetooth Device is Ready to Pair");

  motor_init();
  pinMode (LED_BUILTIN, OUTPUT);//Specify that LED pin is output
}

void loop() 
{
  // put your main code here, to run repeatedly:

  if (ESP_BT.available()) //Check if we receive anything from Bluetooth
  {
    incoming = (char)ESP_BT.read(); //Read what we recevive 

    Serial.print("Received:"); Serial.println(incoming);
    
    switch_controller_actions(incoming);
  }
  delay(20);

}