#pragma once
#include "Excursion.h"
class Manydayexcursion : public Excursion
{
protected:
	Route* route;
	int days;
	virtual std::ostream& print(std::ostream&) const;
public:
	Manydayexcursion() : days(0), route(nullptr), Excursion() {};
	Manydayexcursion(std::string, Date&, double, int, int, int, Route*);
	virtual int getDays() const { return days; };
	virtual Route* getManyRoute() { return route; };
	friend std::ostream& operator << (std::ostream&, const Manydayexcursion&);
	Manydayexcursion(int days_, Route* route_) : days(days_) { route = new Route[days]; route = route_; };
	virtual ~Manydayexcursion() { delete[] route; };
};

