#include "Serializer.hpp"

int main(void)
{
	struct Data data;
	data.s1 = "Hello";
	data.s2 = "world";
	data.n = 42;

	Data *ptr = &data;

	std::cout << "pointer = " << ptr << std::endl;

	uintptr_t iptr = Serializer::serialize(ptr);
	std::cout << "int pointer: " << iptr << std:: endl;

	ptr = Serializer::deserialize(iptr);
	std::cout << "pointer = " << ptr << " value1 = " << ptr->s1 << "; value2 = " << ptr->s2 << "; value3 = " << ptr->n << std::endl;
}