const int pirPin = 2;
const int relPin = 3;
const int led = 13;

const long interval = 10000;
unsigned long previousMillis = 0;     

int pirState = LOW;
int relState = LOW;

void setup() {
  // put your setup code here, to run once:
pinMode(pirPin, INPUT);
pinMode(relPin, OUTPUT);
pinMode(led, OUTPUT);  
}

void loop() {
  pirState = digitalRead(pirPin);

  unsigned long currentMillis = millis();
  
  if (pirState == HIGH) {
    previousMillis = currentMillis;
    relState = HIGH;
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW); 
    if (currentMillis - previousMillis >= interval) {
      relState = LOW;
    }
  }

digitalWrite(relPin, relState);
}
