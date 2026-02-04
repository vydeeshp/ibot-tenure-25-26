
const int buttonPin = 2;   
const int ledPin = 11;     

int ledState = LOW;        
int buttonState;           
int lastButtonState = HIGH; 

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Internal pull-up resistor
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Read the button
  buttonState = digitalRead(buttonPin);

  
  if (buttonState != lastButtonState) {
    
    if (buttonState == HIGH) {
      // Toggle LED state
      ledState = !ledState;
      digitalWrite(ledPin, ledState);
    }
    delay(50); 
  }

  
  lastButtonState = buttonState;
}

