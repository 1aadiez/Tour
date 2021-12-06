#pragma once
/*!
* \file
* \brief Заголовочный файл с описанием класса Route
*/
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
	/// \return Количество пунктов экскурсии
	int getNumplaces() const { return num_places; };
	/// \return Массив пунктов экскурсии
	Excursion_place* getExcplaces() const{ return excpl; };
	void setNumplaces(int); 
	void setExcpl(Excursion_place*);
	~Route(){ delete[]excpl; };
};
#endif // !

