#ifndef SEIALIZER_HPP
# define SEIALIZER_HPP

# include <iostream>
# include <cstdint>

class Serializer
{
	private:
		/* data */
	public:
		Serializer();
		Serializer(const Serializer& ref);
		Serializer& operator=(const Serializer& ref);
		~Serializer();
};

#endif