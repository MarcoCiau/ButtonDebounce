#include <ButtonDebounce.h>

ButtonDebounce button(0);//GPIO 0 ESP8266

void setup(){
    Serial.begin(115200);
    button.begin();
}

void loop(){
    button.loop();
    if (button.isPressed())Serial.println("Button Pressed");
}
