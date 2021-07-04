#ifndef BUTTON_DEBOUNCE_H
#define BUTTON_DEBOUNCE_H
#include <Arduino.h>

#define DEBOUNCE_TIMEOUT_MS 180 //180 ms Button Debouncing Timer

class ButtonDebounce
{
private:
    int buttonPin;
    unsigned long firstPressedTime;
    unsigned long skipPressedTimer;
    bool initialState;
    bool buttonStatus;
    bool skipEvent;
    bool lastState;

public:
    ButtonDebounce(int pin);
    void begin();
    void loop();
    bool isPressed();
    bool isReleased();
    bool isSkipEvent();
};





#endif //BUTTON_DEBOUNCE_H