int IRSensor = A0; // IR sensor to pin D9

void setup() {
   Serial.begin(9600);
   pinMode(IRSensor, OUTPUT);
   
}
void loop() {
   int sensorStatus = analogRead(IRSensor);
   Serial.println(sensorStatus);
   delay(500);
}