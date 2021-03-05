#include  <Adafruit_GFX.h>
#include  <SPI.h>
#include  <Wire.h>
#include  <Adafruit_ILI9341.h>
#include  <Adafruit_FT6206.h>

Adafruit_FT6206 ts = Adafruit_FT6206();

#define TFT_CS 10
#define TFT_DC 9
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

int menuPage;
float h = 0.00000;

void setup()
{
  Serial.begin(9600);
  tft.begin();
  if (!ts.begin(40)) { 
    Serial.println("Unable to start touchscreen.");
  } 
  else { 
    Serial.println("Touchscreen started."); 
  }
  tft.fillScreen(ILI9341_BLACK);
  tft.setRotation(1);
  menuPage = 0;
}

void loop()
{
  if (ts.touched())
  {
    if (menuPage == 0)
    {
      drawBegin();
      back0:
      TS_Point p = ts.getPoint();
      p.x = map(p.x, 0, 240, 240, 0);
      p.y = map(p.y, 0, 320, 320, 0);
      int y = tft.height() - p.x;
      int x = p.y;
      if ((x > 40) && (x < 290))
      {
        if ((y > 70) && (y < 170))
        {
          Serial.println("Begin Pressed");
          delay(100);
          menuPage = 1;
          tft.fillRect(40, 70, 250, 100, ILI9341_GREEN);
          tft.drawRect(40, 70, 250, 100, ILI9341_WHITE);
          tft.setCursor(110, 105);
          tft.setTextColor(ILI9341_WHITE);
          tft.setTextSize(4);
          tft.print("Begin");
        }
      }
      else goto back0;
    }

    if (menuPage == 1)
    {
      back1:
      drawZero();
      back2:
      TS_Point p = ts.getPoint();
      p.x = map(p.x, 0, 240, 240, 0);
      p.y = map(p.y, 0, 320, 320, 0);
      int y = tft.height() - p.x;
      int x = p.y;
      if ((x > 40) && (x < 290))
      {
        if ((y > 70) && (y < 170))
        {
          Serial.println("Zero Pressed");
          delay(100);
          menuPage = 2;
          tft.fillRect(40, 70, 250, 100, ILI9341_GREEN);
          tft.drawRect(40, 70, 250, 100, ILI9341_WHITE);
          tft.setCursor(110, 105);
          tft.setTextColor(ILI9341_WHITE);
          tft.setTextSize(4);
          tft.print("Zero");
        }
      }
      else goto back2;
    }
    
    if (menuPage == 2)
    {
      drawSelect();
      back3:
      TS_Point p = ts.getPoint();
      p.x = map(p.x, 0, 240, 240, 0);
      p.y = map(p.y, 0, 320, 320, 0);
      int y = tft.height() - p.x;
      int x = p.y;
      if ((x > 40) && (x < 290))
      {
        if ((y > 70) && (y < 170))
        {
          Serial.println("Select Height Pressed");
          delay(100);
          menuPage = 3;
          tft.fillRect(40, 70, 250, 100, ILI9341_GREEN);
          tft.drawRect(40, 70, 250, 100, ILI9341_WHITE);
          tft.setCursor(50, 110);
          tft.setTextColor(ILI9341_WHITE);
          tft.setTextSize(3);
          tft.print("Select Height");
        }
      }
      else goto back3;
    }
    
    if (menuPage == 3)
    {
      drawHeight();
      back4:
      TS_Point p = ts.getPoint();
      p.x = map(p.x, 0, 240, 240, 0);
      p.y = map(p.y, 0, 320, 320, 0);
      int y = tft.height() - p.x;
      int x = p.y;
      if ((y > 0) && (y < 120))
      {
        if ((x > 0) && (x < 106))
        {
          Serial.println("1in Pressed");
          delay(100);
          h = 1.00000;
          menuPage = 4;
          tft.fillRect(0, 0, 106, 120, ILI9341_GREEN);
          tft.drawRect(0, 0, 106, 120, ILI9341_WHITE);
          tft.setCursor(30, 55);
          tft.setTextColor(ILI9341_WHITE);
          tft.setTextSize(2);
          tft.print("1 in");
        }
        else if ((x > 106) && (x < 212))
        {
          Serial.println("2in Pressed");
          delay(100);
          h = 2.00000;
          menuPage = 4;
          tft.fillRect(106, 0, 106, 120, ILI9341_GREEN);
          tft.drawRect(106, 0, 106, 120, ILI9341_WHITE);
          tft.setCursor(137, 55);
          tft.setTextColor(ILI9341_WHITE);
          tft.setTextSize(2);
          tft.print("2 in");
        }
        else if ((x > 212) && (x < 318))
        {
          Serial.println("3in Pressed");
          delay(100);
          h = 3.00000;
          menuPage = 4;
          tft.fillRect(212, 0, 106, 120, ILI9341_GREEN);
          tft.drawRect(212, 0, 106, 120, ILI9341_WHITE);
          tft.setCursor(245, 55);
          tft.setTextColor(ILI9341_WHITE);
          tft.setTextSize(2);
          tft.print("3 in");
        }
      }
      else if ((y > 120) && (y < 240))
      {
        if ((x > 0) && (x < 106))
        {
          Serial.println("4in Pressed");
          delay(100);
          h = 4.00000;
          menuPage = 4;
          tft.fillRect(0, 120, 106, 120, ILI9341_GREEN);
          tft.drawRect(0, 120, 106, 120, ILI9341_WHITE);
          tft.setCursor(30, 175);
          tft.setTextColor(ILI9341_WHITE);
          tft.setTextSize(2);
          tft.print("4 in");
        }
        else if ((x > 106) && (x < 212))
        {
          Serial.println("5in Pressed");
          delay(100);
          h = 5.00000;
          menuPage = 4;
          tft.fillRect(106, 120, 106, 120, ILI9341_GREEN);
          tft.drawRect(106, 120, 106, 120, ILI9341_WHITE);
          tft.setCursor(137, 175);
          tft.setTextColor(ILI9341_WHITE);
          tft.setTextSize(2);
          tft.print("5 in");
        }
        else if ((x > 212) && (x < 318))
        {
          Serial.println("6in Pressed");
          delay(100);
          h = 6.00000;
          menuPage = 5;
          tft.fillRect(212, 120, 106, 120, ILI9341_GREEN);
          tft.drawRect(212, 120, 106, 120, ILI9341_WHITE);
          tft.setCursor(245, 175);
          tft.setTextColor(ILI9341_WHITE);
          tft.setTextSize(2);
          tft.print("6 in");
        }
      }
      else goto back4;
    }
    
    if (menuPage == 4)
    {
      drawFraction();
      back5:
      TS_Point p = ts.getPoint();
      p.x = map(p.x, 0, 240, 240, 0);
      p.y = map(p.y, 0, 320, 320, 0);
      int y = tft.height() - p.x;
      int x = p.y;
      if ((y > 0) && (y < 120))
      {
        if ((x > 0) && (x < 106))
        {
          Serial.println(".00in Pressed");
          delay(100);
          h += 0.00000;
          menuPage = 5;
          tft.fillRect(0, 0, 106, 120, ILI9341_GREEN);
          tft.drawRect(0, 0, 106, 120, ILI9341_WHITE);
          tft.setCursor(15, 55);
          tft.setTextColor(ILI9341_WHITE);
          tft.setTextSize(2);
          tft.print(".00 in");
        }
        else if ((x > 106) && (x < 212))
        {
          Serial.println(".25in Pressed");
          delay(100);
          h += 0.25000;
          menuPage = 5;
          tft.fillRect(106, 0, 106, 120, ILI9341_GREEN);
          tft.drawRect(106, 0, 106, 120, ILI9341_WHITE);
          tft.setCursor(122, 55);
          tft.setTextColor(ILI9341_WHITE);
          tft.setTextSize(2);
          tft.print(".25 in");
        }
        else if ((x > 212) && (x < 318))
        {
          Serial.println(".50in Pressed");
          delay(100);
          h += 0.50000;
          menuPage = 5;
          tft.fillRect(212, 0, 106, 120, ILI9341_GREEN);
          tft.drawRect(212, 0, 106, 120, ILI9341_WHITE);
          tft.setCursor(230, 55);
          tft.setTextColor(ILI9341_WHITE);
          tft.setTextSize(2);
          tft.print(".5 in");
        }
      }
      else if ((y > 120) && (y < 240))
      {
        if ((x > 0) && (x < 106))
        {
          Serial.println(".75in Pressed");
          delay(100);
          h += 0.75000;
          menuPage = 5;
          tft.fillRect(0, 120, 106, 120, ILI9341_GREEN);
          tft.drawRect(0, 120, 106, 120, ILI9341_WHITE);
          tft.setCursor(15, 175);
          tft.setTextColor(ILI9341_WHITE);
          tft.setTextSize(2);
          tft.print(".75 in");
        }
      }
      else goto back5;
    }
    
    if (menuPage == 5)
    {
      back6:
      drawReadout();
      back7:
      TS_Point p = ts.getPoint();
      p.x = map(p.x, 0, 240, 240, 0);
      p.y = map(p.y, 0, 320, 320, 0);
      int y = tft.height() - p.x;
      int x = p.y;
      if ((y > 0) && (y < 120))
      {
        if ((x > 0) && (x < 106))
        {
          Serial.println("-1/32 Pressed");
          delay(100);
          h -= 0.03125;
          tft.fillRect(0, 0, 106, 120, ILI9341_RED);
          tft.drawRect(0, 0, 106, 120, ILI9341_WHITE);
          tft.setCursor(5, 55);
          tft.setTextColor(ILI9341_WHITE);
          tft.setTextSize(2);
          tft.print("-1/32 in");
          goto back6;
        }
        else if ((x > 212) && (x < 318))
        {
          Serial.println("+.25 Pressed");
          delay(100);
          h += .25000;
          tft.fillRect(212, 0, 106, 120, ILI9341_GREEN);
          tft.drawRect(212, 0, 106, 120, ILI9341_WHITE);
          tft.setCursor(225, 55);
          tft.setTextColor(ILI9341_WHITE);
          tft.setTextSize(2);
          tft.print("+.25 in");
          goto back6;
        }
      }
      else if ((y > 120) && (y < 240))
      {
        if ((x >0) && (x < 106))
        {
          Serial.println("-1/64 Pressed");
          delay(100);
          h -= 0.015625;
          tft.fillRect(0, 120, 106, 120, ILI9341_RED);
          tft.drawRect(0, 120, 106, 120, ILI9341_WHITE);
          tft.setCursor(5, 175);
          tft.setTextColor(ILI9341_WHITE);
          tft.setTextSize(2);
          tft.print("-1/64 in");
          goto back6;
        }
        else if ((x > 106) && (x < 212))
        {
          Serial.println("Zero Pressed");
          delay(100);
          menuPage = 6;
          tft.fillRect(106, 120, 106, 120, ILI9341_YELLOW);
          tft.drawRect(106, 120, 106, 120, ILI9341_WHITE);
          tft.setCursor(135, 175);
          tft.setTextColor(ILI9341_WHITE);
          tft.setTextSize(2);
          tft.print("ZERO");
        }
        else if ((x > 212) && (x < 318))
        {
          Serial.println("+.5 Pressed");
          delay(100);
          h += 0.50000;
          tft.fillRect(212, 120, 106, 120, ILI9341_GREEN);
          tft.drawRect(212, 120, 106, 120, ILI9341_WHITE);
          tft.setCursor(225, 175);
          tft.setTextColor(ILI9341_WHITE);
          tft.setTextSize(2);
          tft.print("+.50 in");
          goto back6;
        }
      }
      else goto back7;
    }

    if (menuPage == 6)
    {
      drawSure();
      back8:
      TS_Point p = ts.getPoint();
      p.x = map(p.x, 0, 240, 240, 0);
      p.y = map(p.y, 0, 320, 320, 0);
      int y = tft.height() - p.x;
      int x = p.y;
      if ((y > 120) && (y < 240))
      {
        if ((x > 0) && (x < 106))
        {
          Serial.println("No Pressed");
          delay(100);
          menuPage = 5;
          tft.fillRect(0, 160, 106, 160, ILI9341_RED);
          tft.drawRect(0, 160, 106, 160, ILI9341_WHITE);
          tft.setCursor(35, 190);
          tft.setTextColor(ILI9341_WHITE);
          tft.setTextSize(3);
          tft.print("No");
          goto back6;
        }
        else if ((x > 212) && (x < 318))
        {
          Serial.println("Yes Pressed");
          delay(100);
          menuPage = 1;
          tft.fillRect(212, 160, 106, 160, ILI9341_GREEN);
          tft.drawRect(212, 160, 106, 160, ILI9341_WHITE);
          tft.setCursor(240, 190);
          tft.setTextColor(ILI9341_WHITE);
          tft.setTextSize(3);
          tft.print("Yes");
          goto back1;
        }
      }
      else goto back8;
    }
  }
}

void drawBegin()
{
  tft.fillScreen(ILI9341_BLACK);
  tft.fillRect(40, 70, 250, 100, ILI9341_RED);
  tft.drawRect(40, 70, 250, 100, ILI9341_WHITE);
  tft.setCursor(110, 105);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(4);
  tft.print("Begin");
}

void drawZero()
{
  tft.fillScreen(ILI9341_BLACK);
  tft.fillRect(40, 70, 250, 100, ILI9341_RED);
  tft.drawRect(40, 70, 250, 100, ILI9341_WHITE);
  tft.setCursor(110, 105);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(4);
  tft.print("Zero");
}

void drawSelect()
{
  tft.fillScreen(ILI9341_BLACK);
  tft.fillRect(40, 70, 250, 100, ILI9341_RED);
  tft.drawRect(40, 70, 250, 100, ILI9341_WHITE);
  tft.setCursor(50, 110);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(3);
  tft.print("Select Height");
}

void drawHeight()
{
  tft.fillScreen(ILI9341_BLACK);
  tft.fillRect(0, 0, 106, 120, ILI9341_RED);
  tft.drawRect(0, 0, 106, 120, ILI9341_WHITE);
  tft.setCursor(30, 55);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.print("1 in");
  tft.fillRect(106, 0, 106, 120, ILI9341_RED);
  tft.drawRect(106, 0, 106, 120, ILI9341_WHITE);
  tft.setCursor(137, 55);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.print("2 in");
  tft.fillRect(212, 0, 106, 120, ILI9341_RED);
  tft.drawRect(212, 0, 106, 120, ILI9341_WHITE);
  tft.setCursor(245, 55);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.print("3 in");
  tft.fillRect(0, 120, 106, 120, ILI9341_RED);
  tft.drawRect(0, 120, 106, 120, ILI9341_WHITE);
  tft.setCursor(30, 175);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.print("4 in");
  tft.fillRect(106, 120, 106, 120, ILI9341_RED);
  tft.drawRect(106, 120, 106, 120, ILI9341_WHITE);
  tft.setCursor(137, 175);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.print("5 in");
  tft.fillRect(212, 120, 106, 120, ILI9341_RED);
  tft.drawRect(212, 120, 106, 120, ILI9341_WHITE);
  tft.setCursor(245, 175);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.print("6 in");
}

void drawFraction()
{
  tft.fillScreen(ILI9341_BLACK);
  tft.fillRect(0, 0, 106, 120, ILI9341_RED);
  tft.drawRect(0, 0, 106, 120, ILI9341_WHITE);
  tft.setCursor(15, 55);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.print(".00 in");
  tft.fillRect(106, 0, 106, 120, ILI9341_RED);
  tft.drawRect(106, 0, 106, 120, ILI9341_WHITE);
  tft.setCursor(122, 55);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.print(".25 in");
  tft.fillRect(212, 0, 106, 120, ILI9341_RED);
  tft.drawRect(212, 0, 106, 120, ILI9341_WHITE);
  tft.setCursor(230, 55);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.print(".5 in");
  tft.fillRect(0, 120, 106, 120, ILI9341_RED);
  tft.drawRect(0, 120, 106, 120, ILI9341_WHITE);
  tft.setCursor(15, 175);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.print(".75 in");
}

void drawReadout()
{
  tft.fillScreen(ILI9341_BLACK);
  tft.fillRect(0, 0, 106, 120, ILI9341_GREEN);
  tft.drawRect(0, 0, 106, 120, ILI9341_WHITE);
  tft.setCursor(5, 55);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.print("-1/32 in");
  tft.fillRect(106, 0, 106, 120, ILI9341_BLACK);
  tft.drawRect(106, 0, 106, 120, ILI9341_WHITE);
  tft.setCursor(122, 55);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.print(h, 5);
  tft.fillRect(212, 0, 106, 120, ILI9341_RED);
  tft.drawRect(212, 0, 106, 120, ILI9341_WHITE);
  tft.setCursor(225, 55);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.print("+.25 in");
  tft.fillRect(0, 120, 106, 120, ILI9341_GREEN);
  tft.drawRect(0, 120, 106, 120, ILI9341_WHITE);
  tft.setCursor(5, 175);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.print("-1/64 in");
  tft.fillRect(106, 120, 106, 120, ILI9341_BLUE);
  tft.drawRect(106, 120, 106, 120, ILI9341_WHITE);
  tft.setCursor(135, 175);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.print("ZERO");
  tft.fillRect(212, 120, 106, 120, ILI9341_RED);
  tft.drawRect(212, 120, 106, 120, ILI9341_WHITE);
  tft.setCursor(225, 175);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.print("+.50 in");
}

void drawSure()
{
  tft.fillScreen(ILI9341_BLACK);
  tft.setCursor(5, 55);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(4);
  tft.print("Are You Sure?");
  tft.fillRect(0, 160, 106, 160, ILI9341_GREEN);
  tft.drawRect(0, 160, 106, 160, ILI9341_WHITE);
  tft.setCursor(35, 190);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(3);
  tft.print("No");
  tft.fillRect(212, 160, 106, 160, ILI9341_RED);
  tft.drawRect(212, 160, 106, 160, ILI9341_WHITE);
  tft.setCursor(240, 190);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(3);
  tft.print("Yes");
}
