#include <Arduino.h>

#define LED 3
#define BUTTON1 12

// Налаштування
void setup() {
  Serial.begin(9600);

  pinMode(LED, 1);
  pinMode(BUTTON1, INPUT_PULLUP);
}


boolean l_flag = 0;
boolean b_ftag = 0;
boolean button;
void but_funk(){
  button = !digitalRead(BUTTON1);
  if (button == 1 && b_ftag == 0){
    b_ftag = 1;
    l_flag = !l_flag;
    digitalWrite(LED, l_flag);
    Serial.println(l_flag);
    Serial.println("OK");
  }
  if (button == 0 && b_ftag == 1){
    b_ftag = 0;
  }
  delay(20);
}


void loop() {
  but_funk();
}

