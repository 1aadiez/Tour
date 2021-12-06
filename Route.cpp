/*!
* \file
* \brief Файл с описанием методов класса Route
*/
#include "Route.h"
#include <iostream>

/*!
* \brief Конструктор
* \param num_ Количество пунктов экскурсии
* \param excpl_ Указатель на динамический массив описателей экскурсии
*/
Route::Route(int num_, Excursion_place* excpl_): num_places(num_)
{
	excpl = new Excursion_place[num_];
	for (int i = 0; i < num_; i++)
		excpl[i] = excpl_[i];
}
/*!
* Устанавливает количество пунктов экскурсии
* \param num Число пунктов экскурсии
* \throw std::invalid_argument Число мест < 0
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
* \brief Устанавливает пункты экскурсии
* \param excplace Динамический массив пунктов экскурсии
*/
void Route::setExcpl(Excursion_place* excplace)
{
	for (int i = 0; i < num_places; i++)
		excpl[i] = excplace[i];
}