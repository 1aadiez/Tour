#pragma once
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
	//virtual Route getRoute() const = 0; //абстрактный
	virtual Route* getManyRoute()  = 0;
	virtual int getDays() const { return 0; };
	int getSold() const { return sold_places; };
    void setSold(const int num);
	Date& getDate()  { return date; };
	friend std::ostream& operator << (std::ostream& out, const Excursion& exc);
	void setDate(const Date& newdate) { date = newdate; };
	virtual ~Excursion() {  };
};

class Onedayexcursion : public Excursion
{
protected:
	Route route;
	virtual std::ostream& print(std::ostream&) const;
public:
	Onedayexcursion() = default;
	Onedayexcursion(std::string e, Date& d, double ec, int max, int sold, Route route_) :
		Excursion(e, d, ec, max, sold), route(route_) {};
	Onedayexcursion(Route route_) : route(route_) {};
	void setRoute(Route route_)  { route = route_; };
	virtual int getDays() const { return 1; };
	virtual Route* getManyRoute() { Route* _route = new Route; _route[0] = route; return _route; };
	virtual ~Onedayexcursion() { };
};

class Manydayexcursion : public Excursion
{
protected:
	Route* route;
	int days;
	virtual std::ostream& print(std::ostream&) const;
public:
	Manydayexcursion() : days(0), route(nullptr) {};
	Manydayexcursion(std::string e, Date& d, double ec, int max, int sold, int days_,Route* route_) :
		Excursion(e, d, ec, max, sold), days(days_) 
	{
		route = new Route(route_->getNumplaces(), route_->getExcplaces());// route = route_;
	};
	
	virtual int getDays() const { return days; };
	virtual Route* getManyRoute() { return route; };
	Manydayexcursion(int days_, Route* route_) : days(days_) { route = new Route[days]; route=route_; };
    virtual ~Manydayexcursion() { delete[] route; };
};

#endif // !EXCURSION_H


