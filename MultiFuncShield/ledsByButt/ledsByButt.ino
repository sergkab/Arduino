
//зажигаем светодиоды кнопками
 
int ledpin1 = 10; //задаем переменную ledpin1 и подсоединяем к выводу 10
int ledpin2 = 11; //задаем переменную ledpin2 и подсоединяем к выводу 11
int ledpin3 = 12; //задаем переменную ledpin3 и подсоединяем к выводу 12
int inpin1=A1; //задаем переменную inpin1 и подсоединяем к выводу A1
int inpin2=A2; //задаем переменную inpin2 и подсоединяем к выводу A2
int inpin3=A3; //задаем переменную inpin3 и подсоединяем к выводу A3
 
int val;//задаем переменную val
 
void setup(){
pinMode(ledpin1,OUTPUT);//устанавливаем вывод 10 как выход
pinMode(ledpin2,OUTPUT);//устанавливаем вывод 11 как выход
pinMode(ledpin3,OUTPUT);//устанавливаем вывод 12 как выход
pinMode(inpin1,INPUT);//устанавливаем вывод A1 как вход
pinMode(inpin2,INPUT);//устанавливаем вывод A2 как вход
pinMode(inpin3,INPUT);//устанавливаем вывод A3 как вход
}


void loop(){
val=digitalRead(inpin1);//считываем данные порта в переменную val
if(val==LOW)           //выполняем условие, если в переменную записан 0, то гасим светодиод
{ digitalWrite(ledpin1,LOW);}
else  //иначе, включаем
{ digitalWrite(ledpin1,HIGH);}
 
val=digitalRead(inpin2);//считываем данные порта в переменную val
if(val==LOW)           //выполняем условие, если в переменную записан 0, то гасим светодиод
{ digitalWrite(ledpin2,LOW);}
else  //иначе, включаем
{ digitalWrite(ledpin2,HIGH);}
 
val=digitalRead(inpin3);//считываем данные порта в переменную val
if(val==LOW)           //выполняем условие, если в переменную записан 0, то гасим светодиод
{ digitalWrite(ledpin3,LOW);}
else  //иначе, включаем
{ digitalWrite(ledpin3,HIGH);}
}
