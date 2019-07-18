#include <Arduino.h>
#line 1 "E:\\BTL TKMS\\cbk-lcd\\cbk-lcd.ino"
#line 1 "E:\\BTL TKMS\\cbk-lcd\\cbk-lcd.ino"
#include <LiquidCrystal.h>
LiquidCrystal lcd(9, 8, 7, 6, 5, 4);

byte degree[8] = {
  0B11111,
  0B11111,
  0B11111,
  0B11111,
  0B11111,
  0B11111,
  0B11111,
  0B11111
};

#line 15 "E:\\BTL TKMS\\cbk-lcd\\cbk-lcd.ino"
void setup();
#line 21 "E:\\BTL TKMS\\cbk-lcd\\cbk-lcd.ino"
void loop();
#line 15 "E:\\BTL TKMS\\cbk-lcd\\cbk-lcd.ino"
void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(6,0);
  lcd.print("SMOKE:");
  lcd.createChar(1, degree);
}
void loop() {
  int A0 = analogRead(A1);
  int D0 = digitalRead(A2);
  float dienAp = A0 * (5.0 / 1023.0);
  float dienAp1 = round(dienAp * 2);
  float value =(A0 / 1023.0) * 100.0;
  int nongDo= int(value);

  lcd.setCursor(13 , 0);
  lcd.print(nongDo);
  lcd.setCursor(15 , 0);
  lcd.print("%");
  if(nongDo>40){
    lcd.setCursor(1 , 0);
    lcd.print("WARN");
  }
  else{
    lcd.setCursor(1 , 0);
    lcd.print("Safe");
  }
  if(D0 == 1){
    lcd.setCursor(0,0);
    lcd.print(" ");
  }
  else{
    lcd.setCursor(0,0);
    lcd.print(".");
  }
  
  lcd.setCursor(11,1);
  lcd.print(dienAp);
  lcd.print("v");
  lcd.setCursor(0,1);
  
    for(int i=0;i<dienAp1;i++){
          lcd.write(1);
    }
  lcd.print(" ");
}

