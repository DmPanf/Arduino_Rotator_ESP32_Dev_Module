#include <Servo.h> //используем библиотеку для работы с сервоприводом v1.2

Servo servo; //объявляем переменную servo типа Servo

Servo servo1; //объявляем переменную servo типа Servo1

void setup() //процедура setup

{

servo.attach(10); //привязываем привод 1 к порту 10

servo1.attach(8); //привязываем привод 2 к порту 8

pinMode(LED_BUILTIN, OUTPUT);

}

void loop() //процедура loop

{

digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);              

servo.write(50); //ставим вал под 0
servo1.write(0); //ставим вал под 0

delay(15000); //ждем 15 секунд

servo.write(60); //ставим вал под 30
servo1.write(5); //ставим вал под 180

delay(500); //ждем 0,5 секунды

servo.write(50); //ставим вал под 60
servo1.write(10); //ставим вал под 0

delay(500); //ждем 0,5 секунды

servo.write(60); //ставим вал под 90
servo1.write(15); //ставим вал под 180

delay(500); //ждем 0,5 секунды

servo.write(50); //ставим вал под 120
servo1.write(20); //ставим вал под 0

delay(500); //ждем 0,5 секунды

servo.write(60); //ставим вал под 150
servo1.write(25); //ставим вал под 180

delay(500); //ждем 0,5 секунды

servo.write(50); //ставим вал под 180
servo1.write(30); //ставим вал под 0

delay(500); //ждем 0,5 секунды

servo.write(60); //ставим вал под 60
servo1.write(35); //ставим вал под 0

delay(500); //ждем 0,5 секунды

servo.write(50); //ставим вал под 90
servo1.write(40); //ставим вал под 180

delay(500); //ждем 0,5 секунды

servo.write(60); //ставим вал под 120
servo1.write(45); //ставим вал под 0

delay(500); //ждем 0,5 секунды

servo.write(50); //ставим вал под 150
servo1.write(50); //ставим вал под 180

delay(500); //ждем 0,5 секунды

servo.write(60); //ставим вал под 180
servo1.write(55); //ставим вал под 0

delay(500); //ждем 0,5 секунды

servo.write(50); //ставим вал под 60
servo1.write(60); //ставим вал под 0

delay(500); //ждем 0,5 секунды

servo.write(60); //ставим вал под 90
servo1.write(65); //ставим вал под 180

delay(500); //ждем 0,5 секунды

servo.write(50); //ставим вал под 120
servo1.write(70); //ставим вал под 0

delay(500); //ждем 0,5 секунды

servo.write(60); //ставим вал под 150
servo1.write(75); //ставим вал под 180

delay(500); //ждем 0,5 секунды

servo.write(50); //ставим вал под 180
servo1.write(80); //ставим вал под 0

delay(500); //ждем 0,5 секунды
servo.write(60); //ставим вал под 60
servo1.write(85); //ставим вал под 0

delay(500); //ждем 0,5 секунды

servo.write(50); //ставим вал под 90
servo1.write(90); //ставим вал под 180

delay(500); //ждем 0,5 секунды

}
