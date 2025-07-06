template <typename T>
Array<T>::Array() : arr(NULL), _size(0) {}

template <typename T>
Array<T>::Array(const size_t size) : _size(size)
{
	this->arr = new T[this->_size];
	for (size_t i = 0; i < this->_size; i++)
		this->arr[i] = T();
}

template <typename T>
Array<T>::Array(const Array& ref) : _size(ref._size)
{
	this->arr = new T[this->_size];
	for (size_t i = 0; i < this->_size; i++)
		this->arr[i] = ref.arr[i];
}

template <typename T>
Array<T>::~Array()
{
	delete[] this->arr;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& ref)
{
	if (this != &ref)
	{
		if (this->arr != NULL)
			delete[] this->arr;
		this->_size = ref._size;
		this->arr = new T[this->_size];
		for (size_t i = 0; i < this->_size; i++)
			this->arr[i] = ref.arr[i];
	}
	return *this;
}

template <typename T>
size_t Array<T>::size() const
{
	return (this->_size);
}

template <typename T>
T& Array<T>::operator[](size_t s)
{
	if (s > this->_size - 1)
		throw WrongIndex();
	return arr[s];
}

template <typename T>
const T& Array<T>::operator[](size_t s) const
{
	if (s > this->_size - 1)
		throw WrongIndex();
	return arr[s];
}

template <typename T>
const char* Array<T>::WrongIndex::what() const throw()
{
	return ("Index is not available!");
}