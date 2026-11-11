
#include <WiFi.h>
#include <esp_now.h>

// Cau truc du lieu gui
typedef struct {
  int id;
  int value;
} Message;

Message sendData;

uint8_t broadcastAddress[] = {
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};

void OnDataSent(const wifi_tx_info_t *info,
                esp_now_send_status_t status) {
  if (status == ESP_NOW_SEND_SUCCESS) {
    Serial.println("Gui du lieu thanh cong!");
  } else {
    Serial.println("Gui du lieu that bai!");
  }
}

void setup() {
  Serial.begin(115200);

  Serial.println("ESP-NOW TRANSMITTER");

  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("Khoi tao ESP-NOW that bai!");
    return;
  }

  esp_now_register_send_cb(OnDataSent);

  esp_now_peer_info_t peerInfo = {};
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Them Receiver that bai!");
    return;
  }

  Serial.println("Transmitter da khoi tao!");
}

void loop() {
  sendData.id = 1;
  sendData.value++;

  esp_err_t result = esp_now_send(
    broadcastAddress,
    (uint8_t *)&sendData,
    sizeof(sendData)
  );

  if (result == ESP_OK) {
    Serial.print("Dang gui gia tri: ");
    Serial.println(sendData.value);
  } else {
    Serial.println("Khong gui duoc du lieu!");
  }

  delay(2000);
}
