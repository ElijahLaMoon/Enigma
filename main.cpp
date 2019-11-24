#include "Rotor.cpp"
#include "Rotor.hpp"
#include <iostream>

void makeRotors() {
	Rotor firstRotor; // = Rotor();
	rotorInitializer(firstRotor);	
};

bool defaulSettings() {
	bool isDefaultOptions;
	char option;
	std::cout << "Would you like to use default settings (y/n)?" << std::endl;
	std::cin >> option;
	do
	{
		if (option == 'y' || option == 'Y')
		{
			isDefaultOptions = true;
		}
		else if (option == 'n' || option == 'N')
		{
			isDefaultOptions = false;
		}
	} while (!(option == 'y' 
			|| option == 'n'
			|| option == 'Y'
			|| option == 'N'));

	return isDefaultOptions;
}

int main()
{
	

	return EXIT_SUCCESS;
}