/*
  Alvarez Gongora Ian Raul
    al-190430
    500MTA - Lab. Sensores y Actuadores
*/

#include <LiquidCrystal.h>

float f = 0.0;
float v = 0.0;
float r = 0.0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup(){
  pinMode(A0,INPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop(){
  v = analogRead(A0)*(5.0/1023.0);
  
  r = 10000*((5/v)-1);    
  if(v <= 3.07){
    f = pow((r/5084.2),(-1/1.092));
  }else{
    f = pow((r/5999.4), (-1/0.701));
  }
  
  delay(10);
  lcd.setCursor(0, 0);
  lcd.print("Fuerza:  ");
  lcd.print(f);
  lcd.setCursor(13, 0);
  lcd.print("  N");
  
  lcd.setCursor(0, 1);
  lcd.print("Peso:    ");
  lcd.print(f/9.81);
  lcd.setCursor(14, 1);
  lcd.print("kg");
}
