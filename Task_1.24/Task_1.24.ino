#include <Servo.h>
// • Brown/Black Wire → GND
// • Red Wire → 5V
// • Orange/Signal Wire → PWM Pin (e.g., Pin 9)
const int servopin=9;
Servo myservo;
void setup() {
  // put your setup code here, to run once:
  myservo.attach(servopin);

}

void loop() {
  // put your main code here, to run repeatedly:
  for (int angle = 0; angle <= 180; angle++) { 
    myservo.write(angle);
   
    delay(15); } 
    // Sweep back from 180° to 0° 
    for (int angle = 180; angle >= 0; angle--) { 
      myservo.write(angle); 
      delay(15); }

}
