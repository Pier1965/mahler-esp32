#include "project.h"
#include "modules/button.h"
//
void init_button(){
  pinMode(TRIGGER_PIN, INPUT);
}
void chk_button(){
  button.currentState = digitalRead(TRIGGER_PIN);
  if (button.lastState == LOW && button.currentState == HIGH){       // fronte di salita
    button.pressedTime = millis();
    DEBUG_PRINTLN("Fronte salita");}
  else if (button.lastState == HIGH && button.currentState == LOW) { // fronte di discesa
    button.releasedTime = millis();
    DEBUG_PRINTLN("Fronte discesa");
    long pressDuration = button.releasedTime - button.pressedTime;
    if ((pressDuration > LONG_PRESS_TIME) && (STATO == AppState::OZIOSO)){
      STATO = AppState::AGGWIFI;
      update_STATO();
      DEBUG_PRINTLN("Aggiornamento WiFi");
      DEBUG_PRINTLN("A long press is detected");
      DEBUG_PRINTLN(pressDuration);}
    else if (((pressDuration > SHORT_PRESS_TIME) && (pressDuration < LONG_PRESS_TIME)) && (STATO == AppState::TESTING)){
      STATO = AppState::FINITO;
      update_STATO();
      DEBUG_PRINTLN("Fine prova anticipata");
      DEBUG_PRINTLN("A short press is detected");
      DEBUG_PRINTLN(pressDuration);}
    else if (((pressDuration > VERY_SHORT_PRESS_TIME) && (pressDuration < SHORT_PRESS_TIME)) && (STATO == AppState::OZIOSO)){
      STATO = AppState::TESTING;
      update_STATO();
      DEBUG_PRINTLN("Inizio rilevazione temperature");
      DEBUG_PRINTLN("An impulse press is detected");
      DEBUG_PRINTLN(pressDuration);}
  }
  // save the the last state
  button.lastState = button.currentState;
}
