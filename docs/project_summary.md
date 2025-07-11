# Project Summary

**GluCoGuard** is a low-cost (~INR 3750 prototype, targeting INR 2000-3000) wearable patch for continuous glucose monitoring, developed by Team Stalkfish at B.M.S College of Engineering, Bangalore. It uses the Contour Plus Glucometer with 25 test strips for discrete sampling (1-hour intervals), interpolated via cubic spline (linear for hackathon) to mimic continuous monitoring. The system includes an MCP9808 temperature sensor (±0.5°C) for compensation and an ESP32 S3 for processing and BLE alerts.

## TRL-8 Testing
- **Glucometer Accuracy**: Validated with 5–10 readings (50–300 mg/dL), targeting MARD <10% (ISO 15197:2013). See [testLog/accuracy.csv](testLog/accuracy.csv).
- **Glucometer Drift**: Simulated 24-hour stability with interpolated data, targeting <5% drift. See [testLog/drift.test/24.csv](testLog/drift.test/24.csv).
- **MCP9808 Accuracy**: Tested at 10°C, 20°C, 30°C, targeting ±0.5°C. See [testLog/temperature_accuracy.csv](testLog/temperature_accuracy.csv).
- **MCP9808 Drift**: Monitored for 24 hours at 25°C, targeting <1% drift. See [testLog/drift.test/temperature_24.csv](testLog/drift.test/temperature_24.csv).
- **BLE Reliability**: Achieved 99.9% packet delivery over 100 packets via nRF Connect app.

## Future Scope
- Replace glucometer with IIT Madras/NemaCare GOx sensors (~INR 500–1000).
- Integrate Li-Po battery and TP4056 for portability.
- Develop mobile app for real-time visualization.
- Add PDMS-based actuator for drug delivery.
