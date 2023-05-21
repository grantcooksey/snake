#include "logger.h"

#include <Arduino.h>

#define SERIAL_BAUD_RATE 9600

char buffer[60];

// The F functions and __FlashStringHelper aren't always supported, so we may
// need to tweak this. See
// https://github.com/arduino/ArduinoCore-megaavr/issues/62

void log_generic(const char *message, short level);
void log_generic(const __FlashStringHelper *message, short level);

#if LOG_LEVEL != LOG_LEVEL_OFF
void log_init() {
  if (LOG_LEVEL <= LOG_LEVEL_OFF) {
    Serial.begin(9600);
  }
}

void log_generic(const char *message, short level) {
  if (LOG_LEVEL <= level) {
    Serial.println(message);
  }
}

void log_generic(const __FlashStringHelper *message, short level) {
  if (LOG_LEVEL <= level) {
    Serial.println(message);
  }
}
#else
void log_init() {}
void log_generic(const char *message, short level) {}
void log_generic(const __FlashStringHelper *message, short level) {}
#endif

void log_info(const char *message) { log_generic(message, LOG_LEVEL_INFO); }
void log_info(const __FlashStringHelper *message) {
  log_generic(message, LOG_LEVEL_INFO);
}

void log_error(const char *message) { log_generic(message, LOG_LEVEL_ERROR); }
void log_error(const __FlashStringHelper *message) {
  log_generic(message, LOG_LEVEL_ERROR);
}

char *get_log_buffer() { return buffer; }
