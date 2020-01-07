#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include "Enigma.hpp"
#include "Reflector.hpp"
#include "Rotor.hpp"

bool Enigma::duplicateCheck(int indexOne, int indexTwo, int indexThree)
{
	if (indexOne == indexTwo || indexOne == indexThree || indexTwo == indexThree)
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
	std::transform(ringSettings.begin(), ringSettings.end(), ringSettings.begin(), ::toupper);
	if (ringSettings.length() != 3)
	{
		std::cout << "Bad input. Try again" << std::endl;
		return true;
	}
	else
	{
		for (auto &iterator : ringSettings)
		{
			if (!(iterator > 64 && iterator < 91))
			{
				std::cout << "Bad input. Try again" << std::endl;
				return true;
			}
		}
		return false;
	}
}

void Enigma::wholeCycle(std::array<Rotor, 3> &rotors, Reflector &reflector, char &eachCharacter)
{
	rotors.at(2).offset();
	
    for (auto i = 0; i < 3; i++)
	{
		rotors[i].ringApply(rotors[i].ring);
	}

	for (auto i = 2; i > -1; i--)
	{
		rotors[i].substitute(eachCharacter, 's');
	}

	reflector.reflectorSubstitute(eachCharacter);

	for (auto i = 0; i < 3; i++)
	{
		rotors[i].substitute(eachCharacter, 'r');
	}
}

int Enigma::start()
{
	std::array<Rotor, 3> rotors;
	int rotorIndexes[3];

	std::cout << "Set up 3 rotors. Choose from 1 to 5. Repeats restricted" << std::endl;

	std::cout << "First rotor: ";
	std::cin >> rotorIndexes[0];
	// TODO add check whether correctInput()
	rotors[0].setRotor(rotorIndexes[0]);
	std::cout << "Second rotor: ";
	std::cin >> rotorIndexes[1];
	if (duplicateCheck(rotorIndexes[0], rotorIndexes[1], rotorIndexes[2]))
	{
		return EXIT_FAILURE;
	}
	std::cout << "Third rotor: ";
	std::cin >> rotorIndexes[2];
	if (duplicateCheck(rotorIndexes[0], rotorIndexes[1], rotorIndexes[2]))
	{
		return EXIT_FAILURE;
	}
	for (auto i = 0; i < 3; i++)
	{	
		rotors[i].setRotor(rotorIndexes[i]);
	}

	std::cout << "Set up rings. Enter 3 characters from A to Z. Not case sensitive" << std::endl;
	if (setRingSettings(*ringSettings))
	{
		return EXIT_FAILURE;
	}
	for (auto i = 0; i < 3; i++)
	{
		rotors[i].ring = ringSettings[0][i];
	}

	Reflector reflector;
	std::string message;
	std::cout << "Type your message: ";
	std::cin.ignore();
	std::getline(std::cin, message);
    std::transform(message.begin(), message.end(), message.begin(), ::toupper);
	for (auto &eachCharacter : message)
	{
		if (eachCharacter > 64 && eachCharacter < 91)
		{
			wholeCycle(rotors, reflector, eachCharacter);
		}
	}
	std::cout << "Ciphered message:  " << message << std::endl;

	// TODO 1. check whether inputs (indexes and rings) are correct
	// TODO 2. offsets and notches
	// TODO 3. plugboard
	// TODO 4. default settings
	// TODO 5. README
	// TODO 6. UI (optional)

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