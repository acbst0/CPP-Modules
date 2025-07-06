#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
	private:
		T* arr;
		size_t _size;
	public:
		Array();
		Array(size_t size);
		Array(const Array& ref);
		~Array();
		Array& operator=(const Array& ref);
		size_t size() const;
		T& operator[](size_t s);
		const T& operator[](size_t s) const;

		class WrongIndex : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#include "Array.tpp"

#endif