SKETCH=snake
BOARD_TYPE=arduino:avr:mega
SERIAL_PORT=$(shell arduino-cli --format json board list | jq -r '.[] | select(.matching_boards[0].fqbn == "$(BOARD_TYPE)") | .port.address')

.PHONY: all compile upload

all: compile upload

compile:
	arduino-cli compile -b $(BOARD_TYPE) $(SKETCH)

upload:
	arduino-cli upload -v -p $(SERIAL_PORT) --fqbn $(BOARD_TYPE) $(SKETCH)

monitor: all
	stty -f $(SERIAL_PORT) raw 115200
	cat $(SERIAL_PORT)

debug_serial_port:
	echo '$(SERIAL_PORT)'
