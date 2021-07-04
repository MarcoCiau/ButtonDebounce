#ifndef BUTTON_DEBOUNCE_H
#define BUTTON_DEBOUNCE_H
#include <Arduino.h>

#define DEBOUNCE_TIMEOUT_MS 150 //250 ms Button Debouncing Timer

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