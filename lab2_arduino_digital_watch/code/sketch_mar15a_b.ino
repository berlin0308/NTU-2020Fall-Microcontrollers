#include "math.h" 

int func_displayL(int);
int func_displayR(int);

int clocks();
int stopwatch();
int stopwatch_display();

int display_digit[10][7]
{
  LOW, LOW, LOW, LOW, LOW, LOW, HIGH, //0
  HIGH, LOW, LOW, HIGH, HIGH, HIGH, HIGH, //1
  LOW, LOW, HIGH, LOW, LOW, HIGH, LOW, //2
  LOW, LOW, LOW, LOW, HIGH, HIGH, LOW, //3
  HIGH, LOW, LOW, HIGH, HIGH, LOW, LOW, //4
  LOW, HIGH, LOW, LOW, HIGH, LOW, LOW, //5
  LOW, HIGH, LOW, LOW, LOW, LOW, LOW, //6
  LOW, LOW, LOW, HIGH, HIGH, HIGH, HIGH, //7
  LOW, LOW, LOW, LOW, LOW, LOW, LOW, //8
  LOW, LOW, LOW, LOW, HIGH, LOW, LOW, //9
};

const int button_mode = 16;
const int button_start = 18;
const int button_reset = 19;

int buttonstate;
int buttonstate_b;
int buttonstate_c;

int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;

int state1 = 0;
int state2 = 0;
int state3 = 0;

int lastButtonState1 = LOW;
int lastButtonState2 = LOW;
int lastButtonState3 = LOW;

long lastdebouncetime = 0;
long lastdebouncetime2 = 0;
long lastdebouncetime3 = 0;

long debounceDelay = 50;

int firstdigit = 0;
int seconddigit = 0;

int time_orig = 60;
long time_new = 0;
long time_old = 0;

void setup()
{
for(int i=2; i<=15; i++)
pinMode( i, OUTPUT);

pinMode(button_mode, INPUT);
pinMode(button_start, INPUT);
pinMode(button_reset, INPUT);
}

void loop() 
{

    buttonState1 = digitalRead(button_mode);
    if (buttonState1 != lastButtonState1)
    {
      lastdebouncetime = millis();
    }

    if ((millis() - lastdebouncetime > debounceDelay))
    {
      if (buttonState1 != buttonstate)
      {
        buttonstate = buttonState1;
        if (buttonstate == 1)
        {
          state1 = !state1;
        }
      }
    }
    
    if (state1 == 0)
      {
        clocks();
        if (state2 == 1)
        {
          stopwatch();
        }
        
      }
    if (state1 == 1)
      {
        stopwatch();
        stopwatch_display();
      }
   
  lastButtonState1 = buttonState1;

}

int clocks()
{
    firstdigit = ((millis() / 1000) / 10) % 6;
    seconddigit = (millis() / 1000) % 10;
    func_displayL(firstdigit);
    func_displayR(seconddigit);
}

int stopwatch()
{

    buttonState2 = digitalRead(button_start);
    if (buttonState2 != lastButtonState2)
    {
      lastdebouncetime2 = millis();
    }

    if ((millis() - lastdebouncetime2 > debounceDelay))
    {
      if (buttonState2 != buttonstate_b)
      {
        buttonstate_b = buttonState2;
        if (buttonstate_b == 1)
        {
          state2 = !state2;
        }
      }
    }

    if (state2 == 1)
    {
      time_new = millis() ;
      if (time_new - time_old >= 1000)
      {
        time_orig--; 
        time_old = time_new;
      }
    }
    

   if (state2 == 0)
   {
       buttonState3 = digitalRead(button_reset);
       if (buttonState3 != lastButtonState3)
      {
        lastdebouncetime3 = millis();
      }

      if ((millis() - lastdebouncetime3 > debounceDelay))
      {
        if (buttonState3 != buttonstate_c)
        {
          buttonstate_c = buttonState3;
          if (buttonstate_c == 1)
          {
            time_orig = 60;
          }
        }
      }
      lastButtonState3 = buttonState3;
      
   }
  
  lastButtonState2 = buttonState2;
}

int stopwatch_display()
{
   if(time_orig != 0)
   {
   func_displayL(time_orig / 10);
   func_displayR(time_orig % 10);
   }
  
   if(time_orig == 0)
   {
     state2 = 0;
     func_displayL(0);
     func_displayR(0);
   }
}

int func_displayL(int num)
{
  digitalWrite( 9, display_digit[num][0]);    //a
  digitalWrite( 10, display_digit[num][1]);   //b
  digitalWrite( 11, display_digit[num][2]);   //c
  digitalWrite( 12, display_digit[num][3]);   //d
  digitalWrite( 13, display_digit[num][4]);   //e
  digitalWrite( 14, display_digit[num][5]);   //f
  digitalWrite( 15, display_digit[num][6]);  //g
}

int func_displayR(int num)
{
  
  digitalWrite( 2, display_digit[num][0]);    //a
  digitalWrite( 3, display_digit[num][1]);   //b
  digitalWrite( 4, display_digit[num][2]);   //c
  digitalWrite( 5, display_digit[num][3]);   //d
  digitalWrite( 6, display_digit[num][4]);   //e
  digitalWrite( 8, display_digit[num][5]);   //f
  digitalWrite( 7, display_digit[num][6]);  //g
}
