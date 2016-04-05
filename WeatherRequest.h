/*
 * WeatherRequest.h
 *
 *  Created on: 05/04/2016
 *      Author: panuhaya
 */
#include <iostream>
#include <fstream>
#include <string>
#include "json/json.h"
#ifndef WEATHERREQUEST_H_
#define WEATHERREQUEST_H_

namespace std {

class WeatherRequest {
	string wrequest;
	char *city;
	string cityFile;
	public:
	string reportWeather(char *);
};
} /* namespace std */

#endif /* WEATHERREQUEST_H_ */
