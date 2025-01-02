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
