//
// Created by Eliam on 29/04/2025.
//

#include "../includes/Serializer.hpp"

#include <string>
#include <iostream>
#include "../includes/Serializer.hpp"
#include "../includes/Data.hpp"

int main() {
	Data data;
	data.id = 42;
	data.info = "Hello 42";

	uintptr_t raw = Serializer::serialize(&data);
	Data* ptr = Serializer::deserialize(raw);

	std::cout << "Original address:   " << &data << std::endl;
	std::cout << "Deserialized ptr:   " << ptr << std::endl;

	if (ptr == &data)
		std::cout << "✅ Pointeur restauré correctement !" << std::endl;
	else
		std::cout << "❌ Mauvais pointeur !" << std::endl;

	std::cout << "Contenu : id = " << ptr->id << ", info = " << ptr->info << std::endl;

	return 0;
}