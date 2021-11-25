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
	Route(int num_, Excursion_place* excpl_) : num_places(num_) { excpl = new Excursion_place[num_]; excpl = excpl_; };
	int getNumplaces() const { return num_places; };
	Excursion_place* getExcplaces() const{ return excpl; };
	void setNumplaces(const int); //{ num_places = num; };
	void setExcpl(Excursion_place* exc) { excpl = new Excursion_place[num_places]; excpl = exc; };
	~Route() = default;
};
#endif // !

