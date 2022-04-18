#include <SPI.h>                             // Подключаем библиотеку SPI
#include <Adafruit_GFX.h>                    // Подключаем библиотеку Adafruit_GFX
#include <Max72xxPanel.h>                    // Подключаем библиотеку Max72xxPanel

#include <DS3231.h>
#include <Wire.h>

DS3231 Clock;

//  Init 7219
int pinCS = 9;                               // Указываем к какому выводу подключен контакт CS
int numberOfHorizontalDisplays = 1;          // Количество матриц по горизонтали
int numberOfVerticalDisplays = 4;            // Количество матриц по-вертикали
int x = 0;
int y = 0;
//byte masmas[8][8];

// byte mass_dot[8];
byte dot_dot =0;

Max72xxPanel matrix = Max72xxPanel(pinCS, numberOfHorizontalDisplays, numberOfVerticalDisplays);

//  for RTC
byte Year;
byte Month;
byte Date;
byte DoW;
byte Hour, edh, desh;
byte Minute, edm, desm;
byte Second;
bool century = false;
bool h12Flag;
bool pmFlag;

byte myMatrix[][3] = {
  {10, 11, 12},
  {13, 14, 15},
  {16, 17, 18},
};

byte masmas[][8] = {                    // Создаем массив 0
 {  0b00011000,                               //     ##
    0b00100100,                               //    #  #
    0b01000010,                               //   #    #
    0b01000010,                               //   #    #
    0b01000010,                               //   #    #
    0b01000010,                               //   #    #
    0b00100100,                               //    #  #
    0b00011000                                //     ##
  } ,                                        

  { 0b00000100,                               //  .....#..
    0b00001100,                               //      ##
    0b00010100,                               //     # #
    0b00000100,                               //       #
    0b00000100,                               //       #
    0b00000100,                               //       # 
    0b00000100,                               //       #
    0b00001110                                //      ###
  } ,                                          

  { 0b00001100,                               //  ....##..
    0b00010010,                               //     #  #
    0b00010010,                               //     #  #
    0b00000010,                               //        #
    0b00000100,                               //       #
    0b00001000,                               //      # 
    0b00010000,                               //     #
    0b00011110                                //     ####
  },                                          

  { 0b00001100,                               //  ....##..
    0b00010010,                               //     #  #
    0b00000010,                               //        #
    0b00001100,                               //      ##
    0b00000010,                               //        #
    0b00000010,                               //        # 
    0b00010010,                               //     #  #
    0b00001100                                //      ##
  } ,                                         

  { 0b00010010,                               //  ...#..#.
    0b00010010,                               //     #  #
    0b00010010,                               //     #  #
    0b00011110,                               //     ####
    0b00000010,                               //        #
    0b00000010,                               //        # 
    0b00000010,                               //        #
    0b00000010                                //        #
  } ,                                         

  { 0b00011110,                               //  ...####.
    0b00010000,                               //     #  
    0b00010000,                               //     #
    0b00001100,                               //      ##
    0b00000010,                               //        #
    0b00000010,                               //        # 
    0b00010010,                               //     #  #
    0b00001100                                //      ##
  } ,                                         

  { 0b00001100,                               //  ....##..
    0b00010010,                               //     #  #
    0b00010000,                               //     #
    0b00011100,                               //     ###
    0b00010010,                               //     #  #
    0b00010010,                               //     #  # 
    0b00010010,                               //     #  #
    0b00001100                                //      ##
  } ,                                         

  { 0b00011110,                               //  ...####.
    0b00000010,                               //        #
    0b00000100,                               //       #
    0b00001000,                               //      #
    0b00001000,                               //      #
    0b00001000,                               //      # 
    0b00001000,                               //      #
    0b00001000                                //      #
  } ,                                         

  { 0b00001100,                               //  ....##..
    0b00010010,                               //     #  #
    0b00010010,                               //     #  #
    0b00001100,                               //      ##
    0b00010010,                               //     #  #
    0b00010010,                               //     #  # 
    0b00010010,                               //     #  #
    0b00001100                                //      ##
  } ,                                         

  { 0b00001100,                               //  ....##..
    0b00010010,                               //     #  #
    0b00010010,                               //     #  #
    0b00010010,                               //     #  #
    0b00001110,                               //      ###
    0b00000010,                               //        # 
    0b00010010,                               //     #  #
    0b00001100                                //      ##
  } } ;                                          



//  ****************###########
//  Процедура отображения цифры ( smech - указывает знакоместо, 7 - первое )
void risdig( byte matr[8], byte smech ) {
  byte tempP;
  for (int y = 0; y < 8; y++ ) {            // Передача массива
    for (int x = 0; x < 8; x++ ) {
      //  отображение точек
      tempP = matr[y] & (1 << x);
      if ( ( smech == 23 ) and ( x == 7 ) and ( ( y==2 ) or ( y==5 ) ) ) {
        tempP = dot_dot;
      }
      matrix.drawPixel(smech-x, y, tempP );
    }
  }
  matrix.write();
}
// *****************


// *****************************
void setup() {

  // Start the serial port
  Serial.begin(57600);

  // Start the I2C interface
  Wire.begin();
  
  matrix.setIntensity(2);                    // Задаем яркость от 0 до 15
  matrix.setRotation(3);                      // Направление текста 1,2,3,4

  //Serial.print(myMatrix[1][1]);
  //myMatrix[1][1];

}
// ******** setup *******

// ************************
void loop() {
  matrix.fillScreen(LOW);                       // Обнуление матрицы
  
  Hour = Clock.getHour(h12Flag, pmFlag);
  Minute = Clock.getMinute();
  desh = int( Hour/10 );
  edh = Hour - ( desh*10 );
  desm = int( Minute/10 );
  edm = Minute - ( desm*10 );

/*
Serial.println(Hour);

Serial.print(desh); Serial.print(" ");
Serial.print(edh); Serial.print(" "); Serial.println(" ");
*/

  risdig(masmas[desh], 7);
  //mass_dot = masmas[edh];
  risdig(masmas[edh], 15);

  risdig(masmas[desm], 23);
  risdig(masmas[edm], 31);

  delay(1000);
  dot_dot = dot_dot+1;
  if ( dot_dot > 1 ) { dot_dot = 0 ; }

 /* 
  risdig(masmas[2], 23);
  delay(2000);
  
  risdig(masmas[3], 31);
  delay(2000);

  matrix.fillScreen(LOW);                       // Обнуление матрицы

  risdig(masmas[4], 7);
  delay(2000);

  risdig(masmas[5], 15);
  delay(2000);

  risdig(masmas[6], 23);
  delay(2000);

  risdig(masmas[7], 31);
  delay(2000);

  matrix.fillScreen(LOW);                       // Обнуление матрицы

  risdig(masmas[8], 7);
  delay(2000);

  risdig(masmas[9], 15);
  delay(2000);
*/

}
// **************************************
