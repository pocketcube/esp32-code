#include <WiFi.h>
#include <WebServer.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#define SEALEVELPRESSURE_HPA (1013.25)
Adafruit_BME280 bme;
float temperature, humidity, pressure, altitude;
/*coloque seu login e senha**/
const char* ssid = "Grupo7"; // Entre no seu login
const char* password = "pi2fga"; //Entre com sua senha
WebServer server(80);
void setup() {
    Serial.begin(115200);
    delay(100);
    bme.begin(0x76);
    Serial.println("Connecting to ");
    Serial.println(ssid);
    //conecte com a rede wi-fi
    WiFi.begin(ssid, password);
    //checar se a conexão teve êxito
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected..!");
    Serial.print("Got IP: "); Serial.println(WiFi.localIP());
    server.on("/", handle_OnConnect);
    server.begin();
    Serial.println("HTTP server started");
}

void loop() {
    server.handleClient();
}
void handle_OnConnect() {
    temperature = bme.readTemperature();
    humidity = bme.readHumidity();
    pressure = bme.readPressure() / 100.0F;
    altitude = bme.readAltitude(SEALEVELPRESSURE_HPA);
    server.send(200, "text/json", (temperature,humidity,pressure,altitude));
}