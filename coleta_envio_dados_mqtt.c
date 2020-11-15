#include <WiFi.h>
#include <PubSubClient.h>
Const char* ssid = "yourNetworkName";
const char* password = "yourNetworkPassword";
const char* mqttServer = "m11.cloudmqtt.com";
const int mqttPort = 12948;
const char* mqttUser = "yourMQTTuser";
const char* mqttPassword = "yourMQTTpassword";
WiFiClient espClient;
PubSubClient client(espClient);
void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.println("Connecting to WiFi..");
    }
    Serial.println("Connected to the WiFi network");
    client.setServer(mqttServer, mqttPort);
    while (!client.connected()) {
        Serial.println("Connecting to MQTT...");
        if (client.connect("ESP32Client", mqttUser, mqttPassword )) {
            Serial.println("connected");
        } else {
            Serial.print("failed with state ");
            Serial.print(client.state());
            delay(2000);
    }
    }
    client.publish("sensor/percent_Humidy", {"Humidy": 60});
    client.publish("sensor/pressure", {press: 30});
    client.publish("sensor/oxygen", {h2: 40});
    client.publish("sensor/gps", { height: 5.5});
}

void loop() {
    client.loop();
}