#pragma once
/*!
* \file 
  \brief Заголовочный с файл с описанием класса Excursion_place
*/
#ifndef EXCURSION_PLACE
#define EXCURSION_PLACE
#include <iostream>

class Excursion_place
{
protected:
	std::string community_name;
	std::string object_name;
	std::string start_time;
	int duration_time;
public:
	/// Конструктор по умолчанию
	Excursion_place() : community_name(""), object_name(""), start_time(""), duration_time(0) {};
	/*!
	* Конструктор \param comm Название населенного пункта \param obj Объект экскурсии \param start Время начала
	* \param duration Время продолжительности
	*/
	Excursion_place(std::string comm, std::string obj, std::string start, int duration);
	/// Возвращает название населенного пункта\return Название населенного пункта
	std::string getComm()const { return community_name; };
	/// Возвращает название эксурсионного объекта\return Название экскурсионного объекта
	std::string getObj() const { return object_name; }; 
	/// Возвращает время начала\return Время начала экскурсии
	std::string getStart() const { return start_time; }; 
	///Возвращает время продолжительности экскурсии\return Время продолжительности экскурсии в часах
	int getDuration() const { return duration_time; }; 
	~Excursion_place()=default;
};

#endif