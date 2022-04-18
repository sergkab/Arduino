/*
DS3231_set.pde
Eric Ayars
4/11

Test of set-time routines for a DS3231 RTC

*/

#include <DS3231.h>
#include <Wire.h>

DS3231 Clock;

byte Year;
byte Month;
byte Date;
byte DoW;
byte Hour;
byte Minute;
byte Second;
bool century = false;


void setup() {
	// Start the serial port
	Serial.begin(57600);

	// Start the I2C interface
	Wire.begin();


  delay(2000);

    Clock.setYear(21);
    Clock.setMonth(3);
    Clock.setDate(24);
    Clock.setHour(15);
    Clock.setMinute(46);

  Serial.print(" S time ");
  Serial.print(Clock.getYear(), DEC);
  Serial.print(" ");
  Serial.print(Clock.getMonth(century), DEC);
  Serial.print(" ");
  Serial.print(Clock.getDate(), DEC);
  Serial.print(" ");
  Serial.println();


    /*
    Clock.setDoW(DoW);
    Clock.setHour(Hour);
    Clock.setMinute(Minute);
    Clock.setSecond(Second);
  */


}

void loop() {

}
