# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as -mcpu=msp430 --traditional-format -mP

all: button.elf 

#additional rules for files
button.elf: ${COMMON_OBJECTS} assembly.o p2_interrupt_handler.o wdInterruptHandler.o switches.o states.o led.o buzzer.o main.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: button.elf
	msp430loader.sh button.elf

clean:
	rm -f *.o *.elf *~ *#

main.c: buzzer.h switches.h

buzzer.c: buzzer.h notes.h

led.o: led.c led.h

states: states.c states.h

wdInterruptHandler.o: states.h

assembly.o: assembly.s assembly.h
