const int buzzer=9;
int freq=1000;
void setup() {
  pinMode(buzzer,OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  tone(buzzer,freq);
  delay(100);
  noTone(buzzer);
  delay(100);
  // put your main code here, to run repeatedly:

}
