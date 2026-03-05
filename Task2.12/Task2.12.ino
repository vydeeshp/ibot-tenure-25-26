#include <WiFi.h>
#include <WebServer.h>

// Replace with your Hotspot SSID and Password
const char* ssid     = "Vydeesh's S22";
const char* password = "PS@147716";

const int ledPin = 5;   
WebServer server(80);   


void handleRoot() {
  String html = "<!DOCTYPE html><html><head><title>ESP32 LED Control</title></head><body>";
  html += "<h1>ESP32 LED Control</h1>";
  html += "<form action=\"/on\" method=\"GET\"><button type=\"submit\">ON</button></form>";
  html += "<form action=\"/off\" method=\"GET\"><button type=\"submit\">OFF</button></form>";
  html += "</body></html>";
  server.send(200, "text/html", html);
}

// Turn LED ON
void handleOn() {
  digitalWrite(ledPin, HIGH);
  server.send(200, "text/html", "<h1>LED is ON</h1><a href=\"/\">Back</a>");
}

// Turn LED OFF
void handleOff() {
  digitalWrite(ledPin, LOW);
  server.send(200, "text/html", "<h1>LED is OFF</h1><a href=\"/\">Back</a>");
}

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);

  // Connect to Wi-Fi
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected!");
  Serial.print("ESP32 IP Address: ");
  Serial.println(WiFi.localIP());

  // Define routes
  server.on("/", handleRoot);
  server.on("/on", handleOn);
  server.on("/off", handleOff);

  // Start server
  server.begin();
}

void loop() {
  server.handleClient();
}
