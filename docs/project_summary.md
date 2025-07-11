# 🚀 **GlucoGuard – Smart BLE-Enabled Glucose Monitoring for Everyone**

---

## 🔍 **Overview**

**GlucoGuard** is a **low-cost, real-time glucose monitoring assistant** built on the ESP32-S3, designed to provide **continuous-like glucose tracking** by interpolating sparse glucometer readings using **ambient skin temperature data**. It’s fully **BLE-enabled**, battery-friendly, and designed for use in **resource-limited or rural environments** where full-blown CGM systems are inaccessible or unaffordable.

> Think of it as a CGM-lite — with real-time alerts, BLE sync, and medically grounded logic, all running on ₹500 worth of silicon.

---

## 🧠 **What It Does**

* 🔬 **Collects real-time temperature** data from an MCP9808 sensor.
* 🧪 **Correlates with glucose levels** from manual glucometer readings.
* 📈 **Interpolates** glucose readings every 5 minutes for a semi-continuous graph.
* 📲 **Broadcasts alerts via BLE** if levels go dangerously low (<70 mg/dL) or high (>180 mg/dL).
* 🔋 **Runs on battery** and works offline — no internet required.

---

## 💡 **Why It Matters**

* **70M+ diabetics in India**, many without access to continuous glucose monitors.
* **Rural clinics** often lack the infrastructure for digital tracking.
* Real-time alerts can **prevent hypoglycemic shock**, especially for the elderly or during sleep.
* Enables **basic health digitization** without recurring CGM costs.

---

## 🧰 **Tech Stack**

| Module      | Component                                                         |
| ----------- | ----------------------------------------------------------------- |
| **MCU**     | ESP32-S3 (BLE + I2C + Low Power)                                  |
| **Sensor**  | MCP9808 (±0.25°C Accuracy)                                        |
| **Display** | BLE GATT profile viewed via nRF Connect or any mobile BLE scanner |
| **Power**   | Bench or Li-Po battery with TP4056                                |
| **Code**    | Arduino/PlatformIO (C++) + interpolation logic                    |

---

## ⚙️ **Key Features**

* ✅ **BLE Alerts**: Works with nRF Connect or custom apps
* ✅ **Offline Logging**: USB Serial output for temperature logs
* ✅ **Threshold Alerts**: <70 or >180 mg/dL = BLE Warning
* ✅ **Battery Operable**: Ideal for wearable use
* ✅ **Plug & Play Firmware**: Open-source & ready to hack

---

## 🧪 **Demo Flow**

1. Take glucose reading via **Contour Plus glucometer** (manual input).
2. Simultaneously log **ambient temperature** via MCP9808.
3. Run interpolation logic to simulate **5-min glucose updates**.
4. Observe **BLE-based alerts** when thresholds are breached.
5. View logs via serial monitor or BLE app on phone.

---

## 🌍 **Use Cases**

* 📱 **Personal Diabetic Management** (non-CGM users)
* 🏥 **Rural Clinics & Mobile Health Camps**
* 📊 **Health Data Logging for Researchers**
* 🎓 **Bio-Med IoT Educational Projects**

---

## 🚧 **Future Enhancements**

* 🔐 **Encrypted BLE** data streams for secure mobile app sync.
* 🧠 **ML models** to predict glucose from temperature + motion.
* 🌐 **Cloud dashboard** integration for remote doctors.
* 💉 Add-ons: HR, GSR, or sweat sensor for richer data.

---

## 📂 **GitHub Repo**

> [https://github.com/nnish14/GluCoGuard](https://github.com/nnish14/GluCoGuard)
> Includes:

* Firmware source (`main.ino`)
* Wiring diagrams
* Setup instructions
* Sample CSV datasets

---

## 🎯 **Hackathon Impact**

* **Problem Tackled**: Affordable, accessible diabetic health tracking
* **Real-World Value**: Works with ₹1000 hardware, no cloud dependency
* **Innovation Quotient**: Interpolation + BLE alerting + thermal proxy = CGM-lite
* **Future-Proof**: Ready for AI, remote sync, and full wearable integration