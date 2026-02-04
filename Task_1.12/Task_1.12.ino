#include <Arduino.h>
const int ldrpin=A0;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  //Read ldr or light value
  int light_amount = analogRead(ldrpin);
int light_percent = map(light_amount, 0, 1023, 0, 100);
Serial.print("Light: ");
Serial.print(light_percent);
Serial.println("%");
delay(200);


}
