#include "TM1637.h" // подключение библиотеки
#define CLK 0 
#define DIO 1 
#define Pulse 2 // Выход для сигнализации 
int timer_val=1; // Обратный отсчет в минутах 
int timer_seconds=00; // Отображение секунд 
// Переменные для хранения индивидуальных номеров 
int firstnum=0; 
int secondnum=0; 
int thirdnum=0; 
int fournum=0; 
TM1637 tm1637(CLK,DIO); // Настройка индикатора
void setup(){ 
   pinMode(Pulse, OUTPUT); 
   digitalWrite(Pulse, LOW); 
   tm1637.init(); // Сброс дисплея 
   tm1637.set(BRIGHT_TYPICAL); // Уровень яркости 
   // BRIGHT_DARKEST = 0,BRIGHTEST = 7 BRIGHT_TYPICAL = 2&#894;
   tm1637.point(POINT_ON); // Активация точки посредине 
   delay(1000); // Задержка 1 секунда
} 
void loop() { 
   // Проверка, запустился ли таймер 
   while (timer_val == 0 && timer_seconds == 0) { 
      tm1637.clearDisplay(); // Очистка дисплея 
      tm1637.display(0,0); 
      tm1637.display(1,0); 
      tm1637.display(2,0); 
      tm1637.display(3,0); 
      digitalWrite(Pulse, HIGH); // Активация сигнализации 
      delay(1000);  // Wait
      tm1637.clearDisplay(); 
      digitalWrite(Pulse, LOW); // Отключение сигнализации
      delay(500); // Ждем полсекунды
   } 
   // Распределяем минуты и сикунды по отдельным сегментам 
   if (timer_val > 9) { 
      firstnum = timer_val/10%10; 
      secondnum = timer_val%10; 
   } 
   else { 
      secondnum = timer_val; 
   } 
   if (timer_seconds > 9) { 
      thirdnum = timer_seconds/10%10; 
      fournum = timer_seconds%10; 
   } 
   else { 
      thirdnum = 0; 
      fournum = timer_seconds; 
   } 
   // Отображаем обратный отсчет
   tm1637.clearDisplay(); // Очистка дисплея
   if (timer_val > 9) { 
      tm1637.display(0,firstnum); 
   } 
   if (timer_val > 0) { 
      tm1637.display(1,secondnum); 
   } 
   if (timer_seconds > 9 || timer_val > 0) { 
      tm1637.display(2,thirdnum); 
   } 
   tm1637.display(3,fournum); 
   // Decrease seconds 
   timer_seconds=timer_seconds-1; 
   delay(1000); // Delay of 1 second 
   // Decrease timer 
   if (timer_seconds == -1) { 
      timer_val=timer_val-1; 
      timer_seconds=59; 
   } 
}
