/*
Pin 11 (SRCLK) сдвигового регистра 74HC595 на пин 11 на Arduino - это будет называться «синхронизирующим пином»,
Pin 12 (RCLK) сдвигового регистра на пин 12 на Arduino - это будет обозначаться как «пин защелка»,
Pin 14 (SER) сдвигового регистра на пин 13 на Arduino - это будет называться «пином данных»,
*/

int latchPin = 3;  //  RCLK  12
int clockPin = 12;  //  SRCLK 11
int dataPin = 2;   //  SER   14
byte leds = 0;
int currentLED = 0;

void setup()
{
    pinMode(latchPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
    pinMode(clockPin, OUTPUT);

    leds = 0;
}

void loop()
{
    leds = 0;

    if (currentLED == 7)
    {
        currentLED = 0;
    }
    else
    {
        currentLED++;
    }

    bitSet(leds, currentLED);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, leds);
    digitalWrite(latchPin, HIGH);

    delay(250);
}
