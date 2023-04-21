#pragma once
/*!
* \file 
  \brief ������������ � ���� � ��������� ������ Excursion_place
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
	/// ����������� �� ���������
	Excursion_place() : community_name(""), object_name(""), start_time(""), duration_time(0) {};
	/*!
	* ����������� \param comm �������� ����������� ������ \param obj ������ ��������� \param start ����� ������
	* \param duration ����� �����������������
	*/
	Excursion_place(std::string comm, std::string obj, std::string start, int duration);
	/// ���������� �������� ����������� ������\return �������� ����������� ������
	std::string getComm()const { return community_name; };
	/// ���������� �������� ������������� �������\return �������� �������������� �������
	std::string getObj() const { return object_name; }; 
	/// ���������� ����� ������\return ����� ������ ���������
	std::string getStart() const { return start_time; }; 
	///���������� ����� ����������������� ���������\return ����� ����������������� ��������� � �����
	int getDuration() const { return duration_time; }; 
	~Excursion_place()=default;
};

#endif