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
const int up=2;
const int down=3;
const int left=4;
const int right=5;
int playerX = SCREEN_WIDTH / 16; 
int playerY = SCREEN_HEIGHT / 16;
void setup() {
 Serial.begin(115200);
 if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
   Serial.println("SSD1306 allocation failed");
   for (;;);
 }
pinMode(up,INPUT_PULLUP);
pinMode(down,INPUT_PULLUP);
pinMode(left,INPUT_PULLUP);
pinMode(right,INPUT_PULLUP);
 

}
void loop() {
  if (digitalRead(up) == LOW) playerY--; 
  if (digitalRead(down) == LOW) playerY++;
  if (digitalRead(left) == LOW) playerX--;
  if (digitalRead(right) == LOW) playerX++;
  // Wrap-around logic 
  if (playerX < 0) playerX = 15; 
  if (playerX > 15) playerX = 0; 
  if (playerY < 0) playerY = 7; 
  if (playerY > 7) playerY = 0; // Draw player block 
  display.clearDisplay(); 
  display.fillRect(playerX * 8, playerY * 8, 8, 8, SSD1306_WHITE); 
  display.display(); 
  delay(150); 
}