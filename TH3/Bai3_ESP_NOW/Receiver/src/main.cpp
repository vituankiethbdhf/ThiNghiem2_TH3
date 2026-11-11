#include <Arduino.h>

#include <WiFi.h>
#include <esp_now.h>

// Cau truc du lieu nhan
typedef struct {
  int id;
  int value;
} Message;

Message receivedData;

// Ham xu ly khi nhan duoc du lieu
void OnDataRecv(const esp_now_recv_info_t *info,
                const uint8_t *data, int len) {
  if (len != sizeof(receivedData)) {
    Serial.println("Du lieu khong hop le!");
    return;
  }

  memcpy(&receivedData, data, sizeof(receivedData));

  Serial.println("===== DA NHAN DU LIEU =====");
  Serial.print("ID: ");
  Serial.println(receivedData.id);

  Serial.print("Gia tri: ");
  Serial.println(receivedData.value);
}

void setup() {
  Serial.begin(115200);

  Serial.println("ESP-NOW RECEIVER");

  WiFi.mode(WIFI_STA);

  Serial.print("MAC Receiver: ");
  Serial.println(WiFi.macAddress());

  if (esp_now_init() != ESP_OK) {
    Serial.println("Khoi tao ESP-NOW that bai!");
    return;
  }

  esp_now_register_recv_cb(OnDataRecv);

  Serial.println("Receiver da khoi tao!");
  Serial.println("Dang cho du lieu...");
}

void loop() {
  delay(1000);
}
