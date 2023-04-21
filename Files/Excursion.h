#pragma once
/*!
* \file
* \brief Заголовочный файл с описанием класса Excursion
*/
#ifndef EXCURSION_H
#define EXCURSION_H
#include <iostream>
#include "Route.h"
#include "Date.h"
class Excursion
{
protected:
	std::string excursion_name;
	Date date;
	double excursion_cost;
	int max_people;
	int sold_places;
	virtual std::ostream& print(std::ostream&)const;
public:
	Excursion() :excursion_name(""), date{ 0,0,0 }, excursion_cost(0), max_people(0), sold_places(0){};
	Excursion(std::string, Date&, double, int, int); 
	virtual Route* getManyRoute()  = 0;
	virtual int getDays() const = 0;
	/// \return Число проданных мест
	int getSold() const { return sold_places; };
    void setSold(const int num);
	/// \return Дату экскурсии
	Date& getDate()  { return date; };
	friend std::ostream& operator << (std::ostream& out, const Excursion& exc);
	/// Установка даты \param newdate Устанавливаемая дата
	void setDate(const Date& newdate) { date = newdate; };
	virtual ~Excursion() {  };
};




#endif // !EXCURSION_H


