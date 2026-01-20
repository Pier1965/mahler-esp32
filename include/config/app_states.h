#pragma once
#include <Arduino.h>
// Stati di funzionamento dello strumento
enum class AppState : uint8_t {
    OZIOSO  = 0,  // Verde
    TESTING = 1,  // Rosso
    FINITO  = 2,  // Viola
    AGGWIFI = 3,  // Bianco
    LED_OFF = 4   // Spento
};

