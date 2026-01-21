#pragma once
//
#include <Arduino.h>
//
// Config
//
// flag di compilazione condizionale
#include "config/define.h"
// macro funzioni di compilazione condizionale
#include "config/prepro_settings.h"
// configurazione dei pin e dei parametri dell'hw in uso
#include "config/hw_settings.h"
// configurazione dei parametri della mail
#include "config/mail_settings.h"
// colfigurazione server ntp e ora locale
#include "config/ntp_settings.h"
// configurazione dei nomi dell'access point e hostname
#include "config/net_settings.h"
// configurazione dei parametri della prova: intervallo di lettuta e Nmax letture
#include "config/parametri_prova.h"
//
// variabili ed oggetti globali
//
#include "globals/global_variables.h"
#include "globals/global_objects.h"
//
// Moduli
//
#include "modules/RGB_Led_Class.h"
#include "modules/oled.h"
#include "modules/temperature_conf.h"
#include "modules/datetime.h"
#include "modules/button.h"
#include "modules/wifi_conf.h"
#include "modules/fs_conf.h"
#include "modules/update_stato.h"
#include "modules/mail.h"

