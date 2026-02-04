int ledpin=11;
int brightness=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledpin,OUTPUT);


}

void loop() {
  
  //increase brightness afer each cycle or decrease
  for (int brightness = 0; brightness <= 255; brightness += 1) {
analogWrite(11, brightness);
delay(10);
}
for (int brightness = 255; brightness >= 0; brightness -= 1) {
analogWrite(11, brightness);
delay(10);
}
  


  


  // put your main code here, to run repeatedly:

}
