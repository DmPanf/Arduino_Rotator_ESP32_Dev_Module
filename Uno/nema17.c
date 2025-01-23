// Подключение шагового двигателя Nema 17 с драйвером A4988

// Пины для подключения
const int stepPin = 3; // Пин для шага
const int dirPin = 4;  // Пин для направления

// Переменные
int I = 200;            // Количество шагов на цикл (например, полный оборот)
int frequency = 500;    // Время между шагами в мкс (частота шагов)
int delayTime = 1000;   // Время паузы после выполнения цикла (мс)
int repeatCount = 10;   // Количество повторений цикла

void setup() {
  // Настройка пинов
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

  // Установка начального направления
  digitalWrite(dirPin, HIGH); // HIGH - по часовой, LOW - против
}

void loop() {
  for (int i = 0; i < repeatCount; i++) {
    // Выполнение одного цикла вращения
    for (int step = 0; step < I; step++) {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(frequency);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(frequency);
    }

    // Пауза после цикла
    delay(delayTime);
  }

  // Остановка выполнения программы
  while (true);
}
