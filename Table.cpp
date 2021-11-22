#include "Table.h"
#include <iterator>
int Table::hash(int k)
{
	//std::size_t h = std::hash<int>{}(k);
	return k % size;
}
Table::Table(const Table& tab): size(tab.size)
{
	//elem = new Element[size];
	for (int i = 0; i < size; ++i)
		elem[i] = tab.elem[i];
}
Table::Table(Table&& tab) noexcept: size(tab.size), elem(tab.elem)
{
	//tab.elem = nullptr;
}
bool operator==(const Element& e1, const Element& e2)
{
	return(e1.key == e2.key && e1.release == e2.release);
}
Table& Table::add(int k, Date& date0, Excursion* l)
{
	int index = hash(k);
	Element* item = new Element;
	item->setKey(k); item->setRelease(date0); item->setExcursion(l);
	if (elem[index].getExcursion())
	{
		item->setNext(elem[index].getNext());
		elem[index].setNext(item);
	}
	else
	{
		elem[index].setKey(k); elem[index].setRelease(date0); elem[index].setExcursion(l);
	}
	/*if (elem[index].getKey() == k)
	{	
		item->setNext(elem[index].getNext());
		elem[index].setNext(item);
	}
	else
	{
		elem[index] = *item;
	}*/
	return *this;
}
Element& Table::find(int k, Date& version)
{
	int index = hash(k);
	if (elem[index].getKey() == k && elem[index].getRelease() == version)
	{
		Element res; 
		res = elem[index];
		std::cout << "Found";
		return res;
	}
	else
	{
		Element* fact = elem[index].getNext();
		while (fact)
		{
			if (fact->getKey() == k && fact->getRelease() == version)
			{
				Element res(k, version,fact->getExcursion());
				std::cout << "Found: ";
				return res;
			}
			fact = fact->getNext();
		}
	}
	throw std::exception("No element with such key or date");
}
Table& Table::remove(int k, Date& date0)
{
	int index = hash(k);
	int flag = 0;
	if (elem[index].getKey() == k && elem[index].getRelease() == date0)
	{
		if (elem[index].getNext())
		{
			elem[index] = *elem[index].getNext();
		}
		else
		{
			Date data{ 0,0,0 };
			elem[index].setKey(NULL);
			elem[index].setRelease(data);
            elem[index].setExcursion(nullptr);
			
		}
	}
	else
	{
		Element* fact = elem[index].getNext();
		if (fact->getKey() == k && fact->getRelease() == date0)
		{
			elem[index].setNext(fact->getNext());
			return *this;
		}
		while (fact)
		{
			Element* tmp = fact;
			if (fact->getNext())
			{
				if (fact->getNext()->getKey() == k && fact->getNext()->getRelease() == date0)
				{
					fact->setNext(fact->getNext()->getNext());
				}
			}
			fact = fact->getNext();
		}
		/*for (auto it = std::begin(elem[index].Next()); it != std::end(elem[index].Next()); ++it)
		{
			if ((*it).getKey() == k && (*it).getRelease() == date0)
			{
				elem[index].Next().erase(it);
				flag = 1;
				break;
			}
		}
		if (!flag)
			throw std::exception("No such element");*/
	}
	return *this;
}
void Table::print() const
{
	for (int i = 0; i < 2; i++)
	{
		std::cout << "[" << i << "] " << elem[i].getKey() << " " << elem[i].getRelease();
       	//std::cout << elem[i].getExcursion()->getDate();
		Excursion* exc = elem[i].getExcursion();
		std::cout << *(elem[i].getExcursion());//elem[i].getExcursion();
	    std::cout << "=>\n";

			Element* fact;
			fact = elem[i].getNext();
			while (fact)
			{
				std::cout << fact->getKey() << " "<< fact->getRelease() << " " << fact->getExcursion()[0]<<"=>";
				fact = fact->getNext();
			}
			delete fact;
			std::cout << std::endl;
		
	}
}
/*std::ostream& operator <<(std::ostream& out, const Element& el)
{
	out << "=> "; out << el.getKey(); out << " "; out << el.getRelease(); out << " ";
	return out;
}*/