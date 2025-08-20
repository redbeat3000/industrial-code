#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";
const char* mqtt_server = "broker.hivemq.com"; // Public broker for testing

WiFiClient espClient;
PubSubClient client(espClient);

// Simulate sensor readings
int readVibration() { return analogRead(34); }
float readTemperature() { return 25.0 + random(-5,5)/10.0; }

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) { delay(500); Serial.print("."); }
  Serial.println("WiFi connected");
  #include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";
const char* mqtt_server = "broker.hivemq.com"; // Public broker for testing

WiFiClient espClient;
PubSubClient client(espClient);

// Simulate sensor readings
int readVibration() { return analogRead(34); }
float readTemperature() { return 25.0 + random(-5,5)/10.0; }

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) { delay(500); Serial.print("."); }
  Serial.println("WiFi connected");
  
  client.setServer(mqtt_server, 1883);
}

void loop() {
  if (!client.connected()) {
    while (!client.connected()) {
      Serial.print("Connecting to MQTT...");
      if (client.connect("ESP32_Client")) {
        Serial.println("connected");
      } else {
        Serial.print("failed, rc=");
        Serial.print(client.state());
        delay(2000);
      }
    }
  }
  client.loop();

  StaticJsonDocument<200> doc;
  doc["vibration"] = readVibration();
  doc["temperature"] = readTemperature();
  
  char buffer[256];
  serializeJson(doc, buffer);
  client.publish("factory/machine1", buffer);

  delay(2000); // Send data every 2 seconds
}

  client.setServer(mqtt_server, 1883);
}

void loop() {
  if (!client.connected()) {
    while (!client.connected()) {
      Serial.print("Connecting to MQTT...");
      if (client.connect("ESP32_Client")) {
        Serial.println("connected");
      } else {
        Serial.print("failed, rc=");
        Serial.print(client.state());
        delay(2000);
      }
    }
  }
  client.loop();

  StaticJsonDocument<200> doc;
  doc["vibration"] = readVibration();
  doc["temperature"] = readTemperature();
  
  char buffer[256];
  serializeJson(doc, buffer);
  client.publish("factory/machine1", buffer);

  delay(2000); // Send data every 2 seconds
}
