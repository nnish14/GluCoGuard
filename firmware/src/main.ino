#include <Wire.h>
#include <Adafruit_MCP9808.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <BLE2902.h>
#include <ArduinoJson.h>

// UUIDs
#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

// I2C pins
#define I2C_SDA 4
#define I2C_SCL 5

// BLE and temp sensor handles
BLECharacteristic *pCharacteristic;
Adafruit_MCP9808 tempsensor = Adafruit_MCP9808();

// Glucose profile over 24h (15-minute intervals × 96)
const float glucoseProfile[] = {
  90,88,85,83,82,81,80,82,85,90,100,110,125,130,125,115,  // 00:00–04:00
  100,95,93,91,89,88,90,92,94,96,98,102,108,115,130,125,  // 04:00–08:00
  110,100,95,90,88,90,92,95,100,110,120,130,135,130,120,110, // 08:00–12:00
  100,95,90,88,85,83,82,80,85,95,110,125,135,140,130,120, // 12:00–16:00
  110,100,95,93,91,90,92,95,100,105,115,125,130,128,120,110, // 16:00–20:00
  105,100,95,90,88,85,84,83,85,88,90,92,95,98,100,95         // 20:00–24:00
};
const int profileSize = sizeof(glucoseProfile) / sizeof(glucoseProfile[0]);
const unsigned long cycleDurationMs = 24UL * 60UL * 60UL * 1000UL;  // 24 hours
unsigned long minutes = millis() / 60000;



void setup() {
  Serial.begin(115200);
  delay(1000);

  // I2C + MCP9808
  Wire.begin(I2C_SDA, I2C_SCL);
  Serial.println("🔌 Booting MCP9808 on custom I2C...");
  if (!tempsensor.begin(0x18)) {
    Serial.println("❌ Couldn't find MCP9808! Check wiring.");
    while (true);
  }

  // BLE setup
  BLEDevice::init("ESP32-GlucoPatch");
  BLEServer *pServer = BLEDevice::createServer();
  BLEService *pService = pServer->createService(SERVICE_UUID);

  pCharacteristic = pService->createCharacteristic(
    CHARACTERISTIC_UUID,
    BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY
  );
  pCharacteristic->addDescriptor(new BLE2902());

  pService->start();
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(0x06);
  pAdvertising->setMinPreferred(0x12);
  BLEDevice::startAdvertising();

  Serial.println("✅ BLE server ready!");
}

void loop() {
  // Calculate position in 24h cycle
  unsigned long now = millis() % cycleDurationMs;
  int index = (now * profileSize) / cycleDurationMs;

  // Get base glucose value and add jitter
  float baseGlucose = glucoseProfile[index];
  float simulatedGlucose = baseGlucose + random(-10, 11); // ±10 mg/dL

  // Read real temperature
  float tempC = tempsensor.readTempC();
  float tempCS = 27.31;

  char uptimeStr[32];
  snprintf(uptimeStr, sizeof(uptimeStr), "%lu minutes", minutes);

  // Build JSON
  StaticJsonDocument<256> doc;
  doc["source"] = "simulated_glucose_profile";
  doc["glucose_mg_dL"] = simulatedGlucose;
  doc["temperature_C"] = tempC;
  doc["index"] = index;
  doc["uptime_ms"] = uptimeStr;

  String jsonOut;
  serializeJson(doc, jsonOut);
  Serial.println("📤 BLE JSON: " + jsonOut);

  pCharacteristic->setValue(jsonOut.c_str());
  pCharacteristic->notify();

  delay(2000);
}
