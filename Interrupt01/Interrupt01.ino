// Arduino таймер CTC прерывание
// avr-libc library includes
#include <avr/io.h>
#include <avr/interrupt.h>

#define LEDPIN 13

volatile char  flag01 = 0;
char sostLed = 0;

void setup()
{
    pinMode(LEDPIN, OUTPUT);

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
}

void loop()
{
    // основная программа
    
    if ( flag01 == 1 ) {
      digitalWrite(LEDPIN, sostLed);
      
      sostLed = !sostLed ;

      flag01 = 0;
    }
    
}

ISR(TIMER1_COMPA_vect)
{
    //digitalWrite(LEDPIN, !digitalRead(LEDPIN));
    flag01 = 1;
}
