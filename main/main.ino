#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  // Устанавливаем дисплей

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
	B00100};


void setup() {
  // put your setup code here, to run once:
  lcd.init();                       


  Serial.begin(9600);
  pinMode(14, INPUT);
  pinMode(A0, OUTPUT);
  CreateUI();
    lcd.setCursor(4,0);
  lcd.print("    ");
}


void CreateUI()
{
  lcd.backlight();// Включаем подсветку диспле
  lcd.createChar(0, tear);  // Устанавливаем количество строк и столбцов.
   lcd.createChar(1, wind); 
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.write((uint8_t)0);
  lcd.print("|");
  lcd.print("V ");
  lcd.print(1000);
  lcd.setCursor(8,0);
  lcd.print("|");
  lcd.print("T ");
  lcd.print("24:24");

  lcd.setCursor(0,1);
  lcd.write((uint8_t)1);
  lcd.print("|");
  lcd.print("V ");
  lcd.print(1000);
  lcd.setCursor(8,1);
  lcd.print("|");
  lcd.print("T ");
  lcd.print("24:24");
    
  // Печатаем наш символ.

}


void loop() {
  digitalWrite(A0, 1);
  // put your main code here, to run repeatedly:

  lcd.setCursor(4,0);
  lcd.print(digitalRead(14));
  //Serial.println(digitalRead(14));
  }
