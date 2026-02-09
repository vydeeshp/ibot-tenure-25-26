#include <LiquidCrystal.h>
// Laser Module (Middle Drawer)- Keep this pointed at the LDR.
// • LDR Module (Middle Drawer)
// • Piezo Buzzer (Middle Drawer)
// • LCD 16x2 Display (Centre Brown Table)
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int ldrp=A0;
const int buzzerp=9;
int threshold=300;
int ldrValue=0;


void setup() {
  pinMode(buzzerp, OUTPUT);
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.println("laser initializing");
  delay(2000); 
  lcd.clear();

}

void loop() {
  // put your main code here, to run repeatedly:
  ldrValue = analogRead(ldrp); 
  if (ldrValue < threshold) { 
  digitalWrite(buzzerp, LOW); // Buzzer off 
  lcd.setCursor(0, 0); 
  noTone(buzzerp);
  lcd.print("No Interference"); }
   else { 
  tone(buzzerp,1000);
  delay(100);
  noTone(buzzerp) ;// Buzzer on 
  lcd.setCursor(0, 0); 
  lcd.print("Interference Detected"); } 
  delay(200);


}
