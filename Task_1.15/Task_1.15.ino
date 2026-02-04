const int led_pin=10;
const int sound_sensor=9;
void setup() {
  pinMode(sound_sensor,INPUT);
  pinMode(led_pin,OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(led_pin,LOW);
  // put your main code here, to run repeatedly:
  int soundState = digitalRead(sound_sensor);
  Serial.print(soundState);
  if (soundState ==HIGH) {
    digitalWrite(led_pin, HIGH); 
    
    delay(100);
    digitalWrite(led_pin,LOW);// LED ON when sound detected
  } else {
    digitalWrite(led_pin, LOW);  // LED OFF otherwise
  }
  
  

}
