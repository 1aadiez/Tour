#include "Manydayexcursion.h"
/**
* \brief �����������
* \param e �������� ��������� \param d ���� ������ ��������� \param ec  ��������� ������ ����� 
* \param max ������������ ����� ������������ � ������ \param sold ����� ��������� ���� \param days_ ���������� ����
* \param route_ ��������� �� ������������ ������ ���������� �������� ��� ������� ��� ���������
*/
Manydayexcursion::Manydayexcursion(std::string e, Date& d, double ec, int max, int sold, int days_, Route* route_):
	Excursion(e, d, ec, max, sold), days(days_)
{
	route = new Route[days_];
	for (int i = 0; i < days; i++)
	{
		route[i].setNumplaces(route_[i].getNumplaces());
		route[i].setExcpl(route_[i].getExcplaces());
	}
};
std::ostream& Manydayexcursion::print(std::ostream& out) const
{
	Excursion::print(out);
	out << " Days: " << days;
	for (int i = 0; i < days; i++)
	{
		out << " day[" << i << "] ";
		for (int j = 0; j < route[i].getNumplaces(); j++)
		{
			out << "place[" << j << "] comm: " << route[j].getExcplaces()[j].getComm() << " object: " 
				<< route[j].getExcplaces()[j].getObj() << " start time:" 
				<< route[j].getExcplaces()[j].getStart() << " duration: "<<route[j].getExcplaces()[j].getDuration();
		}
	}

	return out;
}
std::ostream& operator << (std::ostream& out, const Manydayexcursion& mexc)
{
	return mexc.print(out);
}