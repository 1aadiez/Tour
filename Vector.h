#pragma once
#ifndef VECTOR_H
#define VECTOR_H

template <class T>
class Vector
{
private:
	T* data;
	int m_size;
	int m_capacity;
public:
	Vector() : m_size(0),m_capacity(0), data(nullptr) {};
	Vector(int size) : m_size(size),m_capacity(size) { data = new T[size]; };
	Vector(const Vector& vec): m_size(vec.m_size), m_capacity(vec.m_capacity)
	{
		data = new T[m_size];
		for (int i = 0; i < m_size; i++)
		{
			data[i] = vec.data[i];
		}
	}
	Vector(Vector&& vec) noexcept
		: m_size(vec.m_size), m_capacity(vec.m_capacity), data(vec.data)
	{
		vec.data = nullptr;
	}
	int size() const { return m_size; };
	int capacity() const{ return m_capacity; };
	bool empty() const
	{
		if (m_size == 0)
			return true;
		else
			return false;
	};
	T& operator[](int i) { return data[i]; };
	Vector& operator=(const Vector& vector)
	{
	};
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
	void reserve(const int);
	void resize(const int);
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
	void clear() {
		delete[] data;
		m_size = 0;
		data = new T[m_capacity];
	};
	~Vector() { delete[] data; };
};





#endif