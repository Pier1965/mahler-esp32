#ifndef LEDRGBLAMPEGGIANTE_H
#define LEDRGBLAMPEGGIANTE_H

#include <Arduino.h>

class LedRGBLampeggiante {
private:
    int pinR, pinG, pinB;
    int canaleR, canaleG, canaleB;
    unsigned long T_on, T_off;
    unsigned long lastMillis;
    bool stato;
    float dimming;
    bool started;
    int coloreON[3];
    int coloreOFF[3];
    void aggiornaLedFisico();

public:
    LedRGBLampeggiante(int r, int g, int b,
                       int chR = 0, int chG = 1, int chB = 2);
	void startLed(unsigned long ton, unsigned long toff);
    void flash_led();
    void setTempi(unsigned long ton, unsigned long toff);
    void setDimming(float dim);
    void setColoreON(int r, int g, int b);
    void setColoreOFF(int r, int g, int b);
    void reset();
    bool leggistato() const;
};

#endif

