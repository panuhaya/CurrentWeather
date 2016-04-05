/*
 * WeatherRequest.cpp
 *
 *  Created on: 05/04/2016
 *      Author: panuhaya
 */

#include "WeatherRequest.h"

namespace std {
/**
 *Send current city weather request
 */
string WeatherRequest::reportWeather(char *cadenaN){

	wrequest="curl http://api.openweathermap.org/data/2.5/weather'?'q=LACITY'&'units=metric'&'APPID=b1b15e88fa797225412429c1c50c122a";

	cityFile = cadenaN;
	cityFile.append(".json");
	wrequest.replace(56,62,cadenaN);
	wrequest.append("'&'units=metric'&'APPID=1456337d2a2f5861320c676f255be436 >> ");
	wrequest.append(cityFile);

	city = new char[wrequest.length()+16];
	strcpy(city,wrequest.c_str());
	system(city);

	return cityFile;
}

} /* namespace std */
