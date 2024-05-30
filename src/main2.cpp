/*
#include <Arduino.h>
#include <string.h>
#include <LiquidCrystal_I2C.h>

// Definición de pines para los botones
#define BTN_1 13
#define BTN_2 2
#define BTN_3 3
#define BTN_4 4
#define BTN_5 5
#define BTN_6 6
#define BTN_7 7
#define BTN_8 8
#define BTN_9 9
#define BTN_L1 10 // Botón de selección
#define BTN_L2 11 // Botón de borrado
#define BTN_SPACE 12

// Variables globales
LiquidCrystal_I2C lcd(0x27, 16, 2);
char displayOutput[32];
int lcd_f = 0;
int lcd_c = 0;
int i = 0;

// Configuración inicial
void setup() {
    Serial.begin(9600);
    lcd.init();
    lcd.backlight();
    lcd.home();
    for (int pin = 2; pin <= 13; pin++) {
        pinMode(pin, INPUT);
    }
}

// Bucle principal
void loop() {
    displayOutput[i] = keyboard();

    switch (displayOutput[i]) {
        case 'd': // Borrar
            if (i > 0) {
                displayOutput[i] = ' ';
                i--;
                lcd_c = (lcd_c == 0 && lcd_f == 1) ? 15 : lcd_c - 1;
                lcd_f = (lcd_c == 15 && lcd_f == 0) ? 1 : lcd_f;
                lcd.setCursor(lcd_c, lcd_f);
            }
            break;
        case 'r': // Reiniciar
            lcd.clear();
            lcd.home();
            lcd_f = 0;
            lcd_c = 0;
            i = 0;
            memset(displayOutput, ' ', sizeof(displayOutput));
            break;
        default:
            lcd.print(displayOutput[i]);
            i++;
            lcd_c++;
            if (lcd_c == 16) {
                lcd_f++;
                lcd_c = 0;
            }
            lcd.setCursor(lcd_c, lcd_f);
            break;
    }
}

// Función principal del teclado
char keyboard() {
    char btn1[] = "1ABC";
    char btn2[] = "2DEF";
    char btn3[] = "3GHI";
    char btn4[] = "4JKL";
    char btn5[] = "5MNn";
    char btn6[] = "6OPQ";
    char btn7[] = "7RST";
    char btn8[] = "8UVW";
    char btn9[] = "9XYZ";
    char btnSpace[] = " ?,";

    while (allButtonsLow()) {
        lcd.setCursor(lcd_c, lcd_f);
        lcd.print("_");
    }

    lcd.setCursor(lcd_c, lcd_f);
    lcd.print(' ');

    if (digitalRead(BTN_1) == HIGH) return handleButtonPress(BTN_1, btn1);
    if (digitalRead(BTN_2) == HIGH) return handleButtonPress(BTN_2, btn2);
    if (digitalRead(BTN_3) == HIGH) return handleButtonPress(BTN_3, btn3);
    if (digitalRead(BTN_4) == HIGH) return handleButtonPress(BTN_4, btn4);
    if (digitalRead(BTN_5) == HIGH) return handleButtonPress(BTN_5, btn5);
    if (digitalRead(BTN_6) == HIGH) return handleButtonPress(BTN_6, btn6);
    if (digitalRead(BTN_7) == HIGH) return handleButtonPress(BTN_7, btn7);
    if (digitalRead(BTN_8) == HIGH) return handleButtonPress(BTN_8, btn8);
    if (digitalRead(BTN_9) == HIGH) return handleButtonPress(BTN_9, btn9);
    if (digitalRead(BTN_SPACE) == HIGH) return handleButtonPress(BTN_SPACE, btnSpace);
    if (digitalRead(BTN_L2) == HIGH) return handleDeleteButtonPress();

    return 0;
}

// Función para manejar la presión de botones
char handleButtonPress(int button, char* characters) {
    int j = 0;
    while (digitalRead(button) == HIGH) {}
    delay(DEBOUNCE_DELAY);
    lcd.blink();
    while (digitalRead(BTN_L1) == LOW) {
        lcd.setCursor(lcd_c, lcd_f);
        lcd.print(characters[j]);
        if (digitalRead(button) == HIGH) {
            while (digitalRead(button) == HIGH) {}
            delay(DEBOUNCE_DELAY);
            j = (j + 1) % 4;
        }
    }
    lcd.noBlink();
    while (digitalRead(BTN_L1) == HIGH) {}
    delay(DEBOUNCE_DELAY);
    return characters[j];
}

// Función para manejar la presión del botón de borrado
char handleDeleteButtonPress() {
    double timeCounterPressed = 0;
    while (digitalRead(BTN_L2) == HIGH) {
        timeCounterPressed += 0.1;
    }
    delay(DEBOUNCE_DELAY);
    return (timeCounterPressed > 10000) ? 'r' : 'd';
}

// Verifica si todos los botones están en estado bajo
bool allButtonsLow() {
    for (int pin = 2; pin <= 13; pin++) {
        if (digitalRead(pin) == HIGH) return false;
    }
    return true;
}

*/