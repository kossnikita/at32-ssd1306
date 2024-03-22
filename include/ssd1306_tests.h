#ifndef SSD1306_TESTS_H
#define SSD1306_TESTS_H

#include <_ansi.h>

_BEGIN_STD_C

void ssd1306_TestBorder(void);
void ssd1306_TestFonts1(void);
void ssd1306_TestFonts2(void);
void ssd1306_TestFPS(void);
void ssd1306_TestAll(void);
void ssd1306_TestLine(void);
void ssd1306_TestRectangle(void);
void ssd1306_TestRectangleFill();
void ssd1306_TestCircle(void);
void ssd1306_TestArc(void);
void ssd1306_TestPolyline(void);
void ssd1306_TestDrawBitmap(void);

_END_STD_C

#endif /* SSD1306_TESTS_H */
