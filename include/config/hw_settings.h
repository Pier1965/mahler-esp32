#pragma once
//
// Schermo OLED
//
/*
  ---------------------------
  | JMDO 96C-1 OLED | ESP32 |
  ---------------------------
  | SDA             | 21    |
  | SCL             | 22    |
  | GND             | GND   |
  | 5V              | 5V    |
  ---------------------------
  pin già definiti nel core  -> wire begin funziona senza parametri
*/
constexpr int SCREEN_WIDTH = 128; // OLED display width, in pixels
constexpr int SCREEN_HEIGHT = 64; // OLED display height, in pixels
constexpr int HL = 8;             // altezza riga singola 
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library.
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
// Esp32:   SDA -> G21, SCL -> G22 (sono di default in Arduino.h)
// comunque conviene definirli esplicitamente ed eventualmente usare dopo
// Wire.begin(I2C_SDA, I2C_SCL);
constexpr uint8_t I2C_SDA = 21;
constexpr uint8_t I2C_SCL = 22;
constexpr int OLED_RESET = -1; // Reset pin # (or -1 if sharing Arduino reset pin)
constexpr uint8_t SCREEN_ADDRESS = 0x3C; ///< See datasheet for Address; 0x3C for 128x64
/*
  ----------------------------
  | Pulsanti         | ESP32  |
  ----------------------------
  | Pulsante         | D02    |
  ----------------------------
*/
// pin cui è collegato il pulsante
constexpr int TRIGGER_PIN = 2;
// tempi di pressione del pulsante
constexpr unsigned long VERY_SHORT_PRESS_TIME = 50;    // debump filtro
constexpr unsigned long SHORT_PRESS_TIME = 1000;       // 1000 milliseconds
constexpr unsigned long LONG_PRESS_TIME = 5000;        // 5000 milliseconds
//
// Sensore di temperatura
//
// Precisione
//
constexpr int TEMPERATURE_PRECISION = 12;  	// higher resolution 12 bit -> 2^12 = 4092 valori
									// (125°C-(-55°C))/4096 = 0.0625°C
// pin Sensore di temperature
// GPIO where the DS18B20 is connected to
constexpr int oneWireBus = 4;
//
// Pin del led RGB
//
// Gestione RGB led catodo comune
//      R   C   G   B
// GPIO 14  Gr  12  13
//
// i pin 12, 13 e 14 danno interferenza con altri bus se in pwm
constexpr int redPin = 14; 		//25 -> migliore dei  12, 13, 14 
constexpr int greenPin = 12; 	// 26
constexpr int bluePin = 13; 	// 27
