#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include "Enigma.hpp"
#include "Plugboard.hpp"
#include "Reflector.hpp"
#include "Rotor.hpp"

bool Enigma::duplicateCheck(std::array<int, 3> &rotorIndexes)
{
	if (rotorIndexes[0] == rotorIndexes[1] || rotorIndexes[1] == rotorIndexes[2] || rotorIndexes[0] == rotorIndexes[2])
	{
		std::cout << "Bad input. Try again" << std::endl;
		return true;
	}
	else
	{
		return false;
	}
}

bool Enigma::correctInput(int choice)
{
    if (choice > 0 && choice < 6)
	{
		return false;
	}
	else
	{
		std::cout << "Bad input. Try again" << std::endl;
		return true;
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

void Enigma::encipher(std::array<Rotor, 3> &rotors, Reflector &reflector, Plugboard &plugboard, char &eachCharacter, int &offsetCounter)
{
	plugboard.substitute(eachCharacter);
	rotors[2].offset();
	if (offsetCounter > 25)
	{
		rotors[1].offset();
		if (offsetCounter > 675)
		{
			rotors[0].offset();
		}
	}

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
	offsetCounter++;

	plugboard.substitute(eachCharacter);
}

int Enigma::start()
{
	std::array<Rotor, 3> rotors;
	std::array<int, 3> rotorIndexes = {0, 0, 0}; 

	std::cout << "Set up 3 rotors. Choose from 1 to 5. Repeats restricted" << std::endl;

	std::cout << "First rotor: ";
	std::cin >> rotorIndexes[0];
	if (correctInput(rotorIndexes[0]))
	{
		return EXIT_FAILURE;
	}
	std::cout << "Second rotor: ";
	std::cin >> rotorIndexes[1];
	if (duplicateCheck(rotorIndexes) || correctInput(rotorIndexes[1]))
	{
		return EXIT_FAILURE;
	}
	std::cout << "Third rotor: ";
	std::cin >> rotorIndexes[2];
	if (duplicateCheck(rotorIndexes) || correctInput(rotorIndexes[2]))
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

	Plugboard plugboard;
    std::string plugboardCopy;
	char plugboardOption;
	std::cout << "Would you like to set up plugboard? Y/y to set up or any other character to skip: ";
	std::cin >> plugboardOption;
	if (plugboardOption == 'y' || plugboardOption == 'Y')
	{
    	std::cout << "Type characters in pairs (i.e. \"KL ON ...\"). No more than 13 pairs" << std::endl;
		std::cin.ignore();
		std::getline(std::cin, plugboardCopy);
		if (plugboard.setPlugboard(plugboardCopy))
		{
			return EXIT_FAILURE;
		}
	}
	else
	{
		std::cout << "Goodbye!" << std::endl;
		return EXIT_SUCCESS;
	}
 
	Reflector reflector;
	std::string message;
	int offsetCounter;
	std::cout << "Type your message: ";
	std::cin.ignore();
	std::getline(std::cin, message);
    std::transform(message.begin(), message.end(), message.begin(), ::toupper);
	for (auto &eachCharacter : message)
	{
		if (eachCharacter > 64 && eachCharacter < 91)
		{
			encipher(rotors, reflector, plugboard, eachCharacter, offsetCounter);
		}
	}
	std::cout << "Ciphered message:  " << message << std::endl;

	// TODO 1. plugboard
	// TODO 2. README

	return EXIT_SUCCESS;
}
