#include <Stepper.h> // библиотека для шагового двигателя v1.2

// количество шагов на 1 оборот, измените значение для вашего мотора
const int stepsPerRevolution = 400;

// устанавливаем порты для подключения драйвера
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

void setup() {
  myStepper.setSpeed(10); // устанавливаем скорость 60 об/мин
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(500);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(2500);      

  // поворачиваем ротор по часовой стрелке
  myStepper.step(stepsPerRevolution);
  delay(2500);

  // поворачиваем ротор против часовой стрелки
  myStepper.step(-stepsPerRevolution);
  delay(2500);
}
