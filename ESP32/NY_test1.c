#include <WiFi.h>

const char* ssid = "NYT1"; // Имя Wi-Fi сети
const char* password = "findme123"; // Пароль сети

WiFiServer server(80); // Создаем веб-сервер на порту 80

void setup() {
    Serial.begin(115200);
    
    // Запуск точки доступа
    WiFi.softAP(ssid, password); // Создание Wi-Fi сети
    Serial.println("Wi-Fi точка доступа запущена");
    Serial.print("IP-адрес: ");
    Serial.println(WiFi.softAPIP()); // Вывод IP-адреса точки доступа
    
    // Запуск веб-сервера
    server.begin();
    Serial.println("Веб-сервер запущен");
}

void loop() {
    // Проверка наличия клиентов
    WiFiClient client = server.available();
    if (client) {
        Serial.println("Клиент подключен");
        
        // Ответ с веб-страницей
        client.println("HTTP/1.1 200 OK");
        client.println("Content-type:text/html");
        client.println();
        client.println("<!DOCTYPE html>");
        client.println("<html><body>");
        client.println("<h1>Найди маяк!</h1>");
        client.println("<p>Ты нашел маяк под елкой!</p>");
        client.println("</body></html>");
        client.println();
        
        client.stop(); // Закрытие соединения с клиентом
        Serial.println("Клиент отключен");
    }
}
