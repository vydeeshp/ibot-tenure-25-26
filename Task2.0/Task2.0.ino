

const int ledPin = 5;       
  
const int freq = 5000;      
const int resolution = 8;   

void setup() {
  
  //ledcSetup(ledChannel, freq, resolution);
  ledcAttach(ledPin, freq,resolution);
}

void loop() {
  
  for (int duty = 0; duty <= 255; duty++) {
    ledcWrite(ledPin, duty);
    delay(5); 
  }


  for (int duty = 255; duty >= 0; duty--) {
    ledcWrite(ledPin, duty);
    delay(5);
  }
}
