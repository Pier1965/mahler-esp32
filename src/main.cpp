/************************************************
  Pierpaolo Garofalo - http://pier.unirc.eu
  Licensed under GNU GPL v3
  29.12.2022
***************************************************************************
1) 24.12.2022 Il wifimanager funziona
2) 25.12.2022 Sensore temperatura 18B20 funziona
3) 26.12.2022 Invio file mail dati temp ok
4) 28.12.2022 Gestione tempo mpilazionelpressione pulsante
5) 28.12.2022 Gestione OLED
6) 29.12.2022 Gestione LED RGB
7) 20.01.2023 Gestione inserimento mail invio dati
8) 17.12.2025
              Esp32 da core2 a core3: cambio funzioni gestione LED rgb
              ESP_Mail_Client aggiornata: usa littleFS al posto di SPIFF
***************************************************************************/
#include "project.h"
//
void setup() {
	delay(2000);
	// Start the Serial Monitor
	#ifdef DEBUG
		Serial.begin(115200);
	#endif
	delay(1000);
	// Inizializzazione led RGB
	DEBUG_PRINTLN("Inizializzo led RGB");
	ledRGB.startLed(50,950);
	ledRGB.setDimming(0.2);
	// Inizializzazione OLED
	DEBUG_PRINTLN("Inizializzo OLED");
	initSCR();
	// Start DS18B20 sensore di temperatura
	DEBUG_PRINTLN("Inizializzo 18B20");
	start_sensor();
	// Inizializzazione tasto
	DEBUG_PRINTLN("Inizializzo pulsante");
	init_button();
	// Inizializzazione wifi e orario NTP
	#ifdef WIFI
		DEBUG_PRINTLN("Inizializzo wifi e orario NTP");
		printSCR_attesaWL();
		delay(1000);
		if(start_wifi())
			printSCR_yesnet();
		else
			printSCR_nonet();
		delay(2000);
		//
		initTime();
	#endif
	delay(2000);
	// Formattazione memoria dati in formato LittleFS
	DEBUG_PRINTLN("Montaggio file system");
	printSCR_MSG("Montaggio file system");
	initFS();
	//
	DEBUG_PRINTLN("Entro in stato ozioso");
	printSCR_MSG("Stato: ozioso");
	STATO = AppState::OZIOSO;
	update_STATO();
}

void loop() {
	update_STATO();
	ledRGB.flash_led();
	delay(1000);
	// Aggiornare i dati accesso WIFI?
	for(;STATO == AppState::OZIOSO;){
		print_temperatura_SCR();
		printSCR_email(recipient);
		chk_button();
		ledRGB.flash_led();
	}
	if(STATO == AppState::AGGWIFI){
		DEBUG_PRINTLN("Configurazione WIFI");
		update_STATO();
		#ifdef WIFI
			check_portal_chg();
		#endif
		delay(1000);
		DEBUG_PRINTLN("Configurazione WIFI eseguita");
		STATO = AppState::OZIOSO;
		update_STATO();
		//ESP.restart();
  	} else
	if(STATO == AppState::TESTING){
		update_STATO();
		DEBUG_PRINTLN("Inizio rilievo temperature");
		printSCR_email(recipient);
		do_test();
		DEBUG_PRINTLN("Rilievo temperature finito");
		STATO = AppState::FINITO;
	}else 
  	if(STATO == AppState::FINITO){
		update_STATO();
		DEBUG_PRINTLN("Invio mail...");
		#ifdef MAIL
		  	send_mail();
		#else
			#warning "No mail!"
		#endif
		update_STATO();
		DEBUG_PRINTLN("Mail inviata");
		delay(1000);
		STATO = AppState::OZIOSO;
  	}
}		
