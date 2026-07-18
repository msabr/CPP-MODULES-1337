/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:51:57 by msabr             #+#    #+#             */
/*   Updated: 2026/07/18 17:51:58 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array() : array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : array(NULL), _size(n)
{
	if (_size > 0)
		array = new T[_size]();
}

template <typename T>
Array<T>::Array(const Array& other) : array(NULL), _size(other._size)
{
	if (_size > 0)
	{
		array = new T[_size]();
		for (unsigned int i = 0; i < _size; ++i)
			array[i] = other.array[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		delete[] array;
		_size = other._size;
		if (_size > 0)
		{
			array = new T[_size]();
			for (unsigned int i = 0; i < _size; ++i)
				array[i] = other.array[i];
		}
		else
			array = NULL;
	}
	return *this;
}


template <typename T>
Array<T>::~Array()
{
	delete[] array;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size || index < 0)
		throw OutOfBoundsException();
	return array[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= _size || index < 0)
		throw OutOfBoundsException();
	return array[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{
	return "Array index out of bounds";
}