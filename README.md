ESP 32 LOGGER FOR MAHLER CALORIMETER
-------------------------------------

CONFIGURAZIONE
---------------
I file da modificare prima della compilazione sono:
1. include/config/define.h per compilazione condizionale;
2. include/config/hw_settings.h per pin e parametri riguardanti l'hw;
3. include/config/mail_settings.h per i parametri SMTP del provider di posta elettronica;
4. include/config/ntp_conf.h eventuale cambio del server ntp, ora locale e ora legale;
5. include/config/parametri_prova.h contiene il numero massimo di misure da fare e il tempo tra le stesse in millisecondi;
6. src/globals/global_variables.cpp la mail del ricevente di default, che può anche essere cambiata
a run time dal portale MahlerAP;


USO
-----
1. Attivare l'ESP32;
    - Se la rete non è configurata, connettersi a "MahlerAP" con un cellulare o altro;
    - Se si vuole cambiare la rete cui si connette ESP, in modalità OZIOSO schiacciare per 10s il pulsante
(led color bianco. e connettersi a "MahlerAP" con un cellulare o altro;
2. Con il browser andare all'indirizzo 192.168.4.1 e immettere i dati della rete cui connettere l'ESP;
3. L'ESP si riavvierà e si collegherà in automatico alla rete configurata;
4. L'ESP entrerà in modalità OZIOSA col led verde lampeggiante;
5. Iniziare la prova schiacciando il pulsante per 0.5s circa. Il led diventerà rosso;
6. Se si vuole interrompere in anticipo il test, schiacciare il pulsante per circa 2s;
7. Al termine della prova il led diventa viola, viene inviata la mail con il file delle letture;
8. Il led torna verde lampeggiante e può essere eseguita una nuova prova.

********************************************************************************************************
CONFIGURATION
-------------
The files to modify before compilation are:

1. `include/config/define.h` for conditional compilation;
2. `include/config/hw_settings.h` for pins and parameters related to hardware;
3. `include/config/mail_settings.h` for SMTP parameters of the email provider;
4. `include/config/ntp_conf.h` for possible changes to the NTP server, local time, and daylight saving time;
5. `include/config/parametri_prova.h` contains the maximum number of measurements to take and the time between them in milliseconds;
6. `src/globals/global_variables.cpp` the default recipient email, which can also be changed at runtime from the MahlerAP portal;

USE
---
1. Turn on the ESP32;
  - If the network is not configured, connect to "MahlerAP" with a phone or other device;
  - To change the network the ESP connects to, in OZIOSO mode press the button for 10 seconds (white LED. and connect to "MahlerAP" with a phone or other device;
2. Using a browser, go to address 192.168.4.1 and enter the credentials for the network to connect the ESP to;
3. The ESP will reboot and automatically connect to the configured network;
4. The ESP will enter OZIOSO mode with a blinking green LED;
5. Start the test by pressing the button for approximately 0.5 seconds. The LED will turn red;
6. To interrupt the test early, press the button for approximately 2 seconds;
7. At the end of the test, the LED turns purple, and the email with the readings file is sent;
8. The LED returns to blinking green, and a new test can be performed.
