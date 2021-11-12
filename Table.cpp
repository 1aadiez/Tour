#include "Table.h"
#include <iterator>
int Table::hash(int k)
{
	return k % size;
}
Table::Table(const Table& tab): size(tab.size)
{
	elem = new Element[size];
	for (int i = 0; i < size; ++i)
		elem[i] = tab.elem[i];
}
Table::Table(Table&& tab) noexcept: size(tab.size), elem(tab.elem)
{
	tab.elem = nullptr;
}
void Element::setExcursion(Excursion* excur)
{
	exc = excur;
}
bool operator==(const Element& e1, const Element& e2)
{
	return(e1.key == e2.key && e1.release == e2.release);
}
Table& Table::add(int k, int date0)
{
	int index = hash(k);
	Element item(k,date0);
	if (elem[index].getKey() == k)
	{	
		elem[index].setNext(item);
	}
	else
	{
	    elem[index] = item;
	}
	return *this;
}
Element& Table::find(int k, int version)
{
	int index = hash(k);
	if (elem[index].getKey() == k && elem[index].getRelease() == version)
	{
		Element res; 
		res = elem[index];
		std::cout << "Found";
		return res;
	}
	for (auto it = std::begin(elem[index].Next()); it != std::end(elem[index].Next());++it)
	{
		if ((*it).getKey() == k && ((*it).getRelease()==version))
		{
			std::cout << "Found";
			Element res(k, version);
			return res;
		}
	}
	throw std::exception("No element with such key or date");
}
Table& Table::remove(int k, int date0)
{
	int index = hash(k);
	int flag = 0;
	if (elem[index].getKey() == k && elem[index].getRelease() == date0)
	{
		elem[index] = elem[index].Next().front();
		elem[index].setNext(elem[index]);
	}
	else
	{
		for (auto it = std::begin(elem[index].Next()); it != std::end(elem[index].Next()); ++it)
		{
			if ((*it).getKey() == k && (*it).getRelease() == date0)
			{
				elem[index].Next().erase(it);
				flag = 1;
				break;
			}
		}
		if (!flag)
			throw std::exception("No such element");
	}
	return *this;
}
void Table::print() const
{
	Table tab(*this);
	for (int i = 0; i < size; i++)
	{
		std::cout << "[" << i << "] " << tab.elem[i].getKey()<< " "<< tab.elem[i].getRelease();
		std::list<Element> pop = tab.elem[i].Next();
		std::cout << " ";		
		std::copy(pop.begin(), pop.end(), std::ostream_iterator<Element>(std::cout));
		pop.clear();
		std::cout << std::endl;
	}
}
std::ostream& operator <<(std::ostream& out, const Element& el)
{
	out << "=> "; out << el.getKey(); out << " "; out << el.getRelease(); out << " ";
	return out;
}
