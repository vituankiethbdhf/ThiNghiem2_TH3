
#include <WiFi.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("Dang ket noi Wi-Fi STA...");

  WiFi.mode(WIFI_STA);
  WiFi.setSleep(false);
  WiFi.begin(ssid, password, 6);

  int dem = 0;

  while (WiFi.status() != WL_CONNECTED && dem < 30) {
    delay(1000);
    Serial.print(".");
    dem++;
  }

  Serial.println();

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("KET NOI THANH CONG!");
    Serial.print("Ten Wi-Fi: ");
    Serial.println(WiFi.SSID());
    Serial.print("Dia chi IP: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("KET NOI THAT BAI!");
    Serial.print("Ma trang thai: ");
    Serial.println(WiFi.status());
  }
}

void loop() {
}
