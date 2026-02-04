int flameSensorPin = A0; // Analog pin connected to Flame Sensor 
int sensorValue = 0; 
void setup() { Serial.begin(9600); // Start serial communication
 }

 void loop() { sensorValue = analogRead(flameSensorPin); // Read analog value 
 Serial.println(sensorValue); // Print to Serial Monitor 
 delay(500);  }