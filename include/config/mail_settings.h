#pragma once
//
// CONFIGURAZIONE POSTA ELETTRONICA 
//
#ifdef MAIL
	// char recipient[50]="xxxx@xxxx.xxx";    // <------------ mail destinatario default
														// in global_variables.h
	constexpr char RECIPIENT2[] = "Mahler Bomb Tester";       // <------------ nome destinatario
	/** The smtp port e.g.
	 * 25  or esp_mail_smtp_port_25
	 * 465 or esp_mail_smtp_port_465
	 * 587 or esp_mail_smtp_port_587
	 */
	constexpr char SMTP_HOST[] = "smtp.xxxx.xx";	// <------------ servizio posta smtp mittente
	#define SMTP_PORT esp_mail_smtp_port_465		// <------------ porta smtp server
	/* The log in credentials */
	constexpr char AUTHOR_EMAIL[] = "xxxx@xxxx.xx";	// <------------ mail mittente
	constexpr char AUTHOR_PASSWORD[] = "xxxxx";	// <------------ password mail mittente
	constexpr char ESP_NAME[] = "ESP Mahler";
	constexpr char OGGETTO[] = "Test calorimetro di Mahler";
	constexpr char MESSAGGIO[] = "rilievo profilo di temperatura prova con calorimetro di Mahler ";
#endif
