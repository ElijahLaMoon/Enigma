#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include "Enigma.hpp"
#include "Reflector.hpp"
#include "Rotor.hpp"

bool Enigma::correctInput(int rotorIndex)
{
	if (rotorIndex < 1 || rotorIndex > 5)
	{
		std::cout << "Bad input. Try again" << std::endl;
		return true;
	}
	else
	{
		return false;
	}
	
}

bool Enigma::duplicateCheck(std::array<int, 3> rotorIndexes)
{
	if (rotorIndexes.at(0) == rotorIndexes.at(1) || rotorIndexes.at(1) == rotorIndexes.at(2) || rotorIndexes.at(0) == rotorIndexes.at(2))
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

void Enigma::wholeCycle(std::array<Rotor, 3> &rotors, char &eachCharacter)
{
    eachCharacter = toupper(eachCharacter);
	std::array<int, 3> offsetCounters;
	for (auto i = 2; i > -1; i--)
	{
		rotors[i].substitute(eachCharacter, rotors[i].ring, offsetCounters[i], 's');
	}

	Reflector reflector;
	reflector.reflectorSubstitute(eachCharacter);

	for (auto i = 0; i < 3; i++)
	{
		rotors[i].substitute(eachCharacter, rotors[i].ring, offsetCounters[i], 'r');
	}
	
	for (auto i = 0; i < 3; i++)
	{
		offsetCounters[i] /= 2;
		for (auto j = 0; j < offsetCounters[i]; j++)
		{
			rotors[i].offset();
		}
	}
}

int Enigma::start()
{
	std::array<Rotor, 3> rotors;
	std::array<int, 3> rotorIndexes;

	std::cout << "Set up 3 rotors. Choose from 1 to 5. Repeats restricted" << std::endl;

	std::cout << "First rotor: ";
	std::cin >> rotorIndexes[0];
	if (correctInput(rotorIndexes.at(0)))
	{
		return EXIT_FAILURE;
	}
	std::cout << "Second rotor: ";
	std::cin >> rotorIndexes[1];
	if(correctInput(rotorIndexes.at(1) || duplicateCheck(rotorIndexes)))
	{
		return EXIT_FAILURE;
	}
	std::cout << "Third rotor: ";
	std::cin >> rotorIndexes[2];
	if(correctInput(rotorIndexes.at(2) || duplicateCheck(rotorIndexes)))
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

	std::string message;
	std::cout << "Type your message: ";
	std::cin.ignore();
	std::getline(std::cin, message);
	for (auto &eachCharacter : message)
	{
		wholeCycle(rotors, eachCharacter);
	}
	std::cout << "Ciphered message: " << message << std::endl;

	// TODO 1. plugboard
	// TODO 2. default settings
	// TODO 3. README
	// TODO 4. UI (optional)

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