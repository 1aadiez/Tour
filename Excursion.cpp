#include "Excursion.h"
Excursion::Excursion(std::string name_, Date& date_, double cost_,int max_,int sold_):
	excursion_name(name_), date(date_), excursion_cost(cost_), max_people(max_), sold_places(sold_)
{

}
void Excursion::setSold(const int num)
{
	if (num > max_people)
		throw std::exception("No more free places!");
	if (num < 0)
		throw std::invalid_argument("Invalid argument!");
	sold_places = num; 
}
std::ostream& Excursion::print(std::ostream& out) const
{
	out << "Excursion: " << excursion_name << " Date: " << date  <<
		" Cost: " << excursion_cost << " Sold/max people: " << sold_places << "/" << max_people;
	return out;
}
std::ostream& operator<<(std::ostream& out, const Excursion& excursion)
{
	return excursion.print(out);
}
std::ostream& Onedayexcursion::print(std::ostream& out) const
{
	Excursion::print(out);
	out << " Number of places: " << route.getNumplaces();
	
	for (int i = 0; i < route.getNumplaces(); i++)
	{
		out << "Place " << i << " " << route.getExcplaces()[i].getComm() << " " << route.getExcplaces()[i].getObj()
			<< " start time:" << route.getExcplaces()[i].getStart() << route.getExcplaces()[i].getDuration();
	}
	return out;
}
std::ostream& Manydayexcursion::print(std::ostream& out) const
{
	Excursion::print(out);
	return out << " Days: " << days << " Route: places" << route->getNumplaces();
}
