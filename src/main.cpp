#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

#define SWITCH_PIN 3

void setup() {
  pinMode(SWITCH_PIN, INPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("* Vibration Switch *");

  lcd.setCursor(0, 2);
  lcd.print("Status:");
}

void loop() {
  lcd.setCursor(8, 2);
  if (digitalRead(SWITCH_PIN)) {
    lcd.print("OPEN  ");
  } else {
    lcd.print("CLOSED");
    delay(500);
  }
}
