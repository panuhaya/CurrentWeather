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
	Json::Value llave;
	Json::Reader reader;
	const Json::Value defllave;
	std::ifstream ifilesi("weatherllave/openweatherllave.lve", std::ifstream::in);
	bool isJsonOK1 = reader.parse(ifilesi, llave);
	if(isJsonOK1){
	const Json::Value s = llave.get("name",defllave);
	wrequest="curl http://api.openweathermap.org/data/2.5/weather'?'q=LACITY'&'units=metric'&'APPID=" + s.asString();
	}else
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
