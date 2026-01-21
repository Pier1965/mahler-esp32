#pragma once
#ifdef WIFI
	//
	// Server orario NTP
	//
	constexpr char ntpServer[] = "pool.ntp.org";
	// Uso futuro compatto
	// CET a -1h da Roma CEST ora legale entra a M3: Marzo la 5: 5 settimana 0: domenica 2: alle ore 2
	// finisce ad M10: ottobre 5: 5a settimana 0: domenica : 3: alle ore 3
	//constexpr char TZ_INFO[] = "CET-1CEST,M3.5.0/2,M10.5.0/3";
	//
	// Ora di ROMA -> GMT + 1h
	constexpr long  gmtOffset_sec = 3600;
	// Ora legale estiva +1h
	constexpr int   daylightOffset_sec = 3600;
#endif
