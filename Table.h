#pragma once
/*!
* \file
* \brief Заголовочный файл с описанием классов Element и Table
* Данный файл содержит в себе определение данных двух классов
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
	/// Конструктор \param k Ключ(код экскурсии) \param r Дата \param excur Экскурсия
	Element(int k, Date& r, Excursion* excur) : key(k), release(r), exc(excur), next(nullptr) {};
	Element(const Element&);
	Element(Element&&) noexcept;
	Element& operator=(const Element&);
	/// \return Ключ элемента(код экскурсии)
	int getKey() const { return key; };
	/// \return Дата экскурсии элемента
	Date getRelease() const { return release; };
	friend bool operator ==(const Element&, const Element&);
	/// \return Экскурсия элемента
	Excursion* getExcursion() const{ return exc; };
	/// \return Следующий элемент в списке
	Element* getNext() const { return next; };
	/// Устанавливает следующий элемент в списке \param el
	void setNext(Element* el) { next = el; };
	/// Устанавливает ключ \param k Ключ(код экскурсии)
	void setKey(const int k) { key = k; };
	/// Устанавливает дату \param _release Дата экскурсии
	void setRelease(const Date& _release) { release = _release; };
	/// Устанавливает экскурсию элемента \param excur Экскурсия
	void setExcursion(Excursion* excur) { exc = excur; };
	~Element() {}; 
};
class Table
{
protected:
	int size;
	std::vector<Element> elem;
public:
	/// Конструктор по умолчанию
	Table() : size(1) { elem.resize(size); }; 
	/// Конструктор \param _size Размер таблицы
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

