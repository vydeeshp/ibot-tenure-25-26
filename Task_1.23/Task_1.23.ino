#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
// • SDA→Arduino A4 (or SDA pin)
// • SCL →Arduino A5 (or SCL pin)
// • VCC→5V(Check if your module is 3.3V or 5V!)
// • GND→GND

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
void setup() {
 Serial.begin(115200);
 if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
   Serial.println("SSD1306 allocation failed");
   for (;;);
 }
 display.clearDisplay();
 display.setTextSize(1);
 display.setTextColor(WHITE);
 display.setCursor(0, 10);
 display.println("Hello, world!");
 display.drawCircle(64, 32, 10, SSD1306_WHITE);
 display.display();
 

}
void loop() {}