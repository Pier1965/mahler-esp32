#include "globals/global_variables.h"
//
// Stati del sistema
//
AppState STATO = AppState::OZIOSO;
//
// Variabili temporali gestione pressione bottone
//
ButtonState button = {LOW, LOW, 0, 0}; // last, current, pressedTime, releasedTime
//
// gestione orario
//
bool gotTime = false;
//
// timer
//
unsigned long startMillis = 0;
unsigned long currentMillis = 0;
//
// mail di default del ricevente il file dati
//
char recipient[50]="pierundcarla@gmail.com";    // <------------ mail destinatario default
//
// Temperatura
//
float T[N_SAMPLINGS] = {0.0};				// array delle temperature rilevate
unsigned int N_SAMP_DONE = 0;     	// misurazioni fatte in caso di interruzione prova anticipata
