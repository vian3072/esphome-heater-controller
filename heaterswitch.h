#include "esphome.h"
#include <ESP32_Servo.h>
Servo myservo;
class MyCustomSwitch : public Component, public Switch {
 public:
  void setup() override {
    // This will be called by App.setup()
    myservo.attach(15);
    myservo.write(175);
    //pinMode(2, OUTPUT);
  }
  void write_state(bool state) override {
    // This will be called every time the user requests a state change.

    if(state == true){
    myservo.write(5);
    //digitalWrite(2, HIGH);
    }else if(state == false){
    myservo.write(175);
    //digitalWrite(2, LOW);
    }else{
    myservo.write(175);
    //digitalWrite(2, LOW);
    }
    // Acknowledge new state by publishing it
    publish_state(state);
    delay(250);
  }
};
