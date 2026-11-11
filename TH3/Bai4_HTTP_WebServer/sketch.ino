
#include <WiFi.h>
#include <WebServer.h>

// Cau hinh Wi-Fi Wokwi
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// Chan dieu khien LED
#define LED_PIN 2

// Tao Web Server tai cong 80
WebServer server(80);

// Trang web dieu khien LED
void handleRoot() {
  String html = R"rawliteral(
  <!DOCTYPE html>
  <html>
  <head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>ESP32 LED Control</title>
    <style>
      body {
        font-family: Arial;
        text-align: center;
        margin-top: 60px;
        background: #f0f0f0;
      }
      h1 { color: #222; }
      button {
        padding: 15px 35px;
        font-size: 20px;
        margin: 10px;
        border: none;
        border-radius: 8px;
        cursor: pointer;
      }
      .on { background: green; color: white; }
      .off { background: red; color: white; }
    </style>
  </head>
  <body>
    <h1>ESP32 WEB SERVER</h1>
    <h2>Dieu khien LED</h2>
    <p>Trang thai LED: %STATE%</p>
    <a href="/on"><button class="on">BAT LED</button></a>
    <a href="/off"><button class="off">TAT LED</button></a>
  </body>
  </html>
  )rawliteral";

  if (digitalRead(LED_PIN) == HIGH) {
    html.replace("%STATE%", "DANG BAT");
  } else {
    html.replace("%STATE%", "DANG TAT");
  }

  server.send(200, "text/html", html);
}

// Bat LED
void handleLEDOn() {
  digitalWrite(LED_PIN, HIGH);
  server.sendHeader("Location", "/");
  server.send(303);
}

// Tat LED
void handleLEDOff() {
  digitalWrite(LED_PIN, LOW);
  server.sendHeader("Location", "/");
  server.send(303);
}

void setup() {
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  Serial.println("Dang ket noi Wi-Fi...");

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password, 6);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("Da ket noi Wi-Fi!");

  Serial.print("Dia chi IP: ");
  Serial.println(WiFi.localIP());

  // Cau hinh cac duong dan tren Web Server
  server.on("/", handleRoot);
  server.on("/on", handleLEDOn);
  server.on("/off", handleLEDOff);

  server.begin();

  Serial.println("HTTP Web Server da khoi dong!");
}

void loop() {
  server.handleClient();
}
