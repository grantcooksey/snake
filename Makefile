SKETCH=snake
BOARD_TYPE=arduino:avr:mega
SERIAL_PORT=$(shell arduino-cli --format json board list | jq -r '.[] | select(.matching_boards[0].fqbn == "$(BOARD_TYPE)") | .port.address')
BUILD_DIR=build
SRC_DIR=snake
TEST_DIR=tests
SRC_SOURCES=$(shell find $(SRC_DIR) -type f -name "*.cpp" -o -name "*.ino" -o -name "*.h" -o -name "*.c")
TEST_SOURCES=$(shell find $(TEST_DIR) -type f -name "*.cpp" -o -name "*.ino" -o -name "*.h" -o -name "*.c")

.PHONY: all compile upload test clean format check debug_serial_port

all: compile upload

install-arduino:
	arduino-cli core install "arduino:avr" "arduino:megaavr"
	arduino-cli lib install "Adafruit GFX Library@1.11.1"  "Adafruit ST7735 and ST7789 Library@1.10.0"

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
	clang-format -i $(SRC_SOURCES) $(TEST_SOURCES)

check:
	clang-tidy $(CPPFLAGS) -p $(BUILD_DIR) $(SRC_SOURCES)

debug_serial_port:
	echo '$(SERIAL_PORT)'
