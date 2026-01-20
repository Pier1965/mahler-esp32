#include "globals/global_objects.h"
//
// OLED
//
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
//
// Sensore di temperatura su oneWire
//
// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(oneWireBus);
// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire); 
DeviceAddress tempDeviceAddress; // We'll use this variable to store a found device address
//
// strutture per tempo e orario
//
String time_string;
struct tm timeinfo;
time_t now;
  // int tm_sec;
  // int tm_min;
  // int tm_hour;
  // int tm_mday;
  // int tm_mon;
  // int tm_year;
  // int tm_wday;
  // int tm_yday;
  // int tm_isdst;
const String dow[7] = {"Dom", "Lun", "Mar", "Mer", "Gio", "Ven", "Sab"};
const String months[12] = {"Gen", "Feb", "Mar", "Apr", "Mag", "Giu", "Lug", "Ago", "Set", "Ott", "Nov", "Dic"};
String Anno;
String Giorno;
String Data;
String Ora;
String minuti;
//
// Led RGB lampeggiante
//
LedRGBLampeggiante ledRGB(redPin, greenPin, bluePin);
