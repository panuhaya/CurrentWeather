/*
 * WeatherReport.cpp
 *
 *  Created on: 05/04/2016
 *      Author: panuhaya
 */

#include "WeatherReport.h"

namespace std {
/**
 * Report Template (Map)
 */
map<int,string> WeatherReport::HeaderTabla(){
	tabla.insert(orden_column('1',"name"));
	tabla.insert(orden_column('2',"main"));
	tabla.insert(orden_column('3',"description"));
	tabla.insert(orden_column('4',"temp"));
	tabla.insert(orden_column('5',"pressure"));
	tabla.insert(orden_column('6',"humidity"));
	tabla.insert(orden_column('7',"temp_min"));
	tabla.insert(orden_column('8',"temp_max"));
	map<int, string>::iterator p ;
	int i = 0;
	  for (std::map<int, string>::iterator p =tabla.begin(); p!=tabla.end(); ++p){
		  i++;
	    std::cout << "Column id: "<< i << " Column name: " << p->second << endl;
	  }
	return tabla;
}
string WeatherReport::formatColumn(string dato){
	string newString = dato;
	if(dato.length()>7)
		newString = dato.substr(0,7);
	newString.append("		");

return newString;
}
/**
 * user Layout
 * header true. bulid header
 * 		  false. return user layout
 */
list<string> WeatherReport::datatable(string weatherCity,map<int,string> columns,bool header){
	std::list<string> headerList;
	string::iterator my_iter;
	string layout="";

	for(my_iter = weatherCity.begin(); my_iter != weatherCity.end(); my_iter++)
	{
		for(map<int,string>::iterator ii=columns.begin(); ii!=columns.end(); ++ii)
		   {
			char temp2 = (*ii).first;
			char tmp1 =*my_iter;
			if(tmp1 ==temp2){
				headerList.push_back((*ii).second);
				layout += formatColumn((*ii).second);
			}
		   }
	}
	if(header){
		headerList.clear();
		headerList.push_front(" ***Weathet Report*** ");
		headerList.push_back(layout);
	}
	return headerList;
}
/**
 * Put together Current City Weather
 */
list<string> WeatherReport::currentWeather(list<string> fileList,map<int,string> columndefault,string columnString){
	Json::Value root;
	Json::Reader reader;
	const Json::Value defValue;

	std::list<string> reporte = datatable(columnString,columndefault,true);
	std::list<string> columnsList = datatable(columnString,columndefault,false);

	string rowCity;

	for(std::list<string>::iterator it=fileList.begin(); it!=fileList.end();it++){
		std::ifstream ifilesi(*it);
		rowCity="";
		//bool isJsonOK = (ifile !=NULL);
		bool isJsonOK1 = reader.parse(ifilesi, root);
		if(isJsonOK1){
			for(std::list<string>::iterator itdata=columnsList.begin(); itdata!=columnsList.end();itdata++){
				if(*itdata=="name"){
					const Json::Value s = root.get("name",defValue);
					rowCity += formatColumn(s.asString());
				}
				for (Json::Value::iterator it1 = root["weather"].begin(); it1 != root["weather"].end(); ++it1) {
					if(*itdata=="main")
						rowCity +=formatColumn((*it1)["main"].asString());
					if(*itdata=="description")
						rowCity += formatColumn((*it1)["description"].asString());
				  }
				const Json::Value s2 = root.get("main",defValue);
				if(*itdata=="temp")
					rowCity += formatColumn(s2.get("temp","").asString());
				if(*itdata=="pressure")
					rowCity += formatColumn(s2.get("pressure","").asString());
				if(*itdata=="humidity")
					rowCity += formatColumn(s2.get("humidity","").asString());
				if(*itdata=="temp_min")
					rowCity += formatColumn(s2.get("temp_min","").asString());
				if(*itdata=="temp_max")
					rowCity += formatColumn(s2.get("temp_max","").asString());
			}
			reporte.push_back(rowCity);
		}
	}
	return reporte;
}
/**
 * Print list's rows
 */
void WeatherReport::showReporte(list<string> cityReport){
	for(std::list<string>::iterator it=cityReport.begin(); it!=cityReport.end();it++){
		cout<<*it<<endl;
	}
	//cout<<"delete files"<<endl;
	system("rm *.json");
}

} /* namespace std */
