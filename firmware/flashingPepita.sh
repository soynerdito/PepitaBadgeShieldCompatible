#Badge flashing procedure
#Flashing firmware
avrdude -c usbasp -b 19200 -p atmega328p -P /dev/ttyACM0 -U flash:w:mega32p_16mhz_program_on_reset.hex

#Burnning Fuses
avrdude -c usbasp -p atmega328p -b19200 -P /dev/ttyACM0 -U lfuse:w:0xf7:m -U hfuse:w:0xdA:m -U efuse:w:0x03:m


#Note
#Fuses may be set for 5V even though the board runs at 3.3V but in my testing it is working the same.

#Using Arduino as an ISP
avrdude -c stk500v1 -b 19200 -p atmega328p -P /dev/ttyACM0 -U flash:w:mega32p_16mhz_program_on_reset.hex
avrdude -c stk500v1 -p atmega328p -b19200 -P /dev/ttyACM0 -U lfuse:w:0xf7:m -U hfuse:w:0xdA:m -U efuse:w:0x03:m
