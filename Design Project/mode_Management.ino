/*
   mode management
*/
switch (mode_state)
{
case MODE_IDLE:
  if (resetButtonPressed) {
    Reset();
  }
  if (resetButtonLongPressed) {
    mode_state = MODE_SETUP;
  }
  if (settingButtonPressed) {
    mode_state = mode_state == MODE_IDLE ? MODE_RUNNING : MODE_IDLE;
    if (mode_state  == MODE_RUNNING) {
      //evaluate the password
    }
  }
  break;
case MODE_SETUP:
if (resetButtonPressed){
  dataSelection = 0; 
  stdigit = set_stdigit; 
  nddigit = set_nddigit; 
  rddigit = set_rddigit; 
  thdigit = set_thdigit; 
  mode_state = MODE_IDLE; 
}
if(settingButtonPressed)
//Select next digit to edit 
dataSelection ++; 
if (dataSelection == 4) {
  dataSelection = 1; 
}
if(downButtonPressed){
  switch (dataSelection){
    case 1 : //first digit
    stdigit--; 
    if (stdigit == -1){
      stdigit = 9; 
    }
    break;
     
    case 2 : //second digit
    nddigit--; 
    if (nddigit == -1){
      nddigit = 9; 
    }
    break;
    
    case 3 : //third digit
    rddigit--; 
    if (rddigit == -1){
      rddigit = 9; 
    }
    break;
    
    case 4 : //fourth digit
    thdigit--; 
    if (thdigit == -1){
      thdigit = 9; 
    }
    break;
  }
}

if(upButtonPressed){
  switch (dataSelection){
    case 1 : //first digit
    stdigit++; 
    if (stdigit == 10){
      stdigit = 0; 
    }
    break;
     
    case 2 : //second digit
    nddigit++; 
    if (nddigit == 10){
      nddigit = 0; 
    }
    break;
    
    case 3 : //third digit
    rddigit++; 
    if (rddigit == 10){
      rddigit = 0; 
    }
    break;
    
    case 4 : //fourth digit
    thdigit++; 
    if (thdigit == 10){
      thdigit = 0; 
    }
    break;
  }
}
  break;
  
case MODE_RUNNING:
if(settingButtonPressed){
  mode_state = MODE_IDLE; 
}
if(resetButtonPressed){
  Reset(); 
  mode_state = MODE_IDLE; 
}
 break;


case MODE_RINGING:
if (resetButtonPressed || settingButtonPressed || upButtonPressed || downButtonPressed){
  mode_state = MODE_IDLE; 
}
  break;

default: mode_state = MODE_IDLE;
}
