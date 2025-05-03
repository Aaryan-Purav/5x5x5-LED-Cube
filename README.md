# 5x5x5 LED Cube

This project showcases a **5x5x5 LED Cube** controlled by an **Arduino Mega 2560**. The cube is used to demonstrate various animations and concepts related to **Miller Indices**, commonly studied in crystallography.

---

## 🧰 Components Used

- Arduino Mega 2560
- 125 LEDs (5 layers × 25 LEDs)
- NPN Transistors (for layer selection)
- Resistors (220Ω)
- Jumper wires
- Breadboard (optional)
- Power supply (5V DC)
- Soldering tools

---

## 🔌 Concept Overview

The cube has 5 layers and 5 columns in each layer, totaling **125 LEDs**. Each LED is addressed through a combination of layer selection (via transistors) and column scanning. The animations are designed to visualize planes such as (100), (110), (111), etc., based on Miller Indices.

---

## 📁 Folder Structure

5x5x5_LED_Cube/
├── LED_Cube/
│ └── LED_Cube.ino # Arduino sketch file
├── ProjectReport.pdf # Detailed project report
└── README.md # This file

---

## 🚀 Getting Started

1. Assemble the LED cube according to your circuit design.
2. Connect the control lines to the Arduino Mega.
3. Upload the `LED_Cube.ino` sketch using the Arduino IDE.
4. Power the system and watch the animations play.

---

## 👨‍💻 Author

- **Name:** Aaryan Nitin Purav  
- **Guide:** Mr. Ameya Nyayadhish

---

## 📜 License

This project is licensed under the [MIT License](https://opensource.org/licenses/MIT).
