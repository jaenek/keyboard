FIRMWARE = firmware.hex

upload:
	@avrdude -c avr109 -p atmega32u4 -P /dev/ttyACM0 -U flash:w:$(FIRMWARE):i
