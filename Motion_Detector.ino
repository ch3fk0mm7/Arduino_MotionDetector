const int pirPin1 = 2;
const int pirPin2 = 4;
const int relPin1 = 6;
const int relPin2 = 8;
const int led = 13;

const long interval = 15000;
unsigned long previousMillis = 0;     

int pirState = LOW;
int relState = LOW;

void setup() {
  // put your setup code here, to run once:
pinMode(pirPin1, INPUT);
pinMode(pirPin2, INPUT);
pinMode(relPin1, OUTPUT);
pinMode(relPin2, OUTPUT);
pinMode(led, OUTPUT);
}

void loop() {
  pirState = digitalRead(pirPin1);

  unsigned long currentMillis = millis();
  
  if (pirState == HIGH) {
    previousMillis = currentMillis;
    relState = LOW;
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW); 
    if (currentMillis - previousMillis >= interval) {
      relState = HIGH;
    }
  }

digitalWrite(relPin1, relState);
digitalWrite(relPin2, HIGH);
}
