#include "Onedayexcursion.h"
/*!
* \brief �����������
* \param exc �������� ��������� \param date ���� ��������� \param ec ���� ������ �����
* \param max ������������ ����� ���� \param sold ����� ��������� ����
* \param _route ������� ��������
*/
Onedayexcursion::Onedayexcursion(std::string exc, Date& date, double ec, int max, int sold, Route& _route):
	Excursion(exc, date, ec, max, sold) {
	route.setNumplaces(_route.getNumplaces());
	route.setExcpl(_route.getExcplaces());
};
std::ostream& Onedayexcursion::print(std::ostream& out) const
{
	Excursion::print(out);
	out << " Number of places: " << route.getNumplaces();
	for (int i = 0; i < route.getNumplaces(); i++)
	{
		out << "Place: " << i << " " << route.getExcplaces()[i].getComm() << " " 
			<<" object: " <<route.getExcplaces()[i].getObj()
			<< " start time:" << route.getExcplaces()[i].getStart() << route.getExcplaces()[i].getDuration();
	}
	return out;
}
std::ostream& operator<<(std::ostream& out, const Onedayexcursion& oexc)
{
	return oexc.print(out);
}