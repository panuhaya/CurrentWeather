/*
 * WeatherRequest.h
 *
 *  Created on: 05/04/2016
 *      Author: panuhaya
 */
#include <iostream>
#include <string>
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
