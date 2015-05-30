# PepitaBadgeShieldCompatible
BSides Badge (codename Pepita). Arduino shield compatible.

To program board use an external USBAS at 5V. Connect 5V input voltage via the pin that says 3.3V to send 5V straight to the  atmega chip. If input voltage goes to the input pin it will go through the 3.3V regulator and in my first test it didn't allowed me to program the chip.

#Configure Arduino IDE 1.6.4
Step 1:
File->Preferences
 Paste in "Additional Boards Manager URLS:" https://github.com/soynerdito/PepitaBadgeShieldCompatible/raw/master/Arduino/IDE_Board_Manager/package_bsidespr_index.json
Click OK

Step 2:
Tools->Boards->Boards Manager
	Select BSides Badge from list and click Install

Step 3: Activate the board
Tools->Boads
	Select BSides Badge 2015 from the available boards
	
Step 4: Set the programmer
Tools->Programmer
	Select USBasp


# Flashing firmware
avrdude -c usbasp -b 19200 -p atmega328p -P /dev/ttyACM0 -U flash:w:mega32p_16mhz_program_on_reset.hex

#Fuses
avrdude -c usbasp -p atmega328p -b19200 -P /dev/ttyACM0 -U lfuse:w:0xf7:m -U hfuse:w:0xdA:m -U efuse:w:0x03:m
