#pragma once

#include <Arduino.h>

#define LOG_LEVEL_OFF 2
#define LOG_LEVEL_ERROR 1
#define LOG_LEVEL_INFO 0

#define LOG_LEVEL LOG_LEVEL_INFO

#if LOG_LEVEL == LOG_LEVEL_OFF
#define LOG_OFF
#else
#define LOG_ON
#endif

void log_init();
void log_info(const char *message);
void log_info(const ArduinoFlashStringHelper *message);
void log_error(const char *message);
void log_error(const ArduinoFlashStringHelper *message);
char *get_log_buffer();
