#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include "Enigma.hpp"
#include "Reflector.hpp"
#include "Rotor.hpp"

// TODO make default settings
bool Enigma::defaultSettings()
{
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
	} while (!(option == 'y' || option == 'n' || option == 'Y' || option == 'N'));

	return isDefaultOptions;
}

bool Enigma::duplicateCheck(int n_1, int n_2, int n_3)
{
	if (n_1 == n_2 || n_1 == n_3 || n_2 == n_3)
	{
		std::cout << "Bad input. Try again" << std::endl;
		return true;
	}
	else
		return false;
}

bool Enigma::setRingSettings(std::string &ringSettings)
{
	std::cin >> ringSettings;
	if (ringSettings.length() != 3)
	{
		std::cout << "Bad input. Try again" << std::endl;
		return true;
	}
	else
		return false;
}

int Enigma::start()
{
	// TODO how to access rotors from the array below?
	std::array<Rotor, 3> rotors;
	int firstRotorIndex;
	int secondRotorIndex;
	int thirdRotorIndex;

	std::cout << "Set up 3 rotors. Choose from 1 to 5. Repeats restricted" << std::endl;

	std::cout << "First rotor: ";
	std::cin >> firstRotorIndex;
	rotors[0].setRotor(firstRotorIndex);

	std::cout << "Second rotor: ";
	std::cin >> secondRotorIndex;
	if (duplicateCheck(firstRotorIndex, secondRotorIndex, thirdRotorIndex))
	{
		return EXIT_FAILURE;
	}
	rotors[1].setRotor(secondRotorIndex);

	std::cout << "Third rotor: ";
	std::cin >> thirdRotorIndex;
	if (duplicateCheck(firstRotorIndex, secondRotorIndex, thirdRotorIndex))
	{
		return EXIT_FAILURE;
	}
	rotors[2].setRotor(thirdRotorIndex);

	std::string ringSettings[3];
	std::cout << "Set up rings. Enter 3 characters from A to Z. Not case sensitive" << std::endl;
	if (setRingSettings(*ringSettings))
	{
		return EXIT_FAILURE;
	}
	rotors[0].ring = ringSettings[0][0];
	rotors[1].ring = ringSettings[0][1];
	rotors[2].ring = ringSettings[0][2];

	std::string message;
	std::cout << "Type your message: ";
	std::cin.ignore();
	std::getline(std::cin, message);
	rotors[0].substitute(message);
	rotors[1].substitute(message);
	rotors[2].substitute(message);
	std::cout << "Ciphered message: " << message << std::endl;

	return EXIT_SUCCESS;
}
