// Arduino таймер CTC прерывание
// avr-libc library includes
#include <avr/io.h>
#include <avr/interrupt.h>


#include "TM1637.h"   // Подключаем библиотеку для работы с модулем

int8_t DispMSG[] = {0, 0, 0, 8};   // Настройка символов для последующего вывода на дислей

//Определяем пины для подключения к плате Arduino
#define CLK 10
#define DIO 11

#define f50a 2  //  Частота на кадоды
#define f50b 12

#define LEDPIN 13
#define h_OCR1A 1250;
#define l_OCR1A 1249;

//Создаём объект класса TM1637, в качестве параметров
//передаём номера пинов подключения
TM1637 tm1637(CLK, DIO);



volatile char  flag01 = 0;
char sostLed = 0;

char deschas = 1;
char edchas  = 4;
char desmin  = 5;
char edmin   = 6;
char dessec = 0;
char edsec = 0;
char  f50hz = 0;

void setup()
{
    pinMode(LEDPIN, OUTPUT);

  //Инициализация модуля
  tm1637.init();
  //Установка яркости горения сегментов
  /*
     BRIGHT_TYPICAL = 2 Средний
     BRIGHT_DARKEST = 0 Тёмный
     BRIGHTEST = 7      Яркий
  */
  tm1637.set(BRIGHT_TYPICAL);

  //Задание на включение разделителя
  tm1637.point(true);
  //Выводим массив на дисплей
  tm1637.display(DispMSG);



    // инициализация Timer1
    cli();  // отключить глобальные прерывания
    TCCR1A = 0;   // установить регистры в 0
    TCCR1B = 0;

    //OCR1A = 15624; // установка регистра совпадения 1 гц
    //OCR1A = 1249; // установка регистра совпадения ( 50 гц )
    OCR1A = 1250; // установка регистра совпадения ( 49.96 гц ) ( помедленнее )

    TCCR1B |= (1 << WGM12);  // включить CTC режим 
    /*
    TCCR1B |= (1 << CS10); // Установить биты на коэффициент деления 1024
    TCCR1B |= (1 << CS12);
    */
    TCCR1B |= (0 << CS10); // Установить биты на коэффициент деления 256
    TCCR1B |= (0 << CS11);
    TCCR1B |= (1 << CS12);


    TIMSK1 |= (1 << OCIE1A);  // включить прерывание по совпадению таймера 
    sei(); // включить глобальные прерывания

    //edmin = 0;
}

void loop()
{
    // основная программа

    //  Прерывание 50 гц
    if ( flag01 == 1 ) {
      f50hz++;
      flag01 = 0;
      
      //  секундные импульсы
      if ( f50hz >= 50 ) {
        
        digitalWrite(LEDPIN, sostLed);
        tm1637.point(sostLed);
        sostLed = !sostLed ;

        edsec++;
        if ( edsec > 9 ) {
          edsec = 0;
          dessec++;
          if ( dessec > 5 ) {
            //  increm ed min
            edmin++;
            dessec = 0;
            if ( edmin > 9 ) {
              edmin = 0;
              //  incr des min
              desmin++;
              if ( desmin >5 ) {
                desmin = 0;
                //  incr ed hour
                edchas++;
                if ( ( ( deschas * 10 )+edchas) > 23 ) {
                    deschas = 0;
                    edchas = 0;
                }   //  if ( chas > 23 )
                if ( edchas > 9 ) {
                  edchas = 0;
                  deschas++;
                }   //  if ( edchas > 9 )
                
              }   //  if ( desmin >5 )
            }   //  incr des min
          }
        }
        DispMSG[0] = deschas;
        DispMSG[1] = edchas;
        DispMSG[2] = desmin;
        DispMSG[3] = edmin;
        tm1637.display(DispMSG);
        f50hz = 0;
      }
    }
    
}

ISR(TIMER1_COMPA_vect)
{
    //digitalWrite(LEDPIN, !digitalRead(LEDPIN));
    flag01 = 1;
}
