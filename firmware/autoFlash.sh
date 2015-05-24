#!/bin/bash
CONNECTED=0
for (( ; ; ))
do	
	if [ -e '/dev/ttyACM0' ]; 
	then
		if [ $CONNECTED -eq 0 ];
		then
			CONNECTED=1
			echo "Device connected, wait for 5 seconds"
			sleep 3
			#Using Arduino as an ISP
			avrdude -c stk500v1 -b 19200 -p atmega328p -P /dev/ttyACM0 -U flash:w:mega32p_16mhz_program_on_reset.hex
			avrdude -c stk500v1 -p atmega328p -b19200 -P /dev/ttyACM0 -U lfuse:w:0xf7:m -U hfuse:w:0xdA:m -U efuse:w:0x03:m			
			echo "You may disconnect board now"
		fi
	else		
		CONNECTED=0
		echo "Connect Next one please!"
	fi
done
