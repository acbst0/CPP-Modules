#ifndef SEIALIZER_HPP
# define SEIALIZER_HPP

# include "Data.hpp"
# include <stdint.h>

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer& ref);
		Serializer& operator=(const Serializer& ref);
		~Serializer();
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t _raw);
};

#endif