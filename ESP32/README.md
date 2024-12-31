# 🎄 ESP32 Wi-Fi Beacon Project

Welcome to the **ESP32 Wi-Fi Beacon** project! This project demonstrates how to create a Wi-Fi Access Point using the ESP32 microcontroller, serving a simple web page for a fun game like "Find the Beacon under the Christmas Tree!" 🎅✨

---

## 🌟 Features

- 📡 Creates a Wi-Fi Access Point.
- 🌐 Serves a basic HTML webpage with customizable content.
- 🎮 Perfect for interactive games and fun activities.
- ⚡ Easy to set up and deploy.

---

## 🛠️ Getting Started

### 🔧 Requirements

- An ESP32 development board.
- USB cable for programming.
- Arduino IDE installed on your computer.

### 📥 Installation

1. Clone this repository:
   ```bash
   git clone https://github.com/yourusername/esp32-wifi-beacon.git
   ```
2. Open the `esp32-wifi-beacon.ino` file in Arduino IDE.

3. Install the ESP32 board package:
   - Go to **File > Preferences**.
   - Add this URL to the `Additional Board Manager URLs` field:
     ```
     https://dl.espressif.com/dl/package_esp32_index.json
     ```
   - Open **Tools > Board > Boards Manager**, search for `esp32`, and click **Install**.

4. Select your ESP32 board and COM port from the **Tools** menu.

5. Click **Upload** to flash the code to your ESP32.

---

## 🚀 How It Works

1. After flashing, the ESP32 will create a Wi-Fi network with the name `NYT1`.
2. Connect to the network using the password `findme123`.
3. Open a browser and go to `http://192.168.4.1` to view the web page.
4. Enjoy the game! 🎉

---

## 📋 Code Overview

The main features of the code:

- **Wi-Fi Access Point Setup**: The ESP32 creates a Wi-Fi network using the `WiFi.softAP()` function.
- **HTTP Server**: Serves a simple HTML page with a success message.
- **Serial Debugging**: Outputs connection details and debugging information.

---

## 🖼️ Screenshots

| Feature        | Screenshot               |
|----------------|--------------------------|
| Web Page       | ![Web Page](screenshot1.png) |
| Wi-Fi Network  | ![Wi-Fi Network](screenshot2.png) |

---

## 🌐 Customization

- Change the Wi-Fi network name and password in the code:
  ```cpp
  const char* ssid = "YourNetworkName";
  const char* password = "YourPassword";
  ```
- Update the HTML content to personalize the web page:
  ```cpp
  client.println("<h1>Your Custom Message!</h1>");
  ```

---

## 🛡️ License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

## 🤝 Contributing

Contributions are welcome! Feel free to fork this repository, make improvements, and submit a pull request.

---

## 📞 Contact

For any questions or suggestions, feel free to reach out:
- 💌 Email: yourname@example.com


