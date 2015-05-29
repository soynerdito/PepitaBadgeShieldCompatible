#include "UsbKeyboard.h"

#define BUTTON_PIN 7

// If the timer isr is corrected
// to not take so long change this to 0.
#define BYPASS_TIMER_ISR 1

void doBSidesLogoArt();


void setup() {
  pinMode(BUTTON_PIN, INPUT);
  digitalWrite(BUTTON_PIN, HIGH);
  
#if BYPASS_TIMER_ISR
  // disable timer 0 overflow interrupt (used for millis)
  TIMSK0&=!(1<<TOIE0); // ++
#endif

}


#if BYPASS_TIMER_ISR
void delayMs(unsigned int ms) {
   /*
  */ 
  for (int i = 0; i < ms; i++) {
    delayMicroseconds(1000);
  }
}
#endif


void sendKeys( int keys[] )
{
  int i=0;
  while(keys[i] != 0 )
  {
    UsbKeyboard.sendKeyStroke( keys[i] );
    i++;
  }
}

void loop() {
  
  UsbKeyboard.update();

  digitalWrite(13, !digitalRead(13));

  if (digitalRead(BUTTON_PIN) == 0 /*&& done == 0*/ ) {
    doNotepadLogo();
   }

}

void doNotepadLogo()
{
  UsbKeyboard.sendKeyStroke(KEY_R,    MOD_GUI_LEFT);
    
#if BYPASS_TIMER_ISR  // check if timer isr fixed.
    delayMs(120);
#else
    delay(120);
#endif
    
    int notepad[] = {KEY_N, KEY_O, KEY_T, KEY_E, KEY_P, KEY_A, KEY_D, 0 };
    sendKeys( notepad );

    UsbKeyboard.sendKeyStroke(KEY_ENTER);

#if BYPASS_TIMER_ISR  // check if timer isr fixed.
    delayMs(2500);
#else
    delay(2500);
#endif

    int bsides_pr[] = {KEY_B, KEY_S, KEY_I, KEY_D, KEY_E, KEY_S, KEY_SPACE , KEY_P, KEY_R, 0 };
    sendKeys( bsides_pr );

    UsbKeyboard.sendKeyStroke(KEY_ENTER);
    //Do Art    
    doBSidesLogoArt();
    
#if BYPASS_TIMER_ISR  // check if timer isr fixed.
    delayMs(20);
#else
    delay(20);
#endif
    //done = 0;
}

void doBSidesLogoArt(){
	UsbKeyboard.sendKeyStroke( KEY_PERIOD );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_PERIOD );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_PERIOD );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_PERIOD );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_PERIOD );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_ENTER );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SLASH );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SLASH );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH );
	UsbKeyboard.sendKeyStroke( KEY_ENTER );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_0 , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_9 , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS );
	UsbKeyboard.sendKeyStroke( KEY_MINUS );
	UsbKeyboard.sendKeyStroke( KEY_MINUS );
	UsbKeyboard.sendKeyStroke( KEY_MINUS );
	UsbKeyboard.sendKeyStroke( KEY_TILDE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_PERIOD );
	UsbKeyboard.sendKeyStroke( KEY_MINUS );
	UsbKeyboard.sendKeyStroke( KEY_MINUS );
	UsbKeyboard.sendKeyStroke( KEY_PERIOD );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_9 , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS );
	UsbKeyboard.sendKeyStroke( KEY_MINUS );
	UsbKeyboard.sendKeyStroke( KEY_MINUS );
	UsbKeyboard.sendKeyStroke( KEY_MINUS );
	UsbKeyboard.sendKeyStroke( KEY_TILDE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_0 , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_0 , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_ENTER );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_COMMA , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SLASH );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SLASH );
	UsbKeyboard.sendKeyStroke( KEY_ENTER );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_0 , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_PERIOD );
	UsbKeyboard.sendKeyStroke( KEY_MINUS );
	UsbKeyboard.sendKeyStroke( KEY_MINUS );
	UsbKeyboard.sendKeyStroke( KEY_MINUS );
	UsbKeyboard.sendKeyStroke( KEY_MINUS );
	UsbKeyboard.sendKeyStroke( KEY_0 , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_QUOTE );
	UsbKeyboard.sendKeyStroke( KEY_MINUS );
	UsbKeyboard.sendKeyStroke( KEY_MINUS );
	UsbKeyboard.sendKeyStroke( KEY_QUOTE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_PERIOD );
	UsbKeyboard.sendKeyStroke( KEY_MINUS );
	UsbKeyboard.sendKeyStroke( KEY_MINUS );
	UsbKeyboard.sendKeyStroke( KEY_MINUS );
	UsbKeyboard.sendKeyStroke( KEY_MINUS );
	UsbKeyboard.sendKeyStroke( KEY_0 , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH );
	UsbKeyboard.sendKeyStroke( KEY_MINUS );
	UsbKeyboard.sendKeyStroke( KEY_MINUS );
	UsbKeyboard.sendKeyStroke( KEY_MINUS );
	UsbKeyboard.sendKeyStroke( KEY_MINUS );
	UsbKeyboard.sendKeyStroke( KEY_PERIOD );
	UsbKeyboard.sendKeyStroke( KEY_ENTER );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SLASH );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SLASH );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SLASH );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SLASH );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_TILDE );
	UsbKeyboard.sendKeyStroke( KEY_PERIOD );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_MINUS , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_BACKSLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_ENTER );
	UsbKeyboard.sendKeyStroke( KEY_ENTER );
	UsbKeyboard.sendKeyStroke( KEY_S );
	UsbKeyboard.sendKeyStroke( KEY_E );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_V );
	UsbKeyboard.sendKeyStroke( KEY_E );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_C );
	UsbKeyboard.sendKeyStroke( KEY_A );
	UsbKeyboard.sendKeyStroke( KEY_B );
	UsbKeyboard.sendKeyStroke( KEY_R );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_N );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_V );
	UsbKeyboard.sendKeyStroke( KEY_E );
	UsbKeyboard.sendKeyStroke( KEY_R );
	UsbKeyboard.sendKeyStroke( KEY_D );
	UsbKeyboard.sendKeyStroke( KEY_A );
	UsbKeyboard.sendKeyStroke( KEY_D );
	UsbKeyboard.sendKeyStroke( KEY_SLASH , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_ENTER );
	UsbKeyboard.sendKeyStroke( KEY_SEMICOLON , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_0 , MOD_SHIFT_LEFT );
	UsbKeyboard.sendKeyStroke( KEY_ENTER );
	UsbKeyboard.sendKeyStroke( KEY_ENTER );
	UsbKeyboard.sendKeyStroke( KEY_E );
	UsbKeyboard.sendKeyStroke( KEY_L );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_F );
	UsbKeyboard.sendKeyStroke( KEY_I );
	UsbKeyboard.sendKeyStroke( KEY_N );
	UsbKeyboard.sendKeyStroke( KEY_ENTER );
}


void onWrite(unsigned char*, unsigned char )
{
}

