#pragma once
//
// STATO di funzionamento 
//
#include "config/app_states.h"
extern AppState STATO;
//
// Mappa dei 5 colori di stato del led RGB
//
constexpr uint8_t colors[5][3] = {{0,255,0}, {255,0,0}, {255,0,255}, {255,255,255}, {0,0,0}};
//
// Variabili temporali gestione pressione bottone
//
struct ButtonState {
int lastState;  // the previous state from the input pin
int currentState;     // the current reading from the input pin
unsigned long pressedTime;
unsigned long releasedTime;
};
extern ButtonState button;
//
// gestione orario
//
extern bool gotTime;
// timer generico
extern unsigned long startMillis;
extern unsigned long currentMillis;
constexpr unsigned long updateTime = 60000UL; // 1 min aggiorno orologio su scr
//
// mail di default del ricevente il file dati
//
extern char recipient[50];    // <------------ mail destinatario default
//
// Temperatura: array dei valori letti e numero dei rilievi fatti
//
#include "config/parametri_prova.h"	// N_SAMPLINGS, DT_SAMPLINGS
extern float T[N_SAMPLINGS];		// array delle temperature rilevate
extern unsigned int N_SAMP_DONE;    // misurazioni fatte in caso di interruzione prova anticipata
