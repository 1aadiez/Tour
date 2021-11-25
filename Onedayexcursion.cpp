#include "Onedayexcursion.h"

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
std::ostream& operator<<(std::ostream& out, const Onedayexcursion& oexc)
{
	return oexc.print(out);
}