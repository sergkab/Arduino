

#define ON LOW   //задаем включение зуммера
#define OFF HIGH //задаем выключение зуммера
#define BUZZER 3 //подключаем зуммер к пину 3
#define KEY1 A1  //подключаем кнопку к пину А1

void setup(){
 
/* конфигурируем выводы*/
pinMode(KEY1, INPUT); //кнопка А1 как вход
pinMode(BUZZER,  OUTPUT); //зуммер 3 как выход
digitalWrite(BUZZER, OFF);//выключаем звук зуммера
}
 
void loop(){
 
if( digitalRead(KEY1)==ON ) //нажимаем кнопку KEY1
{
digitalWrite(BUZZER, ON); //зуммер включен
}
else{
digitalWrite(BUZZER, OFF); //зуммер выключен
}
}
