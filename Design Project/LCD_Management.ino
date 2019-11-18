/*
   LCD management
*/
//lcd.clear();
lcd.setCursor(0, 0);
switch (mode_state)
{
case MODE_IDLE:
  lcd.print("Timer ready     ");
  lcd.setCursor(0, 1);
  lcd.print(stdigit);
  lcd.print(" ");
  lcd.print(nddigit);
  lcd.print(" ");
  lcd.print(rddigit);
  lcd.print(" ");
  lcd.print(thdigit);
  lcd.print("    ");
  break;
  
case MODE_SETUP:
  lcd.print("Setup mode: ");
  switch (dataSelection)
  {
    case 0:
      lcd.print("1st digit");
      break;
    case 1:
      lcd.print("2nd digit");
      break;
    case 2:
      lcd.print("3rd digit");
      break;
    case 3:
      lcd.print("4th digit");
      break;
  }
  lcd.setCursor(0, 1);
  lcd.print(set_stdigit);
  lcd.print(" ");
  lcd.print(set_nddigit);
  lcd.print(" ");
  lcd.print(set_rddigit);
  lcd.print(" ");
  lcd.print(set_thdigit);
  lcd.print("    ");
  break;
  
case MODE_RUNNING:
  lcd.print("Checking");
  break;
  
case MODE_RINGING:
  lcd.print("   RING-RING!   ");
  lcd.setCursor(0, 1);
  lcd.print("                ");
  break;
}
delay(10);
}
