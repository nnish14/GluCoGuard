# GluCoGuard: Smart Wearable Patch for Diabetes Monitoring

A low-cost (~INR 3750 prototype, targeting INR 2000-3000) wearable patch for continuous glucose monitoring using the Contour Plus Glucometer with 25 test strips, interpolated for continuous data. Developed by Team Stalkfish at B.M.S College of Engineering, Bangalore, for the Sensor Hackathon (Pulse Track).

## Features
- Contour Plus Glucometer for discrete glucose measurements (20–600 mg/dL).
- MCP9808 temperature sensor (±0.5°C) for environmental compensation.
- ESP32 S3 for data processing, interpolation, and BLE alerts.
- TRL-8 Testing: MARD <10%, drift <5%, BLE 99.9% packet delivery.
- Future plans: PDMS-based actuator for insulin/glucagon delivery, Indian-made GOx sensors.

## Setup
See [docs/setup_steps.md](docs/setup_steps.md) for hardware and firmware setup instructions.

## Demo
Watch the demo video: [demo/demo_video.mp4](demo/demo_video.mp4)

## Testing
- Accuracy and drift tests: [testLog/](testLog/)
- Visualizations: [screenshots/](screenshots/)

## License
MIT License

## Contact
N Nishchit, nishchit.ec22@gmail.com
