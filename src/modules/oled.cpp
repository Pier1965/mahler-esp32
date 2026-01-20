#include "project.h"
#ifdef WIFI
	#include <WiFi.h> 
	#include <WiFiManager.h>
#endif 
#include "modules/oled.h"
//
void initSCR() {
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    DEBUG_PRINTLN(F("SSD1306 allocation failed... System locked"));
    for(;;); // Don't proceed, loop forever
  }
	display.clearDisplay();
	display.setTextColor(WHITE, BLACK);
	display.setCursor(0, 0);
	display.setTextSize(1);
	display.println("OLED Inizialized");
	display.display();
	DEBUG_PRINTLN(F("SSD1306 allocation succeded!"));
	delay(1000);
	// Display static text
	display.clearDisplay();
	display.setCursor(0, 0);
	display.setTextSize(2);
	display.println("PPPC65");
	display.setCursor(0, 16);
	display.setTextSize(1);
	display.println("Tester Bomba Mahler");
	display.print("Dicembre 2025");
	display.display();
	delay(1000);
}
//
void printSCR_TXTMSG(unsigned char x, unsigned char y, String str){
		display.clearDisplay();
        display.setCursor(x, y);
        display.println(str);
        display.display();
}
void printSCR_notavail(){
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Canale non disponibile...");
    //lcd.setCursor(0, 1);
    display.print("Riconnessione...");
    display.display();
    //delay(1000);
}

void printSCR_yesnet(){
        display.clearDisplay();
        display.setCursor(0, 0);
        display.println("Internet OK");
        display.print("SSID: ");
        display.println(WiFi.SSID());
        display.print("IP: ");
        display.println(WiFi.localIP());
        display.display();
}
void printSCR_nonet(){
        display.clearDisplay();
        display.setCursor(0, 0);
        display.print("No Internet");
        display.display();
}
void printSCR_attesaWL(){
        display.clearDisplay();
        display.setCursor(0, 0);
        display.println("Attesa WIFI!");
        //lcd.setCursor(0, 1);
        display.print("Connessione...");
        display.display();
}
void printSCR_recuperoora(){
        display.clearDisplay();
        display.setCursor(0, 0);
        display.println("Attesa orario!");
        //lcd.setCursor(0, 1);
        display.print("Connessione NTP");
        display.display();
}
void printSCR_MSG(String str){
		display.clearDisplay();
        display.setCursor(0, 0);
        display.println("LOG: ");
        display.println(str);
        display.display();
}
void printSCR_STATO(String str){
        display.setCursor(0, 3*HL);
        display.print("                      ");
        display.setCursor(0, 3*HL);
        display.print("STATO: ");
        display.println(str);
        display.display();
}
void printSCR_lettura(String str){
        display.setCursor(0, 6*HL+2);
        display.setTextSize(2);
        display.print("            ");
        display.setCursor(0, 6*HL+2);
        display.println(str);
        display.setTextSize(1);
        display.display();        
}
void printSCR_email(String str){
        display.setCursor(0, 4*HL);
        display.setTextSize(1);
        display.print("            ");
        display.setCursor(0, 4*HL);
        display.println(str);
        display.setTextSize(1);
        display.display();
}
