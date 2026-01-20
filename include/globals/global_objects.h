#pragma once
#include <Arduino.h>   // necessario per String, HIGH, LOW ecc.
#include <Adafruit_SSD1306.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include "config/hw_settings.h"
#include "time.h"
#include "modules/RGB_Led_Class.h"
//
// OLED
//
extern Adafruit_SSD1306 display;
//
// Sensore di temperatura su oneWire
//
// Setup a oneWire instance to communicate with any OneWire devices
extern OneWire oneWire;
// Pass our oneWire reference to Dallas Temperature sensor 
extern DallasTemperature sensors; 
extern DeviceAddress tempDeviceAddress; // We'll use this variable to store a found device address
//
// gestione orario
//
extern String time_string;
extern struct tm timeinfo;
extern time_t now;
  // int tm_sec;
  // int tm_min;
  // int tm_hour;
  // int tm_mday;
  // int tm_mon;
  // int tm_year;
  // int tm_wday;
  // int tm_yday;
  // int tm_isdst;
extern   const String dow[7];
extern   const String months[12];
extern   String Anno;
extern   String Giorno;
extern   String Data;
extern   String Ora;
extern   String minuti;
//
// Led RGB lampeggiante
//
extern LedRGBLampeggiante ledRGB;
