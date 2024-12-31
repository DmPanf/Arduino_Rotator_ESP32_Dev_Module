#include <WiFi.h>

const char* ssid = "NYT1"; // Имя Wi-Fi сети
const char* password = nullptr; // Пароль сети

WiFiServer server(80); // Создаем веб-сервер на порту 80

void setup() {
    Serial.begin(115200);
    
    // Запуск точки доступа
    Serial.println("Запуск точки доступа...");
    if (WiFi.softAP(ssid, password, 6, false, 4)) {
        Serial.println("Wi-Fi точка доступа запущена успешно");
        Serial.print("IP-адрес: ");
        Serial.println(WiFi.softAPIP()); // Вывод IP-адреса точки доступа
    } else {
        Serial.println("Ошибка: не удалось запустить точку доступа!");
    }

    // Запуск веб-сервера
    server.begin();
    Serial.println("Веб-сервер запущен");
}

void loop() {
    WiFiClient client = server.available();
    if (client) {
        Serial.println("Клиент подключен");
        client.println("HTTP/1.1 200 OK");
        client.println("Content-type:text/html");
        client.println();
        client.println("<!DOCTYPE html>");
        client.println("<html><body>");
        client.println("<h1>Найди маяк!</h1>");
        client.println("<p>Ты нашел маяк под елкой!</p>");
        client.println("</body></html>");
        client.println();
        client.stop();
        Serial.println("Клиент отключен");
    }
}
