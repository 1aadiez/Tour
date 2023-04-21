#pragma once
#ifndef VECTOR_H
#define VECTOR_H
//iterator library cppreference - требования к итераторам все условия
template <class T>
class Vector
{
private:
	T* data;
	int m_size;
	int m_capacity;
public:
	/*!
	* Конструктор по умолчанию
	*/
	Vector() : m_size(0),m_capacity(0), data(nullptr) {};
	/*!
	* Конструктор \param size Количество элементов вектора
	*/
	Vector(int size) : m_size(0),m_capacity(size) { data = new T[size]; };
	/*!
	* Копирующий конструктор
	*/
	Vector(const Vector& vec): m_size(vec.m_size), m_capacity(vec.m_capacity)
	{
		data = new T[m_size];
		for (int i = 0; i < m_size; i++)
		{
			data[i] = vec.data[i];
		}
	}
	/*!
	* Перемещающий конструктор
	*/
	Vector(Vector&& vec) noexcept
		: m_size(vec.m_size), m_capacity(vec.m_capacity), data(vec.data)
	{
		vec.data = nullptr;
	}
	/// Возвращает длину вектора \return Длина вектора
	int size() const { return m_size; };
	/// Возвращает емкость вектора \return Емкость вектора
	int capacity() const{ return m_capacity; };
	/*!
	* Функция, проверяющая есть ли в векторе элементы
	* \return true Вектор пустой
	* \return false Вектор не пустой
	*/
	bool empty() const
	{
		if (m_size == 0)
			return true;
		else
			return false;
	};
	/*!
	* Доступ к элементу вектора по индексу \param i Индекс элемента
	*/
	T& operator[](int i) { return data[i]; };
	Vector& operator=(const Vector& vector)
	{
	};
	/*!
	* Перегруженный оператор сравнения двух векторов
	* \return true Два вектора равны
	* \return false Два вектора не равны
	*/
	friend bool operator ==(const Vector& vec1, const Vector& vec2)
	{
		if (vec1.m_size == vec2.m_size)
		{
			for (int i = 0; i < vec1.m_size; i++)
			{
				if (vec1.data[i] != vec2.data[i])
					return false;
			}
			return true;
		}
		else
			return false;
	};
	/**
	* Добавляет элемент в конец вектора
	* \param value Составляющая вектора
	*/
	void push_back(T value)
	{
		if (m_capacity > m_size)
		{
			T* newdata = new T[m_capacity];
			for (int i = 0; i < m_capacity; i++)
			{
				newdata[i] = data[i];
				delete[] data;
				data = newdata;
			}
		}
		data[m_size] = value;
		m_size++;
	};
	/*!
	* Очищает элементы вектора
	*/
	void clear() {
		delete[] data;
		m_size = 0;
		data = new T[m_capacity];
	};
	/*!
	* Функция, удаляющая последний элемент вектора
	*/
	void pop_back()
	{
		T* newdata = new T[m_capacity-1];
		for (int i = 0; i < m_capacity; i++)
			newdata[i] = data[i];
		delete[] data;
		data = newdata;
	}
	~Vector() { delete[] data; };
};





#endif