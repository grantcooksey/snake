#include <Adafruit_GFX.h>     // Core graphics library
#include <Adafruit_ST7735.h>  // Hardware-specific library for ST7735
#include <Adafruit_ST7789.h>  // Hardware-specific library for ST7789
#include <SPI.h>

#define TFT_CS 10
#define TFT_RST 9
#define TFT_DC 8

#define X_CURSOR 30
#define SPEED_ANALOG_PIN A8
#define SPEED_MIN 500
#define SPEED_MAX 30

const char* MESSAGE = "yo";

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

uint8_t y = 30;
int16_t textWidth;
int16_t textHeight;

void printDebug(int16_t x, int16_t y, int16_t width, int16_t height);
unsigned long scaleToSpeed(int unscaled, int maxAllowed, int minAllowed,
                           int unscaledMax, int unscaledMin);
void fastResetScreen(uint8_t currentY, int16_t width, int16_t height);
uint8_t newY(uint8_t oldY);

void setup(void) {
  Serial.begin(9600);
  Serial.println(F("Starting ball demo"));
  tft.initR(INITR_144GREENTAB);
  Serial.print(F("Initialized with height "));
  Serial.print(tft.height());
  Serial.print(F(" and width "));
  Serial.println(tft.width());

  tft.fillScreen(ST7735_BLACK);

  int16_t x1;
  int16_t y1;
  Serial.println(F("Setting up text bounds"));
  tft.getTextBounds(MESSAGE, (int16_t)0, (int16_t)0, &x1, &y1, &textWidth,
                    &textHeight);
  Serial.print(F("x1 "));
  Serial.println(x1);
  Serial.print(F("y1 "));
  Serial.println(y1);
  Serial.print(F("w "));
  Serial.println(textWidth);
  Serial.print(F("h "));
  Serial.println(textHeight);

  tft.setTextColor(ST77XX_CYAN);
  tft.setTextWrap(true);

  analogReference(EXTERNAL);
}

void loop() {
  unsigned long delayMillis = 100;
  while (true) {
    tft.setCursor(X_CURSOR, y);
    tft.print(MESSAGE);

    delay(delayMillis);
    int newSpeed = analogRead(SPEED_ANALOG_PIN);
    delayMillis = scaleToSpeed(newSpeed, SPEED_MIN, SPEED_MAX, 1023, 0);

    // printDebug(X_CURSOR, y, textWidth, textHeight);
    fastResetScreen(y, textWidth, textHeight);
    y = newY(y);
  }
}

unsigned long scaleToSpeed(int unscaled, int maxAllowed, int minAllowed,
                           int unscaledMax, int unscaledMin) {
  uint16_t maxRange = (maxAllowed - minAllowed);          // 470
  uint16_t unscaledwithRange = (unscaled - unscaledMin);  // analog read
  uint32_t numerator = maxRange * unscaledwithRange;
  int denominator = unscaledMax - unscaledMin;
  int divided = numerator / denominator;
  int newScale = divided + minAllowed;

  // char buffer[60];
  // sprintf(
  //     buffer,
  //     "unscaled %i, newScale %d ----- %lu / %ld + %d =  %d + %d = %d",
  //     unscaled,
  //     newScale,
  //     numerator,
  //     denominator,
  //     minAllowed,
  //     divided,
  //     minAllowed,
  //     newScale
  // );
  // Serial.println(buffer);
  // sprintf(
  //     buffer,
  //     "%lu * %i = %lu",
  //     maxRange,
  //     unscaledwithRange,
  //     numerator
  // );
  // Serial.println(buffer);

  return newScale;
}

void fastResetScreen(uint8_t currentY, int16_t width, int16_t height) {
  tft.fillRect(X_CURSOR, currentY, width, height, ST7735_BLACK);
  // tft.fillScreen(ST7735_BLACK);  this is pretty slow, lots of flickering
}

uint8_t newY(uint8_t oldY) {
  if (oldY > 0) {
    oldY--;
  } else {
    oldY = 100;
  }
  return oldY;
}

void printDebug(int16_t x, int16_t y, int16_t width, int16_t height) {
  Serial.print(F("x: "));
  Serial.print(x);

  Serial.print(F(", y: "));
  Serial.print(y);

  Serial.print(F(", w: "));
  Serial.print(width);

  Serial.print(F(", h: "));
  Serial.println(height);
}
