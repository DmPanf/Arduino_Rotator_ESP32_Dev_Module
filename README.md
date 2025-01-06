### ESP32 + DS18B20


---

### Rotator_on_Arduino (for an Arduino microcontroller):
- **`C++`** code for **rotator on Arduino**


### Ver 1. A Stepper Motor. To darken a given HEX color value by a specified factor

1. The "Stepper" library is included to control a stepper motor.
2. **`stepsPerRevolution`** is a constant that defines the number of steps required for the motor to complete one full revolution. It's set to 400, but users might need to adjust this for their specific motor.
3. A **`Stepper`** object named **`myStepper`** is instantiated, indicating that the motor is connected to pins 8, 9, 10, and 11 of the Arduino board.
4. Inside the **`setup()`** function:
 - The speed of the stepper motor is set to 10 RPM.
 - The built-in LED is set as an output.
5. Inside the **`loop()`** function, which runs repeatedly:
 - The built-in LED is turned on, remains on for 500 milliseconds, and then turned off. It remains off for 2500 milliseconds.
 - The stepper motor rotates one full revolution clockwise (in the direction of the clock's hands). It then pauses for 2500 milliseconds.
 - The stepper motor rotates one full revolution counter-clockwise (opposite the direction of the clock's hands). It then pauses for 2500 milliseconds.


### Ver 2. To control a stepper motor to rotate clockwise and counter-clockwise while blinking a built-in LED.

1. The code uses the **`Servo`** library which provides functionality to control servo motors.
2. Two servo objects **`servo`** and **`servo1`** are declared.
3. Within the **`setup()`** function:
 - **`servo`** is attached to pin 10.
 - **`servo1`** is attached to pin 8.
 - The built-in LED is set as an output.
4. Inside the **`loop()`** function (which runs indefinitely):
 - The built-in LED toggles its state (on for 1 second, then off for 1 second).
 - The two servo motors (**`servo`** and **`servo1`**) adjust their positions in a specific sequence. Each adjustment is followed by a half-second delay.
 - After a certain set of positions, there is a longer delay of 15 seconds before the sequence repeats.
        
- **The servos are repeatedly moving between various positions while the LED is blinking in the background.**

---

![image](https://github.com/DmPanf/Arduino_Rotator/assets/99917230/127754ef-0b0b-44de-94c8-69d1f44240ae)

---

### Рекомендации по оптимизации кода:

1. В комментариях указаны очевидные действия, которые делает код. Такие комментарии можно убрать.
2. Для обозначения временных задержек лучше использовать константы. Это делает код более читаемым и позволяет легко изменять значения задержек в одном месте.
3. Чтобы сделать код короче и читаемее, можно использовать цикл и структуры данных, такие как массивы или списки.
   
###

