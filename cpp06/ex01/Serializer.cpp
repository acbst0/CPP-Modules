#include "Serializer.hpp"

Serializer::Serializer()
{

}

Serializer::Serializer(const Serializer& ref)
{
	*this = ref;
}

Serializer& Serializer::operator=(const Serializer& ref)
{
	(void)ref;
	return (*this);
}

Serializer::~Serializer()
{

}

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t _raw)
{
	return (reinterpret_cast<Data*>(_raw));
}