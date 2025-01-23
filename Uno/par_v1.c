// Пины подключения. Константы: stepPin, dirPin и enablePin определяют пины, к которым подключаются соответствующие контакты драйвера A4988.
const int stepPin = 9; // Шаговый вывод
const int dirPin = 8;  // Направление вывода
const int enablePin = 7; // Включить/Выключить драйвер

int I = 200;   // Количество шагов до остановки.  Переменная I: Определяет количество шагов, которое нужно сделать двигателю до остановки.
unsigned long frequency = 500; // Время между шагами в микросекундах
unsigned long delayTime = 1000; // Время стоянки после выполнения I шагов

//Функция setup(): Устанавливает режим работы пинов (OUTPUT) и включает драйвер, установив низкий логический уровень на пин enablePin.
void setup() {
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enablePin, OUTPUT);

  digitalWrite(enablePin, LOW); // Включаем драйвер
}

//Цикл loop(): Выполняется бесконечно.
//Внутри него есть цикл, который выполняется 10 раз.
//В каждом таком цикле двигатель делает I шагов вперёд,
//затем останавливается на заданный промежуток времени,
//потом делает столько же шагов назад и снова останавливается.

void loop() {
  for (int i = 0; i < 10; i++) { // Повторяем вращение 10 раз

    // Двигаем двигатель вперед
    digitalWrite(dirPin, HIGH);
    for (int j = 0; j < I; j++) {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(frequency);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(frequency);
    }

    delay(delayTime); // Пауза перед следующим циклом

//    // Двигаем двигатель назад
//    digitalWrite(dirPin, LOW);
//    for (int k = 0; k < I; k++) {
//      digitalWrite(stepPin, HIGH);
//      delayMicroseconds(frequency);
//      digitalWrite(stepPin, LOW);
//      delayMicroseconds(frequency);
//    }
//
//    delay(delayTime); // Пауза перед следующим циклом
  }
}
