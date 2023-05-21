#include <Arduino.h>

#include "display.h"
#include "logger.h"

void bootstrap() {
  log_init();

  log_info(F("Starting snake"));

  display_init();
}
