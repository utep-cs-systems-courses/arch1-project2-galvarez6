#include <msp430.h>
#include "switches.h"
#include "buzzer.h"
#include "notes.h"

char switch_state_down, switch_state_changed; /* effectively boolean */
int song_1[]={F4, A4, B4, F4, A4, B4, F4, A4, B4, E4, D4, C4, B4, C4, G4, E4, D4, D4, E4, G4};
int song_2[]={B4, E4, G4, B4, E4, G4, E4, D4, Dflat, A4, G4, A4, B4, E4, D4, G4, E4};

static char 
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

void 
switch_init()			/* setup switch */
{  
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE |= SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
  //led_update();
}

void
switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  char btn1down = (p2val & SW1) ? 0 : 1; /* 0 when SW1 is up */
  char btn2down = (p2val & SW2) ? 0 : 1;
  char btn3down = (p2val & SW3) ? 0 : 1;
  char btn4down = (p2val & SW4) ? 0 : 1;

  
  if(btn1down){
    buzzer_set_period(10000);
  }
  if(btn2down){
    buzzer_set_period(50000);
  }
  if(btn3down){
    for(int i = 0; i < 20; i++){
      buzzer_set_period(song_1[i]);
      __delay_cycles(6000000);
    }
    buzzer_set_period(0);
  }
  if(btn4down){
    for(int i = 0; i < 17; i++){
      buzzer_set_period(song_2[i]);
      __delay_cycles(1000000);
    }
    buzzer_set_period(0);
  }

  //switch_state_changed = 1;
  //led_update();
}
