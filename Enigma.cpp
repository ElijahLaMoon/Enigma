#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include "Enigma.hpp"
#include "Reflector.hpp"
#include "Rotor.hpp"

bool Enigma::duplicateCheck(int n_1, int n_2, int n_3)
{
	if (n_1 == n_2 || n_1 == n_3 || n_2 == n_3)
	{
		std::cout << "Bad input. Try again" << std::endl;
		return true;
	}
	else
	{
		return false;
	}
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
	{
		return false;
	}
	std::transform(ringSettings.begin(), ringSettings.end(), ringSettings.begin(), ::toupper);
}

int Enigma::start()
{
	std::array<Rotor, 3> rotors;
	int rotorIndexes[3];

	std::cout << "Set up 3 rotors. Choose from 1 to 5. Repeats restricted" << std::endl;

	std::cout << "First rotor: ";
	std::cin >> rotorIndexes[0];
	rotors[0].setRotor(rotorIndexes[0]);

	std::cout << "Second rotor: ";
	std::cin >> rotorIndexes[1];
	if (duplicateCheck(rotorIndexes[0], rotorIndexes[1], rotorIndexes[2]))
	{
		return EXIT_FAILURE;
	}
	rotors[1].setRotor(rotorIndexes[1]);

	std::cout << "Third rotor: ";
	std::cin >> rotorIndexes[2];
	if (duplicateCheck(rotorIndexes[0], rotorIndexes[1], rotorIndexes[2]))
	{
		return EXIT_FAILURE;
	}
	rotors[2].setRotor(rotorIndexes[2]);

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
	rotors[0].substitute(message, rotors[0].ring);
	rotors[1].substitute(message, rotors[1].ring);
	rotors[2].substitute(message, rotors[2].ring);
	std::cout << "Ciphered message: " << message << std::endl;

	// TODO 1. inverse rotors
	// TODO 2. reflector
	// TODO 3. default settings
	// TODO 4. UI

	return EXIT_SUCCESS;
}

/*
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
*/