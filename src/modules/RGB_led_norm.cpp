#include "project.h"
#include "modules/RGB_led_norm.h"

void init_led(){
	pinMode(redPin, OUTPUT);
	pinMode(greenPin, OUTPUT);
	pinMode(bluePin, OUTPUT);
	digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
	delay(500);
	digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
    delay(500);
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);
    delay(500);
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, HIGH);
    delay(500);
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
}
//
void set_led(unsigned char col_tab){
    digitalWrite(redPin, (colors[col_tab][0] == 255 ? HIGH : LOW));
    digitalWrite(greenPin, (colors[col_tab][1] == 255 ? HIGH : LOW));
    digitalWrite(bluePin, (colors[col_tab][2] == 255 ? HIGH : LOW));
}
//
void flash_led(unsigned int time_on, unsigned int time_off){
  	set_led(static_cast<uint8_t>(STATO));
  	//DEBUG_PRINTLN("LED ON");
    delay(time_on);  
    set_led(static_cast<uint8_t>(AppState::LED_OFF));
    //DEBUG_PRINTLN("LED OFF");
    delay(time_off);
}
