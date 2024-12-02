#include <Arduino.h>
#include "html_File.cpp" // Інший файл


#define LED1 6
#define LED2 7
#define BUTTON1 12

// Налаштування
void setup() {
  Serial.begin(9600);

  pinMode(LED1, 1);
  pinMode(LED2, 1);
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
    digitalWrite(LED1, l_flag);
    // digitalWrite(LED2, l_flag);
    Serial.println(l_flag);
    Serial.println(html_print_text); // Текст з іншого файлу
  }
  if (button == 0 && b_ftag == 1){
    b_ftag = 0;
    Serial.println(Limits);
    // Serial.println(html_main); // Текст з іншого файлу
  }
  delay(20);
}





void loop() {
  but_funk();
}




// // put function declarations here:
// int myFunction(int, int);
// // put your setup code here, to run once:
//   int result = myFunction(2, 3);

// // put function definitions here:
// int myFunction(int x, int y) {
//   return x + y;
// }