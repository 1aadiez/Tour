#include "Route.h"
#include <iostream>

Route::Route(int num_, Excursion_place* excpl_): num_places(num_)
{
	excpl = new Excursion_place[num_];
	for (int i = 0; i < num_; i++)
		excpl[i] = excpl_[i];
}
void Route::setNumplaces(int num)
{
	if (num < 0)
		throw std::invalid_argument("Invalid number of places!");
	delete[] excpl;
	num_places = num;
	excpl = new Excursion_place[num_places];
}