#include "display.h"

#include <Adafruit_GFX.h>     // Core graphics library
#include <Adafruit_ST7735.h>  // Hardware-specific library for ST7735
// #include <Adafruit_ST7789.h>  // Hardware-specific library for ST7789, do we
// need to support this?
#include <SPI.h>
#include <stdint.h>
#include <stdio.h>

#include "logger.h"
#include "pins.h"

// Dependent tft flags
#define INIT_FLAG INITR_144GREENTAB
#define COLOR_BLACK ST7735_BLACK
#define COLOR_WHITE ST7735_WHITE

Adafruit_ST7735 tft = Adafruit_ST7735(DISPLAY_CS, DISPLAY_DC, DISPLAY_RST);

bounds display_bounds = {0};

void display_init() {
  tft.initR(INIT_FLAG);
  display_bounds = {
      .width = tft.width(),
      .height = tft.height(),
  };

  char* log_buffer = get_log_buffer();
  sprintf(log_buffer, "Init display { height: %d, width: %d }",
          display_bounds.height, display_bounds.width);
  log_info(log_buffer);
}

void display_clear() {
  log_info(F("Clearing display"));
  tft.fillScreen(COLOR_BLACK);
}

bounds display_get_bounds() { return display_bounds; }

void display_fill_rect(display_position point, bounds snake_bounds) {
  tft.fillRect(point.x, point.y, snake_bounds.width, snake_bounds.height,
               COLOR_WHITE);
}
