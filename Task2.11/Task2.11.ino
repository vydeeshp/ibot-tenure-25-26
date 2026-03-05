#include <WiFi.h>
const char* ssid = "Vydeesh's S22";
const char* password="PS@147716";
void setup() {
  Serial.begin(115200);
  Serial.println("Connecting...");
  WiFi.begin(ssid,password);
  while(WiFi.status()!=WL_CONNECTED){
    delay(500);
    Serial.print(".");
    Serial.println("\nWiFi connected!");
     Serial.print("ESP32 IP Address: "); 
     Serial.println(WiFi.localIP());
  }

  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
