#pragma once
#ifndef ROUTE_H
#define ROUTE_H
#include <iostream>
class Excursion_place
{
protected:
	std::string community_name;
	std::string object_name;
	std::string start_time;
	int duration_time;
public:
	Excursion_place()=default;
	Excursion_place(std::string comm, std::string obj, std::string start, int duration);
	std::string getComm()const { return community_name; };
	std::string getObj() const { return object_name; };
	std::string getStart() const { return start_time; };
	int getDuration() const { return duration_time; };
	~Excursion_place()=default;
};

class Route
{
protected:
	int num_places;
	Excursion_place* excpl;
public:
	Route() : num_places(1) { excpl = new Excursion_place[num_places]; };
	Route(int num_, Excursion_place* excpl_) : num_places(num_) { excpl = new Excursion_place[num_]; excpl = excpl_; };
	int getNumplaces() const { return num_places; };
	Excursion_place* getExcplaces() const{ return excpl; };
	~Route() { delete excpl; };
};
#endif // !

