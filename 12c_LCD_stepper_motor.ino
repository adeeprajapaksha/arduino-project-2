

#include <LCD_I2C.h>
#define PB1 2
#define PB2 3
#define PB3 4
#define PB4 5
#define PUL 6
#define DIR 7

LCD_I2C lcd(0x27, 16, 2);  // Default address of most PCF8574 modules, change according

void setup() {
  lcd.begin();  // If you are using more I2C devices using the Wire library use lcd.begin(false)
  // this stop the library(LCD_I2C) from calling Wire.begin()
  lcd.backlight();

  pinMode(PUL, OUTPUT);
  pinMode(DIR, OUTPUT);
  pinMode(PB1, INPUT_PULLUP);
  pinMode(PB2, INPUT_PULLUP);
  pinMode(PB3, INPUT_PULLUP);
  pinMode(PB4, INPUT_PULLUP);

  digitalWrite(DIR, HIGH);
}
int b = 1;
int pulses, rev = 0, Ctime = 800, x;
void loop() {

  if (b == 1) {
    lcd.print("     Well");  
    lcd.setCursor(5, 1);     
    lcd.print("Come");
    delay(3000);
    b = 2;
  }
  if (b == 2) {
    lcd.clear();
    lcd.print("1. Run 2. Speed");  
    lcd.setCursor(0, 1);           
    lcd.print("3. Revolution");
    b = 3;
  }
  if (b == 3) {
    if (digitalRead(PB1) == 0) {

      b = 6;
    } else {

      b = 4;
    }
  }
  if (b == 4) {
    if (digitalRead(PB2) == 0) {

      b = 8;
    } else {

      b = 5;
    }
  }
  if (b == 5) {
    if (digitalRead(PB3) == 0) {

      b = 17;
    } else {

      b = 3;
    }
  }
  if (b == 6) {
    lcd.clear();
    lcd.print("Motor Starting...");
    pulses = rev * 400;
    x = Ctime / 2;
    b = 7;
  }
  if (b == 7) {
    lcd.clear();
    lcd.print("Motor Stopped...");
    delay(2000);
    b = 2;
  }
  if (b == 8) {
    if (digitalRead(PB2) == 0) {
      delay(200);
      b = 9;
    } else {
      b = 8;
    }
  }
  if (b == 9) {
    lcd.clear();
    lcd.print("Enter Cycle Time");
    lcd.setCursor(6, 1);
    lcd.print(Ctime);
    b = 10;
  }
  if (b == 10) {
    if (digitalRead(PB3) == 0) {
      b = 11;
    } else {
      b = 13;
    }
  }
  if (b == 11) {
    if (Ctime < 2000) {
      b = 12;
    } else {
      b = 10;
    }
  }
  if (b == 12) {
    Ctime = Ctime + 1;

    b = 9;
  }
  if (b == 13) {
    if (digitalRead(PB4) == 0) {
      b = 14;
    } else {
      b = 16;
    }
  }
  if (b == 14) {
    if (Ctime > 800) {
      b = 15;
    } else {
      b = 10;
    }
  }
  if (b == 15) {
    Ctime = Ctime - 1;

    b = 9;
  }
  if (b == 16) {
    if (digitalRead(PB2) == 0) {
      delay(200);
      b = 2;
    } else {
      b = 10;
    }
  }
  if (b == 17) {
    if (digitalRead(PB3) == 0) {
      delay(200);
      b = 18;
    } else {
      b = 17;
    }
  }
  if (b == 18) {
    lcd.clear();
    lcd.print("Enter revolution number");
    lcd.setCursor(7, 1);
    lcd.print(rev);
    b = 19;
  }
  if (b == 19) {
    if (digitalRead(PB3) == 0) {
      b = 20;
    } else {
      b = 22;
    }
  }
  if (b == 20) {
    if (rev < 100) {
      b = 21;
    } else {
      b = 19;
    }
  }
  if (b == 21) {
    rev = rev + 1;

    b = 18;
  }
  if (b == 22) {
    if (digitalRead(PB4) == 0) {
      b = 23;
    } else {
      b = 25;
    }
  }
  if (b == 23) {
    if (rev > 0) {
      b = 24;
    } else {
      b = 19;
    }
  }
  if (b == 24) {
    rev = rev - 1;

    b = 18;
  }
  if (b == 25) {
    if (digitalRead(PB2) == 0) {
      delay(200);
      b = 2;
    } else {
      b = 19;
    }
  }




  // Flashing the backlight
}
