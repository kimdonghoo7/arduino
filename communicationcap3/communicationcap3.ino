#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2);
int i = 0;
int k = 0;
void setup()
{
  lcd.init();
  lcd.backlight();

}
void loop() {
  if (i < 16) {
    lcd.setCursor(i, 0);
    lcd.print("I");
    lcd.setCursor(i + 1, 0);
    lcd.print("N");
    lcd.setCursor(i + 2, 0);
    lcd.print("D");
    lcd.setCursor(i + 3, 0);
    lcd.print("U");
    lcd.setCursor(i + 4, 0);
    lcd.print("K");
    delay(300);
    i++;
    lcd.clear();
  }
  if (i > 15) {
    lcd.setCursor(k - 4, 1);
    lcd.print("I");
    lcd.setCursor(k - 3, 1);
    lcd.print("N");
    lcd.setCursor(k - 2, 1);
    lcd.print("D");
    lcd.setCursor(k - 1, 1);
    lcd.print("U");
    lcd.setCursor(k, 1);
    lcd.print("K");
    delay(300);
    k++;
    lcd.clear();
  }

}
