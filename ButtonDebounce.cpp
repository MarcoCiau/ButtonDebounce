#include <ButtonDebounce.h>

ButtonDebounce::ButtonDebounce(int pin)
{
    buttonPin = pin;
    firstPressedTime = 0;
    buttonStatus = false;
    lastState = false;
}

void ButtonDebounce::begin()
{
    pinMode(buttonPin, INPUT_PULLUP);
}

void ButtonDebounce::loop()
{
  uint8_t buttonState = digitalRead(buttonPin);
  if (buttonState)//button released
  {
    lastState = false;
    buttonStatus = false; 
    firstPressedTime = millis();
  }
  else //button pressed
  {
    if ((millis() - firstPressedTime) >= DEBOUNCE_TIMEOUT_MS && lastState != true)
    {
      buttonStatus = true;  
      lastState = true;
    }   
  }

}

bool ButtonDebounce::isPressed()
{
    bool status = buttonStatus;
    buttonStatus = 0;
    return status;
}

bool ButtonDebounce::isReleased()
{
    bool status = buttonStatus;
    buttonStatus = 0;
    return !status;
}
