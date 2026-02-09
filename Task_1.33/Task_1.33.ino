#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int audiopin = A0;   
int audiovalue = 0;  
int barheight = 0;   

void setup() {
  Serial.begin(9600);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); 
  }
  display.clearDisplay();
}

void loop() {
  
  audiovalue = analogRead(audiopin);

  
  barheight = map(audiovalue, 300, 1023, 0, 24);

  
  display.clearDisplay();

  
  display.drawLine(SCREEN_WIDTH/2, 0, SCREEN_WIDTH/2, SCREEN_HEIGHT, SSD1306_WHITE);

  
  int centerY = SCREEN_HEIGHT / 2;
  display.fillRect(SCREEN_WIDTH/2 - 2, centerY - barheight, 5, barheight*2, SSD1306_WHITE);

  
  display.display();

 
  Serial.println(audiovalue);
  Serial.println(barheight);

  delay(500); 
}
