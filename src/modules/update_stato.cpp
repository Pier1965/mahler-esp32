#include "project.h"
#include "modules/update_stato.h"
//
void update_STATO(){
  String str;
  uint8_t state = static_cast<uint8_t>(STATO);
  ledRGB.setColoreON(colors[state][0], colors[state][1], colors[state][2]);
  ledRGB.flash_led();
  switch (state) {
    case 0:
      str = "OZIOSO";
      break;
    case 1:
      str = "TESTING";
      break;
    case 2:
      str = "FINITO: Mail->";
      break;
    case 3:
      str = "AGGWIFI";
      break;
  }
  printSCR_yesnet();
  printSCR_STATO(str);
};
