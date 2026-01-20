#include "project.h"
#include "modules/temperature_conf.h"
#include "FS.h"
#include <LittleFS.h>
//
void start_sensor(){
  // Start the DS18B20 sensor
  oneWire.reset();
  delay(10);
  sensors.begin();
  delay(1000);
  //sensors.begin();
  //delay(100);
  int sensorCount = sensors.getDeviceCount();
  DEBUG_PRINT("Sensori rilevati: ");
  DEBUG_PRINTLN(sensorCount);
  delay(100);
  sensors.getAddress(tempDeviceAddress, 0);
  if (sensors.isConnected(tempDeviceAddress)) {
  		DEBUG_PRINTLN("DS18B20 trovato");
  		printSCR_MSG("DS18B20 Ok");
  		delay(1000);
  		// set the resolution to TEMPERATURE_PRECISION bit (Each Dallas/Maxim device is capable of several different resolutions)
        sensors.setResolution(tempDeviceAddress, TEMPERATURE_PRECISION);
        DEBUG_PRINT("Risoluzione bit: ");
        DEBUG_PRINTLN(TEMPERATURE_PRECISION);
        printSCR_MSG("DS18B20 res: 12bit");
        delay(1000);
    } else {
    	DEBUG_PRINTLN("DS18B20 non trovato!");
        printSCR_MSG("DS18B20 NOT connected!");
        for(;;); // Don't proceed, loop forever
    } 
  //sensors.setResolution(tempDeviceAddress, TEMPERATURE_PRECISION);
}
//
void get_temperature(int i){
  sensors.requestTemperatures(); 
  T[i]=sensors.getTempCByIndex(0);
}
//
void writeTempToFile(){
  DEBUG_PRINTLN("Scrittura dati su file"); 
  File file_temperature = LittleFS.open("/fileDati.txt", FILE_WRITE);
  String textMsg = String("Inizio ") + MESSAGGIO + Data + " alle " + Ora + "\n";
  file_temperature.print(textMsg);
  for (int n = 0; n < N_SAMP_DONE; n++) {
    float temp = float(n)*float(DT_SAMPLINGS)/1000;
    file_temperature.print(temp);
    file_temperature.print(" ");
    file_temperature.println(T[n]);
  }
  getTime();
  textMsg.clear();
  textMsg = String("Fine ") + MESSAGGIO + Data + " alle " + Ora + "\n";
  file_temperature.print(textMsg);
  file_temperature.close();
  display.clearDisplay();
  display.println("Verifica fileDati.txt");
  delay(2000);
  DEBUG_PRINTLN("Lettura dati su file"); 
  file_temperature = LittleFS.open("/fileDati.txt");
  if(!file_temperature){
    DEBUG_PRINTLN("There was an error opening the file for reading");
    display.clearDisplay();
    display.println("No fileDati.txt");
    delay(2000);
    return;
  }else{
    file_temperature.close();
    DEBUG_PRINTLN("Fatto...");
  }
}
//
void readTempToFile(){
  DEBUG_PRINTLN("Lettura dati su file"); 
  File file_temperature = LittleFS.open("/fileDati.txt");
  if(!file_temperature){
  DEBUG_PRINTLN("There was an error opening the file for reading");
return;
  }
  while(file_temperature.available()){
    Serial.write(file_temperature.read());
  }
  file_temperature.close();
  DEBUG_PRINTLN("Fatto...");
}
//
void do_test(){
  N_SAMP_DONE = 0;
  getTime();
  for (int i=0;((i<N_SAMPLINGS)&&(STATO == AppState::TESTING));i++){
    get_temperature(i);
    unsigned long t_init = millis();
    N_SAMP_DONE = i+1;
    DEBUG_PRINT(T[i]);
    DEBUG_PRINTLN("ºC");
    String str = String(i) + ":" + String(T[i]) + "C";
    printSCR_lettura(str);
	for(;((millis() - t_init)<DT_SAMPLINGS);){
		chk_button();
		ledRGB.flash_led();
    }
    str="           ";
    printSCR_lettura(str);
  }
  DEBUG_PRINTLN("------------------------");
  for(int i=0;i<N_SAMP_DONE;i++){
    DEBUG_PRINT(T[i]);
    DEBUG_PRINTLN("ºC");
  }
  writeTempToFile();
}
//
void print_temperatura_SCR(){
  get_temperature(0);
  String str = "T:" + String(T[0]) + "C";
  printSCR_lettura(str);
}

