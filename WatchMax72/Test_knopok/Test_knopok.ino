/*
 testing knopki
*/

int log1 = LOW;
int log0 = HIGH;
byte key = log0;

// the setup function runs once when you press reset or power the board
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
}

// the loop function runs over and over again forever
void loop() {
  
  while ( key == log0 ) {
    key = digitalRead(3);   // 
  }
  Serial.write("3");
  key = log0;
  delay(1000);                       // wait for a second
  while ( key == log0 ) {
    key = digitalRead(4);   // 
  }
  Serial.write("4");
  key = log0;
  delay(1000);                       // wait for a second
}
