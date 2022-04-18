#include <SPI.h>                             // Подключаем библиотеку SPI
#include <Adafruit_GFX.h>                    // Подключаем библиотеку Adafruit_GFX
#include <Max72xxPanel.h>                    // Подключаем библиотеку Max72xxPanel
int pinCS = 9;                               // Указываем к какому выводу подключен контакт CS
int numberOfHorizontalDisplays = 1;          // Количество матриц по горизонтали
int numberOfVerticalDisplays = 4;            // Количество матриц по-вертикали
Max72xxPanel matrix = Max72xxPanel(pinCS, numberOfHorizontalDisplays, numberOfVerticalDisplays);
void setup() {
  matrix.setIntensity(5);                    // Задаем яркость от 0 до 15
  matrix.setRotation(3);                      // Направление текста 1,2,3,4
}
void loop() {
  matrix.drawPixel(3, 3, HIGH);            // Включаем светодиод
  matrix.write();                          // Вывод всех пикселей на матрицу
  delay(500);                              // Пауза
  matrix.drawPixel(6, 7, HIGH);            // Включаем светодиод
  matrix.write();                          // Вывод всех пикселей на матрицу
  delay(500);                              // Пауза
  matrix.drawPixel(6, 7, LOW);             // Выключаем светодиод
  matrix.write();                          // Вывод всех пикселей на матрицу
  delay(500);                              // Пауза
  matrix.drawPixel(3, 3, LOW);             // Выключаем светодиод
  matrix.write();                          // Вывод всех пикселей на матрицу
  delay(500);                              // Пауза
  matrix.drawPixel(6, 7, LOW);             // Выключаем светодиод
  matrix.write();                          // Вывод всех пикселей на матрицу
  delay(500);                              // Пауза
}
