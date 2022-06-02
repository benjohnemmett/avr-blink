F_CPU=8000000
CC=avr-g++
MCU=atmega328p

OBJS =  

.PHONY: all
all: blink.hex

flash: blink.hex
	avrdude -p m328p -c usbasp -U flash:w:blink.hex:i

blink.hex: blink.o $(OBJS)
	$(CC) -mmcu=$(MCU) $(OBJS) blink.o -o blink.elf
	avr-objcopy -j .text -j .data -O ihex blink.elf blink.hex

%.o: %.cpp
	$(CC) -Os -mmcu=$(MCU) -c $< -o $@ -DF_CPU=$(F_CPU)

.PHONY: clean
clean:
	rm -f *.elf *.o *.obj  *.hex
