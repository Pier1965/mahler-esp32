#include "modules/RGB_Led_Class.h"

LedRGBLampeggiante::LedRGBLampeggiante(int r, int g, int b,
                                       int chR, int chG, int chB)
    : pinR(r), pinG(g), pinB(b),
      canaleR(chR), canaleG(chG), canaleB(chB),
      lastMillis(0), stato(false), started(false), dimming(1.0)
{
    ledcSetup(canaleR, 5000, 8);
    ledcSetup(canaleG, 5000, 8);
    ledcSetup(canaleB, 5000, 8);

    ledcAttachPin(pinR, canaleR);
    ledcAttachPin(pinG, canaleG);
    ledcAttachPin(pinB, canaleB);

    coloreON[0] = coloreON[1] = coloreON[2] = 0;
    coloreOFF[0] = coloreOFF[1] = coloreOFF[2] = 0;

    aggiornaLedFisico();
}

void LedRGBLampeggiante::startLed(unsigned long ton, unsigned long toff){
	setTempi(ton, toff);
	for (int i=0; i<3; i++){
		ledcWrite(i, 255);
    	delay(1000);
    	ledcWrite(i, 0);
	}
	started = true;
	stato = false;
	aggiornaLedFisico();
}

void LedRGBLampeggiante::flash_led() {
	if(started){
		unsigned long ora = millis();
		unsigned long durata = stato ? T_on : T_off;

		if (ora - lastMillis >= durata) {
		    stato = !stato;
		    lastMillis = ora;
		    aggiornaLedFisico();
		}
    }
}

void LedRGBLampeggiante::setTempi(unsigned long ton, unsigned long toff) {
    T_on = ton;
    T_off = toff;
}

void LedRGBLampeggiante::setDimming(float dim){
	dimming = dim;
}

void LedRGBLampeggiante::setColoreON(int r, int g, int b) {
    coloreON[0] = r;
    coloreON[1] = g;
    coloreON[2] = b;
}

void LedRGBLampeggiante::setColoreOFF(int r, int g, int b) {
    coloreOFF[0] = r;
    coloreOFF[1] = g;
    coloreOFF[2] = b;
}

void LedRGBLampeggiante::reset() {
    stato = false;
    started = false;
    dimming = 1.0;
    lastMillis = millis();
    aggiornaLedFisico();
}

bool LedRGBLampeggiante::leggistato() const {
    return stato;
}

void LedRGBLampeggiante::aggiornaLedFisico() {
    ledcWrite(canaleR, (stato ? coloreON[0] : coloreOFF[0])*dimming);
    ledcWrite(canaleG, (stato ? coloreON[1] : coloreOFF[1])*dimming);
    ledcWrite(canaleB, (stato ? coloreON[2] : coloreOFF[2])*dimming);
}


