#include <msp430.h>
#include "buzzer.h"
#include "notes.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){
  static char blink_count = 0;
  if (++blink_count ==125){
    state_advance();
    blink_count = 0;
  }
}
