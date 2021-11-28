#pragma once
#ifndef ROUTE_H
#define ROUTE_H
#include <iostream>
#include "Excursion_place.h"
class Route
{
protected:
	int num_places;
	Excursion_place* excpl;
public:
	Route() : num_places(1) { excpl = new Excursion_place[num_places]; };
	Route(int, Excursion_place*);
	int getNumplaces() const { return num_places; };
	Excursion_place* getExcplaces() const{ return excpl; };
	void setNumplaces(int); //{ num_places = num; };
	void setExcpl(Excursion_place* exc) {  
		
		for(int i=0;i<num_places;i++)excpl[i] = exc[i]; };
	~Route(){ delete[]excpl; };
};
#endif // !

