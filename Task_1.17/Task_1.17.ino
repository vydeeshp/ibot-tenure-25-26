#include <DHT11.h>



const int d_pin=9;
DHT11 dht11(d_pin);
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  int temperature = 0;
    int humidity = 0;

    // Attempt to read the temperature and humidity values from the DHT11 sensor.
    int result = dht11.readTemperatureHumidity(temperature, humidity);

    
    if (result == 0) {
        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.print(" °C\tHumidity: ");
        Serial.print(humidity);
        Serial.println(" %");
    } else {
       
        Serial.println(DHT11::getErrorString(result));//errormessage
    }

delay(2000); 
  // put your main code here, to run repeatedly:

}
