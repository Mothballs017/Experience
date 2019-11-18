 /***********************************************
* CPET.252.Microcontroller Lab
* Arduino Password Projected Door Lock - 04/15/2019
* By Karen Chen 
* ***********************************************/
# include <LiquidCrystal.h>
# include <Servo.h>
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); 
const int buzzer = 10; 
const int resetButton = 8; 
const int settingButton = 9; 
const int downButton = 10; 
const int upButton = 11; 

int stdigit = 0; 
int nddigit = 0; 
int rddigit = 0; 
int thdigit = 0; 

int set_stdigit = 0; 
int set_nddigit = 0; 
int set_rddigit = 0; 
int set_thdigit = 0; 

long resetButtonLongPressCounter = 0; 

int resetButtonState = LOW;
int settingButtonState = LOW;
int upButtonState = LOW;
int downButtonState = LOW;

int resetButtonPrevState = LOW;
int settingButtonPrevState = LOW;
int upButtonPrevState = LOW;
int downButtonPrevState = LOW;

bool resetButtonPressed = false;
bool resetButtonLongPressed = false;
bool settingButtonPressed = false;
bool upButtonPressed = false;
bool downButtonPressed = false;

enum mode_state {MODE_IDLE, MODE_SETUP, MODE_RUNNING, MODE_RINGING}; 
int  mode_state = MODE_IDLE; 
int  prevMode_state = -1; 
bool isNewState = true; 
int setTimer = 0; 
unsigned long timeStampStartOfLoopMs; 

int dataSelection = 1;  // Currently selected data for edit (setup mode, changes with setting)
                        // 1=fist_digit (0-9) 2=second_digit (0-9) 3=third_digit (0-9) 4=fourth_digit (0-9)

//int currentDigit = Digit_IDLE;  // 0=idle 1=setup 2=running 3=ringing
                                // Power up --> idle
                                // Reset --> idle
                                //  Start/Stop --> start or stop counter
                                //  Up / Down --> NOP
                                // Reset (long press) --> enter setup
                                //   Start/Stop --> data select
                                //   Up --> increase current data value
                                //   Down --> decrease current data value
                                //   Reset --> exit setup (idle)
 
void setup() {
  lcd.begin(16,2); //set up the LCD's number of columns and rows
  pinMode(resetButton, INPUT); 
  pinMode(buzzer, OUTPUT); 
  pinMode(resetButton, INPUT); 
  pinMode(settingButton, INPUT); 
  pinMode(upButton, INPUT); 
  pinMode(downButton, INPUT); 
  Serial.begin(9600);
  Serial.println(F("Password_protected_locker")); 
}

void loop() {
  // put your main code here, to run repeatedly:
  settingButtonPressed = false;
  upButtonPressed = false;
  downButtonPressed = false;

}

void Reset(){
  mode_state = MODE_IDLE; 
  stdigit = set_stdigit; 
  nddigit = set_nddigit; 
  rddigit = set_rddigit; 
  thdigit = set_thdigit; 
  
}
