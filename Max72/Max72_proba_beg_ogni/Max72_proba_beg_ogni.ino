#include <SPI.h>                             // Подключаем библиотеку SPI
#include <Adafruit_GFX.h>                    // Подключаем библиотеку Adafruit_GFX
#include <Max72xxPanel.h>                    // Подключаем библиотеку Max72xxPanel
int pinCS = 9;                               // Указываем к какому выводу подключен контакт CS
int numberOfHorizontalDisplays = 1;          // Количество матриц по горизонтали
int numberOfVerticalDisplays = 4;            // Количество матриц по-вертикали
int x = 0;
int y = 0;
Max72xxPanel matrix = Max72xxPanel(pinCS, numberOfHorizontalDisplays, numberOfVerticalDisplays);
void setup() {
  matrix.setIntensity(5);                    // Задаем яркость от 0 до 15
  matrix.setRotation(3);                      // Направление текста 1,2,3,4
}
void loop() {
  matrix.fillScreen(LOW);                       // Обнуление матрицы
  y = 0;
  for (int x = 0; x < 32; x++ ) { // Передача массива
    matrix.drawPixel(x, y, HIGH);
    matrix.write();
    delay(50);
  }
  x = 31;
  for (int y = 1; y < 8; y++ ) {
    matrix.drawPixel(x, y, HIGH);
    matrix.write();
    delay(50);
  }
  y = 7;
  for (int x = 31; x > 0; x-- ) { // Передача массива
    matrix.drawPixel(x, y, HIGH);
    matrix.write();
    delay(50);
  }
  x = 0;
  for (int y = 8; y > 0; y-- ) {
    matrix.drawPixel(x, y, HIGH);
    matrix.write();
    delay(50);
  }
  y = 0;
  for (int x = 0; x < 32; x++ ) { // Передача массива
    matrix.drawPixel(x, y, LOW);
    matrix.write();
    delay(50);
  }
  x = 31;
  for (int y = 1; y < 8; y++ ) {
    matrix.drawPixel(x, y, LOW);
    matrix.write();
    delay(50);
  }
  y = 7;
  for (int x = 31; x > 0; x-- ) { // Передача массива
    matrix.drawPixel(x, y, LOW);
    matrix.write();
    delay(50);
  }
  x = 0;
  for (int y = 8; y > 0; y-- ) {
    matrix.drawPixel(x, y, LOW);
    matrix.write();
    delay(50);
  }
}
