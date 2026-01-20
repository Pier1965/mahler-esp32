#include "project.h"
#include "FS.h"
#include <LittleFS.h>
#include "modules/fs_conf.h"
//
void initFS(){
	if(!LittleFS.begin(FORMAT_LITTLEFS_IF_FAILED)){
		DEBUG_PRINTLN("Errore file system");
		printSCR_MSG("Errore di file system");
		for(;;); // Don't proceed, loop forever
	}
	DEBUG_PRINTLN("File system OK");
	printSCR_MSG("File system Ok");
}
