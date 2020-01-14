#include <iostream>
#include "Enigma.hpp"

int main()
{
	std::cout << "Welcome to Enigma!" << std::endl;
	Enigma enigma;
	char choice;
	bool menu;
	do
	{
		enigma.start();
		std::cout << "Would you like to encrypt something else? (Y)es or (N)o: ";
		std::cin >> choice;
		if (choice == 'Y' || choice == 'y')
		{
			menu = true;
		}
		else
		{
			menu = false;
		}
		std::cout << std::endl;
	} while (menu);
	
	std::cout << "Press Enter to exit..." << std::endl;
	std::cin.ignore();
	std::cin.get();

	return EXIT_SUCCESS;
}
