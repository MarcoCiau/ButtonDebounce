#include <ButtonDebounce.h>

ButtonDebounce::ButtonDebounce(int pin)
{
    buttonPin = pin;
    firstPressedTime = 0;
    skipPressedTimer = millis();
    buttonStatus = false;
    skipEvent = false;
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
    skipEvent = false;
    firstPressedTime = millis();
  }
  else //button pressed
  {
    if ((millis() - firstPressedTime) >= DEBOUNCE_TIMEOUT_MS && lastState != true)
    {
      skipPressedTimer = millis();
      buttonStatus = true;  
      lastState = true;
    }  
    if ((millis() - skipPressedTimer) >= 600 && lastState && !skipEvent)
    {
      skipEvent = true;
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

bool ButtonDebounce::isSkipEvent()
{
  bool status = skipEvent;
  buttonStatus = 0;
  return status;
}