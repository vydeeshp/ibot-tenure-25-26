const int triger=9;
const int echo=10;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(echo,INPUT);
  pinMode(triger,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(triger, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(triger, LOW); // Read the time the echoPin stays HIGH 
  long duration = pulseIn(echo, HIGH); // Calculate distance (speed of sound = 343 m/s) // Convert duration (µs) to distance (cm) 
  float distance = (duration * 0.0343) / 2; 
  Serial.print("Distance: ");
   Serial.print(distance);
    Serial.println(" cm");
delay(500);
}
