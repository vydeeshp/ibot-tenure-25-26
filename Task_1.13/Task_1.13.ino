const int pir_pin=5;
int value;

int state=LOW;
unsigned long Start = 0; 
unsigned long motionLatency = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pir_pin,INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  value=digitalRead(pir_pin);
  if(value==HIGH&&state==LOW){
    Start=millis();

    Serial.println("motion detected");
    state=HIGH;
  }
  if(value==LOW&&state==HIGH){
    motionLatency=millis()-Start-200;//mills keeps counting and when called returns a valu at the exact moment
    Serial.println("motion stopped");
    Serial.print("latency in ms");
    Serial.println(motionLatency);
    
    state=LOW;

  }
  delay(200);

}