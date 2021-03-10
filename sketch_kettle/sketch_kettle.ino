#include <OneWire.h> 
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 7

const int buttonPin = A1;
bool buttonPressed = false;
unsigned long lastTime;

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  sensors.begin();
  sensors.setResolution(10);
  lastTime = millis();
  pinMode(buttonPin, INPUT);
}

float getTemp(int index=0) {
  sensors.requestTemperatures(); // Send the command to get temperature readings
  return sensors.getTempCByIndex(index);
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonState = digitalRead(buttonPin);
  if ((millis() - lastTime) >= 1000UL) {
    lastTime = millis();
    for (int i = 0; i < 3; i++) {
      Serial.print(millis());
      Serial.print(";");
      Serial.print(i);
      Serial.print(";");
      Serial.println(getTemp(i));
    }
  }
  
  if (buttonPressed == false and buttonState == HIGH) {
    buttonPressed = true;
    Serial.print(millis());
    Serial.println(";P;TEMP");
  } else if (buttonState != HIGH) {
    buttonPressed = false;
  }
}
