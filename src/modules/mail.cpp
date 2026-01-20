#include "project.h"   
#ifdef MAIL
	#include <WiFi.h> 
	// Mail caricata qui solo dopo che il WIFI funziona
	#include <ESP_Mail_Client.h>
	#include "modules/mail.h"
	/* Declare the global used SMTPSession object for SMTP transport */
	//SMTPSession smtp;
	const char rootCACert[] PROGMEM = "-----BEGIN CERTIFICATE-----\n"
		                              "-----END CERTIFICATE-----\n";
	void send_mail()
	{
		if (WiFi.status() != WL_CONNECTED){
			DEBUG_PRINTLN("Mail: no WiFi...");
			delay(1000);
			return;
		}
		/* Set the callback function to get the sending results */
	  SMTPSession smtp;
		/* Declare the ESP_Mail_Session for user defined session credentials */
	  ESP_Mail_Session session;
	  /*  Set the network reconnection option */
	  MailClient.networkReconnect(true);
	  /** Enable the debug via Serial port
	   * 0 for no debugging
	   * 1 for basic level debugging
	   *
	   * Debug port can be changed via ESP_MAIL_DEFAULT_DEBUG_PORT in ESP_Mail_FS.h
	   */
	  smtp.debug(1);
	  smtp.callback(smtpCallback);
	  /* Set the session config */
	  session.server.host_name = SMTP_HOST;
	  session.server.port = SMTP_PORT;
	  session.login.email = AUTHOR_EMAIL;
	  session.login.password = AUTHOR_PASSWORD;
	  session.login.user_domain = F("mydomain.net");
	  /* Set the NTP config time */
	  session.time.ntp_server = F("pool.ntp.org,time.nist.gov");
	  session.time.gmt_offset = 1; // ora di Roma
	  session.time.day_light_offset = 0;
	  /* Declare the message class */
	  SMTP_Message message;
	  /* Set the message headers */
	  message.sender.name = F(ESP_NAME); // This witll be used with 'MAIL FROM' command and 'From' header field.
	  message.sender.email = AUTHOR_EMAIL; // This witll be used with 'From' header field.
	  message.subject = F(OGGETTO);
	  //message.addRecipient(F(RECIPIENT2), F(RECIPIENT1)); // This will be used with RCPT TO command and 'To' header field.
	  message.addRecipient(F(RECIPIENT2), F(recipient)); // This will be used with RCPT TO command and 'To' header field.
	  initTime();
	  String textMsg = MESSAGGIO + Data + " alle " + Ora;
	  message.text.content = textMsg;
	  message.text.charSet = F("us-ascii");
	  message.text.transfer_encoding = Content_Transfer_Encoding::enc_7bit;
	  message.priority = esp_mail_smtp_priority::esp_mail_smtp_priority_low;
	  /* Set the custom message header */
	  message.addHeader(F("Message-ID: <abcde.fghij@gmail.com>"));
	  /* The attachment data item */
	  SMTP_Attachment att;
	  message.resetAttachItem(att);
	  att.descr.filename = "fileDati.txt";
	  att.descr.mime = "text/plain"; //txt data
	  att.file.path = "/fileDati.txt";
	  att.file.storage_type = esp_mail_file_storage_type_flash;
	  att.descr.transfer_encoding = Content_Transfer_Encoding::enc_base64;
	  /* Add attachment to the message */
	  message.addAttachment(att);
	  /* Connect to the server */
	  smtp.setTCPTimeout(60);   // secondi
	  if (!smtp.connect(&session /* session credentials */)){
	  	DEBUG_PRINTLN("Mail: SMTP connec failed");
	  	delay(1000);
		return;
	  }
	  /* Start sending Email and close the session */
	  if (!MailClient.sendMail(&smtp, &message))
		DEBUG_PRINTLN("Error sending Email, " + smtp.errorReason());
	  ESP_MAIL_PRINTF("Free Heap: %d\n", MailClient.getFreeHeap());
	}
	//
	/* Callback function to get the Email sending status */
	//
	void smtpCallback(SMTP_Status status)
	{
		DEBUG_PRINTLN(status.info());

		if (status.success()) {
		    DEBUG_PRINTLN("Mail inviata correttamente");
		} else {
		    DEBUG_PRINTLN("Errore invio mail");
		}
	}
#else
//
#endif
