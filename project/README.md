## Lights

The red and green light go through the states green on, red on, both off, both
on, both off, then green on with the watch dog timer. The lights cycle through
the states every 125th of a second.

## Buttons

switch | function
------ | --------
Button1| uses states to cycle through 2 different sounds.
Button2|
Button3| plays song1
Button4| plays song2

## states.c
Uses enumerations and switch statement to toggle lights to their different
states of on and off with the watch dog timer. There are 5 states, the first
state is the green light on red light off. 2nd state is the red light on green
off. 3rd state is both lights off. 4th states is both lights on. 5th state is
both lights off again. Then the cycle repeats to the green light on again
(state 1).

## switches.c
Senses when the switch goes down then plays a song. Interrupt sense detects
if there was an iterrupt that occurs from the bits P2.0 - P2.3. Switch
interrupt handler can take the value from interrupt sense and compare it the
P2.0-P2.3 bits to detect what switch caused the interrupt to occur. In the
handler, the if statements are used to perform the action based on the switch
pressed, this is just determining what song/notes are played. 

## notes.h
notes.h is used to define the notes and periods assigned to the notes. In
switches.c int arrays are difined using the notes, these int arrays correspond
to songs. In the if statements of the switch interrupt handler these int
arrays are itterated through passing each note to buzzer set period to play
the note on the speaker. Delay cycles is used to increase the amount of time a
note is played (in other words delays the notes to run at nMHZ). 
