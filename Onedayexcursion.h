#pragma once
#include "Excursion.h"
class Onedayexcursion : public Excursion
{
protected:
	Route route;
	virtual std::ostream& print(std::ostream&) const;
public:
	Onedayexcursion() : Excursion() {};
	Onedayexcursion(std::string e, Date& d, double ec, int max, int sold, Route route_) :
		Excursion(e, d, ec, max, sold), route(route_) {};
	Onedayexcursion(Route route_) : route(route_) {};
	void setRoute(Route route_) { route = route_; };
	friend std::ostream& operator << (std::ostream&, const Onedayexcursion&);
	virtual int getDays() const { return 1; };
	virtual Route* getManyRoute() { Route* _route = new Route; _route[0] = route; return _route; };
	virtual ~Onedayexcursion() { };
};


