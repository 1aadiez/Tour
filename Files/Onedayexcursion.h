#pragma once
/*!
* \file
* \brief ������������ ���� � ��������� ������ Onedayexcursion
*/
#include "Excursion.h"
class Onedayexcursion : public Excursion
{
protected:
	Route route;
	virtual std::ostream& print(std::ostream&) const;
public:
	Onedayexcursion() : Excursion() { };
	Onedayexcursion(std::string, Date& , double, int, int , Route& );
	Onedayexcursion(Route _route) : route(_route) {};
	/// ������������� ������� \param route_ ��������������� �������
	void setRoute(Route route_) { route = route_; };
	friend std::ostream& operator << (std::ostream&, const Onedayexcursion&);
	virtual int getDays() const { return 1; };
	virtual Route* getManyRoute() {  return &route; };
	virtual ~Onedayexcursion() =default;
};


