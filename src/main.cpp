#include <Arduino.h>
#include <string.h>
#include "./functions/main_keyboard.h"
#include "../lib/LiquidCrystal/src/LiquidCrystal.h"
#include "../lib/LiquidCrystal_I2C-1.1.2/LiquidCrystal_I2C.h"

// lcd
LiquidCrystal_I2C lcd (0x27, 16, 2);
int lcd_f;
int lcd_c;

// main keyboard
#define BTN_1 2   // 1 a b c
#define BTN_2 3   // 2 d e f
#define BTN_3 4   // 3 g h i
#define BTN_4 5   // 4 j k l
#define BTN_5 6   // 5 m n N
#define BTN_6 7   // 6 o p q
#define BTN_7 8   // 7 r s t
#define BTN_8 9   // 8 u v w
#define BTN_9 10   // 9 x y z
#define BTN_L1 11 // select
#define BTN_L2 12 // delete
#define BTN_SPACE 13
char displayOutput[32];
int i;

// shortcut buttons
#define A1
char a1[20];
#define A2
char a2[20];
#define A3
char a3[20];
#define A4
char a4[20];
#define A5
char a5[20];
#define A6
char a6[20];

#define DEBOUNCE_DELAY 50

// function
char keyboard();
char handleButtonPress(int button, char* characters);
char handleDeleteButtonPress();

void setup() {
	Serial.begin(9600);
	
	lcd.init();
	lcd.backlight();
	lcd.home();

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
    pinMode(BTN_L2, INPUT);
    pinMode(BTN_SPACE, INPUT);


	lcd_f = 0;
	lcd_c = 0;
	i = 0;
}

void loop() {

	displayOutput[i] = keyboard();

	switch (displayOutput[i]){
		
		case 'd':

			if (i == 0){
				break;
			}

			displayOutput[i] = ' ';

			

			i--;
			
			if (lcd_c == 0 && lcd_f == 1) {
				lcd_c = 15;
				lcd_f = 0;
			}
			else {
				lcd_c--;
			}

			lcd.setCursor(lcd_c, lcd_f);

			break;
		case 'r':
	
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
    char btn10[] = " ?,.";

	lcd.setCursor(lcd_c, lcd_f);
	lcd.print("_");

	while (
		digitalRead(BTN_1) == LOW &&
		digitalRead(BTN_2) == LOW &&
		digitalRead(BTN_3) == LOW &&
		digitalRead(BTN_4) == LOW &&
		digitalRead(BTN_5) == LOW &&
		digitalRead(BTN_6) == LOW &&
		digitalRead(BTN_7) == LOW &&
		digitalRead(BTN_8) == LOW &&
		digitalRead(BTN_9) == LOW &&
		digitalRead(BTN_L2) == LOW &&
		digitalRead(BTN_SPACE) == LOW
	){
		
	}

	lcd.setCursor(lcd_c, lcd_f);
	lcd.print(' ');

	if (i == 3) {
		while (digitalRead(BTN_L2) == LOW) {} // limit of the
	}

    if (digitalRead(BTN_1) == HIGH) return handleButtonPress(BTN_1, btn1);
    if (digitalRead(BTN_2) == HIGH) return handleButtonPress(BTN_2, btn2);
    if (digitalRead(BTN_3) == HIGH) return handleButtonPress(BTN_3, btn3);
    if (digitalRead(BTN_4) == HIGH) return handleButtonPress(BTN_4, btn4);
    if (digitalRead(BTN_5) == HIGH) return handleButtonPress(BTN_5, btn5);
    if (digitalRead(BTN_6) == HIGH) return handleButtonPress(BTN_6, btn6);
    if (digitalRead(BTN_7) == HIGH) return handleButtonPress(BTN_7, btn7);
    if (digitalRead(BTN_8) == HIGH) return handleButtonPress(BTN_8, btn8);
    if (digitalRead(BTN_9) == HIGH) return handleButtonPress(BTN_9, btn9);
    if (digitalRead(BTN_SPACE) == HIGH) return handleButtonPress(BTN_SPACE, btn10);
    if (digitalRead(BTN_L2) == HIGH) return handleDeleteButtonPress();

	return 0;
}

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
				
			// Increment j and reboot it if j is > 4
            j = (j + 1) % 4;

		}
	}

	lcd.noBlink();

	while (digitalRead(BTN_L1) == HIGH) {} // captured phantom pulses
	delay(DEBOUNCE_DELAY);

	return characters[j];
}

char handleDeleteButtonPress() {

	double timeCounterPressed = 0;

	while (digitalRead(BTN_L2) == HIGH) {
		timeCounterPressed += 0.1;
	} // captured phantom pulses
	delay(DEBOUNCE_DELAY);

	if (timeCounterPressed > 10000) {
		return 'r'; // reset display
	}
	else {
		return 'd'; // delete
	}


	return 0;
}