#include <msp430.h>
#include "states.h"
#include "led.h"

void state_advance(){
  char changed = 0;

  static enum {R, G, O, B, O2} currState = G;
  switch(currState){
  case G: changed = 1; green_on = 0; red_on = 1; currState = R; break;
  case R: changed = 1; green_on = 1; red_on = 0; currState = O; break;
  case O: changed = 1; green_on = 0; red_on = 0; currState = B; break;
  case B: changed = 1; green_on = 1; red_on = 1; currState = O2; break;
  case O2: changed = 1; green_on = 0; red_on = 0; currState = G; break;
  }
  led_changed = changed;
  led_update();
}

