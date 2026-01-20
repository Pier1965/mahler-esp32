#pragma once
#ifdef MAIL
	/* Declare the global used SMTPSession object for SMTP transport */
	//extern SMTPSession smtp;
	/* Callback function to get the Email sending status */
	class SMTP_Status;   // 👈 forward declaration
	void smtpCallback(SMTP_Status status);
	//extern const char rootCACert[] PROGMEM;
	void send_mail();
#endif
