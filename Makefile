SKETCH=snake
BOARD_TYPE=arduino:avr:mega
SERIAL_PORT=$(shell arduino-cli --format json board list | jq -r '.[] | select(.matching_boards[0].fqbn == "$(BOARD_TYPE)") | .port.address')
BUILD_DIR=build

.PHONY: all compile upload test clean format debug_serial_port

all: compile upload

compile:
	arduino-cli compile --build-path $(BUILD_DIR) -b $(BOARD_TYPE) $(SKETCH)

upload:
	arduino-cli upload -v --input-dir $(BUILD_DIR) -p $(SERIAL_PORT) --fqbn $(BOARD_TYPE) $(SKETCH)

monitor: all
	stty -f $(SERIAL_PORT) raw 115200
	cat $(SERIAL_PORT)

test:
	$(MAKE) -C tests
	$(MAKE) -C tests lcov

ci-test: export CI=true
ci-test: test

clean:
	$(MAKE) -C tests clean

format:
	clang-format -i **/*.h **/*.ino **/*.c **/*.cpp

debug_serial_port:
	echo '$(SERIAL_PORT)'
