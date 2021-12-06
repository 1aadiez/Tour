#pragma once
/*!
* \file
* \brief ������������ ���� � ��������� ������� Element � Table
* ������ ���� �������� � ���� ����������� ������ ���� �������
*/
#ifndef TABLE_H
#define TABLE_H
#include <iostream>
#include <vector>
#include "Excursion.h"
#include "Onedayexcursion.h"
#include "Manydayexcursion.h"

class Element {
protected:
	int key;
	Date release;
	Excursion* exc;
	Element* next;
public:
	Element()=default;
	/// ����������� \param k ����(��� ���������) \param r ���� \param excur ���������
	Element(int k, Date& r, Excursion* excur) : key(k), release(r), exc(excur), next(nullptr) {};
	Element(const Element&);
	Element(Element&&) noexcept;
	Element& operator=(const Element&);
	/// \return ���� ��������(��� ���������)
	int getKey() const { return key; };
	/// \return ���� ��������� ��������
	Date getRelease() const { return release; };
	friend bool operator ==(const Element&, const Element&);
	/// \return ��������� ��������
	Excursion* getExcursion() const{ return exc; };
	/// \return ��������� ������� � ������
	Element* getNext() const { return next; };
	/// ������������� ��������� ������� � ������ \param el
	void setNext(Element* el) { next = el; };
	/// ������������� ���� \param k ����(��� ���������)
	void setKey(const int k) { key = k; };
	/// ������������� ���� \param _release ���� ���������
	void setRelease(const Date& _release) { release = _release; };
	/// ������������� ��������� �������� \param excur ���������
	void setExcursion(Excursion* excur) { exc = excur; };
	~Element() {}; 
};
class Table
{
protected:
	int size;
	std::vector<Element> elem;
public:
	/// ����������� �� ���������
	Table() : size(1) { elem.resize(size); }; 
	/// ����������� \param _size ������ �������
	Table(int _size) : size(_size) { elem.resize(_size); }; 
	Table(const Table&);
	Table(Table&&) noexcept;
	int hash(int k);
	Table& add(int ,Date&, Excursion*);
	Table& remove(int k, Date& version);
	Element find(int k, Date& version);
	void print() const;
	~Table() {};
};
#endif 

