FQBN ?= arduino:avr:micro
PORT ?= /dev/ttyACM0
BAUD ?= 115200
STTY ?= cs8 ignbrk -brkint -imaxbel -opost -onlcr -isig -icanon -iexten \
	-echo -echoe -echok -echoctl -echoke noflsh -ixon -crtscts

all: compile upload terminal

clean:
	@echo cleaning
	-rm *$(subst :,.,.$(FQBN).)*

compile:
	@arduino-cli compile -b $(FQBN)

upload:
	@arduino-cli upload -b $(FQBN) -p $(PORT)

terminal:
	@stty -F $(PORT) $(BAUD) $(STTY)
	@tail -f $(PORT)
