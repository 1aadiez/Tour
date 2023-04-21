#include "Table.h"
#include <iterator>
/*!
* \brief Хэш-функция
* \param k Ключ
* \return Индекс в таблице
*/
int Table::hash(int k)
{
	return k % size;
}
/*!
* \brief Копирующий конструктор
*/
Table::Table(const Table& tab): size(tab.size)
{
	for (int i = 0; i < size; ++i)
		elem[i] = tab.elem[i];
}
/*!
* \brief Перемещающий конструктор
*/
Table::Table(Table&& tab) noexcept: size(tab.size), elem(tab.elem)
{
	
}
/*!
* \brief Перегруженный оператор сравнения
* \return true, если два элемента равны
* \return false, если два элемента не равны
*/
bool operator==(const Element& e1, const Element& e2)
{
	return(e1.key == e2.key && e1.release == e2.release);
}
/*!
* \brief Копирующий конструктор
*/
Element::Element(const Element& el) : key(el.key), release(el.release)
{
	exc = el.exc;
	next = el.next;
}
/*!
* \brief Перемещающий конструктор
*/
Element::Element(Element&& el) noexcept: key(el.key), release(el.release),exc(el.exc),next(el.next)
{
	el.exc = nullptr;
	el.next = nullptr;
}
/*!
* \brief Перегруженный оператор присваивания
*/
Element& Element::operator=(const Element& el)
{
	if (&el == this)
		return *this;
	key = el.key;
	for (int i = 0; el.exc->getDays(); i++)
	{
		exc[i] = el.exc[i];
	}
	//next = el.next;
	return *this;
}
/*!
* \brief Добавляет элемент в таблицу
* \param k Ключ \param date0 Дата \param l Экскурсия
*/
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
		elem[index].setKey(k); 
		elem[index].setRelease(date0); 
		elem[index].setExcursion(l);
	}
	return *this;
}
/**
* \brief Ищет элемент по ключу и дате
* \param k Ключ \param version Дата
* \return Найденный элемент
* \throw std::exception Элемент не найден
*/
Element Table::find(int k, Date& version)
{
	int index = hash(k);
	if (elem[index].getKey() == k && elem[index].getRelease() == version)
	{
		Element res(elem[index]); 
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
				return res;
			}
			fact = fact->getNext();
		}
	}
	throw std::exception("No element with such key or date");
}
/**
* \brief Удаляет элемент из таблицы по ключу и дате
* \param k Ключ \param date0 Дата
*/
Table& Table::remove(int k, Date& date0)
{
	int index = hash(k);
	int flag = 0;
	if (elem[index].getKey() == k && elem[index].getRelease() == date0)
	{
		if (elem[index].getNext())
		{
			elem[index].setKey(elem[index].getNext()->getKey());
			elem[index].setRelease(elem[index].getNext()->getRelease());
			elem[index].setExcursion(elem[index].getNext()->getExcursion());
			elem[index].setNext(elem[index].getNext()->getNext());
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
	}
	return *this;
}
/**
* \brief Выводит на экран таблицу
*/
void Table::print() const
{
	for (int i = 0; i < size; i++)
	{
		if (elem[i].getExcursion())
		{
			std::cout << "[" << i << "] " << elem[i].getKey() << " " << elem[i].getRelease();
			std::cout << *(elem[i].getExcursion());//elem[i].getExcursion();
			std::cout << "=>\n";
			Element* fact;
			fact = elem[i].getNext();
			while (fact)
			{
				std::cout << fact->getKey() << " " << fact->getRelease() << " ";
				for (int j = 0; j < fact->getExcursion()->getDays(); j++)
				{
					std::cout << fact->getExcursion()[i];
				}
				std::cout << "=>\n";
				fact = fact->getNext();
			}
			delete fact;
			std::cout << std::endl;
		}
	}
}