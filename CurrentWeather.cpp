//============================================================================
// Name        : CurrentWeather.cpp
// Author      : panuhaya
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Current Weather in C++, Ansi-style
//============================================================================

#include <iostream>
#include <thread>
#include <list>
#include <map>
#include "WeatherRequest.h"
#include "WeatherReport.h"

using namespace std;
std::list<string> archivos;
void minFuncion(char *cadenay){
	WeatherRequest minWeatherObj;
    archivos.push_back(minWeatherObj.reportWeather(cadenay));
}

int main() {
	char *cadena1, *cadena2;
	map<int,string>headerMap;
	std::list<string> report;
	string recibe, numColumns;

	cout << "To get current weather" << endl;
	cout << "!!!type a city or cities with a back space\n between each other to get the current weather!!!" << endl; // prints !!!Hello World!!!
	getline(cin,recibe);
	if(recibe.length()>65){
		cout<<"Many cities!!!"<<endl;
		return 0;
	}
	cadena1 = new char [recibe.length()+1];
	std::strcpy (cadena1, recibe.c_str());
	cadena2 = std::strtok (cadena1," ");
	//Shows Info weather available
	cout << "Weather columns on report" << endl;
	WeatherReport hhtable;
	headerMap=hhtable.HeaderTabla();

	cout << "type Id number of the report column to show (e.j. 12345)" << endl;
	getline(cin,numColumns);
	int li_dec=0;
	try{
		std::string::size_type sz;
		li_dec = std::stoi (numColumns,&sz);
	}catch(std::invalid_argument& ia){
		cout << "Invalid Argument, type only numbers 1 to 8 (e.j. 182345)" << endl;
		return 0;
	}

	cout << "num columns: " << numColumns.size() << endl;

	std::thread tgetWeather[10];
	int i=0;
	//send the weather request
while (cadena2!=0)
	{
		tgetWeather[i] = std::thread(minFuncion,cadena2);
		//minFuncion(cadena2);
		tgetWeather[i].join();
		i++;
		cadena2=std::strtok(NULL," ");
	}
//put together
report=hhtable.currentWeather(archivos,headerMap,numColumns);
hhtable.showReporte(report);

delete cadena1;
delete cadena2;

	return 0;
}
