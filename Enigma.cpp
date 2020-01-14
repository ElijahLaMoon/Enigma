#include <algorithm>
#include <array>
#include <iostream>
#include <fstream>
#include <string>
#include "Enigma.hpp"
#include "Plugboard.hpp"
#include "Reflector.hpp"
#include "Rotor.hpp"

bool Enigma::duplicateCheck(std::array<int, 3> &rotorIndexes)
{
	if (rotorIndexes[0] == rotorIndexes[1] 
	||	rotorIndexes[1] == rotorIndexes[2] 
	||	rotorIndexes[0] == rotorIndexes[2])
	{
		std::cout << "Error: duplicates found" << std::endl;
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
		std::cout << "Error: incorrect input. There're only 5 rotors" << std::endl;
		return true;
	}
}


bool Enigma::setRingSettings(std::string &ringSettings)
{
	std::cin >> ringSettings;
	std::transform(ringSettings.begin(), ringSettings.end(), ringSettings.begin(), ::toupper);
	if (ringSettings.length() != 3)
	{
		std::cout << "Error: too much or too few rings. There're should be exactly 3 rings" << std::endl;
		return true;
	}
	else
	{
		for (auto &iterator : ringSettings)
		{
			if (!(iterator > 64 && iterator < 91))
			{
				std::cout << "Error: rings should be alphabetical characters (A-Z)" << std::endl;
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
	++offsetCounter;

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
	char plugboardOption;
	std::cout << "Would you like to set up plugboard? Y/y to set up or any other character to skip: ";
	std::cin >> plugboardOption;
	if (plugboardOption == 'y' || plugboardOption == 'Y')
	{
		if (plugboard.setPlugboard())
		{
			return EXIT_FAILURE;
		}
	}
 
	Reflector reflector;
	std::string message;
	int offsetCounter = 0;
	std::cout << "Type your message: ";
	if (!(plugboardOption == 'y' || plugboardOption == 'Y')) std::cin.ignore();
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
	std::ofstream result;
	result.open("result.txt");
	result << message;
	result.close();

	return EXIT_SUCCESS;
}
