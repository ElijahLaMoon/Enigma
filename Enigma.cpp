#include <algorithm>
#include <iostream>
#include <string>
#include "Enigma.hpp"
#include "Reflector.hpp"
#include "Rotor.cpp"

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
	} while (!(option == 'y' 
			|| option == 'n'
			|| option == 'Y'
			|| option == 'N'));

	return isDefaultOptions;
}

bool Enigma::duplicateCheck(int n_1, int n_2, int n_3)
{
    if (n_1 == n_2 || n_1 == n_3 || n_2 == n_3)
    {
        std::cout << "Bad input. Try again" << std::endl;
        return true;
    } else return false;
}


bool Enigma::setRingSettings(std::string& ringSettings)
{
    std::cin >> ringSettings;
    if (ringSettings.length() != 3)
    {
        std::cout << "Bad input. Try again" << std::endl;
        return true;
    } else return false;
}

int Enigma::start()
{
	Rotor firstRotorInstance;
	Rotor secondRotorInstance;
	Rotor thirdRotorInstance;
	int firstRotorIndex;
	int secondRotorIndex;
	int thirdRotorIndex;

	std::cout << "Set up 3 rotors. Choose from 1 to 5. Repeats restricted" << std::endl;
	
	std::cout << "First rotor: ";
	std::cin >> firstRotorIndex;
	firstRotorInstance.setRotor(firstRotorIndex);
	
	std::cout << "Second rotor: ";
	std::cin >> secondRotorIndex;
	if (duplicateCheck(firstRotorIndex, secondRotorIndex, thirdRotorIndex))
	{
		return EXIT_FAILURE;
	}
	secondRotorInstance.setRotor(secondRotorIndex);

	std::cout << "Third rotor: ";
	std::cin >> thirdRotorIndex;
	if (duplicateCheck(firstRotorIndex, secondRotorIndex, thirdRotorIndex))
	{
		return EXIT_FAILURE;
	}
	thirdRotorInstance.setRotor(thirdRotorIndex);

    std::string ringSettings[3];
    std::cout << "Set up rings. Enter 3 characters from A to Z. Not case sensitive" << std::endl;
    if (setRingSettings(*ringSettings))
    {
        return EXIT_FAILURE;
    }
	firstRotorInstance.ring = ringSettings[0][0];
	secondRotorInstance.ring = ringSettings[0][1];
	thirdRotorInstance.ring = ringSettings[0][2];	

	std::string message;
	std::cout << "Type your message: ";
    std::cin.ignore();
    std::getline(std::cin, message);
	firstRotorInstance.substitute(message);
    secondRotorInstance.substitute(message);
    thirdRotorInstance.substitute(message);
	std::cout << "Ciphered message: " << message << std::endl;

	return EXIT_SUCCESS;
}
