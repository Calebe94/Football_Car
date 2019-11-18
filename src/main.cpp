#include <Arduino.h>
#include "BluetoothSerial.h" //Header File for Serial Bluetooth, will be added by default into Arduino
#include "config.h"
#include "motor.h"

BluetoothSerial ESP_BT; //Object for Bluetooth
// int incoming;
int incoming;

void switch_controller_actions(const int command_received)
{
  switch(command_received)
  {
    case 0:
      // Left Button released
      Serial.println("Left Button released");
      motor_1_stop();
      motor_2_stop();
      break;
    case 1:
      // Left Button pressed
      Serial.println("Left Button pressed");
      motor_2_set_speed(LOW_SPEED);
      motor_1_stop();
      motor_2_move_foward();
      break;
    case 2:
      // Right Button released
      Serial.println("Right Button released");
      motor_1_stop();
      motor_2_stop();
      break;
    case 3:
      // Right Button pressed
      Serial.println("Right Button pressed");
      motor_1_set_speed(LOW_SPEED);
      motor_1_move_foward();
      motor_2_stop();
      break;
    case 4:
      // Up Button released
      Serial.println("Up Button released");
      motor_1_stop();
      motor_2_stop();
      break;
    case 5:
      // Up Button pressed
      Serial.println("Up Button pressed");
      motor_1_set_speed(MEDIUM_SPEED);
      motor_2_set_speed(MEDIUM_SPEED);
      motor_1_move_foward();
      motor_2_move_foward();
      break;
    case 6:
      // Down Button released
      Serial.println("Down Button released");
      motor_1_stop();
      motor_2_stop();
      break;
    case 7:
      // Down Button pressed
      Serial.println("Down Button pressed");
      motor_1_set_speed(MEDIUM_SPEED);
      motor_2_set_speed(MEDIUM_SPEED);
      motor_1_move_backward();
      motor_2_move_backward();
      break;
    case 8:
      // Square Button released
      Serial.println("Square Button released");
      break;
    case 9:
      // Square Button pressed
      Serial.println("Square Button pressed");
      break;
    // case 10:
    //   // Circle Button released
    //   Serial.println("Circle Button released");
    //   break;
    // case 11:
    //   // Circle Button pressed 
    //   Serial.println("Circle Button pressed");
    //   break;
    // case 12:
    //   // Triangle Button released
    //   Serial.println("Triangle Button released");
    //   break;
    // case 13:
    //   // Triangle Button pressed
    //   Serial.println("Triangle Button pressed");
    //   break;
    // case 14:
    //   // Cross Button released
    //   Serial.println("Cross Button released");
    //   break;
    // case 15:
    //   // Cross Button pressed
    //   Serial.println("Cross Button pressed");
    //   break;
    // case 16:
    //   // Start Button released
    //   Serial.println("Start Button released");
    //   break;
    // case 17:
    //   // Start Button pressed
    //   Serial.println("Start Button pressed");
    //   break;
    // case 18:
    //   // Stop Button released
    //   Serial.println("Stop Button released");
    //   break;
    // case 19:
    //   // Stop Button pressed
    //   Serial.println("Stop Button pressed");
    //   break;
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

    Serial.print("Received:"); Serial.println(incoming-48);
    
    switch_controller_actions(incoming-48);
  }
  delay(20);

}