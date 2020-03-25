#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

char toggle_red()		/* always toggle! */
{
  static char state = 0;

  switch (state) {
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }
  return 1;			/* always changes an led */
}

char toggle_green()	/* only toggle green if red is on!  */
{
  char changed = 0;
  if (red_on) {
    green_on ^= 1;
    changed = 1;
  }
  return changed;
}


void state_advance()		/* alternate between toggling red & green */
{
  char changed = 0;  

  static enum {R, G, O, B, O2} color = G;
  switch (color) {
    //case R: changed = toggle_red(); color = G; break;
    //case G: changed = toggle_green(); color = R; break;
  case G: changed =1; green_on = 0; red_on=1; color = R; break;
  case R: changed =1; green_on =1; red_on=0; color = O; break;
  case O: changed =1; green_on=0; red_on=0; color=B; break;
  case B: changed =1; green_on=1; red_on=1; color=O2; break;
  case O2: changed =1; green_on=0; red_on=0; color=G; break;
  }

  led_changed = changed;
  led_update();
}



