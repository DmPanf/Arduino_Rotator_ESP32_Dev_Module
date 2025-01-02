### 1. **План подключения**
- **Термодатчики**:
  - Используйте цифровые датчики температуры, например:
    - **DS18B20** (работает по протоколу OneWire).
    - **DHT22/DHT11** (температура и влажность).
  - Подключите датчики к GPIO пинам ESP32.
- **Wi-Fi клиент**:
  - ESP32 подключается к локальной Wi-Fi сети.
  - Устройство отправляет данные на сервер через HTTP или MQTT.

---

### 2. **Алгоритм работы**
1. Подключить термодатчики к ESP32.
2. Считать данные с датчиков.
3. Подключиться к локальной Wi-Fi сети.
4. Отправить данные на сервер (HTTP POST/GET или через MQTT).
5. Повторять цикл через заданный интервал.

---

### 3. **Схема подключения**
#### Пример для **DS18B20**:
- **VCC** → 3.3V ESP32.
- **GND** → GND ESP32.
- **DATA** → GPIO 4 (например).
- Подключите резистор 4.7 кОм между **VCC** и **DATA**.

---

### 4. **Пример кода**
Код для подключения DS18B20 и отправки данных на HTTP-сервер:

```cpp
#include <WiFi.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// Wi-Fi настройки
const char* ssid = "YourWiFiSSID";
const char* password = "YourWiFiPassword";

// Сервер для отправки данных
const char* serverName = "http://yourserver.local/data";

// Пины для DS18B20
#define ONE_WIRE_BUS 4

// Настройка OneWire и DallasTemperature
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(115200);

  // Подключение к Wi-Fi
  Serial.println("Подключение к Wi-Fi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nWi-Fi подключен!");
  Serial.print("IP-адрес: ");
  Serial.println(WiFi.localIP());

  // Инициализация датчиков
  sensors.begin();
}

void loop() {
  // Считывание температуры
  sensors.requestTemperatures();
  float temperature = sensors.getTempCByIndex(0);
  Serial.print("Температура: ");
  Serial.println(temperature);

  // Отправка данных на сервер
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client;
    HTTPClient http;

    String serverPath = serverName + "?temperature=" + String(temperature);

    http.begin(client, serverPath.c_str());
    int httpResponseCode = http.GET();

    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println("Ответ сервера: " + response);
    } else {
      Serial.println("Ошибка отправки данных!");
    }

    http.end();
  } else {
    Serial.println("Нет подключения к Wi-Fi!");
  }

  // Задержка между отправками
  delay(60000); // 60 секунд
}
```

---

### 5. **Настройка сервера**
- **HTTP-сервер**:
  - Разверните сервер (например, с использованием Flask, FastAPI или Node.js).
  - Настройте обработчик для получения данных через GET или POST.
- **MQTT-сервер**:
  - Используйте брокер MQTT (например, Mosquitto).
  - Настройте ESP32 для отправки данных в определённый топик.

---

### 6. **Особенности работы ESP32 как Wi-Fi клиента**
- **Режим STA (Station)**:
  ESP32 подключается к Wi-Fi сети как клиент.
  ```cpp
  WiFi.begin(ssid, password);
  ```
- **Отправка данных через HTTP или MQTT**:
  - HTTP: Легко настроить для локальных серверов.
  - MQTT: Более эффективно для IoT-сетей.

---

### 7. **Расширение функционала**
- Подключить несколько датчиков.
- Сохранять данные в локальной памяти (например, на microSD).
- Развернуть облачный сервер для глобального доступа.

Если потребуется помощь с настройкой сервера или адаптацией кода, дайте знать! 🚀
