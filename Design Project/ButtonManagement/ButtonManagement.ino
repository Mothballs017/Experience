
/*
 *  Reset button management
 */
resetButtonPressed = false;
resetButtonLongPressed = false;
resetButtonState = digitalRead(resetButton);
if (resetButtonState != resetButtonPrevState)
{
  resetButtonPressed = resetButtonState == HIGH;
  resetButtonPrevState = resetButtonState;
}
else // long press management
{
  if (resetButtonState == HIGH)
  {
    resetButtonLongPressCounter++;
    if (resetButtonLongPressCounter == 100)
    {
      resetButtonPressed = false;
      resetButtonLongPressed = true;
      resetButtonLongPressCounter = 0;
    }
    else
    {
      resetButtonLongPressCounter = 0;
      resetButtonPressed = false;
      resetButtonLongPressed = false;
    }

  }
}


/*
 *  setting button management
 */
settingButtonPressed = false;
settingButtonState = digitalRead(settingButton);
if (settingButtonState != settingButtonPrevState)
{
  settingButtonPressed = settingButtonState == HIGH;
  settingButtonPrevState = settingButtonState;
}


/*
 *  Down button management
 */
downButtonPressed = false;
downButtonState = digitalRead(downButton);
if (downButtonState != downButtonPrevState)
{
  downButtonPressed = downButtonState == HIGH;
  downButtonPrevState = downButtonState;
}


/*
 *  Up button management
 */

upButtonPressed = false;
upButtonState = digitalRead(upButton);
if (upButtonState != upButtonPrevState)
{
  upButtonPressed = upButtonState == HIGH;
  upButtonPrevState = upButtonState;
}
