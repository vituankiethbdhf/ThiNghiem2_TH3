#include <Arduino.h>

#include <WiFi.h>
#include <PubSubClient.h>

// Wi-Fi Wokwi
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// MQTT Broker công cộng
const char* mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;

// Thay bằng mã sinh viên của bạn
const char* sv_id = "25112515";

// Tên các topic MQTT
String topic_publish = "TH3/" + String(sv_id) + "/sensor";
String topic_subscribe = "TH3/" + String(sv_id) + "/control";

WiFiClient espClient;
PubSubClient client(espClient);

unsigned long lastMsg = 0;

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Nhan du lieu tu topic: ");
  Serial.println(topic);

  Serial.print("Noi dung: ");
  for (unsigned int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Dang ket noi MQTT...");

    String clientId = "ESP32-" + String(sv_id);

    if (client.connect(clientId.c_str())) {
      Serial.println("Thanh cong!");

      client.subscribe(topic_subscribe.c_str());
      Serial.println("Da dang ky Subscribe!");
    } else {
      Serial.print("That bai, ma loi = ");
      Serial.println(client.state());
      delay(3000);
    }
  }
}

void setup() {
  Serial.begin(115200);

  Serial.println("BAI 5 - MQTT PUBLISH/SUBSCRIBE");

  WiFi.begin(ssid, password, 6);

  Serial.print("Dang ket noi Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nDa ket noi Wi-Fi!");

  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }

  client.loop();

  unsigned long now = millis();

  if (now - lastMsg > 5000) {
    lastMsg = now;

    String message = "{\"sv_id\":\"" + String(sv_id) +
                     "\",\"temperature\":28,\"humidity\":65}";

    Serial.print("Publish: ");
    Serial.println(message);

    client.publish(topic_publish.c_str(), message.c_str());

    Serial.println("Gui tin nhan kiem tra Subscribe...");
    client.publish(topic_subscribe.c_str(), "TEST_SUBSCRIBE");
  }
}
