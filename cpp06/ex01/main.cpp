#include "Serializer.hpp"

int main(void)
{

	Data *data = new Data;
	data->name = "Abostano";
	data->number = 1907;

	uintptr_t raw = Serializer::serialize(data);
	Data *serialized = Serializer::deserialize(raw);

	std::cout << serialized->name << std::endl;
	std::cout << serialized->number << std::endl;

	delete data;
	return (0);
}