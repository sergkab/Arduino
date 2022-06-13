
/*
  Добавлено моргание точек 
  This example code is in the public domain.
 */
 
#include <DS1307.h>
// Init the DS1307
DS1307 rtc(12, 13);
// Init a Time-data structure
Time  t;
 
int anod_tochki = 0;

int katod1 = 2;
int katod2 = 3;

int anod_a1 = 5;
int anod_b1 = 4;
int anod_c1 = 7;
int anod_d1 = 6;
int anod_e1 = 6;
int anod_g1 = 5;

int anod_a2 = 10;
int anod_b2 = 8;
int anod_c2 = 9;
int anod_d2 = 9;
int anod_e2 = 7;
int anod_f2 = 10;
int anod_g2 = 8;

int anod_a3 = 11;
int anod_b3 = 19;
int anod_c3 = 18;
int anod_d3 = 18;
int anod_e3 = 17;
int anod_f3 = 11;
int anod_g3 = 19;

int anod_a4 = 14;
int anod_b4 = 16;
int anod_c4 = 15;
int anod_d4 = 15;
int anod_e4 = 17;
int anod_f4 = 14;
int anod_g4 = 16;

char MasDig1[10];
char MasDig2[10];
char Cifra[4];
char myTemp;
char nomKatod = 1;
char isTochka = 1;

int buf;
long tecVr=0;
long lastVr=0;
char IndDig = 0;
int valKey;


// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  //pinMode(led, OUTPUT);     
  pinMode(0, OUTPUT);     
  pinMode(2, OUTPUT);     
  pinMode(3, OUTPUT);     
  pinMode(4, OUTPUT);     
  pinMode(5, OUTPUT);     
  pinMode(6, OUTPUT);     
  pinMode(7, OUTPUT);     
  pinMode(8, OUTPUT);     
  pinMode(9, OUTPUT);     
  pinMode(10, OUTPUT);     
  pinMode(11, OUTPUT);     
  pinMode(14, OUTPUT);     
  pinMode(15, OUTPUT);     
  pinMode(16, OUTPUT);     
  pinMode(17, OUTPUT);     
  pinMode(18, OUTPUT);     
  pinMode(19, OUTPUT);
  //
  digitalWrite(4, HIGH);   // 
  digitalWrite(5, HIGH);   // 
  digitalWrite(6, HIGH);   // 
  digitalWrite(7, HIGH);   // 
  digitalWrite(8, HIGH);   // 
  digitalWrite(9, HIGH);   // 
  digitalWrite(10, HIGH);   // 
  digitalWrite(11, HIGH);   // 
  digitalWrite(14, HIGH);   // 
  digitalWrite(15, HIGH);   // 
  digitalWrite(16, HIGH);   // 
  digitalWrite(17, HIGH);   // 
  digitalWrite(18, HIGH);   // 
  digitalWrite(19, HIGH);   //
  MasDig1[0] = 0 ;
  MasDig1[1] = 0x30 ;
  MasDig1[2] = 0x6D ;

  MasDig2[0] = 0x7E ;
  MasDig2[1] = 0x30 ;
  MasDig2[2] = 0x6D ;
  MasDig2[3] = 0x79 ;
  MasDig2[4] = 0x33 ;
  MasDig2[5] = 0x5B ;
  MasDig2[6] = 0x5F ;
  MasDig2[7] = 0x70 ;
  MasDig2[8] = 0x7F ;
  MasDig2[9] = 0x7B ;
  
  
  Cifra[0] = Cifra[1] = Cifra[2] = Cifra[3] = 0;
  
  //Serial.begin(9600);
  lastVr = millis();

 // Set the clock to run-mode
  rtc.halt(false);
  
  digitalWrite(anod_tochki, 1 );
  delay ( 500 );
}

// the loop routine runs over and over again forever:
void loop() {

  tecVr = millis();
  if ( ( tecVr - lastVr) > 1000 ) {
    IndDig++; if ( IndDig > 9 ) { IndDig = 0; };
    lastVr = tecVr;
    if ( isTochka == 0 ) { isTochka = 1; } else { isTochka = 0; } ;  //  разделительные точки
    digitalWrite(anod_tochki, isTochka );
    // Get data from the DS1307
    t = rtc.getTime();
    Cifra[0] = t.hour / 10 ;
    Cifra[1] = t.hour - ( Cifra[0] * 10 ) ;
    Cifra[2] = t.min / 10 ;
    Cifra[3] = t.min - ( Cifra[2] * 10 ) ;

    valKey = 0 ;
    buf = analogRead ( 6 ) ;
    //Serial.print ( buf ) ;
    if ( buf < 700 ) {
      if ( buf > 550 ) { valKey = 2; buf = 0; };
      if ( buf > 490 ) { valKey = 3; buf = 0; };
      if ( buf > 380 ) { valKey = 4; buf = 0; };
      if ( buf > 200 ) { valKey = 5; buf = 0; };
      if ( buf < 20  ) { valKey = 1; buf = 0; };
    switch ( valKey ) {
      case 5 :
      if ( t.min < 59 ) { t.min++; };
      break;
      case 4 :
      if ( t.min > 0 ) { t.min--; };
      break;
      case 3 :
      if ( t.hour < 59 ) { t.hour++; };
      break;
      case 2 :
      if ( t.hour > 0 ) { t.hour--; };
      break;
    }  //  switch
    rtc.setTime( t.hour, t.min, 0);
    rtc.halt(false);
  }    //  if ( buf
  // Initialize the rtc object
  //rtc.begin();

    //Serial.println ( valKey ) ;
  }  //  if ( ( tecVr
  
  if ( nomKatod == 1 ) {
      myTemp = Cifra[0];    //  десятки часов
      digitalWrite(anod_a1, ( MasDig1[myTemp] >> 6 ) & 1 );   // массив дес час
      digitalWrite(anod_d1, ( MasDig1[myTemp] >> 3 ) & 1 );   // 

      myTemp = Cifra[1];    //  един часов
      digitalWrite(anod_d2, ( MasDig2[myTemp] >> 3 ) & 1 );   // массив ед час
      digitalWrite(anod_e2, ( MasDig2[myTemp] >> 2 ) & 1 );
      digitalWrite(anod_f2, ( MasDig2[myTemp] >> 1 ) & 1 );
      digitalWrite(anod_g2, ( MasDig2[myTemp] ) & 1 );

      myTemp = Cifra[2];    //  десятки мин
      digitalWrite(anod_a3, ( MasDig2[myTemp] >> 6 ) & 1 );
      digitalWrite(anod_b3, ( MasDig2[myTemp] >> 5 ) & 1 );
      digitalWrite(anod_c3, ( MasDig2[myTemp] >> 4) & 1 );

      myTemp = Cifra[3];    //  един мин
      digitalWrite(anod_d4, ( MasDig2[myTemp] >> 3 ) & 1 );   // массив ед час
      digitalWrite(anod_e4, ( MasDig2[myTemp] >> 2 ) & 1 );
      digitalWrite(anod_f4, ( MasDig2[myTemp] >> 1 ) & 1 );
      digitalWrite(anod_g4, ( MasDig2[myTemp] ) & 1 );

      digitalWrite(katod1, HIGH );

  } else {  //  esli nomKatod == 2
      myTemp = Cifra[0];    //  десятки часов
      digitalWrite(anod_b1, ( MasDig1[myTemp] >> 5 ) & 1 );   // массив дес час
      digitalWrite(anod_c1, ( MasDig1[myTemp] >> 4 ) & 1 );   // 
      digitalWrite(anod_e1, ( MasDig1[myTemp] >> 2 ) & 1 );   //
      digitalWrite(anod_g1, ( MasDig1[myTemp] ) & 1 );   // 

      myTemp = Cifra[1];    //  един часов
      digitalWrite(anod_a2, ( MasDig2[myTemp] >> 6 ) & 1 );   // массив ед час
      digitalWrite(anod_b2, ( MasDig2[myTemp] >> 5 ) & 1 );
      digitalWrite(anod_c2, ( MasDig2[myTemp] >> 4 ) & 1 );

      myTemp = Cifra[2];    //  десятки мин
      digitalWrite(anod_d3, ( MasDig2[myTemp] >> 3 ) & 1 );
      digitalWrite(anod_e3, ( MasDig2[myTemp] >> 2 ) & 1 );
      digitalWrite(anod_f3, ( MasDig2[myTemp] >> 1 ) & 1 );
      digitalWrite(anod_g3, ( MasDig2[myTemp] ) & 1 );   // 

      myTemp = Cifra[3];    //  един мин
      digitalWrite(anod_a4, ( MasDig2[myTemp] >> 6 ) & 1 );   // массив ед час
      digitalWrite(anod_b4, ( MasDig2[myTemp] >> 5 ) & 1 );
      digitalWrite(anod_c4, ( MasDig2[myTemp] >> 4 ) & 1 );
      
      digitalWrite(katod2, HIGH );
  };  // if nomKatod
  
//  delayMicroseconds(3000);               // 
  delay(3);               // 
  digitalWrite(katod1, LOW );
  digitalWrite(katod2, LOW
  );
  if ( nomKatod == 1 ) {
      nomKatod = 2;
  } else {
      nomKatod = 1;
  };
  


//  Serial.println ( "ok");
}
