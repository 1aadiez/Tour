#pragma once
#ifndef TABLE_H
#define TABLE_H
#include <iostream>
#include <list>
#include "Excursion.h"
class Element {
protected:
	int key;
	int release;
	Excursion* exc;
	std::list <Element> next;
public:
	Element()=default;
	Element(int k, int r) : key(k), release(r) { };
	int getKey() const { return key; };
	int getRelease() const { return release; };
	friend bool operator ==(const Element&, const Element&);
	Excursion* getExcursion() const{ return exc; };
	Element & getNext()  { return next.front(); };
	friend std::ostream& operator<< (std::ostream & out, const Element & el);
	std::list <Element>& Next() { return next; };
	void setNext(Element el) { next.push_front(el); };
	void setKey(const int k) { key = k; };
	void setRelease(const int release_) { release = release_; };
	void setExcursion(Excursion*);
	~Element() { delete[]exc; next.clear(); }//delete[] exc; next.clear(); };
};
class Table
{
protected:
	int size;
	Element* elem;
public:
	Table() : size(2) { elem = new Element[size]; };
	Table(int _size) : size(_size) { elem = new Element[size]; };
	Table(const Table&);
	Table(Table&&) noexcept;
	int hash(int k);
	Table& add(int ,int);
	Table& remove(int k, int version);
	Element& find(int k, int version);
	void print() const;
	~Table() 
	{
		delete[] elem; 
	};
};
#endif 

