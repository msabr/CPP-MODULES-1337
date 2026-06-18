#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	private:
		T*				array;
		unsigned int	size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array& operator=(const Array& other);
		~Array();

		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;

		unsigned int getSize() const;

		class OutOfBoundsException : public std::exception
		{
		public:
			virtual const char* what() const throw();
		};
};

#include "Array.tpp"

#endif