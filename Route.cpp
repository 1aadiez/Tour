/*!
* \file
* \brief ���� � ��������� ������� ������ Route
*/
#include "Route.h"
#include <iostream>

/*!
* \brief �����������
* \param num_ ���������� ������� ���������
* \param excpl_ ��������� �� ������������ ������ ���������� ���������
*/
Route::Route(int num_, Excursion_place* excpl_): num_places(num_)
{
	excpl = new Excursion_place[num_];
	for (int i = 0; i < num_; i++)
		excpl[i] = excpl_[i];
}
/*!
* ������������� ���������� ������� ���������
* \param num ����� ������� ���������
* \throw std::invalid_argument ����� ���� < 0
*/
void Route::setNumplaces(int num)
{
	if (num < 0)
		throw std::invalid_argument("Invalid number of places!");
	delete[] excpl;
	num_places = num;
	excpl = new Excursion_place[num_places];
}
/*!
* \brief ������������� ������ ���������
* \param excplace ������������ ������ ������� ���������
*/
void Route::setExcpl(Excursion_place* excplace)
{
	for (int i = 0; i < num_places; i++)
		excpl[i] = excplace[i];
}