# Setup Steps

## Hardware Assembly
1. Connect MCP9808 to ESP32 S3:
   - SDA → IO21 (4.7kΩ pull-up resistor).
   - SCL → IO22 (4.7kΩ pull-up resistor).
   - VCC → 3.3V, GND → GND.
2. Power ESP32 S3 with a 3.3V bench supply (future: Li-Po with TP4056).
3. Use Contour Plus Glucometer for manual glucose readings (no direct connection).

## Data Collection
1. Take 5–10 glucometer readings at 1-hour intervals (50–300 mg/dL).
2. Record MCP9808 temperature simultaneously.

## Firmware Setup
1. Install PlatformIO or Arduino IDE with ESP32 support.
2. Clone this repository: `git clone https://github.com/<your-username>/GluCoGuard.git`.
3. Open `firmware/src/main.ino` and configure `firmware/platformio.ini`.
4. Upload firmware to ESP32 S3.

## Testing
1. Interpolate glucometer data for continuous monitoring (5-minute intervals).
2. Verify BLE alerts (<70 mg/dL, >180 mg/dL) via nRF Connect app.
3. Run TRL-8 tests (MARD <10%, drift <5%, ±0.5°C accuracy).
