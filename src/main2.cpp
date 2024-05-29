/*
#include <Arduino.h>

// main keyboard
#define BTN_1 13   // 1 a b c
#define BTN_2 2   // 2 d e f
#define BTN_3 3   // 3 g h i
#define BTN_4 4   // 4 j k l
#define BTN_5 5   // 5 m n N
#define BTN_6 6   // 6 o p q
#define BTN_7 7   // 7 r s t
#define BTN_8 8   // 8 u v w
#define BTN_9 9   // 9 x y z

#define BTN_L1 10 // select

void setup() {
	Serial.begin(9600);

    pinMode(BTN_1, INPUT);
    pinMode(BTN_2, INPUT);
    pinMode(BTN_3, INPUT);
    pinMode(BTN_4, INPUT);
    pinMode(BTN_5, INPUT);
    pinMode(BTN_6, INPUT);
    pinMode(BTN_7, INPUT);
    pinMode(BTN_8, INPUT);
    pinMode(BTN_9, INPUT);
    pinMode(BTN_L1, INPUT);
}

void loop() {

    while (digitalRead(BTN_L1) == LOW) {

         if (digitalRead(BTN_1) == HIGH) {
            Serial.println("BTN 1");
            while (digitalRead(BTN_1) == HIGH) {}
            break;
        }
        if (digitalRead(BTN_2) == HIGH) {
            Serial.println("BTN 2");
            while (digitalRead(BTN_2) == HIGH) {}
            break;
        }
        if (digitalRead(BTN_3) == HIGH) {
            Serial.println("BTN 3");
            while (digitalRead(BTN_3) == HIGH) {}
            break;
        }
        if (digitalRead(BTN_4) == HIGH) {
            Serial.println("BTN 4");
            while (digitalRead(BTN_4) == HIGH) {}
            break;
        }
        if (digitalRead(BTN_5) == HIGH) {
            Serial.println("BTN 5");
            while (digitalRead(BTN_5) == HIGH) {}
            break;
        }
        if (digitalRead(BTN_6) == HIGH) {
            Serial.println("BTN 6");
            while (digitalRead(BTN_6) == HIGH) {}
            break;
        }
        if (digitalRead(BTN_7) == HIGH) {
            Serial.println("BTN 7");
            while (digitalRead(BTN_7) == HIGH) {}
            break;
        }
        if (digitalRead(BTN_8) == HIGH) {
            Serial.println("BTN 8");
            while (digitalRead(BTN_8) == HIGH) {}
            break;
        }
        if (digitalRead(BTN_9) == HIGH) {
            Serial.println("BTN 9");
            while (digitalRead(BTN_9) == HIGH) {}
            delay(50);
            break;
        }
    }

    while (digitalRead(BTN_L1) == HIGH) {}

}
*/