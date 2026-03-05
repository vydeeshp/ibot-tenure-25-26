#include <BluetoothSerial.h>

BluetoothSerial SerialBT;   
const int ledPin = 5;       

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);

  
  SerialBT.begin("Vydeesh");  
  Serial.println("Bluetooth started. Pair with Vydeesh.");
}

void loop() {
  
  if (SerialBT.available()) {
    char val = SerialBT.read();  

    if (val == '1') {
      digitalWrite(ledPin, HIGH);  
      Serial.println("LED ON");
    } 
    else if (val == '0') {
      digitalWrite(ledPin, LOW);    
      Serial.println("LED OFF");
    }
  }
}
