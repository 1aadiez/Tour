#include "Route.h"
#include <iostream>

void Route::setNumplaces(const int num)
{
	if (num < 0)
		throw std::invalid_argument("Invalid number of places!");
	num_places = num;
}