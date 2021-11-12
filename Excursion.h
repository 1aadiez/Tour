#pragma once
#ifndef EXCURSION_H
#define EXCURSION_H
#include <iostream>
#include "Route.h"
class Excursion
{
protected:
	std::string excursion_name;
	std::string date;
	double excursion_cost;
	int max_people;
	int sold_places;
public:
	Excursion() :excursion_name(""),date(""),excursion_cost(0),max_people(0),sold_places(0){};
	Excursion(std::string, std::string, double, int, int);
	

	
	int getSold() const { return sold_places; };
    void setSold(const int num) { sold_places = num; };
	std::string getDate() const { return date; };
	void setDate(const std::string newdate) { date = newdate; };
	~Excursion() = default;
};
class Onedayexcursion : public Excursion
{
protected:
	Route route;
public:
	Onedayexcursion(std::string e, std::string d, double ec, int max, int sold, Route route_) :
		Excursion(e, d, ec, max, sold), route(route_) {};
	Onedayexcursion(Route route_) : route(route_) {};
	~Onedayexcursion() = default;
};
class Manydayexcursion : public Excursion
{
protected:
	Route* route;
	int days;
public:
	Manydayexcursion();
	Manydayexcursion(std::string e, std::string d, double ec, int max, int sold, int days_,Route* route_) :
		Excursion(e, d, ec, max, sold), days(days_) 
	{
		route = new Route[days]; route = route_;
	};
	Manydayexcursion(int days_, Route* route_) : days(days_) { route = new Route[days]; route=route_; };
	~Manydayexcursion() { delete[] route; };
};

#endif // !EXCURSION_H


