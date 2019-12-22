#include <algorithm>
#include <iostream>
#include "Rotor.cpp"

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
	Rotor rotorInstance;
	//-----------------------
	//	testing zone
	int rotorIndex;

	std::cout << "Which rotor to use?" << std::endl;
	std::cout << "Choose from 1 to 5: ";
	std::cin >> rotorIndex;
	rotorInstance.setRotor(rotorIndex);

	std::string message;
	std::cout << "Type your message: ";
	std::cin >> message;

	rotorInstance.substitute(message);
	std::cout << "Ciphered message: " << message << std::endl;

	/*	USE THIS CONSTRUCTION FOR OFFSETS
	for (itr = message.begin(); itr != message.end(); ++itr)
	{
		std::cout << ++(*itr);
	}
	std::cout << std::endl;
	*/

	//-----------------------

	return EXIT_SUCCESS;
}