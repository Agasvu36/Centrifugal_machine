#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "Timer.h"
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Устанавливаем дисплей

byte tear[8] = {
  B00000,
  B00110,
  B01110,
  B01110,
  B11111,
  B10111,
  B11111,
  B01110
};

byte wind[8] = {
  B00000,
  B00100,
  B00010,
  B10111,
  B11110,
  B10111,
  B00010,
  B00100
};

byte vector[8] = {
  B00000,
  B00100,
  B00110,
  B11111,
  B11111,
  B00110,
  B00100,
  B00000
};

void UI_Create() {
  lcd.backlight();          // Включаем подсветку диспле
  lcd.createChar(0, tear);  // Устанавливаем количество строк и столбцов.
  lcd.createChar(1, wind);
  lcd.createChar(2, vector);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.write((uint8_t)0);
  lcd.print("|");
  lcd.print("V ");

  lcd.setCursor(8, 0);
  lcd.print("|");
  lcd.print("T ");
  lcd.print("24:24");

  lcd.setCursor(0, 1);
  lcd.write((uint8_t)1);
  lcd.print("|");
  lcd.print("V ");

  lcd.setCursor(8, 1);
  lcd.print("|");
  lcd.print("T ");
  lcd.print("24:24");

}

int x = 3;
int y = 0;
void UI_Draw_Vector(int newX, int newY){
  lcd.setCursor(x, y);
  lcd.print(' ');
  x = newX;
  y = newY;
  lcd.setCursor(x,y);
  lcd.write(2);
}

void UI_Change_Velosity(int Velosity, int row)
{
  lcd.setCursor(4, row);
  lcd.print("    ");
  lcd.setCursor(4, row);
  lcd.print(Velosity);
}

void UI_Change_Time(struct Time *t, int row)
{
  lcd.setCursor(11, row);
  lcd.print("     ");
  lcd.setCursor(11, row);
  lcd.print((*t).Hour);
  lcd.print(":");
  lcd.print((*t).Minute);
}

void UI_Init() {
  lcd.init();

  UI_Create();
  lcd.setCursor(4, 0);
  lcd.print("    ");
}