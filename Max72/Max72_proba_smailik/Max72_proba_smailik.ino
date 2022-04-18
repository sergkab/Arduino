#include <SPI.h>                             // Подключаем библиотеку SPI
#include <Adafruit_GFX.h>                    // Подключаем библиотеку Adafruit_GFX
#include <Max72xxPanel.h>                    // Подключаем библиотеку Max72xxPanel
int pinCS = 9;                               // Указываем к какому выводу подключен контакт CS
int numberOfHorizontalDisplays = 1;          // Количество матриц по горизонтали
int numberOfVerticalDisplays = 4;            // Количество матриц по-вертикали
int x = 0;
int y = 0;
Max72xxPanel matrix = Max72xxPanel(pinCS, numberOfHorizontalDisplays, numberOfVerticalDisplays);

  const byte dig00[8] = {                    // Создаем массив 0
    0b00011000,                               //     ##
    0b00100100,                               //    #  #
    0b01000010,                               //   #    #
    0b01000010,                               //   #    #
    0b01000010,                               //   #    #
    0b01000010,                               //   #    #
    0b00100100,                               //    #  #
    0b00011000                                //     ##
  };                                          

  const byte dig01[8] = {                    // Создаем массив 1
    0b00000100,                               //  .....#..
    0b00001100,                               //      ##
    0b00010100,                               //     # #
    0b00000100,                               //       #
    0b00000100,                               //       #
    0b00000100,                               //       # 
    0b00000100,                               //       #
    0b00001110                                //      ###
  };                                          

   const byte dig02[8] = {                    // Создаем массив 2
    0b00001100,                               //  ....##..
    0b00010010,                               //     #  #
    0b00010010,                               //     #  #
    0b00000010,                               //        #
    0b00000100,                               //       #
    0b00001000,                               //      # 
    0b00010000,                               //     #
    0b00011110                                //     ####
  };                                          

   const byte dig03[8] = {                    // Создаем массив 3
    0b00001100,                               //  ....##..
    0b00010010,                               //     #  #
    0b00000010,                               //        #
    0b00001100,                               //      ##
    0b00000010,                               //        #
    0b00000010,                               //        # 
    0b00010010,                               //     #  #
    0b00001100                                //      ##
  };                                          


void risdig( byte matr[8] ) {
  for (int y = 0; y < 8; y++ ) {            // Передача массива
    for (int x = 0; x < 8; x++ ) {
      matrix.drawPixel(7-x, y, matr[y] & (1 << x));
    }
  }
  matrix.write();
}



// *****************************
void setup() {
  matrix.setIntensity(5);                    // Задаем яркость от 0 до 15
  matrix.setRotation(3);                      // Направление текста 1,2,3,4
}

// ************************
void loop() {
  byte nf[8] = {B00111100, B01000010, B10100101, B10000001, B10111101, B10000001, B01000010, B00111100};
  byte sf[8] = {B00111100, B01000010, B10100101, B10000001, B10011001, B10100101, B01000010, B00111100};
  matrix.fillScreen(LOW);                       // Обнуление матрицы
  
  for (int y = 0; y < 8; y++ ) {            // Передача массива
    for (int x = 0; x < 8; x++ ) {
      matrix.drawPixel(7-x, y, dig00[y] & (1 << x));
    }
  }
  matrix.write();
  
  delay(2000);
  for (int y = 0; y < 8; y++ ) {            // Передача массива
    for (int x = 0; x < 8; x++ ) {
      matrix.drawPixel(7-x, y, dig01[y] & (1 << x));
    }
  }
  matrix.write();
  
  delay(2000);
  for (int y = 0; y < 8; y++ ) {            // Передача массива
    for (int x = 0; x < 8; x++ ) {
      matrix.drawPixel(7-x, y, dig02[y] & (1 << x));
    }
  }
  matrix.write();
  delay(2000);
  
  risdig(dig03);
  delay(2000);

}
// **************************************
