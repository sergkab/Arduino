/*
 testing knopki na drebezg
*/

int log1 = LOW;
int log0 = HIGH;
byte key = log0;
byte prevkey = log0;
long CurTime;
long PrevTime;
int schetchik = 0;

// the setup function runs once
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  Serial.begin(9600);
  CurTime = 0;
  PrevTime = 0;
  Serial.println();
}

// the loop function runs over and over again forever
void loop() {

  key = digitalRead(3);
  if ( key != prevkey ) {
    schetchik = schetchik +1;
    CurTime = micros();
    if ( ( CurTime - PrevTime ) > 500000 ) {
      Serial.println( schetchik );
      Serial.print( " " );
      schetchik = 0;
      PrevTime = CurTime;
    } //  if ( ( CurTime
  } //  if ( key
  prevkey = key;

  
  /*
  //Serial.write("3");
  key = log0;
  delay(1000);                       // wait for a second
  while ( key == log0 ) {
    key = digitalRead(4);   // 
  }
  Serial.write("4");
  key = log0;
  delay(1000);                     // wait for a second
  */
}
