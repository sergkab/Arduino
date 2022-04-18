// Arduino таймер CTC прерывание
// avr-libc library includes
#include <avr/io.h>
#include <avr/interrupt.h>


#include "TM1637.h"   // Подключаем библиотеку для работы с модулем

int8_t DispMSG[] = {5, 6, 7, 8};   // Настройка символов для последующего вывода на дислей

//Определяем пины для подключения к плате Arduino
#define CLK 10
#define DIO 11

//Создаём объект класса TM1637, в качестве параметров
//передаём номера пинов подключения
TM1637 tm1637(CLK, DIO);



#define LEDPIN 13

volatile char  flag01 = 0;
char sostLed = 0;

char edmin, desmin;
char edsec = 0;

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

    //OCR1A = 15624; // установка регистра совпадения
    OCR1A = 7812; // установка регистра совпадения

    TCCR1B |= (1 << WGM12);  // включить CTC режим 
    TCCR1B |= (1 << CS10); // Установить биты на коэффициент деления 1024
    TCCR1B |= (1 << CS12);

    TIMSK1 |= (1 << OCIE1A);  // включить прерывание по совпадению таймера 
    sei(); // включить глобальные прерывания

    edmin = 0;
}

void loop()
{
    // основная программа
    
    if ( flag01 == 1 ) {
      digitalWrite(LEDPIN, sostLed);
      
      sostLed = !sostLed ;

      flag01 = 0;

      edsec++;
      if ( edsec > 9 ) {
        edsec = 0;
      }
      DispMSG[3] = edsec;
      tm1637.display(DispMSG);
    }
    
}

ISR(TIMER1_COMPA_vect)
{
    //digitalWrite(LEDPIN, !digitalRead(LEDPIN));
    flag01 = 1;
}
