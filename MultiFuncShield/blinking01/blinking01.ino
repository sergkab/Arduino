
void setup(){
pinMode(10, OUTPUT);//устанавливаем вывод 10 как выход
pinMode(11, OUTPUT);//устанавливаем вывод 11 как выход
pinMode(12, OUTPUT);//устанавливаем вывод 12 как выход
pinMode(13, OUTPUT);//устанавливаем вывод 13 как выход
}


void loop(){
//==========зажигаем и гасим все 4 светодиода с паузой 1 сек.===============
digitalWrite(10, LOW); //включаем LED (pin 10)
digitalWrite(11, LOW); //включаем LED (pin 11)
digitalWrite(12, LOW); //включаем LED (pin 12)
digitalWrite(13, LOW); //включаем LED (pin 13)
delay(1000); //пауза 1 секунда
digitalWrite(10, HIGH); //выключаем LED (pin 10)
digitalWrite(11, HIGH); //выключаем LED (pin 11)
digitalWrite(12, HIGH); //выключаем LED (pin 12)
digitalWrite(13, HIGH); //выключаем LED (pin 13)
delay(1000); // пауза 1 секунда
 
//==========зажигаем и гасим 4 светодиода по очереди с паузой 1 сек.===============
digitalWrite(10, LOW); //включаем LED (pin 10)
delay(1000); //пауза 1 секунда
digitalWrite(11, LOW); //включаем LED (pin 11)
delay(1000); //пауза 1 секунда
digitalWrite(12, LOW); //включаем LED (pin 12)
delay(1000); //пауза 1 секунда
digitalWrite(13, LOW); //включаем LED (pin 13)
delay(1000); //пауза 1 секунда
digitalWrite(10, HIGH); //выключаем LED (pin 10)
delay(1000); //пауза 1 секунда
digitalWrite(11, HIGH); //выключаем LED (pin 11)
delay(1000); //пауза 1 секунда
digitalWrite(12, HIGH); //выключаем LED (pin 12)
delay(1000); //пауза 1 секунда
digitalWrite(13, HIGH); //выключаем LED (pin 13)
delay(1000); // пауза 1 секунда
}
