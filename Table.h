#pragma once
#ifndef TABLE_H
#define TABLE_H
#include <iostream>
#include <list>
#include <vector>
#include "Excursion.h"
class Element {
protected:
	int key;
	Date release;
	Excursion* exc;
	Element* next;
public:
	Element()=default;
	Element(int k, Date& r, Excursion* excur) : key(k), release(r), exc(excur), next(nullptr) {};
	int getKey() const { return key; };
	Date getRelease() const { return release; };
	friend bool operator ==(const Element&, const Element&);
	//friend std::ostream& operator << (std::ostream&, const Element&);
	Excursion* getExcursion() const{ return exc; };
	Element* getNext() const { return next; };
	void setNext(Element* el) { next = el; };
	void setKey(const int k) { key = k; };
	void setRelease(const Date& release_) { release = release_; };
	void setExcursion(Excursion* excur) { exc = excur; };
	~Element() {
			//delete[] exc;
	 };
};
class Table
{
protected:
	int size;
	std::vector<Element> elem;
	//Element* elem; //стандартная stl
public:
	Table() : size(2) { elem.resize(size); };
	Table(int _size) : size(_size) { elem.resize(_size); }//elem = new Element[size]; };
	Table(const Table&);
	Table(Table&&) noexcept;
	int hash(int k);
	Table& add(int ,Date&, Excursion*);
	Table& remove(int k, Date& version);
	Element& find(int k, Date& version);
	void print() const;
	~Table() 
	{
		//delete[] elem; 
	};
};
#endif 

