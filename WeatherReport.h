/*
 * WeatherReport.h
 *
 *  Created on: 05/04/2016
 *      Author: panuhaya
 */
#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include "json/json.h"
#ifndef WEATHERREPORT_H_
#define WEATHERREPORT_H_

namespace std {

class WeatherReport {
	typedef pair<int,string> orden_column;
	map<int,string> tabla;
public:
	map<int,string> HeaderTabla();
	string formatColumn(string);
	list<string> datatable(string ,map<int,string>, bool);
	list<string> currentWeather(list<string>,map<int,string>,string);
	void showReporte(list<string>);
};

} /* namespace std */

#endif /* WEATHERREPORT_H_ */
