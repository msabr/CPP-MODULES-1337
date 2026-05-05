#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	private:
		T	*array;
		size_t	length;
	public:
		Array() : array(NULL), length(0) {}
		Array(unsigned int n) : array(new T[n]()), length(n) {}
		Array(const Array &other) : array(new T[other.length]()), length(other.length)
		{
			for (size_t i = 0; i < length; i++)
				array[i] = other.array[i];
		}
		~Array() { delete[] array; }

		Array &operator=(const Array &other)
		{
			if (this != &other)
			{
				delete[] array;
				length = other.length;
				array = new T[length]();
				for (size_t i = 0; i < length; i++)
					array[i] = other.array[i];
			}
			return *this;
		}

		T &operator[](size_t index)
		{
			if (index >= length)
				throw std::out_of_range("Index out of range");
			return array[index];
		}

		const T &operator[](size_t index) const
		{
			if (index >= length)
				throw std::out_of_range("Index out of range");
			return array[index];
		}

		size_t size() const { return length; }
};

#endif