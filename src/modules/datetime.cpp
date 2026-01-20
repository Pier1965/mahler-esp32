#include "project.h"
#ifdef WIFI
	#include <WiFi.h> 
	#include <WiFiManager.h>
#endif 
#include "modules/datetime.h"
//
void getTime(){
    String ore;
    if (!getLocalTime(&timeinfo)) {
        DEBUG_PRINTLN("NTP non disponibile");
        return;
    }
    if(timeinfo.tm_mday<10)
        Giorno = "0" + String(timeinfo.tm_mday);
    else
        Giorno = String(timeinfo.tm_mday);
    Anno = String(timeinfo.tm_year + 1900);
    Data = dow[timeinfo.tm_wday] + " " + Giorno + " " +  months[timeinfo.tm_mon] + " " + Anno;
    if(timeinfo.tm_hour<10)
        ore = "0" + String(timeinfo.tm_hour);
    else
        ore = String(timeinfo.tm_hour);
    if(timeinfo.tm_min<10)
        minuti = "0" + String(timeinfo.tm_min);
    else
        minuti = String(timeinfo.tm_min);
    Ora = ore + ":" + minuti;
	//
    DEBUG_PRINTLN("Time from Internet  ");
    DEBUG_PRINT(Data);
    DEBUG_PRINT(" - ");
    DEBUG_PRINTLN(Ora);
    //printSCR_MSG(Ora);
}
// init del server ntp
void initTime(){
    // Init and get the time
    unsigned long nsMax = 10000;     //numero di secondi tentativi di connessione al server ntp
    int dt = 400;      //tempo attesa ri-tentativo
    String ore;
    // Verifico connessione wifi
    if (WiFi.status() != WL_CONNECTED) {
        DEBUG_PRINTLN("WiFi non connesso, initTime rimandata");
        printSCR_nonet();
        delay(5000);
        return;
    }
    // config server NTP
    DEBUG_PRINTLN("Config time NTP...");
    printSCR_recuperoora();
    delay(1000);
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
    // setenv("TZ", TZ_INFO, 1);
	// tzset();
	// configTime(0, 0, NTP_SERVER);
    // Attendi fino a max 10s
    unsigned long start = millis();
    while(!getLocalTime(&timeinfo)){
    	if (millis() - start > nsMax) {
            DEBUG_PRINTLN("NTP non sincronizzato, userà orologio locale");
            printSCR_MSG("No NTP, uso ora Esp");
            break;
        } 
        delay(dt);
    }   
    getTime();
    DEBUG_PRINTLN(Ora);
    printSCR_MSG(Ora);
    delay(500);
    /*  
    unsigned int nr = 0;
    unsigned int ntMax = 10;
    while(time(nullptr) <= 150000) {
        DEBUG_PRINTLN("Tentativo di recupero orario...");
        printSCR_MSG("Set ora locale");
        nr++;
        if (nr > ntMax) {
			DEBUG_PRINTLN("Recupero orario fallito...");
            gotTime = false;
            printSCR_MSG("NTP fallito");
            delay(1000);
			break;
		}
        delay(dt);
    }
    if(nr < ntMax){
            DEBUG_PRINTLN("Recupero orario eseguito...");
            printSCR_MSG("NTP Ok");
            gotTime = true;
            getTime();
            printSCR_MSG(Ora);
    }*/ 
}
