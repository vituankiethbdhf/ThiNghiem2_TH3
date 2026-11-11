#include <Arduino.h>

#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

// Ten Bluetooth cua ESP32
#define DEVICE_NAME "ESP32_BLE_Server"

// UUID cua Service
#define SERVICE_UUID "4fafc201-1fb5-459e-8fcc-c5c9c331914b"

// UUID cua Characteristic
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

BLEServer *pServer = NULL;
BLECharacteristic *pCharacteristic = NULL;

bool deviceConnected = false;

class MyServerCallbacks : public BLEServerCallbacks {
  void onConnect(BLEServer *pServer) {
    deviceConnected = true;
    Serial.println("Client da ket noi!");
  }

  void onDisconnect(BLEServer *pServer) {
    deviceConnected = false;
    Serial.println("Client da ngat ket noi!");

    BLEDevice::startAdvertising();
    Serial.println("Dang phat BLE de cho ket noi moi...");
  }
};

void setup() {
  Serial.begin(115200);

  Serial.println("===== BAI 2: BLE SERVER =====");

  // Khoi tao BLE
  BLEDevice::init(DEVICE_NAME);

  // Tao BLE Server
  pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  // Tao Service
  BLEService *pService =
    pServer->createService(SERVICE_UUID);

  // Tao Characteristic
  pCharacteristic = pService->createCharacteristic(
    CHARACTERISTIC_UUID,
    BLECharacteristic::PROPERTY_READ |
    BLECharacteristic::PROPERTY_WRITE |
    BLECharacteristic::PROPERTY_NOTIFY
  );

  // Gia tri ban dau
  pCharacteristic->setValue("Xin chao tu ESP32");

  // Bat dau Service
  pService->start();

  // Cau hinh quang ba BLE
  BLEAdvertising *pAdvertising =
    BLEDevice::getAdvertising();

  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(true);

  BLEDevice::startAdvertising();

  Serial.println("BLE Server da khoi dong!");
  Serial.print("Ten thiet bi: ");
  Serial.println(DEVICE_NAME);
  Serial.println("Dang cho Client ket noi...");
}

void loop() {
  if (deviceConnected) {
    Serial.println("BLE dang co Client ket noi.");
  }

  delay(3000);
}

