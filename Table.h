#pragma once
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
	Element(int k, Date& r, Excursion* excur) : key(k), release(r), exc(excur), next(nullptr) {};
	Element(const Element&);
	Element(Element&&) noexcept;
	Element& operator=(const Element&);
	int getKey() const { return key; };
	Date getRelease() const { return release; };
	friend bool operator ==(const Element&, const Element&);
	Excursion* getExcursion() const{ return exc; };
	Element* getNext() const { return next; };
	void setNext(Element* el) { next = el; };
	void setKey(const int k) { key = k; };
	void setRelease(const Date& release_) { release = release_; };
	void setExcursion(Excursion* excur) { exc = excur; };
	~Element() {};
};
class Table
{
protected:
	int size;
	std::vector<Element> elem;
public:
	Table() : size(1) { elem.resize(size); };
	Table(int _size) : size(_size) { elem.resize(_size); };
	Table(const Table&);
	Table(Table&&) noexcept;
	int hash(int k);
	Table& add(int ,Date&, Excursion*);
	Table& remove(int k, Date& version);
	Element& find(int k, Date& version);
	void print() const;
	~Table() {};
};
#endif 

