template <typename T>
Array<T>::Array() : array(NULL), size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : array(NULL), size(n)
{
	if (size > 0)
		array = new T[size]();
}

template <typename T>
Array<T>::Array(const Array& other) : array(NULL), size(other.size)
{
	if (size > 0)
	{
		array = new T[size];
		for (unsigned int i = 0; i < size; ++i)
			array[i] = other.array[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		delete[] array;
		size = other.size;
		if (size > 0)
		{
			array = new T[size];
			for (unsigned int i = 0; i < size; ++i)
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
	if (index >= size)
		throw OutOfBoundsException();
	return array[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= size)
		throw OutOfBoundsException();
	return array[index];
}

template <typename T>
unsigned int Array<T>::getSize() const
{
	return size;
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{
	return "Array index out of bounds";
}